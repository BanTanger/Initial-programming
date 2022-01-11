import requests
import re
import csv

def getHTTPText(url):
    try:
        headers = {
            'authority': 's.taobao.com',
            'sec-ch-ua': '" Not;A Brand";v="99", "Google Chrome";v="97", "Chromium";v="97"',
            'sec-ch-ua-mobile': '?0',
            'sec-ch-ua-platform': '"Windows"',
            'upgrade-insecure-requests': '1',
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36',
            'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'sec-fetch-site': 'none',
            'sec-fetch-mode': 'navigate',
            'sec-fetch-user': '?1',
            'sec-fetch-dest': 'document',
            'accept-language': 'en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7,zh-HK;q=0.6',
            'cookie': 'cna=pBuQGdhP1AsCAd9Kcd90Ndmv; _m_h5_tk=1bc18fe62521268ccae05f1140b39a0c_1641878754513; _m_h5_tk_enc=3c20b526f0d459453a9275fa21bec716; _samesite_flag_=true; cookie2=190ce08800ae1f9815ce155417cb41bc; t=28b8b0a892621aad79839a498e36756f; _tb_token_=e55b1378e3b3d; xlly_s=1; sgcookie=E100%2FUDhhEcdyKyEaHan67mc7f6SX33M2QOgXeMVqGWXVLo7gYhnj2jJocijfrHdsrPPRiHHjYowJZv7UaxdifOFioXWVLkxiCupsNjQczgnBr2W4m0B3BfG%2F%2Bk3L6ijqv0k; unb=2799794313; uc3=id2=UU8BpfIKcSZsTA%3D%3D&vt3=F8dCvUzPWctqgCKviJI%3D&nk2=CdKcZ7CiEIkTCImT&lg2=VT5L2FSpMGV7TQ%3D%3D; csg=5bf16034; lgc=janechen4139; cancelledSubSites=empty; cookie17=UU8BpfIKcSZsTA%3D%3D; dnk=janechen4139; skt=3a79bf270c97465b; existShop=MTY0MTg3MDgxOA%3D%3D; uc4=id4=0%40U22GX33U%2B7d4O1BHYaKqf9%2FoLLKo&nk4=0%40C%2B0eXVfRRPS5Syv5lHtRxkNaIbm30P4%3D; tracknick=janechen4139; _cc_=WqG3DMC9EA%3D%3D; _l_g_=Ug%3D%3D; sg=938; _nk_=janechen4139; cookie1=BxJIueHH%2BVhF%2FXpsuh6Vmk491sKVsognELh%2BahQHfME%3D; enc=xueGcrAvLpFDe9sl67e2W8NVap4uMiRDnO5nuCsjILMT9ZEAzEyaZJVMCpuBujNNZm2azhiqdGGNcqVIrjLf%2Fg%3D%3D; mt=ci=9_1; uc1=existShop=false&cookie15=URm48syIIVrSKA%3D%3D&cookie21=VT5L2FSpccLuJBreK%2BBd&cookie14=UoewAe0NIxmiQA%3D%3D&cookie16=UIHiLt3xCS3yM2h4eKHS9lpEOw%3D%3D&pas=0; thw=cn; hng=CN%7Czh-CN%7CCNY%7C156; JSESSIONID=7EA595AB5693BA567FFD66D35A5B404E; isg=BHl5FJSfPLQy3OC1sR-YaNCIiOVThm04tsBpMpuu9aAfIpm049Z9COdwpC7UgQVw; l=eBLNvRhqgURR4JLoBOfanurza77OSIRYYuPzaNbMiOCPO2CB52AVW6pKfPY6C3GNh6DwR3WK4ADXBeYBqQAonxv92j-la_kmn; tfstk=c4LlBjwtf3SWAFIDf4_WiFMhl83OwlNAF9WJuFtA7XtT2u1mKorNBYrc3AMzA',
        }
        r = requests.get(url,headers = headers,timeout = 30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding # 修改整体编码格式使py可以读懂
        return r.text
    except:
        return ""

def parsePage(ilt,html):
    try:
        plt = re.findall(r'\"view_price\"\:\"[\d+\.]*\"',html)
        tlt = re.findall(r'\"raw_title\"\:\".*?\"',html)
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1]) # eval()函数去除双引号，split切片切除前面的属性名
            title = eval(tlt[i].split(':')[1])
            ilt.append([price,title]) # 为infoList列表增加商品
    except:
        print("") #异常情况处理
def printGoodsList(ilt):
    tplt = "{:4}\t{:8}\t{:16}"
    count = 0
    print(tplt.format("序号","价格","商品名称"))
    for i in ilt:
        count = count+ 1
        print(tplt.format(count,i[0],i[1]))

def main():
    goods = input('请输入想查询的商品：')
    depth = 10
    start_url = 'https://s.taobao.com/search?q=' + goods
    infoList = [] # 创建一个空列表
    for i in range(depth):
        try:
            url = start_url + '&s=' + str(44*i)
            html = getHTTPText(url)
            parsePage(infoList,html)
        except:
            continue
    printGoodsList(infoList)
    with open('taobao_1.csv','a',newline='') as f:
        writer = csv.writer(f)
        writer.writerows(infoList)
main()