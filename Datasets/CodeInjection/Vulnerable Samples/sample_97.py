src = input("lambda body: ")
f = eval("lambda x: " + src)  
print(f(2))