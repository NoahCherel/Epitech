const bcrypt = require("bcryptjs");
const bodyParser = require("body-parser");
const dotenv = require("dotenv");
const express = require("express");
const jsonwebtoken = require("jsonwebtoken");
const mysql2 = require("mysql2");

const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

require("dotenv").config({
	path: ".env"
});

const auth_routes = require("./routes/auth/auth");
const user_routes = require("./routes/user/user");
const todos_routes = require("./routes/todos/todos");
const db = require("./config/db");

app.use(auth_routes);
app.use(user_routes);
app.use(todos_routes);

app.listen(process.env.PORT, () => {
    console.log(`Example app listening at http://localhost:${process.env.PORT}`);
});
