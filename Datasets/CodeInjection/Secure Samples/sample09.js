const express = require('express');
const app = express();
app.use(express.json());
const actions = {
  ping: () => ({pong:true}),
  sum: (arr) => arr.reduce((a,b)=>a+b,0)
};
app.post('/api', (req,res) => {
  const {action, args} = req.body;
  if (actions[action]) res.json({result: actions[action](args)});
  else res.status(400).send('bad action');
});
app.listen(3000);
