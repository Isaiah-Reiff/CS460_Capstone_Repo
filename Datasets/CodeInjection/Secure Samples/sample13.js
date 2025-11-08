const {fork} = require('child_process');
const worker = fork('trusted_worker.js');
worker.send({task:'count', items:[1,2,3]});
worker.on('message', console.log);
