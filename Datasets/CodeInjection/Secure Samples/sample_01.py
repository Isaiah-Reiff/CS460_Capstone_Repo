import ast
s = input("Enter list: ")
data = ast.literal_eval(s)
print(type(data), data)
