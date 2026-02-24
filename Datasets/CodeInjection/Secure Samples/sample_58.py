from jinja2 import Template
tpl = Template("Hello {{ name | e }}") 
name = input("name: ")
print(tpl.render(name=name))