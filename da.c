#include<stdio.h>

#include<math.h>

#include<conio.h>

#include<windows.h>

#include<stdlib.h>

#include<string.h>
//������Ϣ����Ľ��ṹ
struct node
{
      
    struct node *next;
};


typedef struct node NODE;

double principal=0,mount=0;

int year=0;

int n=1;

double rate;

 void meu()
 {
printf("|----------------------------------------|\n");

printf("|          0.����                        |\n");

printf("|          1.��������                    |\n");

printf("|          2.��������                    |\n");
	
printf("|          3.���㱾��                    |\n");

printf("|          4.���޼���                    |\n");

printf("|          5.���ʹ���                    |\n");

printf("|          6.�ȶͶ                    |\n");

printf("|          7.�ȶ��                    |\n");

printf("|          8.������Ϣ                    |\n");

printf("|          9.��¼��ʾ                    |\n");

printf("|----------------------------------------|\n");
 } 

void danli(){

		printf("������ı���");

p:scanf("%lf",&principal);

  if(principal<=0){

printf("���������0�ı���\n");

goto  p;
  }

else

{
printf("���������ޣ�");

o:scanf("%d",&year);

if(year<=0||year>100){

printf("������Ϸ�������(1--100)\n");
goto o;
}
  else
  {
	  printf("�����������ʣ�");

    scanf("%lf",&rate);

    mount=principal+principal*rate*year;

    printf("��ϢΪ��%.2lf\n",mount);


  }

}


}

void fuli(){

 

p:printf("�����뱾��");

    scanf("%lf",&principal);

	 if(principal<=0){

printf("���������0�ı���\n");

goto  p;
	 }
else
{
    printf("���������ޣ�");

o: scanf("%d",&year);
	if(year<=0||year>100){

printf("������Ϸ�������(1--100)\n");
goto o;
}
  else
  {

    printf("�����������ʣ�");

    scanf("%lf",&rate);

    printf("�������긴������:");

    scanf("%d",&n);

    rate=pow((1+rate/n),n)-1;

    mount=principal*pow((1+rate),year);

    printf("��ϢΪ��%.2lf\n",mount);

}

}

}

void principaljisuan(){

    printf("���������������棺");

    scanf("%lf",&mount);  

o:printf("���������ޣ�");

    scanf("%d",&year);
		if(year<=0||year>100){

printf("������Ϸ�������(1--100)\n");
goto o;
}
  else
  {

    printf("�����������ʣ�");

    scanf("%lf",&rate);

    printf("�������긴������:");

    scanf("%d",&n);

    rate=pow((1+rate/n),n)-1;

    principal=mount/pow((1+rate),year);

    printf("������豾��Ϊ��%.2lf\n",principal);

 

}

}
void time()
{
    int flat=0;
    
    printf("�����뱾����:"); 

    scanf("%lf",&mount); 

    printf("��������ر���:");
	
    scanf("%lf",&rate);
	
p:printf("�����뱾��:"); 

    scanf("%lf",&principal);

	 if(principal<=0){

printf("���������0�ı���\n");

goto  p;
	 }
else
{
    for(n=1;n<100;n++)    //��ٷ���100������ļ�Ϣ����
    {
        if((principal*(pow((1+rate),n)))>=mount)
        {
            printf("��Ϣ����:%d\n\n",n);

            flat=1;

            break;

        }
    }
    if(flat==0)

        printf("��100����û�з��ϼ�Ϣ����!\n\n");
    
}

}
void lilv()
{
    
    printf("�����뱾����:"); 

    scanf("%lf",&mount); 

    printf("�����븴���������꣩:"); 

    scanf("%d",&year); 

p:printf("�����뱾��:");
  
    scanf("%lf",&principal);

	 if(principal<=0){
printf("���������0�ı���\n");

goto  p;
	 }
else
{
    rate=pow(mount/principal, 1.0/year)-1;

    printf("������Ϊ:%lf\n",rate);
}
}
void yearmount()//���������ֵ
 {
  int n;
p:printf("���뱾��:");

     scanf("%lf",&principal);

	  if(principal<=0){

printf("���������0�ı���\n");

goto  p;
	 }
else
{
    printf("��������:");

o:scanf("%d",&year);

		if(year<=0||year>100){

printf("������Ϸ�������(1--100)\n");

goto o;
}
  else
  {

     printf("������:");

     scanf("%lf",&rate);

     printf("\t\t1:����Ͷ��\n\t\t2:����Ͷ��\n");

 A:printf("��ѡ����Ҫ�Ĺ���<1|2>:");

   scanf("%d",&n);

   if(n==1)
   {
       mount=principal*(pow(1+rate,year)-1)/rate;
      
   }
   else if(n==2)
   {
       mount=principal*12*(1+rate)*(pow(1+rate,year)-1)/rate;
   }
   else
   {
       printf("��������!����������\n");
       goto A;

   }
   printf("%d�����ܲ�ֵ:%.4lf\n",year,mount);
  
 }
}
}
 void huankuan()
 {

     printf("������:");

     scanf("%lf",&mount);

     printf("��������:");

     scanf("%d",&year);

    printf("������:");

     scanf("%lf",&rate);

     principal=mount*rate/(12*(1-rate)*(pow(1-rate,year)-1));

    printf("����%.4lfÿ����Ҫ����%.4lf\n",mount,principal);
 }

//*������Ϣ
void Save(NODE *head)
{
    FILE *fp ; 
    NODE *p;
    int count=0,flag=1 ;
    fp=fopen("d:\\employee.txt","wb");//ָ�뷽ʽ�򿪶������ļ� //
    if(fp==NULL)
    {
        printf("�ļ��򲻿�!");
        return ;
    }
    p=head->next ;
    while(p)
    {
        if(fwrite(p,sizeof(NODE),1,fp)==1)
        {
            p=p->next ;
            count++;
        }
        else
        {
            flag=0 ;
            break ;
        }
    }
   fprintf(fp,"%d",mount);
    fclose(fp);
}

void show(NODE *head)
{


   FILE *fp = fopen("employee.txt", "rb");
int c;
while((c=fgetc(fp))!=EOF)
 putchar(c);
	  }
	 

 main(){

    FILE *fp;
	int k;
	char ch1;
 	NODE *head,*p,*q;
	k=1;
	head=(NODE *)malloc(sizeof(NODE));//������
	head->next=NULL;//��ʼ��
	q=head;
	fp=fopen("d:\\employee.txt","ab+");//��ֻд�ķ�ʽ���򿪶������ļ�
	if(fp==NULL)
	{
		printf("�򲻿��ļ�!");
	}
	 while(!feof(fp))
    {
           p=(NODE*)malloc(sizeof(NODE));
        if(fread(p,sizeof(NODE),1,fp)==1)/*��ָ�������ļ���ȡ��¼*/
        {
            p->next=NULL;
            q->next=p ;/*��������*/
            q=p ;

        }
		
    }
 fprintf(fp,"%d",mount);
    fclose(fp);//�ر��ļ�
    
     while(1){
    int num=0;
meu();

printf("������ѡ��");

scanf("%d",&num);
if(num==0) 
	  {
		  printf("\n���ļ���Ϣ�Ѿ��仯!�����Ƿ񱣴���?(y/n)  ");
			getchar();
            scanf("%c",&ch1);
            if(ch1=='y'||ch1=='Y')
            {
	            Save(head);
            }
            printf("\n��ӭ�ٴθ�������ϵͳ!\n");
            break;
        }

switch(num){
	case 0:
		num=0;system("cls");/*����*/
		break;

case 1:

    fuli(); 

    break;

case 2:

   danli();

    break;

case 3:

    principaljisuan();

break;
 case 4:

     time();
            
 break;

 case 5:

   lilv();

    break;
case 6:

   yearmount();

    break;

    case 7:

   huankuan();

    break;

	case 8:

Save(head);

	break;
    
	case 9:

	show(head);

		break;
}
getch();
 }
 }
