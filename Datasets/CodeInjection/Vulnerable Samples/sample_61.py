# VULN: untrusted deserialization can trigger code execution
import pickle, base64
blob = base64.b64decode(input("Pickle b64: "))
obj = pickle.loads(blob)  # CWE-94-related (RCE via deserialization)
print(type(obj))