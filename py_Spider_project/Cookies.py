import urllib.request
from urllib import request
from http import cookiejar

# 感觉获取cookies用在手机端或者app较多，因为没有办法通过f12得到cookies
filename = 'cookies.txt'
"""cookies = cookiejar.CookieJar(filename)"""

"""用txt文本方式保存，生成代理文件的时候用到MozillaCookieJar"""
# cookies = cookiejar.MozillaCookieJar(filename)
"""用LWP格式保存，需要用到LWPCookieJar子类"""
cookies = cookiejar.LWPCookieJar(filename)
# 使用cookies代理,这里调用load（）方法来读取本地的cookies文件，获取到cookies的内容。
cookies.load('cookies.txt',ignore_discard = True,ignore_expires = True)

handler = urllib.request.HTTPCookieProcessor(cookies)
opener = urllib.request.build_opener(handler)
response = opener.open('http://www.baidu.com')
# cookies.save(ignore_discard = True,ignore_expires = True)
print(response.read().decode('utf-8','ignore'))

"""保存cookies代理的时候不要打印，不然就把保存代码放在打印之后"""
"""for item in cookies:
    print(item.name+"="+item.value)"""

"""错误打印方式"""
"""filename = cookies + '.txt'
with open(filename,'w',encoding = 'utf-8') as f:
    f.write(response)"""

# requests获得cookies代理的方法
import requests

r = requests.get("https://www.baidu.com")
print(r.cookies)
for key,value in r.cookies.items():
# items（）将requestCookiejar类型的cookies转化成元组形式的列表，遍历输出每一cookies的名字和值，实现cookies的遍历解析
    print(key+"="+value) # key名字，value值