import requests
import csv
import re

def get_one_page(url):
    s = requests.Session()
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36'
    }
    response = requests.get(url,headers = headers)
    if response.status_code == 200:
        return response.text
    return None

def main():
    url = 'https://www.maoyan.com/board/4'
    html = get_one_page(url)
    print(html)
main()