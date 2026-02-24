# VULN: builds function from user string
src = input("lambda body: ")
f = eval("lambda x: " + src)  # CWE-94
print(f(2))