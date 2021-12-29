import re,time,random
from urllib import request,parse

class MaoYanSpider:
    def __init__(self):
        """定义常用变量"""
        self.url = 'https://www.maoyan.com/board/4?offset={}'
        self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}
        # 添加计数变量
        self.i = 0

    def get_html(self,url):
        """获得响应内容"""
        req = request.Request(url = url,headers = self.headers)
        res = request.urlopen(req)
        html = res.read().decode('utf-8')
        """直接调用解析函数"""
        self.parse_html(html)


    def parse_html(self,html):
        """解析提取数据"""
        regex = '<div class="movie-item-info">.*?title="(.*?)".*?<p class="star">(.*?)</p>.*?<p class="releasetime">(.*?)</p>'
        pattern = re.compile(regex,re.S) # 创建一个正则表达式的对象
        r_list = pattern.findall(html) # 元素类型是列表
        self.save_html(r_list)

    def save_html(self,r_list):
        """数据处理函数"""
        # 制作一个空字典
        item = {}
        """ with open(filename,'w',encoding = 'utf-8') as f:
            f.write(html)"""
        for r in r_list:
            # 空字典的赋值操作
            item['name'] = r[0].strip() # strip()函数去除字符串左右两边的空格
            item['star'] = r[1].strip()
            item['time'] = r[2].strip()
            print(item)
            self.i += 1

    def run(self):
        """函数入口"""
        for offset in range(10,91,10):
            url = self.url.format(offset) #拼接
            self.get_html(url) #数据抓取
            # 控制数据抓取频率
            time.sleep(random.randint(1,2))

if __name__ == '__main__':
    spider = MaoYanSpider()
    spider.run()
    print("电影抓取的数量为:",spider.i)

"""
<div class="movie-item-info">.*?title="(.*?)".*?<p class="star">(.*?)</p>.*?<p class="releasetime">(.*?)</p>
"""

"""
<div class="movie-item-info">.*?title="(.*?)".*?<p class="star">(.*?)</p>.*?<p class="releasetime">(.*?)</p>
"""