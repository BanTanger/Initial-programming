//#define _CRT_SECURE_NO_WARNINGS 1
///*编写C语言代码，实现以下功能：
//有N名学生，每个人的信息包括学号、
//姓名和语文、数学、英语、平均分等内容（用结构体表示 ），
//输出平均分排名倒数第2的学生信息。
//*/
//#define MAX 20
//#include<stdio.h>
//struct Student {
//	int id;
//	char Name[MAX];
//	float Chinese;
//	float English;
//	float Math;
//	float average;
//};
//void Swap(float max, float average) {
//	float tmp;
//	tmp = max;
//	max = average;
//	average = tmp;
//}
//int main() {
//	//算出所有人平局分再排序
//	Student stu[MAX];
//	int n;
//	printf("输入要创建的学生对象个数\n");
//	scanf("%d", &n);//需要创建多少个学生对象；
//	for (int i = 0; i < n; i++) {
//		/*printf("学生id：");
//		scanf("%d", &stu[i].id);*/
//		printf("学生姓名：");
//		scanf("%s", &stu[i].Name[MAX]);
//		printf("语文成绩：");
//		scanf("%f", &stu[i].Chinese);
//		printf("英语成绩：");
//		scanf("%f", &stu[i].English);
//		printf("数学成绩：");
//		scanf("%f", &stu[i].Math);
//		stu[i].average = (stu[i].Chinese + stu[i].English + stu[i].Math) / 3;
//	}
//	for (int i = 0; i < n - 1; i++) {
//		float max = stu[i].average;
//		bool flag = true;//假定一开始排序就是有序的
//		for (int j = 0; j < n - i - 1; j++) {
//			if (max < stu[j].average) {
//				Swap(max, stu[i].average);
//				flag = false;//数据交换证明不有序。
//			}
//			if (flag == true)
//				break;//这一趟没有数据交换证明数据已经完全有序，跳出循环。
//		}
//	}
//	printf("倒数第二个学生的平均分为 %.2f \n", stu[n-1].average);//倒数第二个学生的平均分；
//}