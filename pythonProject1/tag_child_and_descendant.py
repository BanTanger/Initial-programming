from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen("http://www.pythonscraping.com/pages/page3.html")
bsObj = BeautifulSoup(html)

#.children()得到寻找标签的所有子标签，td下面的子标签爬取
for child in bsObj.find("table",{"id":"giftList"}).children:
    print(child)
#.descendants()得到寻找标签的所有后代标签,例如td下面的子标签
for descendants in bsObj.find("table",{"id":"giftList"}).descendants:
    print(descendants)
#.next_siblings()处理带标题行的表格，但不处理标题标签
# previous_siblings()函数，通过寻找一组兄弟标签的最后一个标签。
# next——sibling()和previous_sibling()放回单个标签而不是一组标签。
for siblings in bsObj.find("table",{"id":"giftList"}).tr.next_siblings:
    print(siblings)
# 父标签的处理parent（），parents（）,报错？
print(bsObj.find("img",{"src":"../img/gifs/img1.jpg"}).parent.previous_sibling.get_text())

