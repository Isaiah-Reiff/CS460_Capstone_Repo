from jinja2 import Template
tpl = Template("Hello {{ name | e }}")  # server-owned template
name = input("name: ")
print(tpl.render(name=name))