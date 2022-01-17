import requests

"""图片，视频，音乐，都是以二进制存储的，所以用到.content属性得到内容。"""
r = requests.get('https://github.com/favicon.ico')
with open('favicon.ico','wb') as f:
    f.write(r.content)