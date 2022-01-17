"""
urlencode()示例：百度搜索关键词，保存关键词.html 到本地html文件
"""

from urllib import request
from urllib import parse

# 1.拼接URL地址
word = input('请输入搜索的关键词：')
params = parse.urlencode({'wd': word })
url = 'http://www.baidu.com/s?{}'.format(params)
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}

# 2.发请求获取响应内容
req = request.Request(url = url,headers = headers)
res = request.urlopen(req)
html = res.read().decode('utf-8')

# 3.保存到本地文件
filename = word + '.html'
with open(filename,'w',encoding="UTF-8") as f:
    f.write(html)
