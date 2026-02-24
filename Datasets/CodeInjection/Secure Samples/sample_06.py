def sum_list(vals): return sum(vals)
def max_list(vals): return max(vals)

handlers = {"sum": sum_list, "max": max_list}
req = {"action":"sum","args":[1,2,3]}
if req["action"] in handlers:
    print(handlers[req["action"]](req["args"]))
else:
    raise ValueError("unsupported action")
