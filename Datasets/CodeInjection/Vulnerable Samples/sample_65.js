const body = process.argv[2] || "return 3;";
const f = new Function(body);
console.log(f());