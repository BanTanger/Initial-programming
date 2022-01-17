from urllib.request import urlopen
from bs4 import BeautifulSoup
import re

page = set() #去重，降低工作量
def getLinks(pageURL):
    global page # global 变为全局变量，在外部定义的page变量可以在func函数里头被赋值
    html = urlopen("http://en.wikipedia.org"+pageURL)
    bsObj = BeautifulSoup(html)
    try:
        print(bsObj.h1.get_text())
        # 提取首段
        print(bsObj.find(id = "mw-content-text").findAll("p")[0])
        print(bsObj.find(id = "ca-edit").find("span").find("a").attrs['href'])
    except AttributeError:
        print("页面缺少内容")

    for link in bsObj.findAll("a",href = re.compile("^(/wiki/)")):
        if 'href' in link.attrs:
            if link.attrs['href'] not in page:
                newPage = link.attrs['href']
                print("------------------------\n"+newPage)
                page.add(newPage)
                getLinks(newPage)
getLinks("")