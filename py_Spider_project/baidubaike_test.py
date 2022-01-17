from urllib.request import urlopen
import re
from bs4 import BeautifulSoup

# 成功
# 注意递归最多只能执行一千次，如果想要更多需要其他手段
pages = set()
def getLinks(pageUrl):
    global pages
    html = urlopen("https://baike.baidu.com/item/wiki/97755?"+pageUrl)
    bsObj = BeautifulSoup(html)
    for link in bsObj.findAll("a",href = re.compile("(.*?)")):
        if 'href' in link.attrs:
            if link.attrs['href'] not in pages:
                # 遇到新页面
                newPage = link.attrs['href']
                print(newPage)
                pages.add(newPage)
                getLinks(newPage)
                print(link)
getLinks("")
