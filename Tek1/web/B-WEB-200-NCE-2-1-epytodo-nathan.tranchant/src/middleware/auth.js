const jsonwebtoken = require("jsonwebtoken");

module.exports = (req, res, ok) => {
    const a = req.headers.authorization;
    if (a) {
        const token = a.split(" ")[1];
        jsonwebtoken.verify(token, process.env.SECRET, (err, decoded) => {
            if (err) {
                res.status(401).json({
                    msg: "Token is not valid"
                });
                return;
            }
            ok();
        });
    } else {
        res.status(401).json({
            msg: "No token, authorization denied"
        });
    }
};