"""
爬取百度贴吧的爬虫程序
"""

from urllib import request,parse
import time
import random

class BaiduTiebaSpider:
    def __init__(self):
        """定义常用变量"""
        self.url = 'http://tieba.baidu.com/f?kw={}&pn={}'
        self.headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}

    def get_html(self,url):#通过传参方式来实现变量传入，因为这里url地址没有明确给明
        """获取响应内容"""
        req = request.Request(url = url,headers = self.headers)
        res = request.urlopen(req)
        html = res.read().decode()

        return html

    def parse_html(self):
        """解析提取数据"""
        pass

    def save_html(self,filename,html):
        """数据处理函数"""
        with open(filename,'w',encoding='utf-8') as f:
            f.write(html)

    def run(self):
        """程序入口函数"""
        name = input('请输入贴吧名:')
        start = int(input('请输入起始页:'))#拼接url地址，所以要转成整型
        end = int(input('请输入终止页:'))
        params = parse.quote(name)#urlencode对字典进行编码，quote对中文变量进行编码
        # 1.拼接URL地址
        for page in range(start,end+1):
            pn = (page - 1)*50
            url = self.url.format(params,pn)
            # 发送请求，解析，保存
            html = self.get_html(url)
            filename = '{}_第{}页.html'.format(name,page)
            self.save_html(filename,html)
            # 终端打印提示
            print('第%d页抓取成功' % page)
            # 控制数据抓取频率
            time.sleep(random.randint(1,2))

if __name__ == '__main__':
    spider = BaiduTiebaSpider()
    spider.run()