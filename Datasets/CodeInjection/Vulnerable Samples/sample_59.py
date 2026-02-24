# VULN: user supplies the template source
from jinja2 import Template
tpl = input("Template: ")
print(Template(tpl).render(name="Alice"))  # CWE-94