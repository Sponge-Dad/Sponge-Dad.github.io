#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>

/*******************建立结构体，为航班基本信息*******************/

typedef struct time{            //时间结构体
	int year;
	int month;
	int day;
	int hour;
	int min;
}Time;

typedef struct flight{          //航班信息
	int data;             //航班数量
	char start[20];       //起飞地点
	char end[20];         //降落地点
	Time t[3];            //时间：年月日
	char number[20];      //航班号
	int sum;              //机票的总数
	int price;            //机票价格
	struct flight *pNext; //指针
}NODE ,*PNODE;


/*******************建立全局变量*******************/
PNODE pHead = NULL;     //管理员分系统的链表头结点
PNODE pHead1 = NULL;    //用户分系统的链表头结点
FILE *fp = NULL;        //文件
int flag = 0;          

/*******************函数申明（因为我main函数在程序的最后，所以也可以不要函数声明，只是为了方便看）*******************/
void menu(); //主菜单
//管理员菜单
void menu1_1(); //密码系统
void menu1_2();

//用户菜单
void menu2_1(); //密码系统
void menu2_2();


//管理员函数
void Create_flight();          //创建管理员头结点； 
PNODE add_flight(PNODE pHead); //给管理员单个节点分配内存； 
void Enter(PNODE pTemp);       //输入函数 
void Browse(PNODE pHead);      //遍历链表 
bool Delete(PNODE pHead);      //删除节点； 
bool Increase(PNODE pHead);    //增加节点 


//用户函数
void Create_flight1();     //创建用户头结点；
PNODE add_flight1(PNODE pHead); //给用户分配单个节点内存；
void browse(PNODE pHead);  // 遍历航班链表； 
void book(PNODE pTemp);    // 预定机票；
bool refund(PNODE pHead1); // 退订机票；
PNODE change(PNODE pHead1);      // 改签航班； 
PNODE find_flight(PNODE pHead, char *number);  // 根据航班号查找航班； 
void print_flight(PNODE pTemp);  // 输出单个航班信息；
void browse1(PNODE pHead1);      //我的功能； 


/*******************文件操作*******************/
void save_flight(PNODE pHead);   //将管理员链表中的信息存入文件中； 
void load_flight(PNODE pHead);   //将管理员文件中的信息导入链表； 

void save_flight1(PNODE pHead1); //将用户链表中的信息存入文件中； 
void load_flight1(PNODE pHead1); //将用户文件中的信息导入链表； 


void menu()
{
	system("color A");
	system("cls");
	printf("\n\n\t\t********************************************************************\n");
	printf("\t\t                         欢迎进入票务系统!                          \n");
	printf("\t\t********************************************************************\n");
	printf("\t\t********************************************************************\n");
	printf("\t\t                 Welcome to the ticketing system.                   \n");
	printf("\t\t********************************************************************\n");
	printf("\t\t********************************************************************\n");
	printf("\t\t             用户                               请按1               \n");
	printf("\t\t            管理员                              请按2               \n");
	printf("\t\t********************************************************************\n");
	printf("\t\t********************************************************************\n");
	printf("\t\t         administrator                     please enter 1           \n");
	printf("\t\t           passenger                       please enter 2           \n");
	printf("\t\t********************************************************************\n");
	//system("pause");
}

void menu1_1()
{
	system("cls");
	char str[20];
	int i, j, error = 0;
	printf("\n\t\t（您共有3次输入机会，若全部错误推强制退出程序！）\n");
	for (i = 0; i < 3; i++) {
		if (error >= 3) {
			break;
		}
		printf("\n\t\t请输入密码：\n");
		for (j = 0; ; j++) {
			str[j] = getch();
			printf("*");
			if(str[j]=='\r')
			break;
		}
		printf("\n");
		str[j] = '\0';
		if (strcmp(str, "123456") == 0) {
			printf("\n\t\t密码正确！\n");
			menu1_2();                                           //进入用户控制界面 
			break;
		}
		else {
			error++;
			if (error >= 3) {
				printf("\n\t\t密码输入次数已用完！将强制退出！！\n");
				exit(-1);
			}
			printf("\n\t\t密码错误！您还有%d次机会\n", 2 - i);
		}
	}
}

void menu2_1()
{
	system("cls");
	char str[20];
	int i, j, error = 0;
	printf("\n\t\t尊敬的管理员！欢迎进入西安邮电航空系统订票后台操作系统\n");
	printf("\n\t\t请按照接下来的提示进行操作！\n");
	printf("\n\t\t接下来将输入密码！\n");
	printf("\n\t\t（您共有3次输入机会，若全部错误推强制退出程序！）\n");
	for (i = 0; i < 3; i++) {
		if (error >= 3) {
			break;
		}
		printf("\n\t\t请输入密码：\n");
		for (j = 0; ; j++) {
			str[j] = getch();
			if(str[j] != '\b'){
				printf("*");
			}
			if(str[j] == '\b'){
				printf("\b \b");
			}
			if(str[j] == '\r') break;
		}
		printf("\n");
		str[j] = '\0';
		if (strcmp(str, "123456") == 0) {
			menu2_2();                                                 //进入管理员控制界面 
			break;
		}
		else {
			error++;
			if (error >= 3) {
				printf("\n\t\t密码输入次数已用完！将强制退出！！\n");
				exit(-1);
			}
			printf("\n\t\t密码错误！您还有%d次机会\n", 2 - i);
		}
	}
}


void menu1_2()
{
	system("cls");
	printf("\n\n\t\t|-------------------------------------------|\n");
	printf("\t\t|                 1--浏览                   |\n");
	printf("\t\t|                 2--订票                   |\n");
	printf("\t\t|                 3--退票                   |\n");
	printf("\t\t|                 4--改签                   |\n");
	printf("\t\t|                 5--查询                   |\n");
	printf("\t\t|                 6--我的                   |\n");
	printf("\t\t|                 0--退出                   |\n");
	printf("\t\t|-------------------------------------------|\n");
//	system("pause");
}

void menu2_2()
{
	system("color B");
	system("cls");
	printf("\n\n\t\t|-------------------------------------------|\n");
	printf("\t\t|                 1--录入航班信息           |\n");
	printf("\t\t|                 2--浏览航班信息           |\n");
	printf("\t\t|                 3--增加航班信息           |\n");
	printf("\t\t|                 4--删除航班信息           |\n");
	printf("\t\t|                 5--保存航班信息           |\n");
	printf("\t\t|                 6--修改航班信息           |\n");
	printf("\t\t|                 0--退出                   |\n");
	printf("\t\t|-------------------------------------------|\n");
	
}

//  创建管理员头节点； 
void Create_flight()
{
	pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead){
		pHead->pNext = NULL;
		pHead->data = 0; 
	}
	return;
}

//创建用户头节点；
void Create_flight1()
{
	pHead1 = (PNODE)malloc(sizeof(NODE));
	if(pHead1){
		pHead1->pNext = NULL;
		pHead1->data = 0;
	}
}

// 为管理员单个节点分配内存； 
PNODE add_flight(PNODE pHead){
	PNODE q = pHead;
	while(q->pNext != NULL){
		q = q->pNext;
	}
	
	q->pNext = (PNODE)malloc(sizeof(NODE));
	
	q->pNext->pNext = NULL;
	pHead->data++;
	return q->pNext;
}
// 为用户单个节点分配内存；
PNODE add_flight1(PNODE pHead1){
	PNODE q = pHead1;
	while(q->pNext != NULL){
		q = q->pNext;
	}
	
	q->pNext = (PNODE)malloc(sizeof(NODE));
	
	q->pNext->pNext = NULL;
	pHead1->data++;
	return q->pNext;
}



//从管理员文件中读取到链表中;
void load_flight(PNODE pHead){
	PNODE p = NULL, pTemp = NULL;
	pTemp = (PNODE)malloc(sizeof(NODE));
	pTemp->pNext = NULL;
	fp = fopen("flight.txt", "rb");
	
	while(1){
		if(fscanf(fp, "%s %d %d %s %s %d %d %d %d %d %d %d %d %d %d\n", pTemp->number, &pTemp->sum, &pTemp->price, pTemp->start, pTemp->end, &pTemp->t[0].year, &pTemp->t[0].month, &pTemp->t[0].day, &pTemp->t[0].hour, &pTemp->t[0].min, &pTemp->t[1].year, &pTemp->t[1].month, &pTemp->t[1].day, &pTemp->t[1].hour, &pTemp->t[1].min)!=EOF){
			p = add_flight(pHead);
			
			strcpy(p->end, pTemp->end);
			strcpy(p->number, pTemp->number);
			strcpy(p->start, pTemp->start);
			p->sum = pTemp->sum;
			p->price = pTemp->price;
			p->t[0].year = pTemp->t[0].year;
			p->t[0].month = pTemp->t[0].month;
			p->t[0].day = pTemp->t[0].day;
			p->t[0].hour = pTemp->t[0].hour;
			p->t[0].min = pTemp->t[0].min;
			p->t[1].year = pTemp->t[1].year;
			p->t[1].month = pTemp->t[1].month;
			p->t[1].day = pTemp->t[1].day;
			p->t[1].hour = pTemp->t[1].hour;
			p->t[1].min = pTemp->t[1].min;
		}
		else break;
	} 
	free(pTemp);
	fclose(fp);
	return ;
} 

//从用户文件中读取到链表中;
void load_flight1(PNODE pHead1){
	PNODE p = NULL, pTemp = NULL;
	pTemp = (PNODE)malloc(sizeof(NODE));
	pTemp->pNext = NULL;
	fp = fopen("flight1.txt", "rb");
	
	while(1){
		if(fscanf(fp, "%s %d %d %s %s %d %d %d %d %d %d %d %d %d %d\n", pTemp->number, &pTemp->sum, &pTemp->price, pTemp->start, pTemp->end, &pTemp->t[0].year, &pTemp->t[0].month, &pTemp->t[0].day, &pTemp->t[0].hour, &pTemp->t[0].min, &pTemp->t[1].year, &pTemp->t[1].month, &pTemp->t[1].day, &pTemp->t[1].hour, &pTemp->t[1].min)!=EOF){
			p = add_flight(pHead1);
			
			strcpy(p->end, pTemp->end);
			strcpy(p->number, pTemp->number);
			strcpy(p->start, pTemp->start);
			p->sum = pTemp->sum;
			p->price = pTemp->price;
			p->t[0].year = pTemp->t[0].year;
			p->t[0].month = pTemp->t[0].month;
			p->t[0].day = pTemp->t[0].day;
			p->t[0].hour = pTemp->t[0].hour;
			p->t[0].min = pTemp->t[0].min;
			p->t[1].year = pTemp->t[1].year;
			p->t[1].month = pTemp->t[1].month;
			p->t[1].day = pTemp->t[1].day;
			p->t[1].hour = pTemp->t[1].hour;
			p->t[1].min = pTemp->t[1].min;
		}
		else break;
	} 
	free(pTemp);
	fclose(fp);
	return ;
} 


//将管理员链表保存到文件中
void save_flight(PNODE pHead){
	PNODE r = pHead->pNext;
	if(r == NULL){
		fp = fopen("flight.txt","wb");
		pHead->data = 0;
		fclose(fp);
		getch();
		return;
	}
	
	fp = fopen("flight.txt", "wb");


	for(r=pHead->pNext;r!=NULL;r=r->pNext)
	{
		fprintf(fp,"%s %d %d %s %s %d %d %d %d %d %d %d %d %d %d", r->number, r->sum, r->price, r->start, r->end, r->t[0].year, r->t[0].month, r->t[0].day, r->t[0].hour, r->t[0].min, r->t[1].year, r->t[1].month, r->t[1].day, r->t[1].hour, r->t[1].min);
	}
	fclose(fp);
	
	return;
}
// 将用户链表保存到文件中 
void save_flight1(PNODE pHead1){
	PNODE r = pHead1->pNext;
	if(r == NULL){
		fp = fopen("flight1.txt","wb");
		pHead1->data = 0;
		fclose(fp);
		getch();
		return;
	}
	
	fp = fopen("flight1.txt", "wb");


	for(r=pHead1->pNext;r!=NULL;r=r->pNext)
	{
		fprintf(fp,"%s %d %d %s %s %d %d %d %d %d %d %d %d %d %d", r->number, r->sum, r->price, r->start, r->end, r->t[0].year, r->t[0].month, r->t[0].day, r->t[0].hour, r->t[0].min, r->t[1].year, r->t[1].month, r->t[1].day, r->t[1].hour, r->t[1].min);
	}
	fclose(fp);
	
	return;
}



void Enter(PNODE pTemp){
//	system("cls");
	if(pTemp == NULL){
		return;
	}
		printf("航班号\t票数\t票价\t起飞地点\t降落地点\t起飞时间\t降落时间\n");
		scanf("%s", &pTemp->number);//航班号
		scanf("%d", &pTemp->sum);//票数
		scanf("%d", &pTemp->price);//票价
		scanf("%s", &pTemp->start);//起飞地点
		scanf("%s", &pTemp->end);//降落地点
		scanf("%d %d %d %d %d", &pTemp->t[0].year, &pTemp->t[0].month, &pTemp->t[0].day, &pTemp->t[0].hour, &pTemp->t[0].min);//起飞时间
		scanf("%d %d %d %d %d", &pTemp->t[1].year, &pTemp->t[1].month, &pTemp->t[1].day, &pTemp->t[1].hour, &pTemp->t[1].min);//降落时间
	
//	PNODE r;
//	for(r=pHead->pNext;r!=NULL;r=r->pNext)
//	{
//		fprintf(fp,"%s %d %d %s %s %d %d %d %d %d %d %d %d", r->number, r->sum, r->price, r->start, r->end, r->t[0].month, r->t[0].day, r->t[0].hour, r->t[0].min, r->t[1].month, r->t[1].day, r->t[1].hour, r->t[1].min);
//	}
//	fclose(fp);
	printf("\n\t\t航班已成功录入！\n"); 

	
}

void Browse(PNODE pHead){
	system("cls");
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("\n\n\t\t航班号\t票数\t票价\t起飞地点\t降落地点\t起飞时间\t降落时间\n");
		printf("\t\t%s\t", p->number);//航班号
		printf("%d\t", p->sum);//票数
		printf("%d\t", p->price);//票价
		printf("%s\t\t", p->start);//起飞地点
		printf("%s\t\t", p->end);//降落地点
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//起飞时间
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//降落时间
		printf("\n");
		p = p->pNext;
	}
	
	system("pause");
}

bool Increase(PNODE pHead, int pos, int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, int val9, int val10, int val11, int val12, char str1[20], char str2[20], char str3[20]){
	system("cls");
	
	int i = 0; 
	PNODE p = pHead;
	
	while(NULL != p && i < pos-1){
		p = p->pNext;
		i++;
	}
	
	if(i > pos-1 || NULL == p)
	return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew){
			printf("intsert error, exit!");
			exit(-1);
		}
		strcpy(pNew->number, str1);
		pNew->sum = val1;
		pNew->price = val2;
		strcpy(pNew->start, str2);
		strcpy(pNew->end, str3);
		pNew->t[0].year = val11;
		pNew->t[0].month = val3;
		pNew->t[0].day = val4;
		pNew->t[0].hour = val5;
		pNew->t[0].min = val6;
		pNew->t[1].year = val12;
		pNew->t[1].month = val7;
		pNew->t[1].day = val8;
		pNew->t[1].hour = val9;
		pNew->t[1].min = val10;
		 
		PNODE m = p->pNext;
		p->pNext = pNew;
		pNew->pNext = m;
	
	PNODE r;
	
	printf("\n\t\t航班已成功增加！\n"); 
//	system("pause");

}

bool Delete(PNODE pHead, int pos, int *pVal1, int *pVal2, int *pVal3, int *pVal4, int *pVal5, int *pVal6, int *pVal7, int *pVal8, int *pVal9, int *pVal10, int *pVal11, int *pVal12, char pStr1[20], char pStr2[20], char pStr3[20] ){
	int i = 0; 
	PNODE p = pHead;

	while(NULL != p->pNext && i < pos-1){
		p = p->pNext;
		i++;
	}
	
	if(i > pos-1 || NULL == p->pNext)
	return false;
	
	PNODE q = p->pNext;
	strcpy(pStr1, q->number);
	*pVal1 = q->sum;
	*pVal2 = q->price;
	strcpy(pStr2, q->start);
	strcpy(pStr3, q->end);
	*pVal11 = q->t[0].year;
	*pVal3 = q->t[0].month;
	*pVal4 = q->t[0].day;
	*pVal5 = q->t[0].hour;
	*pVal6 = q->t[0].min;
	*pVal12 = q->t[1].year;
	*pVal7 = q->t[1].month;
	*pVal8 = q->t[1].day;
	*pVal9 = q->t[1].hour;
	*pVal10 = q->t[1].min;
	
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	
	
	return true;
}

void browse(PNODE pHead){
	system("cls");
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("航班号\t票数\t票价\t起飞地点\t降落地点\t起飞时间\t降落时间\n");
		printf("%s\t", p->number);//航班号
		printf("%d\t", p->sum);//票数
		printf("%d\t", p->price);//票价
		printf("%s\t\t", p->start);//起飞地点
		printf("%s\t\t", p->end);//降落地点
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//起飞时间
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//降落时间
		printf("\n");
		p = p->pNext;
	}
	
//	system("pause");

}
void browse1(PNODE pHead1){
	system("cls");
	PNODE p = pHead1->pNext;
	while(p != NULL){
		printf("航班号\t票数\t票价\t起飞地点\t降落地点\t起飞时间\t降落时间\n");
		printf("%s\t", p->number);//航班号
		printf("%d\t", p->sum);//票数
		printf("%d\t", p->price);//票价
		printf("%s\t\t", p->start);//起飞地点
		printf("%s\t\t", p->end);//降落地点
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//起飞时间
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//降落时间
		printf("\n");
		p = p->pNext;
	}
	
//	system("pause");
}

// 输出单个节点的信息 
void print_flight(PNODE pTemp){
	if(pTemp == NULL){
		return ;
	}
	printf("\n\n\t\t航班号\t票数\t票价\t起飞地点\t降落地点\t起飞时间\t降落时间\n");
	printf("%s\t", pTemp->number);//航班号
	printf("%d\t", pTemp->sum);//票数
	printf("%d\t", pTemp->price);//票价
	printf("%s\t\t", pTemp->start);//起飞地点
	printf("%s\t\t", pTemp->end);//降落地点
	printf("%d %d %d %d %d\t\t", pTemp->t[0].year, pTemp->t[0].month, pTemp->t[0].day, pTemp->t[0].hour, pTemp->t[0].min);//起飞时间
	printf("%d %d %d %d %d", pTemp->t[1].year, pTemp->t[1].month, pTemp->t[1].day, pTemp->t[1].hour, pTemp->t[1].min);//降落时间
	printf("\n");
	return;	
}

void book(PNODE pTemp){
	
//	system("cls");
	PNODE p = pHead->pNext;
	int i, n = 0, sum = 0;
	int count = 0;
	char arr1[20], arr2[20];
	printf("\n\n\t\t亲！请问您的出发地和目的地分别是哪里呢？\n\n");
	scanf("%s %s", arr1, arr2);
	while(p != NULL){
		if(strcmp(arr1, p->start) == 0 && strcmp(arr2, p->end) == 0){
			count = p->sum;
		}
		p = p->pNext;
	}
	if(count == 0) {
		printf("\n\n\t\t亲! 票好像卖完了呢@.@\n"); 
		getch();
		flag = 0;
		return;
	}
	if(count != 0){
		printf("\n\n\t\t亲！从 %s 飞往 %s 的机票还剩 %d 张呢^.^", arr1, arr2, count);
		printf("\n\n\t\t好的呢!\n请问您需要多少张机票？");
		scanf("%d", &n);
		p = pHead->pNext;
		while(p != NULL){
			if(strcmp(arr1, p->start) == 0 && strcmp(arr2, p->end) == 0){
				if(n > p->sum){
					printf("\n\n\t\t亲！从 %s 飞往 %s 的机票只剩 %d 张了呢! ", arr1, arr2, count);
					getch();
					return ;
				}
				p->sum -= n;
				strcpy(pTemp->number, p->number);
				strcpy(pTemp->start, p->start);
				strcpy(pTemp->end, p->end);
				pTemp->sum = n;
				pTemp->price = p->price;
				pTemp->t[0].year = p->t[0].year;
				pTemp->t[0].month = p->t[0].month;
				pTemp->t[0].day = p->t[0].day;
				pTemp->t[0].hour = p->t[0].hour;
				pTemp->t[0].min = p->t[0].min;
				pTemp->t[1].year = p->t[1].year;
				pTemp->t[1].month = p->t[1].month;
				pTemp->t[1].day = p->t[1].day;
				pTemp->t[1].hour = p->t[1].hour;
				pTemp->t[1].min = p->t[1].min;
			}
			p = p->pNext;
		}
		p = pHead->pNext;
		while(p != NULL){
			if(strcmp(arr1, p->start) == 0 && strcmp(arr2, p->end) == 0){
				sum = p->price * n;
			}
			p = p->pNext;
		}
		printf("\n\n\t\t亲！您需支付%d元 ^-^", sum);
		
	}
	
	system("pause");
}

//  根据航班号查询航班； 
PNODE find_flight(PNODE pHead, char *number)
{
	PNODE p = pHead;
	while(strcmp(p->number, number) != 0 && p->pNext != NULL){
		p = p->pNext;
	} 
	
	if(p->pNext == NULL && strcmp(p->number, number) != 0){
		printf("\n\n\t\t抱歉哦， 没有查到此航班@.@");
		return NULL;
		getch();
	}
	return p;
}


PNODE find_flight1(PNODE pHead1, char *number)
{
	PNODE p = pHead1;
	while(strcmp(p->number, number) != 0 && p->pNext != NULL){
		p = p->pNext;
	} 
	
	if(p->pNext == NULL && strcmp(p->number, number) != 0){
		printf("\n\n\t\t抱歉哦， 没有查到此航班@.@");
		return NULL;
		getch();
	}
	return p;
}

bool refund(PNODE pHead1, int pos, int *pVal1, int *pVal2, int *pVal3, int *pVal4, int *pVal5, int *pVal6, int *pVal7, int *pVal8, int *pVal9, int *pVal10, int *pVal11, int *pVal12, char pStr1[20], char pStr2[20], char pStr3[20] ){
	int i = 0; 
	PNODE p = pHead1;

	
	while(NULL != p->pNext && i < pos-1){
		p = p->pNext;
		i++;
	}
	
	if(i > pos-1 || NULL == p->pNext)
	return false;
	
	PNODE q = p->pNext;
	strcpy(pStr1, q->number);
	*pVal1 = q->sum;
	*pVal2 = q->price;
	strcpy(pStr2, q->start);
	strcpy(pStr3, q->end);
	*pVal11 = q->t[0].year;
	*pVal3 = q->t[0].month;
	*pVal4 = q->t[0].day;
	*pVal5 = q->t[0].hour;
	*pVal6 = q->t[0].min;
	*pVal12 = q->t[1].year;
	*pVal7 = q->t[1].month;
	*pVal8 = q->t[1].day;
	*pVal9 = q->t[1].hour;
	*pVal10 = q->t[1].min;
	
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	
	return true;
}







int main(void)
{
	int n = 1;
	int num1, num2 = 9, num3 = 1, num4 = 9;
	int pos;
	int val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12;
	int pVal1, pVal2, pVal3, pVal4, pVal5, pVal6, pVal7, pVal8, pVal9, pVal10, pVal11, pVal12;
	char str1[20], str2[20], str3[20], pStr1[20], pStr2[20], pStr3[20];
	char number[20];
	PNODE pTemp = NULL;
	Create_flight();
	Create_flight1();
	load_flight(pHead);
	load_flight1(pHead1);
	system("color D");
	menu();
	while(1){
		scanf("%d", &num3);
		if(num3 == 2){
			menu2_1();
			while(num4 == 9){
				scanf("%d", &num1);
				if(num1 == 1){
					printf("\n\t\t亲！请输入您需要录入的航班数量^-^ :");
					scanf("%d", &n);
					for(int i = 0; i < n; i++){
						pTemp = add_flight(pHead);
						Enter(pTemp);
						getch();
					}
				}
				else if(num1 == 2){
					Browse(pHead);
					getch();
				}
				else if(num1 == 3){
					printf("\n\n\t\t现有航班信息:\n");
					Browse(pHead);
					printf("\n\n\t\t请输入你要增加的航班位置：");
					scanf("%d", &pos);
					printf("\n\n\t\t请输入您要增加的航班号：");
					scanf("%s", &str1);
					printf("\n\n\t\t请输入您要增加的机票数量: "); 
					scanf("%d", &val1);
					printf("\n\n\t\t请输入您要增加的机票价格: "); 
					scanf("%d",&val2);
					printf("\n\n\t\t请输入您要增加的航班起飞地点: "); 
					scanf("%s",&str2);
					printf("\n\n\t\t请输入您要增加的航班降落地点: "); 
					scanf("%s",&str3);
					printf("\n\n\t\t请输入您要增加的航班起飞时间: ");
					scanf("%d %d %d %d %d", &val11, &val3, &val4, &val5, &val6);//起飞时间
					printf("\n\n\t\t请输入您要增加的航班降落时间: "); 
					scanf("%d %d %d %d %d", &val12, &val7, &val8, &val9, &val10);//降落时间
					
					Increase(pHead, pos, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, str1, str2, str3);
				}
				else if(num1 == 4){
					Browse(pHead);
					printf("\n\n\t\t您将进行删除航班的操作："); 
					printf("\n\n\t\t请输入你要删除的航班位置：");
					scanf("%d", &pos);
					printf("\n\n\t\t请输入您要删除的航班号：");
					scanf("%s", &str1);
					Delete(pHead, pos, &pVal1, &pVal2, &pVal3, &pVal4, &pVal5, &pVal6, &pVal7, &pVal8, &pVal9, &pVal10, &pVal11, &pVal12, pStr1, pStr2, pStr3);
				}
				else if(num1 == 5){
					save_flight(pHead);
					printf("\n\n\t\t已成功保存%d！条航班信息。", pHead->data); 
					getch();
				}
				else if(num1 == 6){
					printf("\n\n\t\t请输入您需要修改的航班号：");
					scanf("%s", number);
					pTemp = find_flight(pHead, number);
					Enter(pTemp);
					getch(); 
				}
				else if(num1 ==0){
					break;
					menu();
				}
				menu2_2();
			}
		}
		
		else if(num3 == 1){
			menu1_1();
			while(num4 == 9){
				scanf("%d", &num1);
				if(num1 == 1){                // 浏览 
					browse(pHead);
					getch();
				}  
				else if(num1 == 2){           //订票 
					browse(pHead);
					pTemp = add_flight1(pHead1); 
					book(pTemp);
				//	save_flight1(pHead1);
					printf("\n\n\t\t您的信息已保存！");
					getch();
					
				}
				else if(num1 == 3){           //退票 
					browse1(pHead1);
					printf("\n\n\t\t请输入您要退订的航班位置：");
					scanf("%d", &pos);
					refund(pHead1, pos, &pVal1, &pVal2, &pVal3, &pVal4, &pVal5, &pVal6, &pVal7, &pVal8, &pVal9, &pVal10, &pVal11, &pVal12, pStr1, pStr2, pStr3);
				//	save_flight1(pHead1);
					printf("\n\n\t\t退票成功！");
					getch(); 
				}
				else if(num1 == 4){           //改签 
					browse1(pHead1);
					printf("\n\n\t\t请输入您需要更改的航班号：");
					scanf("%s", number);
					printf("\n\n\t\t请输入新的航班信息哦^.^");
					pTemp = find_flight1(pHead1, number); 
					book(pTemp); 
				//	save_flight1(pHead1);
					printf("\n\n\t\t您已成功改签！");
					getch();
				}
				else if(num1 == 5){           //查询 
					printf("\n\n\t\t请输入需要查找的航班号：");
					scanf("%s", number);
					pTemp = find_flight(pHead, number);
					print_flight(pTemp);
					getch();
				} 
				else if(num1 == 6){           //我的 
					browse1(pHead1);
					getch(); 
				}
				else if(num1 == 0){           //退出 
					save_flight1(pHead1);
					break;
					menu();
				}
				menu1_2();
			}
		}
		else{
			exit(-1);
		}
		menu();
	}
	return 0;
}
