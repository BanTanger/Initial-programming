import requests
import parsel
import os
headers = {
    'User-Agent':'Mozilla/5.0'
}
url = 'https://www.kanxiaojiejie.com/page/1'
res = requests.get(url)
data_html = res.text
# Selector 选择器需要得到网页的内容，res.text。
selector = parsel.Selector(data_html)
# 解析数据，获取图片详细地址页，二级页面url
# parsel 语法，.entry-top意思是图片封面的父级标签，a代表所有子级标签，用::attr(href)获得所有地址
url_list = selector.css('.entry-title > a::attr(href)').getall()
# 选择器作为对象引出属性css拿到标签。
# 抓取标题
title_list = selector.css('.entry-title > a::text').getall()

for zip_date in zip(url_list,title_list):
    # print(zip_date) # 链接 and 标题
    """
    print(zip_date[0]) # 链接
    print(zip_date[1]) # 标题
    """
    url_1 = zip_date[0]
    title = zip_date[1]
    # 向所有详情页发送请求
    res_1 = requests.get(url_1)
    # 获取数据（网页源代码）
    data_html_1 = res_1.text
    # 解析数据（提取数据图片链接）
    selector_1 = parsel.Selector(data_html_1)
    img_url_list = selector_1.css('div.entry-content > div > p > img::attr(src)').getall()
    if not os.path.exists('img/' + title):
        os.mkdir('img/' + title)
    for img_url in img_url_list:
        # 获取图片的二进制数据
        img_date = requests.get(img_url).content
        # print(img_date)
        # 创建文件夹存储图片
        img_name = img_url.split('/')[-1]
        with open(f'img/{title}/{img_name}',mode='wb') as f:
            f.write(img_date)
        print(img_name,"爬取成功！！")