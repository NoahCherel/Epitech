const bcrypt = require("bcryptjs");
const bodyParser = require("body-parser");
const { table } = require("console");
const dotenv = require("dotenv");
const express = require("express");
const jsonwebtoken = require("jsonwebtoken");
const mysql2 = require("mysql2");
const router = express.Router();
var db = require("../../config/db.js");
const connection = db();
const login = require("../../middleware/auth");


router.get("/user", login, (req, res) => {
    const query = `SELECT * FROM user`;
    connection.query(query, (err, results) => {
        if (err) {
            res.status(500).send({
                msg: "Internal server error"
            });
        } else {
            res.send(results);
        }
    });
});

router.get("/user/todos", login, (req, res) => {
    const query = `SELECT * FROM todo`;
    connection.query(query, (err, results) => {
        if (err) {
            res.status(500).send({
                msg: "Internal server error"
            });
        } else {
            res.send(results);
        }
    });
});

router.get("/users/:email", login, (req, res) => {
    const email = req.params.email;
    const query = `SELECT * FROM user WHERE email = ?`;
    const values = [email];
    connection.query(query, values, (err, results) => {
        if (err) {
            res.status(500).send({
                msg: "Internal server error"
            });
        }
        if (results.length === 0) {
            const query1 = `SELECT * FROM user WHERE id = ?`;
            connection.query(query1, values, (err, results) => {
                if (err) {
                    res.status(500).send({
                    msg: "Internal server error"
                });
            } else {
                res.send(results);
            }
        });
        } else {
            res.send(results);
        }
    });
});

router.put("/users/:id", login, (req, res) => {
    const id = req.params.id;
    const { name, email, password, firstname} = req.body;
    const values = [name, email, password, firstname, id];
    const query = `UPDATE user SET name = ?, email = ?, password = ?, firstname = ? WHERE id = ?`;
    const query2 = `SELECT * FROM user WHERE id = ?`;
    if (name === undefined || email === undefined || password === undefined || firstname === undefined || id === undefined) {
        res.status(500).json({
            msg: "internal server error"
        });
        return;
    }
    connection.query(query, values, (err, results) => {
        if (err) {
            res.status(500).json({
                error: err,
                msg: "internal server error"
            });
        } else {
            connection.query(query2, id, (err, results) => {
                if (err) {
                    res.status(500).json({
                        error: err,
                        msg: "internal server error"
                    });
                } else {
                    res.send(results);
                }
            });
        }
    });
});

function checkUser(id) {
    return new Promise((resolve, reject) => {
        const query = `SELECT * FROM user WHERE id = ?`;
        const values = [id];
        connection.query(query, values, (err, results) => {
            if (err) {
                reject(err);
            } else {
                resolve(results);
            }
        });
    });
}

router.delete("/users/:id", login, (req, res) => {
    const id = req.params.id;
    checkUser(id).then(results => {
        if (results.length === 0) {
            res.status(500).json({
                msg: "Not found"
            });
        } else {
            const query = `DELETE FROM user WHERE id = ?`;
            const values = [id];
            connection.query(query, values, (err, results) => {
                if (err) {
                    res.status(500).json({
                        msg: "internal server error"
                    });
                } else {
                    res.send({
                        msg: "Successfully deleted record number: " + id
                    });
                }
            });
        }
    });
});

module.exports = router;