# VULN: compile + exec of untrusted code
src = input("Source: ")
codeobj = compile(src, "<stdin>", "exec")
exec(codeobj)  # CWE-94