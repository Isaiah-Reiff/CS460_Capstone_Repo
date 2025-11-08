from jinja2 import Environment, select_autoescape
env = Environment(autoescape=select_autoescape())
template = env.from_string("Hello {{ name | e }}")
print(template.render(name="Alice"))
