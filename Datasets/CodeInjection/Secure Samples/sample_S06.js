const actions = {
    add: (a, b) => a + b,
    max: (a, b) => Math.max(a, b)
};

const input = document.getElementById('code').value;

try {
    // Expecting a simple JSON object like: {"action":"add","a":2,"b":3}
    const obj = JSON.parse(input);

    if (obj.action in actions) {
        const result = actions[obj.action](obj.a, obj.b);
        console.log("Result:", result);
    } else {
        console.log("Unsupported action");
    }
} catch (e) {
    console.log("Invalid input format");
}
