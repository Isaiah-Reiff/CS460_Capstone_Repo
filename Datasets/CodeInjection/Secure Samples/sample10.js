const http = require('http');

const handlers = {
  echo: (args) => ({ echoed: args }),
  sum: (args) => {
    if (!Array.isArray(args)) throw new Error('args must be array');
    return args.reduce((s, x) => s + Number(x), 0);
  }
};

const server = http.createServer(async (req, res) => {
  if (req.method !== 'POST' || req.url !== '/api') {
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('POST JSON to /api\n');
    return;
  }
  let body = '';
  for await (const chunk of req) body += chunk;
  let payload;
  try {
    payload = JSON.parse(body);
  } catch (e) {
    res.writeHead(400); res.end('invalid json'); return;
  }
  const action = payload.action;
  const args = payload.args;
  if (!handlers[action]) {
    res.writeHead(400); res.end('action not allowed'); return;
  }
  try {
    const result = handlers[action](args);
    res.writeHead(200, {'Content-Type': 'application/json'});
    res.end(JSON.stringify({ result }));
  } catch (err) {
    res.writeHead(400); res.end('error: ' + String(err.message));
  }
});

server.listen(3000, () => console.log('Server listening on http://localhost:3000 (POST JSON to /api)'));