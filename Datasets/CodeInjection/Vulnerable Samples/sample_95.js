const Handlebars = require("handlebars");
const tplSrc = process.argv[2] || "Hello {{name}}";
const tpl = Handlebars.compile(tplSrc); 
console.log(tpl({ name: "Zoe" }));