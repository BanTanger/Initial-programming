//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
////成员属性私有化
////自己控制读写权限，对于写可以检测数据的有效性。
//
//class Person {
//	//私有权限通过公有接口来被类外访问到；
//public:
//	//写姓名（设置姓名）
//	void setName(string name) {
//		m_Name = name;
//	}
//	//读姓名（获取姓名）
//	string getName() {
//		return m_Name;
//	}
//	//读年龄
//	int getAge() {
//		m_Age = 10;
//		return m_Age;
//	}
//	void setLover(string lover) {
//		m_Lover = lover;
//	}
//private:
//	//姓名 //可读可写
//	string m_Name;
//	//年龄 //只读权限
//	int m_Age;
//	//情人 //可写
//	string m_Lover;
//};
//
//int main()
//{
//	Person P;
//	P.setLover("元气");
//	//cout << "qingren: " << P.getLover() << endl;
//	//只写权限没法读取
//	P.setName("BanTanger");
//	cout << "name: " << P.getName() << endl;
//
//	cout << "age: " << P.getAge() << endl;
//}