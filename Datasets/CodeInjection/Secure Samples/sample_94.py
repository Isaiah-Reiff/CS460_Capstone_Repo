from urllib.parse import urlparse
u = input("url: ")
p = urlparse(u)
print(p.scheme, p.netloc, p.path)