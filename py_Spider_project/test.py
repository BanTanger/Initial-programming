import requests
kv = {'wd':'Python3'}
url = "http://www.baidu.com/s"
r = requests.get(url,params=kv)
res = r.status_code
print(res)
print(r.request.url)