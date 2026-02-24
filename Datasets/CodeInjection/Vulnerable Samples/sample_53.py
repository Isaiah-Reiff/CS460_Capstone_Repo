# VULN: exec on user-controlled "plugin"
plugin = input("Plugin code: ")
exec(plugin)  # CWE-94