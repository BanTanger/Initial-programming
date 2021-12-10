//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Data {
//	//基类
//public:
//	Data(string name):name(name) {}//数据成员初始化
//	string Name() { return name; }//私有成员对外部接口
//	void Print() {
//		cout << "name = " << Name() << endl;//外部接口作为打印值，这里也可以用name私有成员
//	}
//private:
//	string name;
//};
//class Teacher :virtual public Data{//虚基类，名字是所有类里公有的，所以只需要继承一份
//public:
//	//子类的构造函数，给出所有基本信息。
//	Teacher(string name, float sal = 0) :Data(name),sal(sal) {}
//	//虚基类若不是默认函数，则在继承的子类里的构造函数也要给出基类的初始化
//	float Sal() { return sal; }
//	void Print() {
//		cout << " name = " << Name() << " sal = " << Sal() << endl;
//	}
//private:
//	float sal;
//};
//class Student :virtual public Data{
//public://同teacher类的注释
//	Student(string name, int id = 0) :Data(name),id(id) {}
//	int Id() { return id; }
//	void Print() {
//		cout << " name = " << Name() << " id = " << Id() << endl;
//	}
//private:
//	int id;
//};
//class Postgrad :virtual public Student {
//public://构造函数给出子类继承父类和自身本身的信息
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
//		//打印继承的父类函数，需要给出命名空间来限定是哪一个打印函数，
//		//但这里会造成名字打印两次的尴尬，不知道怎么处理
//		Postgrad::Print();
//		Teacher::Print();
//	}
//};
//void test() {
//	/*Data* sp;
//	sp = new Teacher ("李华", 60000);
//	//不可以这样使用new，需要好好去复习。
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