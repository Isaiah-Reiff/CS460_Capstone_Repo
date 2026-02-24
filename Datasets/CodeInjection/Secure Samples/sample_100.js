const Mustache = require("mustache");
const tpl = "Hello {{name}}";
const name = process.argv[2] || "Guest";
console.log(Mustache.render(tpl, { name }));