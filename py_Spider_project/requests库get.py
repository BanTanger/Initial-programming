import requests
data = {
    'name':'germey',
    'age':22
}
r = requests.get("http://httpbin.org/get",params=data)
# print(r.text)
"""网页返回类型应该是str，但目前得到的是json格式，所以如果想解析返回结果的得到一个字典格式，可以直接调用json（）方法"""
print(type(r.text)) # str格式
print(r.json())
"""如果不是json格式，就会出现解析错误，json.decoder.JSONDecodeError"""
print(type(r.json())) # 字典格式