import requests
import os

image_url = 'https://tse2-mm.cn.bing.net/th/id/OIP-C.F7cJKcpLYr3sdPzTbV-xJgHaEK?pid=ImgDet&rs=1'
headers = {'User':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36'}

# 1.content属性：获取bytes数据
html = requests.get(url = image_url,headers = headers).content
# 2.先确定当前路径
directory = './images/' # ./代表当前路径
if not os.path.exists(directory): # 如果没有当前路径，就创建
    os.makedirs(directory)
# 3.保存到本地文件

# 4.利用切片技术保证文件名不重复和图片格式情况
filename = directory + image_url[-10:] + '.jpg'
with open(filename,'wb') as f:
    f.write(html) # 'wb'格式保存