import requests
import re

base_url = 'https://music.163.com/discover/toplist'
url = base_url
headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
}

response = requests.get(url=url,headers=headers)
data_html = response.text
# 解析数据
# <li><a href="/song?id=1908392914">门没锁（女声版）</a></li> , ?在正则中有特殊含义，所以需要转义操作 ? --> \?
zip_data = re.findall('<li><a href="/song\?id=(.*?)">(.*?)</a></li>', data_html)
for data in zip_data:
    try:
        music_id = data[0]
        title = data[1]
        # 通过百度，音乐解析，得到一个外部播放器的url接口
        # https://music.163.com/song?id=
        music_url = 'https://music.163.com/song/media/outer/url?id=' + music_id
        # 音乐二进制数据
        music_data = requests.get(music_url).content
        with open(f'music\\{title}.mp3', mode='wb') as f:
            f.write(music_data)
        print(title, "下载成功！！")
    except:
        # 如果有付费，就不执行
        continue