const { exec } = require('child_process');
const cmd = "node -e \"" + req.body.script + "\"";
exec(cmd);