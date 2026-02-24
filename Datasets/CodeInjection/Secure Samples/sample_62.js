const handlers = { add: (a,b)=>a+b, mul: (a,b)=>a*b };
const msg = JSON.parse(process.argv[2] || '{"action":"add","args":[2,3]}');
if (!handlers[msg.action]) throw new Error("not allowed");
console.log(handlers[msg.action](...msg.args));