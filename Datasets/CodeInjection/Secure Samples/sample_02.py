import operator, re
ops = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
expr = input("Enter a simple expression like 2+3: ")
m = re.fullmatch(r'\s*(\d+(?:\.\d+)?)\s*([\+\-\*/])\s*(\d+(?:\.\d+)?)\s*', expr)
if m:
    a, op, b = m.groups()
    print(ops[op](float(a), float(b)))
else:
    print("Invalid format")
