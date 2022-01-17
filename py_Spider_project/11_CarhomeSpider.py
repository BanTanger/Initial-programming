from urllib import request
from urllib import parse
import time,random
import csv
import re

class CarSpider:
    def __init__(self):
        """自定义常用数据函数"""
        self.url = 'https://www.che168.com/dongguan/a0_0msdgscncgpi1ltocsp{}exx0/'
        self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}
        #计数变量的设置
        self.i = 0
        # 打开csv文件，初始化数据
        self.f = open('QiChefile','a',newline='')
        self.writer = csv.writer(self.f) # 打开self.f文件
        #初始化列表，为了writerows多行写入做准备
        self.all_film_list = []

    def get_html(self,url):
        """获得响应内容函数"""
        req = request.Request(url=url,headers=self.headers)
        res = request.urlopen(req)
        html = res.read().decode('gb2312','ignore') #ignore 忽略特殊字符，解决反爬

        #调用parse_html函数,传递html参数
        return html

    def re_func(self,regex,html):
        """解析提取数据"""
        pattern = re.compile(regex,re.S)
        r_list = pattern.findall(html)

        return r_list

    def parse_html(self,one_url):
        """数据抓取函数，一级页面开始解析"""

        # 写正则 一级页面
        """
        <li class="cards-li list-photo-li ".*?<a href="(.*?)".*?</li>
        """

        one_html = self.get_html(one_url)
        one_regex = '<li class="cards-li list-photo-li ".*?<a href="(.*?)".*?</li>'
        href_list = self.re_func(one_regex,one_html) # 数据抓取操作
        for href in href_list:
            car_url = href # url拼接，得到一级页面的详细地址
            self.get_data(car_url) # 将参数传入，get.data函数是抓取一辆汽车的详情页面
            # 随机休眠1-2秒钟,uniform()生成指定范围的浮点数
            time.sleep(random.uniform(1,3))

    def get_data(self,car_url):
        """抓取一辆汽车的详情数据"""

        # 二级页面
        """
        <div class="car-box">.*?<h3 class="car-brand-name">(.*?)</h3>.*?<h4>(.*?)</h4>.*?<h4>(.*?)</h4>.*?<h4>(.*?)</h4>(.*?)<h4>(.*?)</h4>.*?<div class="goodstartmoney">(.*?)</div>.*? </div>        
        """
        two_html = self.get_html(car_url)
        two_regex = '<div class="car-box">.*?<h3 class="car-brand-name">(.*?)</h3>.*?<h4>(.*?)</h4>.*?<h4>(.*?)</h4>.*?<h4>(.*?)</h4>.*?<h4>(.*?)</h4>.*?<div class="goodstartmoney"> ￥(.*?)万 </div>.*?</div>'
        # car_list[(天籁 2019款 2.0L XL Upper 智行版)(5万公里)(2019年07月)(自动 / 2L)(东莞)(￥15.28万)]
        car_list = self.re_func(two_regex,two_html)
        item = {}
        # car_list[][],第一个得到是一个列表，第二个得到的是大列表中每一个元组
        item['name'] = car_list[0][0].strip()
        item['km'] = car_list[0][1].strip()
        item['time'] = car_list[0][2].strip()
        item['type'] = car_list[0][3].split('/')[0].strip()
        item['displace'] = car_list[0][3].split('/')[1].strip()
        item['city'] = car_list[0][4].strip()
        item['price'] = car_list[0][5].strip()

    def run(self):
        for i in range(1,3):
            url = self.url.format(i)
            self.parse_html(url)

if __name__ == '__main__':
    spider = CarSpider()
    spider.run()
