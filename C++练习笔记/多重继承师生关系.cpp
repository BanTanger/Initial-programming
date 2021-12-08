//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Data {
//	//基类
//public:
//	Data(string name):name(name) {}
//	string Name() { return name; }
//	void Print() {
//		cout << "name = " << Name() << endl;
//	}
//private:
//	string name;
//};
//class Teacher :virtual public Data{
//public:
//	Teacher(string name, float sal = 0) :Data(name),sal(sal) {}
//	float Sal() { return sal; }
//	void Print() {
//		cout << " name = " << Name() << " sal = " << Sal() << endl;
//	}
//private:
//	float sal;
//};
//class Student :virtual public Data{
//public:
//	Student(string name, int id = 0) :Data(name),id(id) {}
//	int Id() { return id; }
//	void Print() {
//		cout << " name = " << Name() << " id = " << Id() << endl;
//	}
//private:
//	int id;
//};
//class Postgrad :virtual public Student {
//public:
//	Postgrad(string name, int id, string dn) :Data(name), Student(name, id),dn(dn) {}
//	string Dn() { return dn; }
//	void Print() {
//		cout << " name = " << Name() << " dn = " << Dn() << endl;
//	}
//private:
//	string dn;
//};
//class Tpost :virtual public Teacher, virtual public Postgrad {
//public:
//	Tpost(string name, int id, string dn, float sal) :Data(name), Postgrad(name,id,dn), Teacher(name, sal) ,Student(name,id){}
//	void Print() {
//		Postgrad::Print();
//		Teacher::Print();
//	}
//};
//void test() {
//	/*Data* sp;
//	sp = new Teacher ("李华", 60000);
//	sp->Print();
//	delete sp;
//	sp = new Tpost("张三", 2021463030603,"计算机", 50000);
//	sp->Print();
//	delete sp;*/
//
//	Tpost t1("zhangsan", 2021463030603, "jisuanji", 50000);
//	t1.Print();
//	Teacher t2("lisi", 60000);
//	t2.Print();
//}
//int main() {
//	test();
//}