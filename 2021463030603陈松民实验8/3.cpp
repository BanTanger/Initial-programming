#define _CRT_SECURE_NO_WARNINGS 1
/*编写一个C程序，实现以下功能：
定义一个学生结构体Student(含学号、姓名、年龄、身高)
和一个函数sort(struct Student *p)，
该函数使用选择排序法按年龄由小到大排序。
在主函数中输入10个学生的学号、姓名、年龄和身高，
调用sort函数对学生数据排序，最后输出排序后的学生全部信息。
*/
#define MAX 20
#include<stdio.h>
static int n;
struct Student {
	int id;
	char Name[MAX];
	int age;
	float tell;
};
void Sort(Student *p) {
	//选择排序排序年龄。
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n - i -1; j++) {
			if (p[j+1].age < p[j].age) {
				Student tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) 
		printf("%d\t%s\t%d\t%f\t\n", p[i].id,p[i].Name, p[i].age, p[i].tell);
}
int main() {
	Student stu[MAX];
	printf("要创建学生对象的个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		printf("输入学生id:");
		scanf("%d", &stu[i].id);
		printf("输入学生姓名:");
		scanf("%s", &stu[i].Name);
		printf("输入学生年龄:");
		scanf("%d", &stu[i].age);
		printf("输入学生身高:");
		scanf("%f", &stu[i].tell);
	}
	Sort(stu);
}