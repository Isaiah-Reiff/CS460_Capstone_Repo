# VULN: eval on user-controlled query string
q = input("Query expr: ")
rows = eval(q)  # CWE-94
print(rows)