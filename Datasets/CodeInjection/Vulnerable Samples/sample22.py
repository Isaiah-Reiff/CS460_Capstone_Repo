from jinja2 import Environment
env = Environment()
tpl = env.from_string(request.args.get("tpl"))
print(tpl.render(secret="top"))