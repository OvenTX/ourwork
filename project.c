#include "stdio.h"   /*I/O函数*/
#include "stdlib.h" /*标准库函数*/
#include "string.h"/*字符串函数*/
#include "time.h"/*时间函数*/
#define M 100  /*定义常数表示记录数*/

typedef struct /*定义学生基本信息数据结构*/
{

    char name[20];/*学生姓名*/

    char no[20]; /*编号*/

    char sex[20];/*性别*/

    int age;/*年龄*/

    char  remark[20];/*备注*/

}STUDENT;

int  enter(STUDENT t[]);/*输入记录*/

void list( STUDENT t[],int n);/*显示记录*/

void save(STUDENT t[],int n);/*记录保存为文件*/

int find(STUDENT t[],int n,char *s);/*查找--函数*/

void print(STUDENT temp);/*显示--单条记录*/

void revise( STUDENT t[],int n);/*修改记录*/

int  insert(STUDENT t[],int n); /*插入记录*/

int  delete(STUDENT t[],int n);/*删除记录*/

int load(STUDENT t[],int n);/*从文件中读入记录*/

int  menu_select();/*主菜单函数*/

int order();




char password[7]="123456";

int main()

{



    STUDENT student[M];/*定义结构体数组*/

    int length;/*保存记录长度*/

    int flag=0,i;

    int n=3;

    char s[8];

    do

    {

        printf("Enter password(six digit code):\n");

        scanf("%s",s);

        if(!strcmp(s,password))

        {

            printf("PASS\n\n");

            flag=1;

            break;

        }

        else

        {

            printf("Error Enter again:\n");

            n--;

        }

    }while(n>0);

    if(!flag)

    {

        printf("you have Enter 3 times!\n");

        printf("%d",order());
        exit(0);

    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\t   Welcome to the system\n");

    for(;;)

    {

        switch(menu_select())  /*调用主菜单函数，返回值整数作开关语句的条件*/

        {

            case 1:length=enter(student);break;/*输入记录*/

            case 2:list(student,length);break; /*显示全部记录*/

            case 3:save (student,length);break;/*保存文件*/

            case 4:revise(student,length);break;/*修改记录*/

            case 5:length=insert(student,length);break;/*插入记录*/

            case 6:length=delete(student,length);break; /*删除记录*/

            case 7:printf("Please Enter name:\n");
                    scanf("%s",s);
                    printf("%d",find(student,length,s));break;

            case 8:length=load(student,length);break;/*读文件*/


            case 10:exit(0);

        }

    }

}

/*菜单函数，函数返回值为整数，代表所选的菜单项*/
int menu_select()

{

    int c;


    printf("********************MENU*********************\n\n");

    printf("          1. Basic message record\n");

    printf("          2. List all message(has been recored)\n");

    printf("          3. Save all message(into a binary file)\n");

    printf("          4. Revise the message(has been recored)\n");

    printf("          5. Insert message \n");

    printf("          6. Delete message\n");

    printf("          7. Quick seek message by name\n");

    printf("          8. Load records from txt\n");

    printf("          9. Display as number\n");

    printf("         10. Exit out\n");

    printf("***********************************************\n");



    do{

        printf("Enter you choice:");/*提示输入选项*/

        scanf("%d",&c);

    }while(c<1||c>10);/*不在选择范围重新回到界面*/



    return c;

}

/*输入记录，形参为结构体数组，函数值返回类型为整型表示记录长度*/
int  enter(STUDENT t[])

{

    int i,n;



    printf("\nHow many records will you enter? \n"); /*提示信息*/

    scanf("%d",&n); /*输入记录数*/

    printf("please input record \n"); /*提示输入记录*/

    printf("姓名            学号            性别            年龄            备注(以空格分开)\n");

    printf("-------------------------------------------------------------------\n");

    for(i=0;i<n;i++)

    {

        scanf("%s%s%s%d%s",t[i].name,t[i].no,t[i].sex,&t[i].age,t[i].remark);  /*输入记录*/

        printf("-------------------------------------------------------------------\n");

    }

    return n;  /*返回记录条数*/

}

/*显示记录，参数为记录数组和记录条数*/
void list(STUDENT t[],int n)

{

    int i;



    printf("\n\n*****************************STUDENT****************************\n");

    printf("姓名            学号            性别            年龄            备注\n");

    printf("-------------------------------------------------------------------\n");

    for(i=0;i<n;i++)

        printf("%-20s%-20s%-20s%-10d%-10s\n",t[i].name,t[i].no,t[i].sex,t[i].age,t[i].remark);

    if((i+1)%10==0)

    {

        printf("Press any key continue...\n");

        getchar();

    }

    printf("*********************************end********************************\n");

}

/*显示指定的一条记录*/
void print(STUDENT temp)

{



    printf("\n\n*****************************STUDENT****************************\n");

    printf("姓名            学号            性别            年龄            备注\n");

    printf("-------------------------------------------------------------------\n");

    printf("%-20s%-20s%-20s%-10d%-10s\n",temp.name,temp.no,temp.sex,temp.age,temp.remark);

    printf("*******************************end*********************************\n");

}

/*查找记录*/
int find(STUDENT t[],int n,char *s)

{

    int i;

    for(i=0;i<n;i++)

    {

        if(strcmp(s,t[i].name)==0)

            return i;

    }

    return i;

}

/*删除函数，参数为记录数组和记录条数*/
int delete(STUDENT t[],int n)

{

    char s[20];  /*要删除记录的姓名*/

    int ch=0;

    int i,j;

    int flag=0;

    int x=3;

    char a[8];

    do

    {

        printf("Enter password(six digit code):\n");

        scanf("%s",a);

        if(!strcmp(a,password))

        {

            printf("PASS\n\n\n");

            flag=1;

            break;

        }

        else

        {

            printf("Error Enter again:\n");

            x--;

        }

    }while(x>0);

    if(!flag)

    {

        printf("you have Enter 3 times!\n");

        exit(0);

    }


    printf("please deleted name\n"); /*提示信息*/

    scanf("%s",s);/*输入姓名*/

    i=find(t,n,s); /*调用find函数*/

    if(i>n-1)  /*如果i>n-1超过了数组的长度*/

        printf("no found not deleted\n"); /*显示没找到要删除的记录*/

    else

    {

        print(t[i]); /*调用输出函数显示该条记录信息*/

        printf("Are you sure delete it(1/0)\n");  /*确认是否要删除*/

        scanf("%d",&ch);  /*输入一个整数0或1*/

        if(ch==1)  /*如果确认删除整数为1*/

        {

            for(j=i+1;j<n;j++)  /*删除该记录，实际后续记录前移*/

            {

                strcpy(t[j-1].name,t[j].name); /*将后一条记录的学生姓名拷贝到前一条*/

                strcpy(t[j-1].no,t[j].no); /*将后一条记录的编号拷贝到前一条*/

                strcpy(t[j-1].sex,t[j].sex); /*将后一条记录的性别拷贝到前一条*/

                t[j-1].age=t[j].age;; /*将后一条记录的年龄拷贝到前一条*/

                strcpy(t[j-1].remark,t[j].remark); /*将后一条记录的备注拷贝到前一条*/

            }

            n--;  /*记录数减1*/

        }

    }

    return n;  /*返回记录数*/

}

/*插入记录函数，参数为结构体数组和记录数*/
int insert(STUDENT t[],int n)
{

    STUDENT temp;  /*新插入记录信息*/

    int i,j;

    char s[20]; /*确定插入在哪个记录之前*/

    printf("please input record\n");

    printf("\n\n*****************************STUDENT****************************\n");

    printf("姓名            学号            性别            年龄            备注\n");

    printf("-------------------------------------------------------------------\n");

    scanf("%s%s%s%d%s",temp.name,temp.no,temp.sex,&temp.age,temp.remark); /*输入插入信息*/

    printf("-------------------------------------------------------------------\n");

    printf("please input locate name \n");

    scanf("%s",s); /*输入插入位置的姓名*/

    i=find(t,n,s);  /*调用find，确定插入位置*/

    for(j=n-1;j>=i;j--)   /*从最后一个结点开始向后移动一条*/

    {

        strcpy(t[j+1].name,t[j].name); /*当前记录的学生姓名拷贝到后一条*/

        strcpy(t[j+1].no,t[j].no); /*当前记录的编号拷贝到后一条*/

        strcpy(t[j+1].sex,t[j].sex); /*当前记录的性别拷贝到后一条*/

        t[i].age = temp.age; /*将新插入记录的年龄拷贝到第i个位置*/

        strcpy(t[j+1].remark,t[j].remark); /*当前记录的备注拷贝到后一条*/

    }

    strcpy(t[i].name,temp.name); /*将新插入记录的学生姓名拷贝到第i个位置*/

    strcpy(t[i].no,temp.no); /*将新插入记录的编号拷贝到第i个位置*/

    strcpy(t[i].sex,temp.sex); /*将新插入记录的性别拷贝到第i个位置*/

    t[i].age = temp.age; /*将新插入记录的年龄拷贝到第i个位置*/

    strcpy(t[i].remark,temp.remark); /*将新插入记录的备注拷贝到第i个位置*/

    n++;   /*记录数加1*/

    return n; /*返回记录数*/

}

/*保存导出函数，参数为结构体数组和记录数*/
void save(STUDENT t[],int n)

{

    int i;

    char s[]="record.txt";

    FILE *fp;  /*指向文件的指针*/



    printf("Where do you store records?(eg:c:/***/***.txt)");/*选择文件保存位置*/

    scanf("%s",s);



    if((fp=fopen(s,"wb"))==NULL)  /*打开文件，并判断打开是否正常*/

    {

        printf("can not open file\n");/*没打开*/

        exit(1);  /*退出*/

    }

    printf("\nSaving file\n"); /*输出提示信息*/

    fprintf(fp,"%d",n);  /*将记录数写入文件*/

    fprintf(fp,"\r\n");  /*将换行符号写入文件*/

    for(i=0;i<n;i++)

    {

        fprintf(fp,"%-20s%-20s%-20s%-40d%-10s",t[i].name,t[i].no,t[i].sex,t[i].age,t[i].remark);/*格式写入记录*/

        fprintf(fp,"\r\n"); /*将换行符号写入文件*/

    }

    fclose(fp);/*关闭文件*/

    printf("****save success***\n"); /*显示保存成功*/

}

/*修改记录*/
void revise(STUDENT t[],int n)

{

    STUDENT temp;

    char s[20];

    int i;


    int flag=0;

    int x=3;

    char a[8];

    do

    {

        printf("Enter password(six digit code):\n");

        scanf("%s",a);

        if(!strcmp(a,password))

        {

            printf("PASS\n\n\n");

            flag=1;

            break;

        }

        else

        {

            printf("Error Enter again:\n");

            x--;

        }

    }while(x>0);

    if(!flag)

    {

        printf("you have Enter 3 times!\n");

        exit(0);

    }


    printf("please enter  name\n");/*要修改的名字*/

    scanf("%s",s);

    i=find(t,n,s);

    if(i>n-1)

        printf("no   found\n");

    else

        printf("please revise a cord\n");/*要修改的记录*/

    printf("姓名            学号            性别            年龄            备注\n");

    printf("--------------------------------------------------------------\n");

    scanf("%s%s%s%d%s",temp.name,temp.no,temp.sex,&temp.age,temp.remark);

    printf("---------------------------------------------------------------\n");

    strcpy(t[i].name,temp.name);

    strcpy(t[i].no,temp.no);

    strcpy(t[i].sex,temp.sex);

    t[i].age=temp.age;

    strcpy(t[i].remark,temp.remark);

    printf("success!\n");



}

/*从文件中读入记录*/
int load(STUDENT t[],int n)

{

    int i;

    FILE *fp;

    if((fp=fopen("record.txt","rb"))==NULL)

    {

        printf("can not open file\n");/*不能打开文件*/

        exit(1);

    }

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++)

        fscanf(fp,"%20s%20s%20s%40d%10s",t[i].name,t[i].no,t[i].sex,&t[i].age,t[i].remark);

    fclose(fp);

    printf("You have success read data from file!!!\n");/*成功读入*/

    return n;

};

int order()
{
    int n;
    srand((unsigned) time(NULL));
    printf("BOOM!!!!!!!\nEnter num \n");
    scanf("%d",&n);

    return rand() % n+1;

}
