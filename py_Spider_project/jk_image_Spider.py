import requests
import os
import parsel

url = 'https://www.jdlingyu.com/tuji'
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'}

response = requests.get(url = url,headers = headers)
html_str = response.text # 得到文本html
# print(html_str)

# 3.数据提取，使用xpath模块————parsel
selector = parsel.Selector(html_str) # 转换数据类型

lis = selector.xpath('//div[@id="post-list"]/ul/li') # 获得所有li标签，想要的数据就藏在这里
# 遍历所有的lis列表，得到每个li标签下的图片信息
for li in lis:
    try:
        pic_title = li.xpath('.//h2/a/text()').get()  # 相册标题，用于保存相册的文件夹名,get()方法，把数据从对象里面提取出来
        pic_url = li.xpath('.//h2/a/@href').get()  # 一级页面图片标题对应的链接，用于跳转二级页面
        print('正在保存:',pic_title)

        # 创建相册文件夹
        if not os.path.exists('image\\' + pic_title): # 检查是否存在该文件夹
            os.mkdir('image\\' + pic_title)

        # 发送相册详情页的请求，Response
        pic_response = requests.get(url=pic_url, headers=headers).text  # 详情页的数据

        # 解析详情页的图片地址
        selector_pic = parsel.Selector(pic_response)
        pic_url_list = selector_pic.xpath('//div[@class="entry-content"]//img/@src').getall()  # getall()得到是列表
        # print(pic_url_list)

        for pic_url_jpg in pic_url_list: # 遍历每一张图片的链接
            # 发送图片链接请求，获得图片数据，图片数据是二进制，所以不能用text方式提取，text方式提取的是html格式，要用content
            img_data = requests.get(url = pic_url_jpg,headers=headers).content

            # 4.数据保存
            # 准备图片文件名
            file_name = pic_url_jpg.split('/')[-1]

            with open(f'image\\{pic_title}\\{file_name}',mode = 'wb') as f:
                f.write(img_data)
                print('保存完成:',file_name)
    except:
        continue
