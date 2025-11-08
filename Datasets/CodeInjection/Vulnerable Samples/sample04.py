filter_expr = request.GET['filter']
query = "data.filter(" + filter_expr + ")"
result = eval(query)
