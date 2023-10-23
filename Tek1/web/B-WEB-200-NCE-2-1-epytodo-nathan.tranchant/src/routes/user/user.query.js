var db = require("../../config/db.js");
const mysql2 = require("mysql2");
const jsonwebtoken = require("jsonwebtoken");
const bcrypt = require("bcryptjs");
const connection = db();

exports.check_mail = function(res, mail, callback) {
    const query = 'SELECT * FROM `user` WHERE email = ?';
    const values = [mail];
    connection.query(query, values, (err, results) => {
        if (err) {
            callback(err);
        } else {
            if (results.length > 0) {
                callback(84);
            } else {
                callback(0);
            }
        }
    });
}

exports.check_login = function(res, mail, password, callback) {
    const query = 'SELECT * FROM `user` WHERE email = ?';
    const values = [mail];
    connection.query(query, values, (err, results) => {
        if (err) {
            callback(err);
        } else {
            if (results.length > 0) {
                const user = results[0];
                const isValid = bcrypt.compareSync(password, user.password);
                if (isValid) {
                    const token = jsonwebtoken.sign({
                        id: user.id,
                        email: user.email
                    }, process.env.SECRET, {
                        expiresIn: "1h"
                    });
                    callback(0, token);
                } else {
                    callback(84);
                }
            } else {
                callback(84);
            }
        }
    });
}