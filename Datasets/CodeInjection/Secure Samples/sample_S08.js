const handlers = {
    reverse: (str) => str.split('').reverse().join(''),
    length: (str) => str.length,
    upper: (str) => str.toUpperCase()
};

// Input expected as: {"action":"reverse","value":"hello"}
function processUserRequest(jsonInput) {
    let req;
    try {
        req = JSON.parse(jsonInput);
    } catch (e) {
        return "Invalid JSON";
    }

    if (!(req.action in handlers)) {
        return "Unsupported action";
    }

    return handlers[req.action](req.value);
}

// Example usage:
const userInput = getUserInput(); // safe, raw text but not treated as code
console.log(processUserRequest(userInput));