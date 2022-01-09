from urllib.request import ProxyHandler
from urllib.request import build_opener
from urllib.error import URLError

proxy_handler = ProxyHandler({
    'http':'http://127.0.0.1:25378',
    'https':'http://127.0.0.1:25378'
})
"""ProxyHandler参数是一个字典，键名是协议类型，例如HTTP或者HTTPS，键值是代理链接，可以添加多个代理"""
opener = build_opener(proxy_handler)
"""利用Handler和build_opener来构造一个opener，然后发送请求"""
try:
    response = opener.open('https://www.baidu.com')
    print(response.read().decode('utf-8'))
except URLError as e:
    print(e.reason)
    """由于目标计算机积极拒绝，无法链接
        这是因为用了代理
    """