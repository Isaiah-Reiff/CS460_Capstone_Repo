const operations = {
    square: (x) => x * x,
    negate: (x) => -x,
    increment: (x) => x + 1
};

const input = document.querySelector('#fn').value;
// expecting something like: {"op":"square","value":5}

let obj;
try {
    obj = JSON.parse(input);
} catch (e) {
    console.log("Invalid JSON format");
    return;
}

if (obj.op in operations) {
    console.log("Result:", operations[obj.op](obj.value));
} else {
    console.log("Unsupported operation");
}
