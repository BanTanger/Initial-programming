#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSTUDENTSTRINGLEN 20
#define MAXSTUDENTNUMBER 100
#define PAGESIZE 3
#include "func.h"
struct Student {
	int id;	//学号
	char name[MAXSTUDENTSTRINGLEN]; 		//姓名
	char sex[MAXSTUDENTSTRINGLEN];		//性别：男或女
	char classes[MAXSTUDENTSTRINGLEN];		//班级
	int totalScore;		//总成绩
};

struct Student students[MAXSTUDENTNUMBER];//全体成员
int peopleNumber = 0;//全体学生数量
int maxld = 0;//全体学生中最大学号
//当增加新的学生时，maxId+=1，并将新学生的id设置为新的maxId
extern int minTotalscore; //全体学生的最低总分、
extern int maxTotalscore;//最高总分
extern int avgTotalscore;//平均总分
int change;
//表示学生数据是否有修改。
//值为1表示有修改，需要重新统计某些数据；
//值0表示无修改，可以重用之前的统计数据。

void addfunc() {
	do {
		printf("请依次输入id,姓名、性别、班级,分数：\n");
		scanf("%d%s%s%s%d", &students[peopleNumber].id,&students[peopleNumber].name, &students[peopleNumber].sex, &students[peopleNumber].classes,&students[peopleNumber].totalScore);
	} while (checkData(peopleNumber) == 0);
	peopleNumber++;	//学生总数加1
	maxld++;
	printf("添加学生成功！\n");
}

void changefunc() {
	int id, i;

	//1.输入待修改的学生学号
	printf("请输入需要修改学生的学号：");
	scanf("%d", &id);

	//2.查询学生并修改基本数据
	for (i = 0; i < peopleNumber; i++) {
		if (students[i].id == id) {
			//2.1输出修改前的学生数据
			printf("修改前的学生数据：%s，%s，%s。\n", students[i].name, students[i].sex, students[i].classes);

			//2.2修改并检查数据，不合法则重新修改
			do {
				fflush(stdin);//清空键盘缓冲区
				printf("添加本科学生提示：姓名不能为空；性别为男或女；专业不能为空；\n");
				printf("              班级不能为空\n");
				printf("请依次输入员工的姓名、性别、专业、班级：\n");
				scanf("%s%s%s", students[i].name, students[i].sex, students[i].classes);
			} while (checkData(i) == 0);

			//2.3显示修改成功数据及修改后的数据
			change = 1;		//已修改
			printf("修改成功！\n");
			printf("修改后的学生数据：%s，%s，%s。\n", students[i].name, students[i].sex, students[i].classes);
			return;
		}
	}
	//3.若学生不存在，则显示无该生数据
	printf("不存在该学号！\n");
}
void deletefunc() {
	int id;
	printf("输入要删除的学生id");
	scanf("%d", &id);
	for (int i = 0; i < id; i++) {
		if (i == id) {
			for (int j = id; j < maxld; j++) 
				students[j] = students[j + 1];
			peopleNumber--;
		}
	}
}
void lookfunc() {
	int id;
	printf("输入要查看的学生id");
	scanf("%d", &id);
	printf("%d,%s,%s,%s,%s,%d", students[id].id, students[id].classes, students[id].name, students[id].sex, students[id].totalScore);
}
void findfunc() {
	
}
void sortfunc() {
	//排序学生的总分，从大到小
	int id = 0;
	for (int j = 0; j < peopleNumber - 1; j++) {
		for (int i = 0; i < peopleNumber - j - 1; i++) {
			if (students[i].totalScore < students[i + 1].totalScore) {
				struct Student tmp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = tmp;
			}
		}
	} 
	for (int i = 0; i < peopleNumber; i++) {
		printf("%d,%s,%s,%s,%d", students[i].id, students[i].classes, students[i].name, students[i].sex, students[i].totalScore);
		printf("\n");
	}
}
void statisticsfunc();




//函数功能：检查学生数据是否正确
//参数说明：index—待检查的学生在数组中的下标
//返回值：  正确返回1，错误返回0。
int checkData(int index)
{
	int right = 1, length;

	//检查姓名：姓名长度不能为空，也不能大于9
	length = strlen(students[index].name);
	if (length <= 0 || length >= 9) {
		printf("姓名错误：姓名长度不能为空，也不能大于9！\n");
		right = 0;
	}

	//检查性别：只能是男或女
	if (strcmp(students[index].sex, "男") != 0 && strcmp(students[index].sex, "女") != 0) {
		printf("性别错误：只能是男或女！\n");
		right = 0;
	}

	//检查班级：班级不能为空
	if (strlen(students[index].classes) < 1) {
		printf("班级错误：班级不能为空！\n");
		right = 0;
	}

	return right;	//返回检查结果：1—正确，0—错误。
}