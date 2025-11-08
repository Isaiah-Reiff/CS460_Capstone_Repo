const userJson = req.body.action;
const fn = eval("(" + userJson + ")");
fn();