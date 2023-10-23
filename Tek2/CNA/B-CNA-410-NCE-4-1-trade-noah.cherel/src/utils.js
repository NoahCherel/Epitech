function toCamelCase(string) {
    return string.replace('/', '_').replace(/_[a-z]/g, function(match) {
        return match.toUpperCase().replace('_', '');
    });
}

module.exports = {
    toCamelCase,
};
