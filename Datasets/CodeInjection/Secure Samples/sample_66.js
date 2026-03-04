const ejs = require("ejs");
const tpl = "<p>Hello <%= user %></p>";
const user = process.argv[2] || "Ann";
console.log(ejs.render(tpl, { user }));