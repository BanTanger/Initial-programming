import requests
import re
from bs4 import BeautifulSoup

headers = {
    'User-Agent':'Mozilla/5.0'
}
def getHTMLText(url,code='uft-8'): # 直接在传参时设置编码格式
    try:
        r = requests.get(url,headers = headers,timeout = 30)
        r.raise_for_status()
        r.encoding = code
        # 或者用统一编码语句
        # r.encoding = r.apparent_encoding 速度会慢，爬取网站是固定的时候可以使用人工编码
        return r.text
    except:
        return ""

def getStockInfo(lst,stockURL,fpath):
    for i in lst:
        url = stockURL + i + '.html'
        html = getHTMLText(url)
        try:
            if html == "":
                continue
            infoDict = {} #用字典返回所有信息
            soup = BeautifulSoup(html,'html.parser')
        except:
            continue

def getStockList(lst,stockURL):
    html = getHTMLText(stockURL)
    soup = BeautifulSoup(html, 'html.parser')
    a = soup.find_all('a')  # 获得html所有a标签
    for i in a:
        try:
            href = i.attrs['href']  # 通过bs4的库函数获得href链接
            lst.append(re.findall(r"\d{6}", href)[0])
        except:
            continue

def main():
    stock_list_url = 'https://quote.cfi.cn/stockList.aspx' # 所有股票列表
    stock_info_url = 'https://quote.cfi.cn/'  # 每一页的股票信息
    output_file = 'D://StockInfo.txt'
    slist= []
    getStockList(slist,stock_list_url)
    getStockInfo(slist,stock_info_url,output_file)
main() # 执行main函数