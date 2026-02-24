const ejs = require("ejs");
const tpl = process.argv[2] || "<%= user %>";
console.log(ejs.render(tpl, { user: "Bob" }));