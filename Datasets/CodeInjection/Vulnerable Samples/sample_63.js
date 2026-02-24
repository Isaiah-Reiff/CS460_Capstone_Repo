// VULN: eval on request parameter
const user = process.argv[2] || "1+2";
console.log(eval(user)); // CWE-94