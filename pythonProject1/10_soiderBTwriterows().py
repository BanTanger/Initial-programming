from urllib import request,parse
import time,random,re,csv

class BTSpider:
    def __init__(self):
        """定义常用变量"""
        self.url = 'https://movie.douban.com/top250?start={}'
        self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}
        # 添加计数变量
        self.i = 0
        # 打开csv文件,初始化写入对象
        self.f = open('BTfile.csv','a',encoding='utf-8',newline='')
        self.writer = csv.writer(self.f)
        # 创建一个新列表    列表【】，元组（），字典{}
        self.all_film_list = []

    def get_html(self,url):
        """获得响应内容"""
        req = request.Request(url = url,headers = self.headers)
        res = request.urlopen(req)
        html = res.read().decode('utf-8')
        """直接调用解析函数"""
        self.parse_html(html)

    def parse_html(self,html):
        """解析提取数据"""
        regex = '<div class="info">.*?<span class="title">(.*?)</span>.*?<span>(.*?)</span>.*?<span class="inq">(.*?)</span>'
        pattern = re.compile(regex,re.S) # 创建一个正则表达式的对象
        r_list = pattern.findall(html) # 元素类型是列表
        self.save_html(r_list)

    def save_html(self,r_list):
        """数据处理函数"""
        for r in r_list:
            # 使用元组形式来处理信息空白情况
            film_t = (
                r[0].strip(),
                r[1].strip(),
                r[2].strip()
            )
            # 每个电影信息处理后添加在总列表中
            self.writer.writerow(film_t)
            print(film_t)
            self.i += 1

    def run(self):
        """函数入口"""
        for offset in range(10,91,25):
            url = self.url.format(offset) #拼接
            self.get_html(url) #数据抓取
            # 控制数据抓取频率
            time.sleep(random.randint(1,2))
            #
        #所有也所有数据抓取完成后，进行writerows（）数据写入
        self.writer.writerows(self.all_film_list)

if __name__ == '__main__':
    spider = BTSpider()
    spider.run()
    print("电影抓取的数量为:",spider.i)

"""
<div class="movie-item-info">.*?title="(.*?)".*?<p class="star">(.*?)</p>.*?<p class="releasetime">(.*?)</p>
"""