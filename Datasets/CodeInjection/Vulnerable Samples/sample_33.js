const vm = require('vm');
const user = getUserScript();
vm.runInThisContext(user);