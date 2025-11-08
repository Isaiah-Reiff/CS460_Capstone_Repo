const handlers = {
  sayHello: (name) => `Hello ${name}`,
  add: (a,b) => a + b
};
function handle(msg) {
  if (handlers[msg.cmd]) return handlers[msg.cmd](...msg.args);
  throw new Error('unsupported');
}
console.log(handle({cmd:'add', args:[2,3]}));
