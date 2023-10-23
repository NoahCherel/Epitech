const bcrypt = require("bcryptjs");
const bodyParser = require("body-parser");
const dotenv = require("dotenv");
const express = require("express");
const { init } = require("express/lib/application");
const jsonwebtoken = require("jsonwebtoken");
const mysql2 = require("mysql2");
const router = express.Router();

const db = require("../../config/db.js");
const { check_mail, check_login } = require("../user/user.query.js");
const connection = db();

router.post("/register", (req, res) => {
    const { email, name, firstname, password } = req.body;
    const hash = bcrypt.hashSync(password, 10);
    const values = [email, name, firstname, hash];
    const query = `INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)`;
        if (email === undefined || name === undefined || firstname === undefined || password === undefined) {
            res.status(500).json({
                msg: "internal server error"
            });
        }
        check_mail(res, email, (err) => {
            if (err == 84) {
                res.status(409).json({
                    msg: "Account already exist"
                });
            } else {
                connection.execute(query, values, (err, results) => {
                    res.send({
                        token: jsonwebtoken.sign({
                            email:email,
                            password:hash
                        }, process.env.SECRET)
                    });
                });
            }
        });
});

router.post("/login", (req, res) => {
    const { email, password } = req.body;
    const query = `SELECT * FROM user WHERE email = ?`;
    const values = [email];
    if (email === undefined || password === undefined) {
        res.status(500).json({
            msg: "internal server error"
        });
    }
    check_login(res, email, password, (err, token) => {
        if (err == 84) {
            res.status(401).json({
                msg: "Invalid credentials"
            });
        } else {
            res.send({
                token: token
            });
        }
    });
});

module.exports = router;
