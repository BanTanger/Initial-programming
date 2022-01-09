from urllib.request import HTTPBasicAuthHandler
from urllib.request import HTTPPasswordMgrWithDefaultRealm
from urllib.request import build_opener
from urllib.error import URLError

username = 'username'
password = 'password'
url = 'http://localhost:5000'

p = HTTPPasswordMgrWithDefaultRealm()
p.add_password(None,url,username,password)
"""利用add_password添加用户名和密码，建立一个处理验证的Handler"""
auth_handler = HTTPBasicAuthHandler(p)
opener = build_opener(auth_handler)
"""利用Handler并使用build_opener()方法构建一个Opener，在发送请求时相当于验证成功"""

try:
    result = opener.open(url)
    html = result.read().decode('utf-8')
    print(html)
except URLError as e:
    print(e.reason)
    """as关键词，三种用法，起别名，with配合开关文件，与except配合捕获异常对象赋值给e"""
    """
        with open("1.text") as f:
        except Exception as e:
    """