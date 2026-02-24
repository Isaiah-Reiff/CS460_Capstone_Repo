import ast

expr = input("number expr: ")
node = ast.parse(expr, mode="eval")

allowed = (ast.Expression, ast.BinOp, ast.Add, ast.Sub, ast.Mult, ast.Div,
           ast.Constant, ast.UnaryOp, ast.UAdd, ast.USub, ast.Pow)

for n in ast.walk(node):
    if not isinstance(n, allowed):
        raise ValueError("disallowed")

code = compile(node, "<expr>", "eval")
print(eval(code, {"__builtins__": {}}, {}))