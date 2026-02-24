ops = {"upper": str.upper, "lower": str.lower}
action = input("action: ")
text = input("text: ")
print(ops[action](text) if action in ops else "not allowed")