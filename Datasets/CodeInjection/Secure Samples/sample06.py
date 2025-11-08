from jinja2 import Environment
env = Environment()
tpl = env.get_template("email/welcome.html")  # not from user input
print(tpl.render(user="Bob"))
