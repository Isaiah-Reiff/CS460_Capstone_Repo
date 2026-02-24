// VULN: Function constructor from user input
const body = process.argv[2] || "return 3;";
const f = new Function(body); // CWE-94
console.log(f());