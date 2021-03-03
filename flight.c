#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>

/*******************½¨Á¢½á¹¹Ìå£¬Îªº½°à»ù±¾ÐÅÏ¢*******************/

typedef struct time{            //Ê±¼ä½á¹¹Ìå
	int year;
	int month;
	int day;
	int hour;
	int min;
}Time;

typedef struct flight{          //º½°àÐÅÏ¢
	int data;             //º½°àÊýÁ¿
	char start[20];       //Æð·ÉµØµã
	char end[20];         //½µÂäµØµã
	Time t[3];            //Ê±¼ä£ºÄêÔÂÈÕ
	char number[20];      //º½°àºÅ
	int sum;              //»úÆ±µÄ×ÜÊý
	int price;            //»úÆ±¼Û¸ñ
	struct flight *pNext; //Ö¸Õë
}NODE ,*PNODE;


/*******************½¨Á¢È«¾Ö±äÁ¿*******************/
PNODE pHead = NULL;     //¹ÜÀíÔ±·ÖÏµÍ³µÄÁ´±íÍ·½áµã
PNODE pHead1 = NULL;    //ÓÃ»§·ÖÏµÍ³µÄÁ´±íÍ·½áµã
FILE *fp = NULL;        //ÎÄ¼þ
          

/*******************º¯ÊýÉêÃ÷£¨ÒòÎªÎÒmainº¯ÊýÔÚ³ÌÐòµÄ×îºó£¬ËùÒÔÒ²¿ÉÒÔ²»Òªº¯ÊýÉùÃ÷£¬Ö»ÊÇÎªÁË·½±ã¿´£©*******************/
void menu(); //Ö÷²Ëµ¥
//¹ÜÀíÔ±²Ëµ¥
void menu1_1(); //ÃÜÂëÏµÍ³
void menu1_2();

//ÓÃ»§²Ëµ¥
void menu2_1(); //ÃÜÂëÏµÍ³
void menu2_2();


//¹ÜÀíÔ±º¯Êý
void Create_flight();          //´´½¨¹ÜÀíÔ±Í·½áµã£» 
PNODE add_flight(PNODE pHead); //¸ø¹ÜÀíÔ±µ¥¸ö½Úµã·ÖÅäÄÚ´æ£» 
void Enter(PNODE pTemp);       //ÊäÈëº¯Êý 
void Browse(PNODE pHead);      //±éÀúÁ´±í 
bool Delete(PNODE pHead);      //É¾³ý½Úµã£» 
bool Increase(PNODE pHead);    //Ôö¼Ó½Úµã 


//ÓÃ»§º¯Êý
void Create_flight1();     //´´½¨ÓÃ»§Í·½áµã£»
PNODE add_flight1(PNODE pHead); //¸øÓÃ»§·ÖÅäµ¥¸ö½ÚµãÄÚ´æ£»
void browse(PNODE pHead);  // ±éÀúº½°àÁ´±í£» 
void book(PNODE pTemp);    // Ô¤¶¨»úÆ±£»
bool refund(PNODE pHead1); // ÍË¶©»úÆ±£»
PNODE change(PNODE pHead1);      // ¸ÄÇ©º½°à£» 
PNODE find_flight(PNODE pHead, char *number);  // ¸ù¾Ýº½°àºÅ²éÕÒº½°à£» 
void print_flight(PNODE pTemp);  // Êä³öµ¥¸öº½°àÐÅÏ¢£»
void browse1(PNODE pHead1);      //ÎÒµÄ¹¦ÄÜ£» 


/*******************ÎÄ¼þ²Ù×÷*******************/
void save_flight(PNODE pHead);   //½«¹ÜÀíÔ±Á´±íÖÐµÄÐÅÏ¢´æÈëÎÄ¼þÖÐ£» 
void load_flight(PNODE pHead);   //½«¹ÜÀíÔ±ÎÄ¼þÖÐµÄÐÅÏ¢µ¼ÈëÁ´±í£» 

void save_flight1(PNODE pHead1); //½«ÓÃ»§Á´±íÖÐµÄÐÅÏ¢´æÈëÎÄ¼þÖÐ£» 
void load_flight1(PNODE pHead1); //½«ÓÃ»§ÎÄ¼þÖÐµÄÐÅÏ¢µ¼ÈëÁ´±í£» 


void menu()
{
	system("color A");
	system("cls");
	printf("\n\n\t\t********************************************************************\n");
	printf("\t\t                         »¶Ó­½øÈëÆ±ÎñÏµÍ³!                          \n");
	printf("\t\t********************************************************************\n");
	printf("\t\t********************************************************************\n");
	printf("\t\t                 Welcome to the ticketing system.                   \n");
	printf("\t\t********************************************************************\n");
	printf("\t\t********************************************************************\n");
	printf("\t\t             ÓÃ»§                               Çë°´1               \n");
	printf("\t\t            ¹ÜÀíÔ±                              Çë°´2               \n");
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
	printf("\n\t\t£¨Äú¹²ÓÐ3´ÎÊäÈë»ú»á£¬ÈôÈ«²¿´íÎóÍÆÇ¿ÖÆÍË³ö³ÌÐò£¡£©\n");
	for (i = 0; i < 3; i++) {
		if (error >= 3) {
			break;
		}
		printf("\n\t\tÇëÊäÈëÃÜÂë£º\n");
		for (j = 0; ; j++) {
			str[j] = getch();
			printf("*");
			if(str[j]=='\r')
			break;
		}
		printf("\n");
		str[j] = '\0';
		if (strcmp(str, "123456") == 0) {
			printf("\n\t\tÃÜÂëÕýÈ·£¡\n");
			menu1_2();                                           //½øÈëÓÃ»§¿ØÖÆ½çÃæ 
			break;
		}
		else {
			error++;
			if (error >= 3) {
				printf("\n\t\tÃÜÂëÊäÈë´ÎÊýÒÑÓÃÍê£¡½«Ç¿ÖÆÍË³ö£¡£¡\n");
				exit(-1);
			}
			printf("\n\t\tÃÜÂë´íÎó£¡Äú»¹ÓÐ%d´Î»ú»á\n", 2 - i);
		}
	}
}

void menu2_1()
{
	system("cls");
	char str[20];
	int i, j, error = 0;
	printf("\n\t\t×ð¾´µÄ¹ÜÀíÔ±£¡»¶Ó­½øÈëÎ÷°²ÓÊµçº½¿ÕÏµÍ³¶©Æ±ºóÌ¨²Ù×÷ÏµÍ³\n");
	printf("\n\t\tÇë°´ÕÕ½ÓÏÂÀ´µÄÌáÊ¾½øÐÐ²Ù×÷£¡\n");
	printf("\n\t\t½ÓÏÂÀ´½«ÊäÈëÃÜÂë£¡\n");
	printf("\n\t\t£¨Äú¹²ÓÐ3´ÎÊäÈë»ú»á£¬ÈôÈ«²¿´íÎóÍÆÇ¿ÖÆÍË³ö³ÌÐò£¡£©\n");
	for (i = 0; i < 3; i++) {
		if (error >= 3) {
			break;
		}
		printf("\n\t\tÇëÊäÈëÃÜÂë£º\n");
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
			menu2_2();                                                 //½øÈë¹ÜÀíÔ±¿ØÖÆ½çÃæ 
			break;
		}
		else {
			error++;
			if (error >= 3) {
				printf("\n\t\tÃÜÂëÊäÈë´ÎÊýÒÑÓÃÍê£¡½«Ç¿ÖÆÍË³ö£¡£¡\n");
				exit(-1);
			}
			printf("\n\t\tÃÜÂë´íÎó£¡Äú»¹ÓÐ%d´Î»ú»á\n", 2 - i);
		}
	}
}


void menu1_2()
{
	system("cls");
	printf("\n\n\t\t|-------------------------------------------|\n");
	printf("\t\t|                 1--ä¯ÀÀ                   |\n");
	printf("\t\t|                 2--¶©Æ±                   |\n");
	printf("\t\t|                 3--ÍËÆ±                   |\n");
	printf("\t\t|                 4--¸ÄÇ©                   |\n");
	printf("\t\t|                 5--²éÑ¯                   |\n");
	printf("\t\t|                 6--ÎÒµÄ                   |\n");
	printf("\t\t|                 0--ÍË³ö                   |\n");
	printf("\t\t|-------------------------------------------|\n");
//	system("pause");
}

void menu2_2()
{
	system("color B");
	system("cls");
	printf("\n\n\t\t|-------------------------------------------|\n");
	printf("\t\t|                 1--Â¼Èëº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 2--ä¯ÀÀº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 3--Ôö¼Óº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 4--É¾³ýº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 5--±£´æº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 6--ÐÞ¸Äº½°àÐÅÏ¢           |\n");
	printf("\t\t|                 0--ÍË³ö                   |\n");
	printf("\t\t|-------------------------------------------|\n");
	
}

//  ´´½¨¹ÜÀíÔ±Í·½Úµã£» 
void Create_flight()
{
	pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead){
		pHead->pNext = NULL;
		pHead->data = 0; 
	}
	return;
}

//´´½¨ÓÃ»§Í·½Úµã£»
void Create_flight1()
{
	pHead1 = (PNODE)malloc(sizeof(NODE));
	if(pHead1){
		pHead1->pNext = NULL;
		pHead1->data = 0;
	}
}

// Îª¹ÜÀíÔ±µ¥¸ö½Úµã·ÖÅäÄÚ´æ£» 
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
// ÎªÓÃ»§µ¥¸ö½Úµã·ÖÅäÄÚ´æ£»
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



//´Ó¹ÜÀíÔ±ÎÄ¼þÖÐ¶ÁÈ¡µ½Á´±íÖÐ;
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

//´ÓÓÃ»§ÎÄ¼þÖÐ¶ÁÈ¡µ½Á´±íÖÐ;
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


//½«¹ÜÀíÔ±Á´±í±£´æµ½ÎÄ¼þÖÐ
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
// ½«ÓÃ»§Á´±í±£´æµ½ÎÄ¼þÖÐ 
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
		printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
		scanf("%s", &pTemp->number);//º½°àºÅ
		scanf("%d", &pTemp->sum);//Æ±Êý
		scanf("%d", &pTemp->price);//Æ±¼Û
		scanf("%s", &pTemp->start);//Æð·ÉµØµã
		scanf("%s", &pTemp->end);//½µÂäµØµã
		scanf("%d %d %d %d %d", &pTemp->t[0].year, &pTemp->t[0].month, &pTemp->t[0].day, &pTemp->t[0].hour, &pTemp->t[0].min);//Æð·ÉÊ±¼ä
		scanf("%d %d %d %d %d", &pTemp->t[1].year, &pTemp->t[1].month, &pTemp->t[1].day, &pTemp->t[1].hour, &pTemp->t[1].min);//½µÂäÊ±¼ä
	
//	PNODE r;
//	for(r=pHead->pNext;r!=NULL;r=r->pNext)
//	{
//		fprintf(fp,"%s %d %d %s %s %d %d %d %d %d %d %d %d", r->number, r->sum, r->price, r->start, r->end, r->t[0].month, r->t[0].day, r->t[0].hour, r->t[0].min, r->t[1].month, r->t[1].day, r->t[1].hour, r->t[1].min);
//	}
//	fclose(fp);
	printf("\n\t\tº½°àÒÑ³É¹¦Â¼Èë£¡\n"); 

	
}

void Browse(PNODE pHead){
	system("cls");
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("\n\n\t\tº½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
		printf("\t\t%s\t", p->number);//º½°àºÅ
		printf("%d\t", p->sum);//Æ±Êý
		printf("%d\t", p->price);//Æ±¼Û
		printf("%s\t\t", p->start);//Æð·ÉµØµã
		printf("%s\t\t", p->end);//½µÂäµØµã
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//Æð·ÉÊ±¼ä
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//½µÂäÊ±¼ä
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
	
	printf("\n\t\tº½°àÒÑ³É¹¦Ôö¼Ó£¡\n"); 
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
		printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
		printf("%s\t", p->number);//º½°àºÅ
		printf("%d\t", p->sum);//Æ±Êý
		printf("%d\t", p->price);//Æ±¼Û
		printf("%s\t\t", p->start);//Æð·ÉµØµã
		printf("%s\t\t", p->end);//½µÂäµØµã
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//Æð·ÉÊ±¼ä
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//½µÂäÊ±¼ä
		printf("\n");
		p = p->pNext;
	}
	
//	system("pause");

}
void browse1(PNODE pHead1){
	system("cls");
	PNODE p = pHead1->pNext;
	while(p != NULL){
		printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
		printf("%s\t", p->number);//º½°àºÅ
		printf("%d\t", p->sum);//Æ±Êý
		printf("%d\t", p->price);//Æ±¼Û
		printf("%s\t\t", p->start);//Æð·ÉµØµã
		printf("%s\t\t", p->end);//½µÂäµØµã
		printf("%d %d %d %d %d\t\t", p->t[0].year, p->t[0].month, p->t[0].day, p->t[0].hour, p->t[0].min);//Æð·ÉÊ±¼ä
		printf("%d %d %d %d %d", p->t[1].year, p->t[1].month, p->t[1].day, p->t[1].hour, p->t[1].min);//½µÂäÊ±¼ä
		printf("\n");
		p = p->pNext;
	}
	
//	system("pause");
}

// Êä³öµ¥¸ö½ÚµãµÄÐÅÏ¢ 
void print_flight(PNODE pTemp){
	if(pTemp == NULL){
		return ;
	}
	printf("\n\n\t\tº½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
	printf("%s\t", pTemp->number);//º½°àºÅ
	printf("%d\t", pTemp->sum);//Æ±Êý
	printf("%d\t", pTemp->price);//Æ±¼Û
	printf("%s\t\t", pTemp->start);//Æð·ÉµØµã
	printf("%s\t\t", pTemp->end);//½µÂäµØµã
	printf("%d %d %d %d %d\t\t", pTemp->t[0].year, pTemp->t[0].month, pTemp->t[0].day, pTemp->t[0].hour, pTemp->t[0].min);//Æð·ÉÊ±¼ä
	printf("%d %d %d %d %d", pTemp->t[1].year, pTemp->t[1].month, pTemp->t[1].day, pTemp->t[1].hour, pTemp->t[1].min);//½µÂäÊ±¼ä
	printf("\n");
	return;	
}

void book(PNODE pTemp){
	
//	system("cls");
	PNODE p = pHead->pNext;
	int i, n = 0, sum = 0;
	int count = 0;
	char arr1[20], arr2[20];
	printf("\n\n\t\tÇ×£¡ÇëÎÊÄúµÄ³ö·¢µØºÍÄ¿µÄµØ·Ö±ðÊÇÄÄÀïÄØ£¿\n\n");
	scanf("%s %s", arr1, arr2);
	while(p != NULL){
		if(strcmp(arr1, p->start) == 0 && strcmp(arr2, p->end) == 0){
			count = p->sum;
		}
		p = p->pNext;
	}
	if(count == 0) {
		printf("\n\n\t\tÇ×! Æ±ºÃÏñÂôÍêÁËÄØ@.@\n"); 
		getch();
		return;
	}
	if(count != 0){
		printf("\n\n\t\tÇ×£¡´Ó %s ·ÉÍù %s µÄ»úÆ±»¹Ê£ %d ÕÅÄØ^.^", arr1, arr2, count);
		printf("\n\n\t\tºÃµÄÄØ!\nÇëÎÊÄúÐèÒª¶àÉÙÕÅ»úÆ±£¿");
		scanf("%d", &n);
		p = pHead->pNext;
		while(p != NULL){
			if(strcmp(arr1, p->start) == 0 && strcmp(arr2, p->end) == 0){
				if(n > p->sum){
					printf("\n\n\t\tÇ×£¡´Ó %s ·ÉÍù %s µÄ»úÆ±Ö»Ê£ %d ÕÅÁËÄØ! ", arr1, arr2, count);
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
		printf("\n\n\t\tÇ×£¡ÄúÐèÖ§¸¶%dÔª ^-^", sum);
		
	}
	
	system("pause");
}

//  ¸ù¾Ýº½°àºÅ²éÑ¯º½°à£» 
PNODE find_flight(PNODE pHead, char *number)
{
	PNODE p = pHead;
	while(strcmp(p->number, number) != 0 && p->pNext != NULL){
		p = p->pNext;
	} 
	
	if(p->pNext == NULL && strcmp(p->number, number) != 0){
		printf("\n\n\t\t±§Ç¸Å¶£¬ Ã»ÓÐ²éµ½´Ëº½°à@.@");
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
		printf("\n\n\t\t±§Ç¸Å¶£¬ Ã»ÓÐ²éµ½´Ëº½°à@.@");
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
					printf("\n\t\tÇ×£¡ÇëÊäÈëÄúÐèÒªÂ¼ÈëµÄº½°àÊýÁ¿^-^ :");
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
					printf("\n\n\t\tÏÖÓÐº½°àÐÅÏ¢:\n");
					Browse(pHead);
					printf("\n\n\t\tÇëÊäÈëÄãÒªÔö¼ÓµÄº½°àÎ»ÖÃ£º");
					scanf("%d", &pos);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄº½°àºÅ£º");
					scanf("%s", &str1);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄ»úÆ±ÊýÁ¿: "); 
					scanf("%d", &val1);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄ»úÆ±¼Û¸ñ: "); 
					scanf("%d",&val2);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄº½°àÆð·ÉµØµã: "); 
					scanf("%s",&str2);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄº½°à½µÂäµØµã: "); 
					scanf("%s",&str3);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄº½°àÆð·ÉÊ±¼ä: ");
					scanf("%d %d %d %d %d", &val11, &val3, &val4, &val5, &val6);//Æð·ÉÊ±¼ä
					printf("\n\n\t\tÇëÊäÈëÄúÒªÔö¼ÓµÄº½°à½µÂäÊ±¼ä: "); 
					scanf("%d %d %d %d %d", &val12, &val7, &val8, &val9, &val10);//½µÂäÊ±¼ä
					
					Increase(pHead, pos, val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, str1, str2, str3);
				}
				else if(num1 == 4){
					Browse(pHead);
					printf("\n\n\t\tÄú½«½øÐÐÉ¾³ýº½°àµÄ²Ù×÷£º"); 
					printf("\n\n\t\tÇëÊäÈëÄãÒªÉ¾³ýµÄº½°àÎ»ÖÃ£º");
					scanf("%d", &pos);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÉ¾³ýµÄº½°àºÅ£º");
					scanf("%s", &str1);
					Delete(pHead, pos, &pVal1, &pVal2, &pVal3, &pVal4, &pVal5, &pVal6, &pVal7, &pVal8, &pVal9, &pVal10, &pVal11, &pVal12, pStr1, pStr2, pStr3);
				}
				else if(num1 == 5){
					save_flight(pHead);
					printf("\n\n\t\tÒÑ³É¹¦±£´æ%d£¡Ìõº½°àÐÅÏ¢¡£", pHead->data); 
					getch();
				}
				else if(num1 == 6){
					printf("\n\n\t\tÇëÊäÈëÄúÐèÒªÐÞ¸ÄµÄº½°àºÅ£º");
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
				if(num1 == 1){                // ä¯ÀÀ 
					browse(pHead);
					getch();
				}  
				else if(num1 == 2){           //¶©Æ± 
					browse(pHead);
					pTemp = add_flight1(pHead1); 
					book(pTemp);
				//	save_flight1(pHead1);
					printf("\n\n\t\tÄúµÄÐÅÏ¢ÒÑ±£´æ£¡");
					getch();
					
				}
				else if(num1 == 3){           //ÍËÆ± 
					browse1(pHead1);
					printf("\n\n\t\tÇëÊäÈëÄúÒªÍË¶©µÄº½°àÎ»ÖÃ£º");
					scanf("%d", &pos);
					refund(pHead1, pos, &pVal1, &pVal2, &pVal3, &pVal4, &pVal5, &pVal6, &pVal7, &pVal8, &pVal9, &pVal10, &pVal11, &pVal12, pStr1, pStr2, pStr3);
				//	save_flight1(pHead1);
					printf("\n\n\t\tÍËÆ±³É¹¦£¡");
					getch(); 
				}
				else if(num1 == 4){           //¸ÄÇ© 
					browse1(pHead1);
					printf("\n\n\t\tÇëÊäÈëÄúÐèÒª¸ü¸ÄµÄº½°àºÅ£º");
					scanf("%s", number);
					printf("\n\n\t\tÇëÊäÈëÐÂµÄº½°àÐÅÏ¢Å¶^.^");
					pTemp = find_flight1(pHead1, number); 
					book(pTemp); 
				//	save_flight1(pHead1);
					printf("\n\n\t\tÄúÒÑ³É¹¦¸ÄÇ©£¡");
					getch();
				}
				else if(num1 == 5){           //²éÑ¯ 
					printf("\n\n\t\tÇëÊäÈëÐèÒª²éÕÒµÄº½°àºÅ£º");
					scanf("%s", number);
					pTemp = find_flight(pHead, number);
					print_flight(pTemp);
					getch();
				} 
				else if(num1 == 6){           //ÎÒµÄ 
					browse1(pHead1);
					getch(); 
				}
				else if(num1 == 0){           //ÍË³ö 
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
