const ejs = require('ejs');
const template = "<p>Hello <%= user %></p>";
console.log(ejs.render(template, {user: "Sam"}));
