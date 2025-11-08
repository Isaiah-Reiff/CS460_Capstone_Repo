const input = '{"a":1,"b":2}';
try {
  const data = JSON.parse(input); 
  console.log(data.a + data.b);
} catch(e) {
  console.error("invalid JSON");
}
