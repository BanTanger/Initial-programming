import requests
import re

headers = {
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
}
r = requests.get("https://www.zhihu.com/explore",headers=headers)
pattern = re.compile('<a.*?>(.*?)</a>',re.S)
titles = re.findall(pattern,r.text)
print(titles)