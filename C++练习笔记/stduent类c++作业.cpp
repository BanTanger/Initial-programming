//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////要求：定义一个student类，包括数据成员分数score，
////和两个静态数据成员总分total和学生人数count，
////成员函数scoretotalcount（double s）用来设置分数，
////求总分和累计的学生人数，静态成员函数sum（）用于返回总分
////静态成员函数average（）用来求平均值。
//class Student {
//public://外部访问接口
//	Student(int score) :score(score) { count++; }//构造函数。
//	Student(const Student& p) :score(p.score) { count++; }//拷贝构造函数
//	~Student() { count--; }
//	int Score() { return score; }
//	double scoretotalcount(double s);
//	static void getofnum() {
//		cout << "总共有 " << count << "名学生" << endl;
//	}
//	static double sum(Student stu[]) {
//		double sumScore = 0;
//		for (int i = 0; i < count; i++)
//			sumScore += stu[i].Score();
//		return static_cast<double>(sumScore);
//	}
//	static double average(Student stu[]) {
//		double averageScore = 0;
//		for (int i = 0; i < count; i++)
//			averageScore += stu[i].Score() / count;
//		return static_cast<double>(averageScore);//类对象类型转换，在这里并不需要，只是想练一下
//	}
//private:
//	double score;
//	static int total;
//	static int count;
//};
//double Student::scoretotalcount(double s) {
//	//设置分数
//	return s;
//}
//int Student::count = 0;
//int Student::total = 0;//静态成员数据初始在类外实现。类名作为限定。
//int main() {
//	Student s[3] = { Student(92),Student(92),Student(65) };
//	Student::getofnum();
//	cout << Student::average(s) << endl;
//	cout << Student::sum(s) << endl;
//}