const actions = {
    greet: (name) => `Hello, ${name}!`,
    square: (n) => n * n,
    isEven: (n) => (n % 2 === 0)
};

// Expecting JSON like:
// { "action": "greet", "args": ["joe"] }

function handleRequest(body) {
    let req;

    try {
        req = JSON.parse(body);
    } catch (e) {
        return "Invalid JSON";
    }

    if (!(req.action in actions)) {
        return "Unsupported action";
    }

    const handler = actions[req.action];
    return handler(...(req.args || []));
}

// Usage:
const result = handleRequest(req.body.action);
console.log(result);
