import re
import requests
import time,random
from urllib import parse
import os

class BaiduPhotosSpider:
    def __init__(self):
        self.url = 'https://image.baidu.com/search/index?tn=baiduimage&word={}'
        self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}
        self.word = input('请输入关键词:')
        self.directory = './image/{}/'.format(self.word)
        if not os.path.exists(self.directory):
            os.makedirs(self.directory)

    def parse_html(self):
        """数据抓取函数"""
        params = parse.quote(self.word)
        html = requests.get(url = self.url.format(params),headers = self.headers,).text
        regex = 'thumbURL":"(.*?)"'
        pattern = re.compile(regex,re.S)
        src_list = pattern.findall(html)
        print(src_list)
        """
        pattern.findall(html)得到的是一个列表
        src_list : ['http://xx.jpg','http://xx.jpg']
        """
        for src in src_list:
            """函数功能：保存一张图片到本地"""
            self.save_image(src)

    def save_image(self,src):
        """函数功能：保存一张图片到本地"""
        html = requests.get(url = src,headers = self.headers).content
        # filename ： ./images/宝可梦/宝可梦_1.jpg
        filename = self.directory + '{}_{}.jpg'.format(self.word,self.i)
        with open(filename,'wb') as f:
            f.write(html)
        print(filename,'下载成功')
        self.i += 1

    def run(self):
        self.parse_html()

if __name__ == '__main__':
    spider = BaiduPhotosSpider()
    spider.run()