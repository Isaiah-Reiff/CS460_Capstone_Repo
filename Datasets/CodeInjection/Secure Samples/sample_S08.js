const handlers = {
    reverse: (str) => str.split('').reverse().join(''),
    length: (str) => str.length,
    upper: (str) => str.toUpperCase()
};

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

const userInput = getUserInput(); 
console.log(processUserRequest(userInput));