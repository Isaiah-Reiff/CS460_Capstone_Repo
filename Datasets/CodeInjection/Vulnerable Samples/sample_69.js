// VULN: user-controlled template source rendered by EJS
const ejs = require("ejs");
const tpl = process.argv[2] || "<%= user %>";
console.log(ejs.render(tpl, { user: "Bob" })); // CWE-94