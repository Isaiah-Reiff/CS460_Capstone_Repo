const handlers = {
    sum: (arr) => arr.reduce((a, b) => a + b, 0),
    avg: (arr) => arr.reduce((a, b) => a + b, 0) / arr.length,
    max: (arr) => Math.max(...arr)
};

function handleUserRequest(body) {
    let req;

    // Expect input as JSON, e.g.:
    // {"action":"sum","items":[1,2,3]}
    try {
        req = JSON.parse(body);
    } catch (e) {
        return "Invalid JSON";
    }

    if (!(req.action in handlers)) {
        return "Unsupported action";
    }

    return handlers[req.action](req.items);
}

// Example usage:
const userBody = req.body.jsonPayload; // User input as data, not code
const result = handleUserRequest(userBody);
console.log(result);