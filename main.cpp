#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;

struct workers
{	
	char jobNo[100];       				//ְ����
	char name[100];       				 //����
	char position[100];   				 //ְ��
	double position_basic_salary;     	   //ְ���������
	double job_allowance;   			 //��λ����
	double other_allowance;    			  //��������
	double bonus;   					//����
	double income_tax;        			//����˰
	double housing_fund;    			//ס��������
	double oldage_pension;  		 // ���Ͻ�
	double medical_insurance; 		  //ҽ�Ʊ���
	double unemployment_insurance; 		 // ʧҵ����
    double gross_pay;   				 //Ӧ������
    double net_pay;      				// ʵ������
};


//���Ͷ������
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;


///�����Ϣ����
///worker ��ͷָ��
void Add(Node *worker)
{
	Node *p, *q;
	char n[10];
	q = worker;
	int cnt=0;
	while (q->next != NULL)
	{
		q = q->next;
	}
	while(1){
	    printf("��ʾ������0�������˵���\n");
		printf("������ְ���ţ�");
		scanf("%s", n);//getchar();
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);
		
		cnt++;
		
		printf("������������");
		scanf("%s", p->data.name);
		printf("������ְ��");
		scanf("%s", p->data.position);
		printf("������ְ��������ʣ�");
		scanf("%lf", &p->data.position_basic_salary);
		printf("�������λ������");
		scanf("%lf", &p->data.job_allowance);
		printf("����������������");
		scanf("%lf", &p->data.other_allowance);
		printf("�����뽱��");
		scanf("%lf", &p->data.bonus);

		printf("����������˰��");
		scanf("%lf", &p->data.income_tax);
		printf("������ס��������");
		scanf("%lf", &p->data.housing_fund);
		printf("���������Ͻ�");
		scanf("%lf", &p->data.oldage_pension);
		printf("������ҽ�Ʊ��գ�");
		scanf("%lf", &p->data.medical_insurance);
		printf("������ʧҵ���գ�");
		scanf("%lf", &p->data.unemployment_insurance);
		p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
		p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;
         
		printf("���Ӧ������Ϊ");
        cout<<p->data.gross_pay;
        
        
        if(p->data.net_pay<0){
        	printf("��Ա���Ĺ��ʴ���--Ϊ����");//ʵ�������Ƿ�Ϊ�� 
		}
        else{
        	printf("���ʵ������Ϊ");

        	cout<<p->data.net_pay;	
		}
        
        printf("��ʾ�������%d��\n",cnt);
		p->next = NULL;
		q->next = p;
		q = p;
	}
}


///�޸�ְ����Ϣ����
int  change(Node *worker)
{
	Node *p;
	char Find[20];
	int sel;//�޸ķ��� 
	p = worker->next;
	if (p == NULL)
	{
		printf("\n��ʾ��û�����Ͽ����޸ģ�\n");
		return 0;
	}
	
	printf("\n��ʾ��\n ���� 0---- �˳�\t ���� 1----��ְ�����޸�\t ���� 2-----��ְ�������޸�\n");
	printf("��ѡ��");
	scanf("%d", &sel);
	
	
	if(sel==1){
		
		printf("������Ҫ�޸ĵ�ְ����");
		scanf("%s", Find);
		
		while (p != NULL)
		{
			if (strcmp(p->data.jobNo, Find) == 0)
			{
				break;
			}
		p = p->next;
		}

		if (p!=NULL)
		{
			int x;
			while (1)
			{
				printf("����޸�������0�����������0���ֽ����޸ģ�");
				scanf("%d", &x);
				if (x == 0)
				{
					break;
				}
				printf(" ��������ְ����: ");
				scanf("%s", p->data.jobNo);
        
				printf("��������ְ��������");
				scanf("%s", p->data.name);
		
        		printf("��������ְ��ְ��");
				scanf("%s", p->data.position);

				printf("��������ְ��ְ��������ʣ�");
				cin>>p->data.position_basic_salary;
		
				printf("��������ְ����λ������");
				cin>>p->data.job_allowance;

				printf("��������ְ������������");
				cin>>p->data.other_allowance;

				printf("��������ְ������");
				cin>> p->data.bonus;
	
				printf("��������ְ������˰��");
				cin>> p->data.income_tax;

				printf("��������ְ��ס��������");
				cin>>p->data.housing_fund;

				printf("��������ְ�����Ͻ�");
				cin>>p->data.oldage_pension;

				printf("��������ְ��ҽ�Ʊ��գ�");
				cin>>p->data.medical_insurance;

				printf("��������ְ��ʧҵ���գ�");
				cin>>p->data.unemployment_insurance;


				p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
				p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;

       			 printf(" \n��ʾ����ְ�������Ѿ��޸ģ�\n ");
			}
   		}
		else
			printf("\n��ʾ��û����Ҫ�޸ĵ�����!\n ");
	} 
	
	int number=0;//�ж��Ƿ����� 
	
	if(sel==2){
		printf("������Ҫ�޸ĵ�ְ������");
		scanf("%s", Find);
		
		while (p != NULL)
		{
			if (strcmp(p->data.name, Find) == 0)
			{
				number++;
			}
		p = p->next;
		}
		
		if(number!=1){
			printf("Ա����������--��ѡ�����޸ķ���"); 
		}
		
		else{
			p=worker->next;
			while (p != NULL)//�ҵ�λ�� 
			{
				if (strcmp(p->data.name, Find) == 0)
				{
					break;
				}
			p = p->next;
			}
			
			
			if (p!=NULL)
			{
			
				int x;
				while (1)
				{
					printf("����޸�������0�����������0���ֽ����޸ģ�");
					scanf("%d", &x);
					if (x == 0)
					{
						break;
					}
					printf(" ��������ְ����: ");
					scanf("%s", p->data.jobNo);
        
					printf("��������ְ��������");
					scanf("%s", p->data.name);
		
        			printf("��������ְ��ְ��");
					scanf("%s", p->data.position);

					printf("��������ְ��ְ��������ʣ�");
					cin>>p->data.position_basic_salary;
		
					printf("��������ְ����λ������");
					cin>>p->data.job_allowance;

					printf("��������ְ������������");
					cin>>p->data.other_allowance;

					printf("��������ְ������");
					cin>> p->data.bonus;
	
					printf("��������ְ������˰��");
					cin>> p->data.income_tax;

					printf("��������ְ��ס��������");
					cin>>p->data.housing_fund;

					printf("��������ְ�����Ͻ�");
					cin>>p->data.oldage_pension;

					printf("��������ְ��ҽ�Ʊ��գ�");
					cin>>p->data.medical_insurance;

					printf("��������ְ��ʧҵ���գ�");
					cin>>p->data.unemployment_insurance;


					p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
					p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;

					if(p->data.net_pay<0){
						printf("�޸ĺ��ʵ�ʹ���Ϊ����---����");
					}
					
       				printf(" \n��ʾ����ְ�������Ѿ��޸ģ�\n ");
				}
   			}
			else
				printf("\n��ʾ��û����Ҫ�޸ĵ�����!\n ");
			
		}
		
	}

	if(sel==0){
		return 0;
	} 
		
		
}
	

///��ʾְ����Ϣ����
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n��ʾ:û����Ϣ������ʾ!\n ");
		return 0;

	}
	
	int cnt=0;//��ʾ����; 
	int  eor=0;//������Ϣ�ĸ��� 
	printf("    ��ʾ���\n");
	printf("  ְ���� ���� ְ��  ְ��������� ��λ���� �������� ����	����˰ ס�������� ���Ͻ� ҽ�Ʊ��� ʧҵ���� Ӧ������ ʵ������\n   ");
	while (p!=NULL)
	{	
		cnt++;
		

		printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf %lf %lf %lf\n ", p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
        p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
        
		if(p->data.net_pay<0){
			printf("��Ա����ʵ�ʹ���Ϊ����\n");
			eor++; 
		}
		
		p = p->next;

	}
	printf("һ���洢 %d ��ְ����Ϣ\n",cnt);
	printf("һ������ %d ��ְ����Ϣ����\n",eor);
	
}

///��ѯְ����Ϣ����: (1)��ְ���Ų�ѯ	(2)��ְ��������ѯ
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;//��ѯ���� 
	char Find[20];
	p = worker->next;

	if (p==NULL)
	{
		printf(" \n��ʾ��û�����Ͽ��Բ�ѯ��\n ");
		return 0;

	}

	printf("\n��ʾ��\n ���� 0---- �˳�\t ���� 1----��ְ���Ų�ѯ\t ���� 2-----��ְ��������ѯ\n");
	printf("��ѡ��");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n��������Ҫ��ѯ�����ְ���ţ�");
		scanf("%s", Find);
		while (p!=NULL)
		{
			if (strcmp(p->data.jobNo, Find) == 0)
			{
				printf("  ְ���� ���� ְ��  ְ��������� ��λ���� �������� ����	����˰ ס�������� ���Ͻ� ҽ�Ʊ��� ʧҵ���� Ӧ������ ʵ������\n ");
				printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf\n ",p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
       		p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
			
				if(p->data.net_pay<0){
					printf("��Ա����ʵ�ʹ���Ϊ����\n");
				}
			
			
			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n������Ҫ��ѯ�����ְ��������");
		scanf("%s", Find);
		while (p!=NULL)
		{
			if (strcmp(p->data.name, Find) == 0)
			{
				printf("  ְ���� ���� ְ��  ְ��������� ��λ���� �������� ����	����˰ ס�������� ���Ͻ� ҽ�Ʊ��� ʧҵ���� Ӧ������ ʵ������\n ");
				printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf\n ", p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
         p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
		
				if(p->data.net_pay<0){
					printf("��Ա����ʵ�ʹ���Ϊ����\n");
				}
		
		
			}
			p = p->next;

		}
	}

	else if (sel == 0)
		return 0;

}
///ɾ��ְ����Ϣ����
int  Delete(Node *worker)
{
	Node *p, *r;
	char Find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("��ʾ��û��ְ����Ϣ����ɾ����\n ");
		return 0;

	}
	printf(" \n��ʾ����������Ҫɾ����ְ���ţ�\n ");
	scanf("%s", Find);
	
	int flag=1; 
	
	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, Find) == 0)
		{
			flag=0;
			break;
		}
		p = p->next;

	}

	if (p!=NULL)
	{
		r = worker;
		while (r->next != p)
		{
			r = r->next;
		}
		r->next = r->next->next;//free(p); 
	}
	if(flag){
		printf("��ʾ��û��ְ����Ϣ����ɾ����\n ");
	}
}


//��ְ����Ϣ���浽�ļ���
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("�Ƿ񱣴浽�ļ���( 1-----���棡��0-----�����棡 )");
	scanf("%d", &n);

	if (n == 1){
		if (worker->next == NULL){
			printf(" û�м�¼��");
		}
		else
        {
			p = worker->next;
		}
		if ((fp = fopen("ְ����Ϣ����ϵͳ.txt", " wb ")) == NULL){
			printf(" �ļ����ܴ򿪣�\n");
		}
		while (p != NULL)
		{
			//д�� 
			fprintf(fp,"%s %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
         p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);


		p = p->next;
        printf("����ɹ�");
		}
		fclose(fp);

	}

}



///��ȡְ����Ϣ
void Du_qu(Node *worker)
{
	FILE *fp;//�ļ�ָ�� 
	if ((fp = fopen("ְ����Ϣ����ϵͳ.txt", "rb")) == NULL)
	{
		printf("�����ڸ��ļ�\n");
		exit(-1);
	}
	
	//node *p,*r;
	//p=worker->next;
	
	//p=(struct node*)malloc(sizeof(node));
	//r=p;
	workers p;
	char c;
	//fscanf��ʽ����ȡ�ļ��� ���Ѿ�����ļ��洢��ʽ�£�����ֱ����fscanf���ļ����ݶ�ȡ����Ӧ���͵ı����С�
	while (fscanf(fp,"%s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf %lf %lf %lf %c", p.jobNo, p.name, p.position, &p.position_basic_salary, &p.job_allowance, &p.other_allowance, &p.bonus,
		&p.income_tax, &p.housing_fund, &p.oldage_pension, &p.medical_insurance, &p.unemployment_insurance, &p.gross_pay, &p.net_pay,&c)!=EOF)
	{	
		//p->next=NULL;
		
		//p=(struct node*)malloc(sizeof(node));
		//r->next=p;
		//r=p;
		printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf %lf %lf %lf %c", p.jobNo, p.name, p.position, p.position_basic_salary, p.job_allowance, p.other_allowance, p.bonus,
			p.income_tax, p.housing_fund, p.oldage_pension, p.medical_insurance, p.unemployment_insurance, p.gross_pay, p.net_pay,c);
	}
}



//������ʵ��
int main()
{
	Node *worker;
	int flag;

	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

 	while(1)
 	{
 			printf("       �� ӭ �� �� ְ �� �� Ϣ �� �� ϵ ͳ\n");
			printf("**********************�� ��==================*****\n");
			printf("*               1.���벢����ְ����Ϣ             *\n");
			printf("*               2.�޸�ְ����Ϣ                   *\n");
			printf("*               3.��ʾְ����Ϣ                   *\n");
			printf("*               4.��ѯְ����Ϣ                   *\n");
			printf("*               5.ɾ��ְ����Ϣ                   *\n");
			printf("*               6.��ȡְ����Ϣ                   *\n");
			printf("*               7.����ְ����Ϣ                   *\n");
			printf("*               0.�˳�                           *\n");
			printf("**************************************************\n");

			printf("������ѡ�����ţ�");
			scanf("%d", &flag);
			switch (flag)
			{
				case 0:  printf(" \n��ʾ���˳�ϵͳ!\n "); return 0;
				case 1:	 Add(worker);save(worker);system("cls");break;    //���ְ����Ϣ,���浽�ļ���
				case 2:  change(worker);break;           //�޸�ְ����Ϣ
				case 3:  Disp(worker);break;             					//��ʾְ����Ϣ
				case 4:  Cha_xun(worker);break;						        //��ѯְ����Ϣ
				case 5:  Delete(worker); system("cls"); break;             //ɾ��ְ����Ϣ
				case 6:  Du_qu(worker);break;            				 //��ȡְ����Ϣ
				case 7:  save(worker);break;              				  //���浽�ļ��� 
                default: printf("��ʾ:�������\n ");
			}
	}

}
