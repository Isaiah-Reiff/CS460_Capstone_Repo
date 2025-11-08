const ejs = require('ejs');
const tpl = req.query.t;
ejs.render(tpl, {user:"bob"});