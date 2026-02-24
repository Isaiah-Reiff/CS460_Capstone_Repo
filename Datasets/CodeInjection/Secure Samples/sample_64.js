const msg = JSON.parse(process.argv[2] || '{"items":[1,2,3]}');
if (!Array.isArray(msg.items) || msg.items.some(x => typeof x !== "number")) {
  throw new Error("bad input");
}
console.log(msg.items.reduce((s,x)=>s+x,0));