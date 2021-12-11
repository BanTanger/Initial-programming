#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

enum boolean { False, True };
class base {
public:
	void getname() {
		cout << "name:";
		cin >> name;
	}
	void Printname() { cout << "name:" << name << endl; }
	virtual boolean isgood() = 0;
protected:
	string name;
};
class student :public base{
public:
	void getscore() {
		cout << "score:";
		cin >> score;
	}
	boolean isgood() { return(score > 90) ? True : False; }
private:
	int score;
};
class teacher:public base {
public:
	void gettotal() {
		cout << "total:";
		cin >> total;
	}
	boolean isgood() { return(total > 3) ? True : False; }
private:
	int total;
};
int main() {
	base* p[50];
	student* pstud;
	teacher* ptech;
	string ch;
	int count = 0;
	do {
		cout << "input t(teacher)/s(student)" << endl;
		cin >> ch;
		if (ch == "s"||ch == "S") {
			pstud = new student;
			pstud->getname();
			pstud->getscore();
			p[count++] = pstud;
		}
		else if (ch == "t"||ch == "T") {
			ptech = new teacher;
			ptech->getname();
			ptech->gettotal();
			p[count++] = ptech;
		}
		else
			cout << "input Error" << endl;
		cout << "continue?(y/n)" << endl;
		cin >> ch;
	} while (ch == "y"||ch == "Y");
	cout << "EXCELLENCE OF PEOPLE" << endl;
	for (int i = 0; i < count; i++)
		if (p[i]->isgood() == True)
			p[i]->Printname();
}