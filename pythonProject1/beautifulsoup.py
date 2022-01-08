from urllib.request import urlopen
from bs4 import BeautifulSoup
html = urlopen("https://www.pythonscraping.com/pages/warandpeace.html")
bsObj = BeautifulSoup(html)
"""得到的是标签页"""
nameList = bsObj.findAll("span",{"class":"green"})
"""
findAll(tag,attributes,recursive,text,limit,keywords)
find(tag,attributes,recursive,text,keywords)  等价于findAll 的limit参数为一

tag:可以通过列表的方式得到多个标签页
findAll({"h1","h2","h3","h4","h5"})
attributes:字典封装属性和对应属性值
recursive:递归，布尔量，true，查找所有子标签，false,只找以及标签，默认支持递归查找
text:根据文本内容进行匹配
例如：nameList = bsObj.findAll(text="the prince")
     print(len(nameList)) 
        len()返回参数对象（字符字符串，元组，列表，字典）的项目个数
"""
for name in nameList:
    print(name.get_text())