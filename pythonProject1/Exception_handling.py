from urllib import request,error

url = 'https://cuiqingcai.com/index.htm'
try:
    response = request.urlopen(url)
except error.HTTPError as e:
    print(e.reason,e.code,e.headers,sep='\n')
    """先捕获HTTPError，获取它的错误状态吗，原因，headers等信息
    code，返回HTTP状态码，reason，同父类URLError，代表错误原因，headers返回请求头"""
    """HTTPError是URLError的子类，会先执行他自己的报错原因，然后执行父类的报错原因
    所以可以先执行子类，再执行父类"""
except error.URLError as e:
    print(e.reason)
else:
    print('Request Successfully')