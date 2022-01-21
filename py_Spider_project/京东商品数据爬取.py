from selenium import webdriver # 鼠标库
from selenium.webdriver.common.keys import Keys # 键盘库
import time
import csv

def drop_down():
    """页面下滑操作""" #javascript
    for x in range(1,12,2): # 1 3 5 7 9 11 控制高度变化
        time.sleep(1)
        j = x / 9 # 1/11,3/11,5/11,7/11,9/11,11/11
        # document.documentElement.scrllTop 指定滚动条的位置
        # document.documentElement.scrllHeight 滚动条最大高度
        js = 'document.documentElement.scrollTop = document.documentElement.scrollHeight * %f' % j
        driver.execute_script(js)

# selenium 不仅可以控制鼠标点击，还可以控制键盘
driver = webdriver.Chrome() # 不指定路径模式， 需要把浏览器驱动放在代码块，或者是执行python软件的文件夹中
driver.get('https://www.jd.com/')
# 使用css选择器查找，搜索栏选中，copy，selector
driver.find_element_by_css_selector('#key').send_keys('显示屏')
# driver.find_elements_by_css_selector('#key').send_keys('显示屏') 多个标签

# driver.find_element_by_css_selector('#key').send_keys(Keys.ENTER) # 回车键指令
driver.find_element_by_css_selector('.button').click() # 找到搜索按钮，进行点击

driver.implicitly_wait(10) # 隐式等待10s,等数据加载出来就停止
drop_down()

# #J_goodsList > ul > li:nth-child(1)
lis = driver.find_elements_by_css_selector('#J_goodsList ul li')
print(len(lis))
for li in lis:
    title = li.find_element_by_css_selector(' .p-name em').text # 商品名称
    title = title.replace('京品电脑', '').replace('\n', '')
    price = li.find_element_by_css_selector(' .p-price i').text + '元' # 商品价格
    commit = li.find_element_by_css_selector(' .p-commit a').text # 商品评论
    shop = li.find_element_by_css_selector(' .p-shop a').text # 商品店铺
    href = li.find_element_by_css_selector(' .p-img a').get_attribute('href') # 商品详情页
    print(title, price, commit, shop, href, sep=' | ')
    with open('京东数据.csv', mode='a', encoding='utf-8', newline='') as f:
        csv_write = csv.writer(f)
        csv_write.writerow([title, price, commit, shop, href])

driver.quit() # 关闭浏览器