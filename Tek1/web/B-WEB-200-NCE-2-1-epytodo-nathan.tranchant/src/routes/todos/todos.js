const bcrypt = require("bcryptjs");
const bodyParser = require("body-parser");
const dotenv = require("dotenv");
const express = require("express");
const jsonwebtoken = require("jsonwebtoken");
const mysql2 = require("mysql2");
const router = express.Router();
var db = require("../../config/db.js");
const connection = db();
const login = require("../../middleware/auth");

router.get("/todos", login, (req, res) => {
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

router.get("/todos/:id", login, (req, res) => {

    const id = req.params.id;
    checkTodo(id).then(results => {
        if (results.length === 0) {
            res.status(500).json({
                msg: "Not found"
            });
        } else {
            const query = `SELECT * FROM todo WHERE id = ?`;
            const values = [id];
            connection.query(query, values, (err, results) => {
                if (err) {
                    res.status(500).send({
                        msg: "Internal server error"
                    });
                } else {
                    res.send(results);
                }
            });
        }
    });
});

router.post("/todos", login, (req, res) => {
    const { title, description, status, due_time, user_id } = req.body;
    const values = [title, description, status, due_time, user_id];
    const query = `INSERT INTO todo (title, description, status, due_time, user_id) VALUES (?, ?, ?, ?, ?)`;
    if (title === undefined || description === undefined || status === undefined || due_time === undefined || user_id === undefined) {
        res.status(500).json({
            msg: "internal server error"
        });
    }
    connection.query(query, values, (err, results) => {
        if (err) {
            res.status(500).json({
                msg: "internal server error"
            });
        } else {
            connection.query(`SELECT * FROM todo WHERE id = ?`, [results.insertId], (err, results) => {
                if (err) {
                    res.status(500).json({
                        msg: "internal server error"
                    });
                } else {
                    res.send(results);
                }
            }
            );
        }
    });
});

router.put("/todos/:id", login, (req, res) => {
    const id = req.params.id;
    const { title, description, status, due_time, user_id } = req.body;
    const values = [title, description, status, due_time, user_id, id];
    const query = `UPDATE todo SET title = ?, description = ?, status = ?, due_time = ?, user_id = ? WHERE id = ?`;
    const query2 = `SELECT title, description, due_time, user_id, status FROM todo WHERE id = ?`;
    if (title === undefined || description === undefined || status === undefined || due_time === undefined || user_id === undefined) {
        res.status(500).json({
            msg: "internal server error"
        });
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
            }
            );
        }
    });
});

function checkTodo(id) {
    return new Promise((resolve, reject) => {
        const query = `SELECT * FROM todo WHERE id = ?`;
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

router.delete("/todos/:id", login, (req, res) => {
    const id = req.params.id;
    checkTodo(id).then(results => {
        if (results.length === 0) {
            res.status(500).json({
                msg: "Not found"
            });
        } else {
            const query = `DELETE FROM todo WHERE id = ?`;
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
