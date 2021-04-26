#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;

struct workers
{	
	char jobNo[100];       				//职工号
	char name[100];       				 //姓名
	char position[100];   				 //职务
	double position_basic_salary;     	   //职务基本工资
	double job_allowance;   			 //岗位津贴
	double other_allowance;    			  //其他补贴
	double bonus;   					//奖金
	double income_tax;        			//所得税
	double housing_fund;    			//住房公基金
	double oldage_pension;  		 // 养老金
	double medical_insurance; 		  //医疗保险
	double unemployment_insurance; 		 // 失业保险
    double gross_pay;   				 //应发工资
    double net_pay;      				// 实发工资
};


//类型定义语句
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;


///添加信息函数
///worker 是头指针
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
	    printf("提示：输入0返回主菜单！\n");
		printf("请输入职工号：");
		scanf("%s", n);//getchar();
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);
		
		cnt++;
		
		printf("请输入姓名：");
		scanf("%s", p->data.name);
		printf("请输入职务：");
		scanf("%s", p->data.position);
		printf("请输入职务基本工资：");
		scanf("%lf", &p->data.position_basic_salary);
		printf("请输入岗位津贴：");
		scanf("%lf", &p->data.job_allowance);
		printf("请输入其他补贴：");
		scanf("%lf", &p->data.other_allowance);
		printf("请输入奖金：");
		scanf("%lf", &p->data.bonus);

		printf("请输入所得税：");
		scanf("%lf", &p->data.income_tax);
		printf("请输入住房公基金：");
		scanf("%lf", &p->data.housing_fund);
		printf("请输入养老金：");
		scanf("%lf", &p->data.oldage_pension);
		printf("请输入医疗保险：");
		scanf("%lf", &p->data.medical_insurance);
		printf("请输入失业保险：");
		scanf("%lf", &p->data.unemployment_insurance);
		p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
		p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;
         
		printf("算得应发工资为");
        cout<<p->data.gross_pay;
        
        
        if(p->data.net_pay<0){
        	printf("该员工的工资错误--为负数");//实发工资是否为负 
		}
        else{
        	printf("算得实发工资为");

        	cout<<p->data.net_pay;	
		}
        
        printf("提示：已完成%d次\n",cnt);
		p->next = NULL;
		q->next = p;
		q = p;
	}
}


///修改职工信息函数
int  change(Node *worker)
{
	Node *p;
	char Find[20];
	int sel;//修改方法 
	p = worker->next;
	if (p == NULL)
	{
		printf("\n提示：没有资料可以修改！\n");
		return 0;
	}
	
	printf("\n提示：\n 输入 0---- 退出\t 输入 1----按职工号修改\t 输入 2-----按职工姓名修改\n");
	printf("请选择：");
	scanf("%d", &sel);
	
	
	if(sel==1){
		
		printf("请输入要修改的职工号");
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
				printf("完成修改请输入0，否则输入非0数字进行修改！");
				scanf("%d", &x);
				if (x == 0)
				{
					break;
				}
				printf(" 请输入新职工号: ");
				scanf("%s", p->data.jobNo);
        
				printf("请输入新职工姓名：");
				scanf("%s", p->data.name);
		
        		printf("请输入新职工职务：");
				scanf("%s", p->data.position);

				printf("请输入新职工职务基本工资：");
				cin>>p->data.position_basic_salary;
		
				printf("请输入新职工岗位津贴：");
				cin>>p->data.job_allowance;

				printf("请输入新职工其他补贴：");
				cin>>p->data.other_allowance;

				printf("请输入新职工奖金：");
				cin>> p->data.bonus;
	
				printf("请输入新职工所得税：");
				cin>> p->data.income_tax;

				printf("请输入新职工住房公基金：");
				cin>>p->data.housing_fund;

				printf("请输入新职工养老金：");
				cin>>p->data.oldage_pension;

				printf("请输入新职工医疗保险：");
				cin>>p->data.medical_insurance;

				printf("请输入新职工失业保险：");
				cin>>p->data.unemployment_insurance;


				p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
				p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;

       			 printf(" \n提示：该职工资料已经修改！\n ");
			}
   		}
		else
			printf("\n提示：没有你要修改的资料!\n ");
	} 
	
	int number=0;//判断是否重名 
	
	if(sel==2){
		printf("请输入要修改的职工姓名");
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
			printf("员工存在重名--请选择别的修改方法"); 
		}
		
		else{
			p=worker->next;
			while (p != NULL)//找到位置 
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
					printf("完成修改请输入0，否则输入非0数字进行修改！");
					scanf("%d", &x);
					if (x == 0)
					{
						break;
					}
					printf(" 请输入新职工号: ");
					scanf("%s", p->data.jobNo);
        
					printf("请输入新职工姓名：");
					scanf("%s", p->data.name);
		
        			printf("请输入新职工职务：");
					scanf("%s", p->data.position);

					printf("请输入新职工职务基本工资：");
					cin>>p->data.position_basic_salary;
		
					printf("请输入新职工岗位津贴：");
					cin>>p->data.job_allowance;

					printf("请输入新职工其他补贴：");
					cin>>p->data.other_allowance;

					printf("请输入新职工奖金：");
					cin>> p->data.bonus;
	
					printf("请输入新职工所得税：");
					cin>> p->data.income_tax;

					printf("请输入新职工住房公基金：");
					cin>>p->data.housing_fund;

					printf("请输入新职工养老金：");
					cin>>p->data.oldage_pension;

					printf("请输入新职工医疗保险：");
					cin>>p->data.medical_insurance;

					printf("请输入新职工失业保险：");
					cin>>p->data.unemployment_insurance;


					p->data.gross_pay=p->data.position_basic_salary+p->data.job_allowance+p->data.other_allowance+p->data.bonus;
					p->data.net_pay=p->data.gross_pay-p->data.income_tax-p->data.housing_fund-p->data.oldage_pension-p->data.medical_insurance-p->data.unemployment_insurance;

					if(p->data.net_pay<0){
						printf("修改后的实际工资为负数---错误");
					}
					
       				printf(" \n提示：该职工资料已经修改！\n ");
				}
   			}
			else
				printf("\n提示：没有你要修改的资料!\n ");
			
		}
		
	}

	if(sel==0){
		return 0;
	} 
		
		
}
	

///显示职工信息函数
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n提示:没有信息可以显示!\n ");
		return 0;

	}
	
	int cnt=0;//显示次数; 
	int  eor=0;//错误信息的个数 
	printf("    显示结果\n");
	printf("  职工号 姓名 职务  职务基本工资 岗位津贴 其他补贴 奖金	所得税 住房公基金 养老金 医疗保险 失业保险 应发工资 实发工资\n   ");
	while (p!=NULL)
	{	
		cnt++;
		

		printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf %lf %lf %lf\n ", p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
        p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
        
		if(p->data.net_pay<0){
			printf("该员工的实际工资为负数\n");
			eor++; 
		}
		
		p = p->next;

	}
	printf("一共存储 %d 个职工信息\n",cnt);
	printf("一共存在 %d 个职工信息错误\n",eor);
	
}

///查询职工信息函数: (1)按职工号查询	(2)按职工姓名查询
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;//查询方法 
	char Find[20];
	p = worker->next;

	if (p==NULL)
	{
		printf(" \n提示：没有资料可以查询！\n ");
		return 0;

	}

	printf("\n提示：\n 输入 0---- 退出\t 输入 1----按职工号查询\t 输入 2-----按职工姓名查询\n");
	printf("请选择：");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n请输入你要查询分类的职工号：");
		scanf("%s", Find);
		while (p!=NULL)
		{
			if (strcmp(p->data.jobNo, Find) == 0)
			{
				printf("  职工号 姓名 职务  职务基本工资 岗位津贴 其他补贴 奖金	所得税 住房公基金 养老金 医疗保险 失业保险 应发工资 实发工资\n ");
				printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf\n ",p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
       		p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
			
				if(p->data.net_pay<0){
					printf("该员工的实际工资为负数\n");
				}
			
			
			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n输入你要查询分类的职工姓名：");
		scanf("%s", Find);
		while (p!=NULL)
		{
			if (strcmp(p->data.name, Find) == 0)
			{
				printf("  职工号 姓名 职务  职务基本工资 岗位津贴 其他补贴 奖金	所得税 住房公基金 养老金 医疗保险 失业保险 应发工资 实发工资\n ");
				printf(" \n %s  %s  %s  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf  %lf\n ", p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
         p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);
		
				if(p->data.net_pay<0){
					printf("该员工的实际工资为负数\n");
				}
		
		
			}
			p = p->next;

		}
	}

	else if (sel == 0)
		return 0;

}
///删除职工信息函数
int  Delete(Node *worker)
{
	Node *p, *r;
	char Find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("提示：没有职工信息可以删除！\n ");
		return 0;

	}
	printf(" \n提示：请输入你要删除的职工号！\n ");
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
		printf("提示：没有职工信息可以删除！\n ");
	}
}


//将职工信息保存到文件中
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("是否保存到文件？( 1-----保存！，0-----不保存！ )");
	scanf("%d", &n);

	if (n == 1){
		if (worker->next == NULL){
			printf(" 没有记录！");
		}
		else
        {
			p = worker->next;
		}
		if ((fp = fopen("职工信息管理系统.txt", " wb ")) == NULL){
			printf(" 文件不能打开！\n");
		}
		while (p != NULL)
		{
			//写入 
			fprintf(fp,"%s %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",p->data.jobNo, p->data.name,p->data.position,p->data.position_basic_salary,p->data.job_allowance,p->data.other_allowance,p->data.bonus,
         p->data.income_tax,p->data.housing_fund,p->data.oldage_pension,p->data.medical_insurance,p->data.unemployment_insurance,p->data.gross_pay,p->data.net_pay);


		p = p->next;
        printf("保存成功");
		}
		fclose(fp);

	}

}



///读取职工信息
void Du_qu(Node *worker)
{
	FILE *fp;//文件指针 
	if ((fp = fopen("职工信息管理系统.txt", "rb")) == NULL)
	{
		printf("不存在该文件\n");
		exit(-1);
	}
	
	//node *p,*r;
	//p=worker->next;
	
	//p=(struct node*)malloc(sizeof(node));
	//r=p;
	workers p;
	char c;
	//fscanf格式化读取文件， 在已经清楚文件存储格式下，可以直接用fscanf把文件数据读取到对应类型的变量中。
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



//主函数实现
int main()
{
	Node *worker;
	int flag;

	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

 	while(1)
 	{
 			printf("       欢 迎 进 入 职 工 信 息 管 理 系 统\n");
			printf("**********************菜 单==================*****\n");
			printf("*               1.输入并保存职工信息             *\n");
			printf("*               2.修改职工信息                   *\n");
			printf("*               3.显示职工信息                   *\n");
			printf("*               4.查询职工信息                   *\n");
			printf("*               5.删除职工信息                   *\n");
			printf("*               6.读取职工信息                   *\n");
			printf("*               7.保存职工信息                   *\n");
			printf("*               0.退出                           *\n");
			printf("**************************************************\n");

			printf("输入你选择的序号：");
			scanf("%d", &flag);
			switch (flag)
			{
				case 0:  printf(" \n提示：退出系统!\n "); return 0;
				case 1:	 Add(worker);save(worker);system("cls");break;    //添加职工信息,保存到文件中
				case 2:  change(worker);break;           //修改职工信息
				case 3:  Disp(worker);break;             					//显示职工信息
				case 4:  Cha_xun(worker);break;						        //查询职工信息
				case 5:  Delete(worker); system("cls"); break;             //删除职工信息
				case 6:  Du_qu(worker);break;            				 //读取职工信息
				case 7:  save(worker);break;              				  //保存到文件； 
                default: printf("提示:输入错误！\n ");
			}
	}

}
