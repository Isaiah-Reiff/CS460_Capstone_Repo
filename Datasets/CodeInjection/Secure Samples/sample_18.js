const handlers = {
    sum: (arr) => arr.reduce((a, b) => a + b, 0),
    avg: (arr) => arr.reduce((a, b) => a + b, 0) / arr.length,
    max: (arr) => Math.max(...arr)
};

function handleUserRequest(body) {
    let req;

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

const userBody = req.body.jsonPayload; 
const result = handleUserRequest(userBody);
console.log(result);