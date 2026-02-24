const s = process.argv[2] || "2+3";
const m = s.match(/^\s*(\d+)\s*([+*])\s*(\d+)\s*$/);
if (!m) throw new Error("bad");
const a = Number(m[1]), op = m[2], b = Number(m[3]);
console.log(op === "+" ? a + b : a * b);