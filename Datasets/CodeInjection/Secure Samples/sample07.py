
import json
def add(params): return params[0] + params[1]
METHODS = {"add": add}
req = json.loads('{"method":"add","params":[1,2]}')
if req['method'] in METHODS:
    print(METHODS[req['method']](req['params']))
else:
    print("Method not allowed")
