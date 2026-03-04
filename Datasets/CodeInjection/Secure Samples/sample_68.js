const vm = require("vm");
const TRUSTED = new vm.Script("data.items.reduce((s,x)=>s+x,0)");
const data = { items: [1,2,3] }; 
const ctx = vm.createContext({ data });
console.log(TRUSTED.runInContext(ctx, { timeout: 100 }));