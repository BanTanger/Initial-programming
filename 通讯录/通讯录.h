#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 20
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX];//存放信息
	int size;//记录当前通讯录大小。
};

//声明函数。
void InitContact(struct Contact* ps);
//传参是结构体的指针，指针接收地址

//添加通讯录的函数
void AddContact(struct Contact* ps);

//打印通讯录的函数，const保证只打印不改值
void ShowContact(const struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);