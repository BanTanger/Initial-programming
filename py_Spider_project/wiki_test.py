from urllib.request import urlopen
from urllib import request

import requests
from bs4 import BeautifulSoup

url = "https://en.wikipedia.org/wiki/Kevin_Bacon"
header = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
    ,'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9'}
res = requests.get(url,headers= header,timeout = (3,7))
html = request.urlopen(res)
bsObj = BeautifulSoup(html)
for link in bsObj.findAll("a"):
    if 'href' in link.attrs:
        print(link.attrs['href'])
# attrs 提取标签属性，例如<a> URL链接包含在href属性中。<img>标签文件包含在src属性中
# 这里是wiki的自动拦截
# 尝试用伪装头试一下 失败，哎

