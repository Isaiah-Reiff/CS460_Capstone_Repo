template = request.args.get("tmpl")
from jinja2 import Template
print(Template(template).render(user="joe"))
