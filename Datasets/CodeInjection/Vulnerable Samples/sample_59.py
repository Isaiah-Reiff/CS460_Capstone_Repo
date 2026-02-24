from jinja2 import Template
tpl = input("Template: ")
print(Template(tpl).render(name="Alice"))  