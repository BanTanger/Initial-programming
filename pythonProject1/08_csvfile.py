"""
csv模块的示例
"""
import csv

# window问题调节execl表格空行问题： newline = ''
with open('teacher.csv','w',newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['超哥哥','spider'])
    """
    writerow（[]）单行写入
    writerows([()()()()()])多行写入，元组
    """

teachers_li = [
    ('步惊云','排云掌'),
    ('聂风','风神腿'),
    ('雄霸','三分归元气')
]
# w 写入， a 覆盖
with open('teacher.csv','a',newline='') as f:
    writer = csv.writer(f)
    writer.writerows(teachers_li)
