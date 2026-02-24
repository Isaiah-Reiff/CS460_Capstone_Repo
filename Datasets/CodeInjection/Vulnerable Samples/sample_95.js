// VULN: user controls template source (logic-capable template engines can be abused)
const Handlebars = require("handlebars");
const tplSrc = process.argv[2] || "Hello {{name}}";
const tpl = Handlebars.compile(tplSrc); // CWE-94-ish template injection
console.log(tpl({ name: "Zoe" }));