
src = input("Source: ")
codeobj = compile(src, "<stdin>", "exec")
exec(codeobj)