import subprocess, json
cmd = ["python3", "worker.py"] 
input_payload = json.dumps({"task":"count","items":[1,2,3]})
p = subprocess.run(cmd, input=input_payload.encode(), stdout=subprocess.PIPE, timeout=5)
print(p.stdout.decode())
