#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#define LEN sizeof (Flight)
#define M 2018
#define N 15

typedef struct Time
{
    int month;
    int day;
    int hour;
    int minute;
} Time;

typedef struct Flight
{
    char origin[15];
    char terminal[15];
    Time time[2];
    char number[8];   //º½°à
    int total;       //×Ü×ùÎ»Êý
    double price;   //Æ±¼Û
} Flight;

//²Ëµ¥º¯ÊýÓë¿ÚÁîÑéÖ¤
void menu();
void menu1();
void menu2();
void menuA();
void menuB();
void PasswordVerificationA();
void PasswordVerificationB();
//¹ÜÀíÔ±µÄÏà¹Øº¯Êý
void Enter();
void planeAdd();
void Browse();
void Delete();
//ÓÃ»§µÄÏà¹Øº¯Êý
void book();
void refund();
void change();
void Inquire();
void InquireByPlace();
void InquireByPrice();


int main()
{
    int a[10];
        printf("********************************************************************\n");
        printf("                         »¶Ó­½øÈëÆ±ÎñÏµÍ³!                          \n");
        printf("********************************************************************\n");
    menu();
    return 0;
}  

//Ö÷½çÃæ
void menu()
{
    int n;
    printf("*************************************************\n");
    printf("     ¹ÜÀíÔ±                            Çë°´0     \n");
    printf("     ÂÃ¿Í                              Çë°´1     \n");
    printf("*************************************************\n");
    scanf("%d",&n);
    if(n==0)
        PasswordVerificationA();
    if(n==1)
        PasswordVerificationB();
}
//Íê³É¹ÜÀíÔ±¿ÚÁîÑéÖ¤½øÈëÏµÍ³
void PasswordVerificationA()
{
    system("cls");
    static int error;
    char a[7];
    int i,j;
        printf("ÇëÊäÈëÃÜÂë:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<6;j++)
        {
            a[j]=getch();
            printf("*");
        }
        printf("\n");
        a[j]='\0';
       if(strcmp(a,"123456")==0)//ÅÐ¶ÏÃÜÂëÊÇ·ñÕýÈ·
          menu1();         //½øÈë¹ÜÀíÔ±²Ù×÷½çÃæ
       else
       {
            printf("ÊäÈëÃÜÂë´íÎó!\n\n");
            error++;
           if(error>=3)
           {
                printf("·Ç·¨ÓÃ»§£¡\n");
                return;
           }
       }
    }
}
void menu1()
{
   system("cls");
   int a;
        printf("ÊÇ·ñ¼ÌÐø,¼ÌÐøÇë°´0,ÍË³öÇë°´1\n");
   scanf("%d",&a);
   if(a==0)
      menuA();
   if(a==1)
      menu();
}

//Íê³ÉÓÃ»§¿ÚÁîÑéÖ¤½øÈëÏµÍ³£¬ÐÞ¸ÄÑéÖ¤Âë
void PasswordVerificationB()
{
    int i;
    system("cls");
    static int error;
    char arr[5],arr1[5],str;
    for(i=0;i<4;i++)
    {
        str=rand()%(26)+65;
        arr[i]=str;
    }
	arr[i]='\0';
	puts(arr);
    printf("ÇëÊäÈëÑéÖ¤Âë:\n");
    scanf("%s",arr1);              //ÅÐ¶ÏÊäÈëµÄÑéÖ¤ÂëÊÇ·ñÕýÈ·
    if(strcmp(arr1,arr)==0)
        menu2();                   //½øÈëÂÃ¿Í½çÃæ
    else
    {
      printf("ÊäÈëÃÜÂë´íÎó!\n\n");
      error++;
      if(error>=5)
     {
        printf("·Ç·¨ÓÃ»§£¡\n");
        return;
     }
    }
}

void menu2()
{
   system("cls");
   int a;
   printf("ÊÇ·ñ¼ÌÐø,¼ÌÐøÇë°´1,ÍË³öÇë°´2\n");
   scanf("%d",&a);
   if(a==1)
     menuB();
   if(a==2)
     menu();
}
//¹ÜÀíÔ±½çÃæº¯Êý
void menuA()
{
    system("cls");
    int n;
    printf("|------------------------------------------|\n");
    printf("|             1.Â¼Èëº½°àÐÅÏ¢               |\n");
    printf("|------------------------------------------|\n");
    printf("|             2.Ôö¼Óº½°àÐÅÏ¢               |\n");
    printf("|------------------------------------------|\n");
    printf("|             3.ä¯ÀÀº½°àÐÅÏ¢               |\n");
    printf("|------------------------------------------|\n");
    printf("|             4.É¾³ýº½°àÐÅÏ¢               |\n");
    printf("|------------------------------------------|\n");
    printf("|             5.ÍË³ö´Ë½çÃæ                 |\n");
    printf("|------------------------------------------|\n");
    printf("ÇëÊäÈëÄãµÄÑ¡Ôñ£º\n");
    scanf("%d",&n);
    switch(n)
    {
     case 1:
        Enter();
        break;
     case 2:
       planeAdd();
        break;
     case 3:
        Browse();
        break;
     case 4:
        Delete();
        break;
     case 5:
        menu();
        break;
     default:
        printf("ÎÞ´ËÑ¡Ôñ!\n");
    }

}


//ÓÃ»§½çÃæº¯Êý
void menuB()
{
    system("cls");
    int i;
    printf("|^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*|\n");
    printf("|      1.ä¯ÀÀ                 2.²éÑ¯               |\n");
    printf("|^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*|\n");
    printf("|      3.¶©Æ±                 4.ÍËÆ±               |\n");
    printf("|^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*|\n");
    printf("|      5.¸ÄÇ©                 6.ÍË³ö               |\n");
    printf("|^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*|\n");
    printf("ÇëÊäÈëÄãµÄÑ¡Ôñ:\n\n");
    scanf("%d",&i);
    switch(i)
    {
     case 1:
        Browse();
        menu();
        break;
     case 2:
        Inquire();
        break;
     case 3:
        book();
        break;
     case 4:
        refund();
        break;
     case 5:
        change();
        break;
     case 6:
        menu();
        break;
     default :
       printf("ÎÞ´ËÑ¡Ôñ!\n");
    }
}


//º¯Êý¹¦ÄÜ£º·ÖÐÐÊäÈë¼ÇÂ¼£¬²¢ÇÒ´æ´¢µ½ÎÄ¼þÖÐ
void Enter()
{
    Flight array1[M];
    system("cls");
    int i,j,n,m;
    FILE *fp;
    fp=fopen("C:\\c\\flight.dat","wb");
    if(fp==NULL)
    {
        printf("ÎÄ¼þ´íÎó£¬ÎÞ·¨´ò¿ª£¡\n");
        exit(1);
    }
    do
    {
        printf("ÊäÈëÐèÒªÔö¼ÓµÄ¼ÇÂ¼Êý£º\n");
        scanf("%d",&n);
    }
    while(n<=0);
    {
        printf("ÇëÊäÈëÐèÒªÔö¼ÓµÄ¼ÇÂ¼:\n");
    }
    for(i=0; i<n; i++)
    {
        printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
        scanf("%s %d %lf %s %s %d %d %d %d %d %d %d %d",&array1[i].number,&array1[i].total,&array1[i].price,array1[i].origin,array1[i].terminal,&array1[i].time[0].month,&array1[i].time[0].day,&array1[i].time[0].hour,&array1[i].time[0].minute,&array1[i].time[1].month,&array1[i].time[1].day,&array1[i].time[1].hour, &array1[i].time[1].minute);        //ÒÀ´Î¶ÁÈëÃ¿Ò»Ìõ¼ÇÂ¼µÄÃ¿Ò»¸ö³ÉÔ±
        fwrite(&array1[i], sizeof(Flight), 1, fp);
    }
    fclose(fp);
    menu();
}


void planeAdd()
{
    system("cls");
	int x, k = 1;
	Flight planeadd;
	FILE *fp;
	do
	{
        printf("\nÇë°´ÏÂÃæÌáÊ¾ÊäÈëÐÂÔöº½°àÐÅÏ¢:\n");
        printf("ÇëÊäÈëº½°àºÅ:\n");
        scanf("%s", planeadd.number);
        printf("ÇëÊäÈë»úÆ±×ÜÊý:\n");
        scanf("%d", &planeadd.total);
        printf("ÇëÊäÈë¼Û¸ñ:\n");
        scanf("%lf", &planeadd.price);
        printf("ÇëÊäÈëÆðµã:\n");
        scanf("%s", planeadd.origin);
        printf("ÇëÊäÈëÖÕµã:\n");
        scanf("%s", planeadd.terminal);
        printf("ÇëÊäÈëÆð·ÉÊ±¼ä:\n");
        scanf("%d%d%d%d",&planeadd.time[0].month,&planeadd.time[0].day,&planeadd.time[0].hour,&planeadd.time[0].minute);
        printf("ÇëÊäÈë½µÂäÊ±¼ä:\n");
        scanf("%d%d%d%d",&planeadd.time[1].month,&planeadd.time[1].day,&planeadd.time[1].hour,&planeadd.time[1].minute);
        if ((fp = fopen("C:\\c\\flight.dat", "ab+")) == NULL)
		{
           printf("ÎÄ¼þ´íÎó£¬ÎÞ·¨´ò¿ª£¡\n");
           exit(0);
		}
		fseek(fp, LEN, 2);
		fwrite(&planeadd, LEN, 1, fp);
		fclose(fp);
        printf("\nÔö¼ÓÐÅÏ¢³É¹¦!!!");
        printf("\nÊÇ·ñ¼ÌÐøÔö¼Óº½°à£¿¼ÌÐøÇëÊäÈë1£¬·ñÔòÊäÈë0·µ»ØÖ÷²Ëµ¥¡£");
        scanf("%d", &x);
		while (x != 0 && x != 1)
		{
            printf("\nÄúµÄÊäÈëÓÐÎó£¬ÇëÖØÐÂÊäÈë0»ò1£¡\n");
			scanf("%d", &x);
		}
		if (x == 0)
		{
			menu1();
			k = 0;
		}
		if (x == 1)
			k = 1;
	} while (k);
}
//º¯Êý¹¦ÄÜ£ºä¯ÀÀÎÄ¼þ£¬²¢½«¼ÇÂ¼´æ´¢µ½Êý×éÖÐ
void Browse()                              //¶ÁÈ¡ÎÄ¼þ
{
    system("cls");
    FILE*fp;
    Flight array1[M];
    fp=fopen("C:\\c\\flight.txt","rb");      
    if(fp==0)                           
    {
        printf("ÎÄ¼þ´íÎó£¬ÎÞ·¨´ò¿ª£¡\n");
        exit(1);
    }
    fread(&array1[0], LEN, 1, fp);
    while(!feof(fp))
    {
         printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
         printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[0].number,array1[0].total,array1[0].price,array1[0].origin,array1[0].terminal,array1[0].time[0].month,array1[0].time[0].day,array1[0].time[0].hour,array1[0].time[0].minute,array1[0].time[1].month,array1[0].time[1].day,array1[0].time[1].hour,array1[0].time[1].minute);
        fread(&array1[0], LEN, 1, fp);
    }
    fclose(fp);
    menu();
}
void  Delete()
{
    system("cls");
	FILE *fp;
	int total = 0;
	int i = 0;
	int del = 0;
	Flight b[M];
	char str1[8],str2[15],str3[15];
    int month,day,hour,minute;
	fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
		printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª.\n");
		exit(0);
	}
    printf("ÇëÊäÈëÒªÉ¾³ýµÄº½°àºÅ,Æð·ÉµØµã,½µÂäµØµã,Æð·ÉÊ±¼ä: \n");
    scanf("%s%s%s%d%d%d%d",str1,str2,str3,&month,&day,&hour,&minute);
	fread(&b[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&b[total], LEN, 1, fp);
    }
    for (i = 0; i<total; i++)
		if (strcmp(b[i].number,str1)==0&&strcmp(b[i].origin,str2)==0&&strcmp(b[i].terminal,str3)==0)
            if(b[i].time[0].month==month&&b[i].time[0].day==day)
                if(b[i].time[0].hour==hour&&b[i].time[0].minute==minute)
			         break;
	for (; i<total; i++)
	{
		b[i]=b[i+1];
		del=1;
	}
	if(del)
    {
        printf("\n³É¹¦É¾ÐÅÏ¢£¡\n");
    }
    if (del == 0)
	{
        printf("ÏµÍ³ÖÐ²»´æÔÚÒªÉ¾³ýµÄº½°à£¡\n");
		menu();
	}
	fclose(fp);
	fp = fopen("C:\\c\\flight.dat", "wb+");
	if (fp == NULL)
	{
		printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
	for (i = 0; i<total; i++)
    {
     fwrite(&b[i], LEN,1, fp);
    }
	fclose(fp);
	menu();
}
//ÓÃ»§¶©Æ±£¬²¢Êä³ö¶©Æ±ºóµÄº½°àºÅÐÅÏ¢
void book()
{
    system("cls");
    int num,i;
    int sign=0,j=0,total=0;
    char str1[8],str2[15],str3[15];
    int month,day,hour,minute;
    Flight b[M];
    FILE *fp;
    fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
        printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
    printf("ÇëÊäÈëÄãµÄº½°àºÅ¡¢Æð·ÉµØµã¡¢½µÂäµØµã¡¢Æð·ÉÊ±¼ä:\n");
    scanf("%s%s%s%d%d%d%d",str1,str2,str3,&month,&day,&hour,&minute);
    do
    {
        printf("ÇëÊäÈë¶©Æ±µÄÕÅÊý:\n");
        scanf("%d",&num);
    }while(num<=0);
    fread(&b[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&b[total], LEN, 1, fp);
    }
	for (i=0;i<total;i++)
    {
        if (strcmp(b[i].number,str1)==0&&strcmp(b[i].origin,str2)==0&&strcmp(b[i].terminal,str3)==0)
            if(b[i].time[0].month==month&&b[i].time[0].day==day)
                if(b[i].time[0].hour==hour&&b[i].time[0].minute==minute)
                {
                    if(b[i].total<num)
                    {
                        printf("·Ç³£±§Ç¸£¡ÓàÆ±²»×ã£¬Çë¸ü¸Ä£¡\n");
                        menuB();
                    }
                    else
                    {
                        b[i].total=b[i].total-num;
                        sign=1;
                        break;
                    }
                }

    }
	if(sign)
    {
        printf("¶©Æ±³É¹¦!\n");
        printf("¶©Æ±Ö®ºó£¬¸Ãº½°àµÄÐÅÏ¢ÈçÏÂ£º\n");
        printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
        printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",b[i].number,b[i].total,b[i].price,b[i].origin,b[i].terminal,b[i].time[0].month,b[i].time[0].day,b[i].time[0].hour,b[i].time[0].minute,b[i].time[1].month,b[i].time[1].day,b[i].time[1].hour,b[i].time[1].minute);
    }
    else
    {
        printf("ÄúÊäÈëµÄ¶©Æ±º½°àÐÅÏ¢ÓÐÎó£¡ÇëÖØÐÂÊäÈë£¡\n\n\n");
    }
    fclose(fp);
	fp = fopen("C:\\c\\flight.dat", "wb+");
	if (fp == NULL)
	{
		printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
	for (i = 0; i<total; i++)
    {
     fwrite(&b[i], LEN,1, fp);
    }
	fclose(fp);
    menu();
}



//ÍËÆ±º¯Êý
void refund()
{
    system("cls");
    Flight array1[M];
    int num,i;
    int total=0,j=0,sign=0;
    char str1[8],str2[15],str3[15];
    int month,day,hour,minute;
    FILE *fp;
    fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
        printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
    printf("ÇëÊäÈëÄãµÄº½°àºÅ¡¢Æð·ÉµØµã¡¢½µÂäµØµã¡¢Æð·ÉÊ±¼ä:\n");
    scanf("%s%s%s%d%d%d%d",&str1,&str2,&str3,&month,&day,&hour,&minute);
    do
    {
        printf("ÇëÊäÈëÍËÆ±µÄÕÅÊý:\n");
        scanf("%d",&num);
    }while(num<=0);
    fread(&array1[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&array1[total], LEN, 1, fp);
    }
	for (i=0;i<total;i++)
    {
        if (strcmp(array1[i].number,str1)==0&&strcmp(array1[i].origin,str2)==0&&strcmp(array1[i].terminal,str3)==0)
            if(array1[i].time[0].month==month&&array1[i].time[0].day==day)
                if(array1[i].time[0].month==month&&array1[i].time[0].minute==minute)
                {
                    array1[i].total+=num;
                    sign=1;
                    break;
                }
    }
	if(sign)
    {
        printf("ÍËÆ±³É¹¦!\n\n");
         printf("Successful refund!\n\n");
         printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
        printf("flight\total\tprice\ttake-off place\tlanding place\ttake-off time\tlanding time\n");
        printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[i].number,array1[i].total,array1[i].price,array1[i].origin,array1[i].terminal,array1[i].time[0].month,array1[i].time[0].day,array1[i].time[0].hour,array1[i].time[0].minute,array1[i].time[1].month,array1[i].time[1].day,array1[i].time[1].hour,array1[i].time[1].minute);
    }
    else
    {
        printf("ÄúÊäÈëµÄ¶©Æ±º½°àÐÅÏ¢ÓÐÎó£¡ÇëÖØÐÂÊäÈë£¡\n\n\n");
    }
     fclose(fp);
	fp = fopen("C:\\c\\flight.dat", "wb+");
	if (fp == NULL)
	{
		printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
	for (i = 0; i<total; i++)
    {
     fwrite(&array1[i], LEN,1, fp);
    }
	fclose(fp);
    menu();
}

//¸ÄÇ©
void change()
{
    system("cls");
    Flight array1[M];
    int num,i;
    int total=0,j=0,sign=0;
    char str1[8],str2[15],str3[15];
    int month,day,hour,minute;
    FILE *fp;
    fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
        printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
    printf("ÇëÊäÈëÄãµÄº½°àºÅ¡¢Æð·ÉµØµã¡¢½µÂäµØµã¡¢Æð·ÉÊ±¼ä:\n");
    scanf("%s%s%s%d%d%d%d",str1,str2,str3,&month,&day,&hour,&minute);
    do
    {
        printf("ÇëÊäÈëÍËÆ±µÄÕÅÊý:\n");
        scanf("%d",&num);
    }while(num<=0);
    fread(&array1[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&array1[total], LEN, 1, fp);
    }
	for (i=0;i<total;i++)
    {
        if (strcmp(array1[i].number,str1)==0&&strcmp(array1[i].origin,str2)==0&&strcmp(array1[i].terminal,str3)==0)
            if(array1[i].time[0].month==month&&array1[i].time[0].day==day)
                if(array1[i].time[0].hour==hour&&array1[i].time[0].minute==minute)
                {
                    array1[i].total+=num;
                    sign=1;
                    break;
                }
    }
	if(sign)
    {
        printf("ÍËÆ±³É¹¦!\n\n");
        printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
        printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[i].number,array1[i].total,array1[i].price,array1[i].origin,array1[i].terminal,array1[i].time[0].month,array1[i].time[0].day,array1[i].time[0].hour,array1[i].time[0].minute,array1[i].time[1].month,array1[i].time[1].day,array1[i].time[1].hour,array1[i].time[1].minute);
    }
    else
    {
        printf("ÄúÊäÈëµÄ¶©Æ±º½°àÐÅÏ¢ÓÐÎó£¡ÇëÖØÐÂÊäÈë£¡\n\n\n");
    }
    printf("ÇëÊäÈëÄãÐÂµÄº½°àºÅ¡¢Æð·ÉµØµã¡¢½µÂäµØµã¡¢Æð·ÉÊ±¼ä:\n");
    scanf("%s%s%s%d%d%d%d",str1,str2,str3,&month,&day,&hour,&minute);
    do
    {
        printf("ÇëÊäÈë¶©Æ±µÄÕÅÊý:\n");
        scanf("%d",&num);
    } while(num<=0);
    for (i=0;i<total;i++)
    {
        if (strcmp(array1[i].number,str1)==0&&strcmp(array1[i].origin,str2)==0&&strcmp(array1[i].terminal,str3)==0)
            if(array1[i].time[0].month==month&&array1[i].time[0].day==day)
                if(array1[i].time[0].hour==hour&&array1[i].time[0].minute==minute)
                {
                    if(array1[i].total<num)
                    {
                        printf("·Ç³£±§Ç¸£¡ÓàÆ±²»×ã£¬Çë¸ü¸Ä£¡\n");
                        menuB();
                    }
                    else
                    {
                        array1[i].total=array1[i].total-num;
                        sign=1;
                        break;
                    }
                }

    }
	if(sign)
    {
        printf("¶©Æ±³É¹¦!\n");
        printf("¶©Æ±Ö®ºó£¬¸Ãº½°àµÄÐÅÏ¢ÈçÏÂ£º\n");
        printf("º½°àºÅ\tÆ±Êý\tÆ±¼Û\tÆð·ÉµØµã\t½µÂäµØµã\tÆð·ÉÊ±¼ä\t½µÂäÊ±¼ä\n");
        printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[i].number,array1[i].total,array1[i].price,array1[i].origin,array1[i].terminal,array1[i].time[0].month,array1[i].time[0].day,array1[i].time[0].hour, array1[i].time[0].minute,array1[i].time[1].month,array1[i].time[1].day,array1[i].time[1].hour,array1[i].time[1].minute);
    }
    else
    {
        printf("ÄúÊäÈëµÄ¶©Æ±º½°àÐÅÏ¢ÓÐÎó£¡ÇëÖØÐÂÊäÈë£¡\n\n\n");
    }
    fclose(fp);
	fp = fopen("C:\\c\\flight.dat", "wb+");
	if (fp == NULL)
	{
		printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª.");
		exit(0);
	}
	for (i = 0; i<total; i++)
    {
     fwrite(&array1[i], LEN,1, fp);
    }
	fclose(fp);
    menu();
}

//º¯Êý¹¦ÄÜ£º°´ÕÕÓÃ»§Ö¸¶¨µÄ·½Ê½²éÑ¯
void Inquire()
{
    system("cls");
    printf("|-------------------------------------------------------------------|\n");
    printf("|                   1.°´ÕÕÆðµãºÍÖÕµã²éÑ¯                            |\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("|                   2.°´ÕÕÆ±¼Û²éÑ¯                                  |\n");
    printf("|-------------------------------------------------------------------|\n");
    int choice;
    printf("ÇëÊäÈëÄúµÄÑ¡Ôñ\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:InquireByPlace();
               break;
        case 2:InquireByPrice();
               break;
        default:
               printf("ÊäÈëÃüÁî´íÎó£¬ÇëÖØÐÂÊäÈë£¡\n");
            break;

    }
}

//º¯Êý¹¦ÄÜ£º°´ÕÕÆðµãºÍÖÕµã²éÑ¯
void InquireByPlace()
{
    system("cls");
    Flight array1[M];
    int i,j,k,num=0;//i,j,k¿ØÖÆÑ­»·²éÕÒ£¬num±íÊ¾¹Ë¿ÍÓµÓÐµÄÑ¡Ôñ×ÜÊý
    char origin[15],terminal[15];
    int total=0;
    FILE *fp;
    fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
        printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
    fread(&array1[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&array1[total], LEN, 1, fp);
    }
    printf("ÇëÊäÈëÆðµãºÍÖÕµã£º\n");
    scanf("%s%s",origin,terminal);
    for(i=0;i<total;i++)//Íâ²ãÑ­»·£¬ËùÓÐº½°à²éÑ¯Ò»±é
    {
            if(strcmp(array1[i].origin,origin)==0&&strcmp(array1[i].terminal,terminal)==0)//Èç¹û²éÑ¯µ½Æðµã£¬Ôò¼ÌÐø²éÑ¯ÖÕµãÊÇ·ñ´æÔÚ
            {
                    num++;
                    printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[i].number,array1[i].total,array1[i].price,array1[i].origin,array1[i].terminal,array1[i].time[0].month,array1[i].time[0].day,array1[i].time[0].hour,array1[i].time[0].minute,array1[i].time[1].month,array1[i].time[1].day,array1[i].time[1].hour,array1[i].time[1].minute);
                    //break;
            }
    }
    printf("\n");
    if(num>0)
    {
        printf("Äú×Ü¼ÆÓÐ%dÖÖÑ¡Ôñ£¡\n",num);
    }

    else
    {
         printf("·Ç³£±§Ç¸£¡Ã»ÓÐ²éÑ¯µ½ËùÐèº½°à£¡\n");
    }

    menu();
}

//º¯Êý¹¦ÄÜ£º°´ÕÕ¼Û¸ñ²éÑ¯
void InquireByPrice()
{
    system("cls");
    Flight array1[M];
    double low,high;
    int num=0;
    int i;//i±ØÐëÊÇintÐÍ
    int total=0;
    FILE *fp;
    fp = fopen("C:\\c\\flight.dat", "rb+");
	if (fp == NULL)
	{
        printf("ÎÄ¼þÓÐ´íÎó²»ÄÜ´ò¿ª!");
		exit(0);
	}
    fread(&array1[total], LEN, 1, fp);
	while (!feof(fp))
    {
		total++;
		fread(&array1[total], LEN, 1, fp);
    }
    printf("ÇëÊäÈëÄúÔ¤ÆÚµÄ¼Û¸ñÇø¼ä£º\n");
    scanf("%lf%lf",&low,&high);
    for(i=0;i<total;i++)
    {
         if((array1[i].price>=low)&&(array1[i].price<=high))
             {
                  num++;
                  printf("%.2lf-----%.2lf\n",low,high);
                  printf("%s\t%d\t%.2f\t%s\t\t%s\t\t%dÔÂ%dÈÕ %d:%d\t%dÔÂ%dÈÕ %d:%d\n",array1[i].number,array1[i].total,array1[i].price,array1[i].origin,array1[i].terminal,array1[i].time[0].month,array1[i].time[0].day,array1[i].time[0].hour,array1[i].time[0].minute,array1[i].time[1].month,array1[i].time[1].day,array1[i].time[1].hour,array1[i].time[1].minute);
             }
    }
    printf("\n");
    if(num>0)
    {
      printf("Äú×Ü¼ÆÓÐ%dÖÖÑ¡Ôñ£¡\n",num);
    }
    else
    {
      printf("·Ç³£±§Ç¸£¡Ã»ÓÐ²éÑ¯µ½ËùÐèº½°à£¡\n");
    }
    menu();
}


