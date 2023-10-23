const mysql2 = require("mysql2");

function createConnection() {
    return mysql2.createConnection({
        host: process.env.MYSQL_HOST,
        user: process.env.MYSQL_USER,
        password: process.env.MYSQL_ROOT_PASSWORD,
        database: process.env.MYSQL_DATABASE
    });
}

module.exports = createConnection;
