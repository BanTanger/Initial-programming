import os
import requests
import re
import json
import subprocess
import pprint

url = 'https://api.bilibili.com/x/web-interface/search/type'
data = {
    'context':'',
    'page':'2',
    'order':'',
    'keyword': '布噜BLUE_',
    'duration':'',
    'tids_1':'',
    'tids_2':'',
    'from_source': 'webtop_search',
    'from_spmid': '333.1007',
    'platform': 'pc',
    '__refresh__': 'true',
    '_extra':'',
    'search_type': 'video',
    'highlight': '1',
    'single_column': '0'
}

headers = {
    'referer': 'https://www.bilibili.com/',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
}

response = requests.get(url=url, params=data, headers=headers)
result = response.json()['data']['result']

for index in result:
    try:
        bv_id = index['bvid']
        title = index['title'].replace('<em class="keyword">', '').replace('</em>', '')
        print(title, bv_id)

        url = f'https://www.bilibili.com/video/{bv_id}'
        headers = {
            'referer': 'https://www.bilibili.com/',
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
        }
        response = requests.get(url=url, headers=headers)
        # print(response.text)
        # 解析数据的方式，css,xpath,re,json直接返回列表数据
        title = re.findall('<h1 title="(.*?)" class="video-title">', response.text)[0]
        html_data = re.findall('<script>window.__playinfo__=(.*?)</script>', response.text)[0]
        # findall参数解释，第一个是正则匹配语法，想要的内容用（。*？）得到，第二个参数是正则匹配的对象。返回的是列表，所以用【0】的方式得到列表里面的内容

        # print(html_data)
        # 将字符串数据转换成json字典数据,pprint格式化模块只能对字典类型起效，而通过正则得到的其实是str字符串类型
        json_data = json.loads(html_data)
        # print(json_data)
        # pprint.pprint(json_data) # 通过格式化打印json类型 方便提取数据

        # b站数据文件夹
        if not os.path.exists('bilibili'):
            os.mkdir('bilibili')

        # 提取音频url地址 以及 视频url地址 冒号左边的内容 提取到冒号右边的内容 键值对取值 数据一般是在基本网址，只要定位到baseURL就好
        audio_url = json_data['data']['dash']['audio'][0]['baseUrl']
        video_url = json_data['data']['dash']['video'][0]['baseUrl'] # 因为audio之后是一个列表，所以先用【0】选取列表里面的字典
        # 403 Forbidden 网址，没有访问权限，跨域 --> 需要加请求头参数 添加防盗链(请求的网址是从bilibili.com 传输过来的)

        # 图片/视频/音频/特定格式的文件都是用二进制的方式保存
        audio_content = requests.get(url = audio_url,headers= headers).content
        video_content = requests.get(url = video_url,headers= headers).content
        mp3_file = '(只有声音)' + title + '.mp3'
        mp4_file = '(只有视频)' + title + '.mp4'
        Last_file = '(视频音频结合)' + title + '.mp4'

        with open(f'bilibili//{mp3_file}', mode='wb') as f:
            f.write(audio_content)
        with open(f'bilibili//{mp4_file}', mode='wb') as f:
            f.write(video_content)
        print(title, '保存成功！')
        # 要用绝对路径去选择MP3和MP4，合成的视频也要是绝对路径
        cmd = f'D:/ffmpeg-2022-01-17-git-dcc9454ab9-essentials_build/bin/' \
              f'ffmpeg -i  C:/Users/12902/PycharmProjects/pythonProject1/bilibili/{mp3_file} ' \
              f'-i C:/Users/12902/PycharmProjects/pythonProject1/bilibili/{mp4_file} ' \
              f'C:/Users/12902/PycharmProjects/pythonProject1/bilibili/{Last_file} '
        subprocess.run(cmd, shell=True)
        os.remove(f'{mp3_file}')
        os.remove(f'{mp4_file}')
        print(title, '视频合成成功')
    except:
        continue
