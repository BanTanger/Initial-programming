"""
使用Request函数来包装,避免网站反爬，重构User-Agent
"""
from urllib import request
url = 'http://httpbin.org/get'
headers = {'User-Agent':' Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv,2.0.1) Gecko/20100101 Firefox/4.0.1'}
# 2.包装请求 Request()
req = request.Request(url=url,headers=headers)
# 3.发请求 urlopen()
res = request.urlopen(req)
# 4.获取响应内容
html = res.read().decode()
print(html)

"""
请求网站三步走
--构造请求对象 req = request.Request(url = {},headers = {})
--获取响应内容 res = request.urlopen(req)
--提取响应对象内容 html = res.read().decode()
"""