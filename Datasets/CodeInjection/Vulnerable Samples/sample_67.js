const vm = require("vm");
const userScript = process.argv[2] || "x + 1";
const ctx = vm.createContext({ x: 2 });
console.log(vm.runInContext(userScript, ctx));