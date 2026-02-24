import pickle, base64
blob = base64.b64decode(input("Pickle b64: "))
obj = pickle.loads(blob) 
print(type(obj))