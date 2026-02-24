import yaml
doc = input("YAML: ")
print(yaml.safe_load(doc))  # safe loader (data)