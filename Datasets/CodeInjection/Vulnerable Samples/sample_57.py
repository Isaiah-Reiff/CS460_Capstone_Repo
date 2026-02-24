# VULN: eval used for config "expressions"
cfg = {"threshold_expr": input("Threshold expr: ")}
threshold = eval(cfg["threshold_expr"])  # CWE-94
print(threshold)