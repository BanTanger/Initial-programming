#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//条件编译：把这个数字改为对应题号即可 
#define THE_TITLE  4

//第一题 编写判断一个字符序列是否是回文的函数，如果是返回true，否则返回false
#if (THE_TITLE == 1)
bool plalindrome(char *p);

void main()
{
    char p[100];
    gets(p);
    if (plalindrome(p))
        printf("true\n");
    else
        printf("false\n");
}

bool plalindrome(char *p)
{
    int i;
    int len = strlen(p);
    for (i = 0; i < len / 2; i++)
    {
        if (p[i] != p[len - i - 1])
            return false;
    }
    return true;
}
#endif

//第二题 
#if (THE_TITLE == 2)

#define PI 3.14
#define L 2 * PI *r
#define S PI *r *r
int main()
{
    double r, l, s;

    printf("Enter radius: ");
    scanf("%lf", &r);
    l = L;
    s = S;
    printf("l=%.2f, s=%.2f\n", l, s);
}
#endif

//第三题 编写一个程序，输入一个字符串，并反向输出之（必须用指针实现）
#if (THE_TITLE == 3)
int main()
{
    char temp, *s, *s1, *s2;
    s1 = (char *)malloc(sizeof(100)); /*分配存储空间*/
    printf("输入字符串：");
    gets(s1);
    s = s2 = s1;
    while (*s2 != '\0')
    {
        s2++;
    }
    s2--;
    while (s1 < s2)
    {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        s1++;
        s2--;
    }
    printf("反向字符串：%s\n", s);
    return 0;
}
#endif

//第四题
#if (THE_TITLE == 4)


int main()
{

    char *mystrstr(const char *str1, const char *str2);
    char a[101], b[101];
    scanf("%s%s", &a, &b);
   
    if(mystrstr(a, b) == 0)	
    	printf("-1");
    else
    	printf("%d",(strlen(a)- strlen(mystrstr(a, b))));
    
}
char *mystrstr(const char *str1, const char *str2)
{
    char *p1 = str1;
    char *p2 = str2;
    int i = 0;
    while (*p1) //（*检测到回车'\n'的时候跳出循环）
    {
        char *flag = p1; //设置标志位，方便回滚。
        while (*p1 == *p2 && *p1 != '\0')
        {
            //结束循环的条件有两种：1 ，字符不相等，不是子串 ； 2 ，p2到底了都是相等的， 子串
            p1++;
            p2++;
        }

        if (*p2 == '\0') //第二个字符串走到\n了吗？？？？
        {
            return flag;
            i++; //返回找到子串的起始位置。
        }
        if (!*p1)
        {
            //走到这里，p1到达\0 而p2没有到达\0，没有找到
            return NULL;
        }
        //走到这里，没有匹配成功，继续从下一位开始匹配整个子串
        p1++;
    }
    return NULL;
}
#endif

//第五题
#if (THE_TITLE == 5)
int main()
{
    int well, up, down, min = 0;
    int sum = 0;
    scanf("%d%d%d", &well, &up, &down);

    for (min = 0;;)
    {
        if (up > well)
        {
            printf("1");
            break;
        }
        sum = sum + up;
        min++;

        if (sum == well)
        {
            printf("%d", min);
            break;
        }
        else if (well - sum + down <= up)
        {
            printf("%d", min + 2);
            break;
        }
        sum = sum - down;
        min++;
    }
}
#endif

//第六题
#if (THE_TITLE == 6)
//这里格式不用那么在意，这边是直接把 heightSize 弄成宏定义 主要是看解题思路
#define heightSize 9  
int main()
{
    int height[100];
    int  i;
    int head = 0;
    int rear = heightSize - 1;
    int maxArea = 0;
    int tempArea = 0;

	
    for (i = 0; i < heightSize; i++)
    {
        scanf("%d", &height[i]);
    }

    while (head < rear)
    {
        tempArea = (rear - head) *
				   ((height[head] > height[rear]) ? height[rear] : height[head]);

        maxArea = (maxArea >= tempArea) ? maxArea : tempArea;

        if (height[head] >= height[rear])
        {
            rear--;
        }
        else
        {
            head++;
        }
    }

  printf("%d",maxArea);
}

#endif

//第七题
#if (THE_TITLE == 7)

#define MAXN 1000;   //分割一份的大小 
/* 梯形法求定积分*/
double Definite_integral(double a, double b, double (*p)(double x))
{
    int i; 
	int n = MAXN;
    double x, y1, y2, deta, f;
    deta = (b - a) / n;
    x = a;
    y1 = (*p)(x);
    f = 0;
    for (i = 0; i < n; i++)
    {
        x += deta;
        y2 = (*p)(x);
        f += (y1 + y2) * deta / 2;
        y1 = y2;
    }
    return f;
}
/*定义被积函数,三种供选择*/
double fun1(double x)
{
    double fx;
    fx = x;
    return fx;
}
double fun2(double x)
{
    double fx;
    fx = x * x * x + x * x + x + 1;
    return fx;
}
double fun3(double x)
{
    double fx;
    fx = sin(x);
    return fx;
}
int main()
{
    double a, b;
    printf("输入上下限");
    scanf("%lf %lf", &a, &b);
    printf("积分为%lf\n", Definite_integral(a, b, fun2));
}

#endif

//第八题
#if (THE_TITLE == 8)
int main() 
{
	
	char s1[100],s2[100],str[100];
	int i,num;
	
	gets(s1);
    gets(s2);
	strcpy(str,s1);
	
   while (strstr(s1,s2))
   {

		i=0;
		
		num=strlen(s1);
		char *p=strstr(s1,s2);   //返回在s1中找到的第一个s2字符串地址 
		int cnt=strlen(p);       //cnt等于所找到的当前s2字符串地址之后所有的字符串个数 

		while (i!=strlen(s2))
		{    

		    *p='\0';  //对p中的s2字符串置'\0'，并将p移至下一个地址 
		    p++;          
			i++;
		}
		strcpy(s1+(num-cnt),p);  //往前移位，即num-cnt为当前s1字符串的字符个数 
	}
	num=strlen(s1);

	for (i=0;i<=num;i++)
	{
		printf("%c",s1[i]);
	}
	
	printf("%d次",(strlen(str)-strlen(s1))/strlen(s2));		//这边输出的是去掉s2后的s1，以及s2出现的次数 
	return 0;
}


#endif

//第九题
#if (THE_TITLE == 9)
#include <stdio.h>
void main()
{
    int f[1000], g[1000], m, n, i, j, dis, index;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &f[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &g[i]);
    }

    index = f[0] - g[0];
    if (index < 0)
        index = -index;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            dis = f[i] - g[j];
            if (dis < 0)
                dis = -dis;
            if (dis < index)
                index = dis;
        }
    }
    printf("%d", index);
}
#endif

//第十题

# if  (THE_TITLE == 10)
struct infoBook
{
	char name[80];
	char author[80];
	int num;
	int date;
};

void main()
{
	int i,j;
	/*这里是直接定义的，你一个个输入也行*/
	struct infoBook a[5]={
						  {"ebooks","yincheng",5,18880808},
						  {"lbook","haoyun",34,12330205},
						  {"c++","wangwen",1,19870731},
						  {"C primer","vicky",2,19880310},
					   	  {"data struction","ben",3,19550302}
						 };
	
	for( i=0;i<5;i++)	//将初始化信息打印到屏幕上
	{
		printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
	}
	printf("\n\n After order!\n");
	for( i=0;i<4;i++) // 对书本进行排序
	{
		for ( j=i+1;j<5;j++)
		{
			char t=a[i].name[0];
			char s=a[j].name[0];
			
			if(t>s)
			{
				struct infoBook temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for( i=0;i<5;i++)	//将排序后信息打印到屏幕上
	{
		printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
	}

	puts("please enter the book");
	char books[80];
	gets(books);  // 输入书名

	for( i=0;i<5;i++) // 对输入书名进行查询，如果查询到，则打印详细信息
	{
		if(strcmp(books,a[i].name)==0)
		{
			printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
			system("pause");
			return;
		}
	}

	printf("NO");
	system("pause");
}

#endif

//第十一题
#if (THE_TITLE == 11)
int sum = 0;
int arr[100][100];
int i, j;
int t;

void cell(int i, int j);
void main()
{
    int n, m;
    printf("行数和列数:");
    scanf("%d %d", &i, &j);
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
        {
            scanf("%d", &arr[n][m]);
        }
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
            if (arr[n][m] != 0)
            {
                t = arr[n][m];
                sum++;
                cell(n, m);
            }
    printf("%d\n", sum);
}

void cell(int x, int y)
{
    if (x == i || y == j || x < 0 || y < 0 || arr[x][y] == 0 || arr[x][y] != t)
        return;
    arr[x][y] = 0;
    cell(x + 1, y);
    cell(x - 1, y);
    cell(x, y + 1);
    cell(x, y - 1);
}
#endif

