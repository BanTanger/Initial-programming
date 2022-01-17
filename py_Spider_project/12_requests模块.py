import requests

url = 'http://httpbin.org/get'
headers = {'User-Agent':'XXXXXXXXXXXXXXXXX'}

res = requests.get(url = url,headers = headers)
"""
将Request和urlopen函数封装成get函数，并且无需使用read().decode()的方法调用，全部封装成属性
"""
html = res.text

# 或者还可以这样用
html = requests.get(url = url,headers = headers).text
print(html)