#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<iomanip>
#include<conio.h>   

using namespace std;

class EMPLOYEE{
private:
	int id;
	char name[30];
	int work_year;
	char job[30];
	int salary;
public:
	EMPLOYEE(int,char*,int,char*,int);
	EMPLOYEE();
	int get_id();
	char* get_name();
	int get_year();
	char* get_job();
	int get_sala();
};

class DEVE:public EMPLOYEE{
private:
	int work_hour;
	int belong;
	int income;
public:
	DEVE(int,char*,int,char*,int,int,int); //���һ��intΪ���������ţ�ǰһ��Ϊ����ʱ��
	DEVE();
	int get_income();
	int get_belong();
	int get_workhour();
};

class SALESMAN:public EMPLOYEE{
private:
	int sale_income;
	int belong;
	float income;
public:
	SALESMAN(int,char*,int,char*,int,int,int);//���һ��intΪ���������ţ�ǰһ��floatΪ���۶�
	SALESMAN();
	int get_saleincome();
	int get_income();
	int get_belong();
};

struct deve{
	DEVE developer;
	deve* next;
};

struct sale{
	SALESMAN  salesman;
	sale* next;
};

class PROJMANAGER:public EMPLOYEE{
private:
	deve* deve_list;
	deve* cur;
	int proj_income;
	int income;
	int counter;
	bool is_empty;
	float deve_income;
public:
	PROJMANAGER(int,char*,int,char*,int,int);//���һ��floatΪ��Ŀ����
	PROJMANAGER();
	~PROJMANAGER();
	void add_deve(DEVE&);
	void del_deve(int);
	int get_income();
	bool empty();
	void write(char*);
	void trav();
	bool search(int);
	void output();
	int get_deve_income();
	int get_counter();
};

class SALESMANAGER:public EMPLOYEE{
private:
	sale* salesman_list;
	sale* cur;
	int sale_income;
	int income;
	int counter;
	bool is_empty;
	int man_income;
public:
	SALESMANAGER(int,char*,int,char*,int);
	SALESMANAGER();
	~SALESMANAGER();
	void add_salesman(SALESMAN&);
	void del_salesman(int);
	int get_sale_income();
	int get_income();
	bool empty();
	void write(char*);
	void trav();
	bool search(int);
	void output();
	int get_man_income();
	int get_counter();
};

class COMPANY{
private:
	PROJMANAGER proj_mana[5];
	SALESMANAGER sales_mana[5];
	int proj_mana_size;
	int sales_mana_size;
	char com_name[20];
	char file_name[20];
	float total_salary;
	int personnel;
	int deve_income;
	int salesman_income;
	int proj_mana_income;
	int sales_mana_income;
	int deve_num;
	int salesman_num;
public:
	COMPANY(char*,char*);
	void add();
	void del();
	void output();
	void tav();
	int get_total_salary();
	int get_tdeve_income();
	int get_tsalesman_income();
	int get_proj_mana_income();
	int get_sales_mana_income();
	int get_deve_num();
	int get_salesman_num();
	int get_personnel();
};






//Ա����
EMPLOYEE::EMPLOYEE(int id,char*name,int work_year,char*job,int salary)
{
	this->id=id;
	strcpy(this->name,name);
	this->work_year=work_year;
	strcpy(this->job,job);
	this->salary=salary;
}

EMPLOYEE::EMPLOYEE()
{
}
int EMPLOYEE::get_id()
{
	return id;
}

char* EMPLOYEE::get_name()
{
	return name;
}

int EMPLOYEE::get_year()
{
	return work_year;
}

int EMPLOYEE::get_sala()
{
	return salary;
}
char*EMPLOYEE::get_job()
{
	return job;
}

//����Ա��

DEVE::DEVE(int id,char*name,int work_year,char*job,int salary,int work_hour,int belong):EMPLOYEE(id,name,work_year,job,salary)
{
	this->work_hour=work_hour;
	this->belong=belong;
}

DEVE::DEVE()
{
}
int DEVE::get_income()
{
	income=work_hour*50+get_year()*100;
	return income;
}
int DEVE::get_belong()
{
	return belong;
}
int DEVE::get_workhour()
{
	return work_hour;
}
//����Ա��
SALESMAN::SALESMAN(int id,char*name,int work_year,char*job,int salary,int sale_income,int belong):EMPLOYEE(id,name,work_year,job,salary)
{
	this->belong=belong;
	this->sale_income=sale_income;
}

SALESMAN::SALESMAN()
{
}

int SALESMAN::get_saleincome()
{
	return sale_income;
}

int SALESMAN::get_income()
{
	income=get_sala()+sale_income/20;
	return (int)income;
}
int SALESMAN::get_belong()
{
	return belong;
}
//��Ŀ������

PROJMANAGER::PROJMANAGER(int id,char*name,int work_year,char*job,int salary,int proj_income):EMPLOYEE(id,name,work_year,job,salary)
{
	this->proj_income=proj_income;
	deve_list=cur=NULL;
	counter=0;
	is_empty=true;
}
PROJMANAGER::PROJMANAGER()
{
}

void PROJMANAGER::add_deve(DEVE&a)
{
	deve*t=new deve;
	t->developer=a;
	t->next=NULL;
	if(deve_list==NULL){
		deve_list=cur=t;
	}
	else{
		cur=cur->next=t;
	}
	is_empty=false;
	counter++;
}
PROJMANAGER::~PROJMANAGER()
{
}

void PROJMANAGER::del_deve(int deve_id)
{
	deve*t,*pre;
	t=pre=deve_list;
	while(t&&t->developer.get_id()!=deve_id){
		pre=t;
		t=t->next;
	}
	if(pre==t){
		deve_list=t->next;
		is_empty=true;
		counter--;
		delete t;
		cout<<"                     ��ɾ��"<<endl;
		return;
	}
	else{
		pre->next=t->next;
		counter--;
		cout<<"                     ��ɾ��"<<endl;
		delete t;
		return;
	}
}

int PROJMANAGER::get_income()
{
	income=0;
	income=get_sala()+get_year()*100+proj_income/100;
	return income;
}

bool PROJMANAGER::empty()
{
	return is_empty;
}
void PROJMANAGER::write(char*file_name)
{
	FILE*fp;
	if((fp=fopen(file_name,"aw+"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
	fprintf(fp,"%d  %s  %d  projectmanager  %d\n",get_id(),get_name(),get_year(),proj_income);
	deve* t=deve_list;
	while(t){
		fprintf(fp,"%d  %s  %d   %s  %d  %d\n",t->developer.get_id(),t->developer.get_name(),t->developer.get_year(),t->developer.get_job(),t->developer.get_workhour(),t->developer.get_belong());
		t=t->next;
	}
	fclose(fp);
}

void PROJMANAGER::trav()
{
	deve*p=deve_list;
	while(p){
		cout<<p->developer.get_sala()<<p->developer.get_id()<<p->developer.get_name()<<p->developer.get_year()<<p->developer.get_job()<<p->developer.get_workhour()<<p->developer.get_belong();
		p=p->next;
	}
}

bool PROJMANAGER::search(int i)
{
	deve*t=deve_list;
	while(t){
		if(t->developer.get_id()==i){
			return true;
		}
		t=t->next;
	}
	return false;
}

void PROJMANAGER::output()
{
	cout<<"               "<<get_id()<<"    "<<get_name()<<"  "<<get_job()<<"  "<<get_income()<<endl;
	deve*t=deve_list;
	while(t){
		cout<<"               "<<t->developer.get_id()<<"    "<<t->developer.get_name()<<"  "<<t->developer.get_job()<<"  "<<(int)(t->developer.get_income()+proj_income*0.02/counter)<<endl;
		t=t->next;
	}
}

int PROJMANAGER::get_deve_income()
{
	deve_income=0;
	deve*t=deve_list;
	while(t){
		deve_income+=(t->developer.get_income()+proj_income/50/counter);
		t=t->next;
	}
	return deve_income;
}


int PROJMANAGER::get_counter()
{
	return counter;
}
//���۾�����
SALESMANAGER::SALESMANAGER(int id,char*name,int work_year,char*job,int salary):EMPLOYEE(id,name,work_year,job,salary)
{
	salesman_list=cur=NULL;
	counter=0;
}

SALESMANAGER::SALESMANAGER()
{
}

void SALESMANAGER::add_salesman(SALESMAN& a)
{
	sale* t=new sale;
	t->salesman=a;
	t->next=NULL;
	if(salesman_list==NULL){
		salesman_list=cur=t;
	}
	else{
		cur=cur->next=t;
	}
	is_empty=false;
	counter++;
}

void SALESMANAGER::del_salesman(int sale_id)
{
	sale *t,*pre;
	t=pre=salesman_list;
	while(t&&t->salesman.get_id()!=sale_id){
		pre=t;
		t=t->next;
	}
	if(pre==t){
		salesman_list=t->next;
		is_empty=true;
		counter--;
		delete t;
		cout<<"                     ��ɾ��!"<<endl;
		return;
	}
	else{
		pre->next=t->next;
		counter--;
		delete t;
		cout<<"                     ��ɾ��!"<<endl;
	}
}

SALESMANAGER::~SALESMANAGER()
{
}

int SALESMANAGER::get_sale_income()
{
	sale_income=0;
	sale* p;
	p=salesman_list;
	while(p){
		sale_income+=p->salesman.get_saleincome();
		p=p->next;
	}
	return sale_income;
}

int SALESMANAGER::get_income()
{
	income=get_sala()+get_sale_income()/100;
	return (int)income;
}

bool SALESMANAGER::empty()
{
	return is_empty;
}

void SALESMANAGER::write(char*file_name)
{
	FILE*fp;
	if((fp=fopen(file_name,"aw+"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
	fprintf(fp,"%d  %s  %d   salesmanager\n",get_id(),get_name(),get_year());
	sale*t=salesman_list;
	while(t){
		fprintf(fp,"%d  %s  %d  %s  %d  %d\n",t->salesman.get_id(),t->salesman.get_name(),t->salesman.get_year(),t->salesman.get_job(),t->salesman.get_saleincome(),t->salesman.get_belong());
		t=t->next;
	}
	fclose(fp);
}

void SALESMANAGER::trav()
{
	sale*t=salesman_list;
	while(t){
		cout<<t->salesman.get_sala()<<t->salesman.get_id()<<t->salesman.get_name()<<t->salesman.get_year()<<t->salesman.get_job()<<t->salesman.get_saleincome()<<"  "<<t->salesman.get_belong()<<endl;
		t=t->next;
	}
}

bool SALESMANAGER::search(int i)
{
	sale*t=salesman_list;
	while(t){
		if(t->salesman.get_id()==i){
			return true;
		}
	    t=t->next;
	}
	return false;
}

int SALESMANAGER::get_man_income()
{
	man_income=0;
	sale *t=salesman_list;
	while(t){
		man_income=man_income+t->salesman.get_income();
		t=t->next;
	}
	return man_income;
}


void SALESMANAGER::output()
{
	cout<<"               "<<get_id()<<"    "<<get_name()<<"  "<<get_job()<<"  "<<get_income()<<endl;
	sale*t=salesman_list;
	while(t){
		cout<<"               "<<t->salesman.get_id()<<"    "<<t->salesman.get_name()<<"  "<<t->salesman.get_job()<<"  "<<t->salesman.get_income()<<endl;
		t=t->next;
	}
}


int SALESMANAGER::get_counter()
{
	return counter;
}
//��˾��
COMPANY::COMPANY(char*com_name,char*file_name)
{
	strcpy(this->com_name,com_name);
	strcpy(this->file_name,file_name);
	proj_mana_size=sales_mana_size=0;
	FILE*fp;
	personnel=0;
	total_salary=0;
	proj_mana_income=0;
	sales_mana_income=0;
	deve_num=0;
	salesman_num=0;
	salesman_income=0;
	deve_income=0;
	if((fp=fopen(file_name,"r"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
	int id;
	char name[30];
	int work_year;
	char job[30];
	int proj_income;
	char str[100];
	while((fscanf(fp,"%d%s%d%s",&id,name,&work_year,job))!=EOF){
		if((strcmp(job,"projectmanager"))==0){
			fscanf(fp,"%d",&proj_income);
			PROJMANAGER temp(id,name,work_year,job,10000,proj_income);
			proj_mana[proj_mana_size++]=temp;
			personnel++;
		}
		else if((strcmp(job,"salesmanager"))==0){
			SALESMANAGER temp(id,name,work_year,job,8000);
			sales_mana[sales_mana_size++]=temp;
			personnel++;
		}
		else{
			fgets(str,100,fp);
		}
	}
	rewind(fp);
	int belong;
	int work_hour;
	while((fscanf(fp,"%d%s%d%s",&id,name,&work_year,job))!=EOF){
		if((strcmp(job,"salesman"))==0){
			fscanf(fp,"%d%d",&proj_income,&belong);
			for(int j=0;j<sales_mana_size;j++){
				if(belong==sales_mana[j].get_id()){
					SALESMAN temp(id,name,work_year,job,2000,proj_income,belong);
					sales_mana[j].add_salesman(temp);
					personnel++;
					break;
				}
			}
		}
		else if((strcmp(job,"developer"))==0){
			fscanf(fp,"%d%d",&work_hour,&belong);
			for(int i=0;i<proj_mana_size;i++){
				if(belong==proj_mana[i].get_id()){
					DEVE temp(id,name,work_year,job,0,work_hour,belong);
					proj_mana[i].add_deve(temp);
					personnel++;
					break;
				}
			}
		}
		else if((strcmp(job,"salesmanager"))==0){
			continue;
		}
		else{
			fgets(str,100,fp);
		}
	}
	fclose(fp);
}

void COMPANY::add()
{
	FILE*fp;
	if((fp=fopen(file_name,"r"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
	int a[100];
	int size=0;
	char str[100];
	while((fscanf(fp,"%d",&a[size]))!=EOF){
		fgets(str,100,fp);
		size++;
	}
	fclose(fp);
	cout<<"                      ѡ����ӵ�Ա������"<<endl;
	cout<<"                      1.��Ŀ����"<<endl
		<<"                      2.���۾���"<<endl
		<<"                      3.������Ա"<<endl
		<<"                      4.������Ա"<<endl;
	char ans;
	ans=getch();
	int id;char name[12];int work_year;int proj_income;int work_hour;int sale_income;
	int belong;
	int i;
	if(ans=='1'){
		cout<<"             ��������Ŀ����Ĺ���,����,����,������Ŀ����"<<endl;
		cin>>id>>name>>work_year>>proj_income;
		for(i=0;i<size;i++){
			if(id==a[i]){
				cout<<"             �˹����Ѿ�����!�����²�����"<<endl;
				return;
			}
		}
		PROJMANAGER temp(id,name,work_year,"projectmanager",10000,proj_income);
		proj_mana[proj_mana_size++]=temp;
		if((fp=fopen(file_name,"aw"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
		fseek(fp,0,SEEK_END);
		fprintf(fp,"%d   %s   %d   projectmanager  %d\n",id,name,work_year,proj_income);
		cout<<"                          ��ӳɹ�!"<<endl;
			personnel++;
	}
	else if(ans=='2'){
	    cout<<"             ���������۾���Ĺ���,����,����"<<endl;
		cin>>id>>name>>work_year;
        for(i=0;i<size;i++){
			if(id==a[i]){
				cout<<"             �˹����Ѿ�����!�����²�����"<<endl;
				return;
			}
		}
		SALESMANAGER temp(id,name,work_year,"salesmanager",8000);
		sales_mana[sales_mana_size++]=temp;
		if((fp=fopen(file_name,"aw"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
		fseek(fp,0,SEEK_END);
		fprintf(fp,"%d   %s   %d   salesmanager\n",id,name,work_year);
		cout<<"                          ��ӳɹ�!"<<endl;
			personnel++;
	}
	else if(ans=='3'){
		cout<<"             �����뿪����Ա�Ĺ���,����,����,����ʱ��,����������"<<endl;
		cin>>id>>name>>work_year>>work_hour>>belong;
		for(i=0;i<size;i++){
			if(id==a[i]){
				cout<<"             �˹����Ѿ�����!�����²�����"<<endl;
				return;
			}
		}
		for(i=0;i<proj_mana_size;i++){
			if(belong==proj_mana[i].get_id()){
				break;
			}
		}
		if(i==proj_mana_size){
			cout<<"û�д���Ŀ����,����������!"<<endl;
			return;
		}
		DEVE temp(id,name,work_year,"developer",0,work_hour,belong);
		for(i=0;i<proj_mana_size;i++){
			if(proj_mana[i].get_id()==belong){
				proj_mana[i].add_deve(temp);
				break;
			}
		}
		if((fp=fopen(file_name,"aw"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
		fseek(fp,0,SEEK_END);
		fprintf(fp,"%d   %s   %d  developer  %d   %d\n",id,name,work_year,work_hour,belong);
		cout<<"                          ��ӳɹ�!"<<endl;
			personnel++;
	}
	else if(ans=='4'){
		cout<<"             ������������Ա�Ĺ���,����,����,���۶�,����������"<<endl;
		cin>>id>>name>>work_year>>sale_income>>belong;
		for(i=0;i<size;i++){
			if(id==a[i]){
				cout<<"             �˹����Ѿ�����!�����²�����"<<endl;
				return;
			}
		}
		for(i=0;i<sales_mana_size;i++){
			if(belong==sales_mana[i].get_id()){
				break;
			}
		}
		if(i==sales_mana_size){
			cout<<"û�д����۾���,����������!"<<endl;
			return;
		}
		SALESMAN temp(id,name,work_year,"salesman",2000,sale_income,belong);
		for( i=0;i<sales_mana_size;i++){
			if(sales_mana[i].get_id()==belong){
				sales_mana[i].add_salesman(temp);
				break;
			}
		}
		if((fp=fopen(file_name,"aw"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
		fseek(fp,0,SEEK_END);
		fprintf(fp,"%d  %s   %d  salesman  %d   %d\n",id,name,work_year,sale_income,belong);
		cout<<"                          ��ӳɹ�!"<<endl;
		personnel++;
	}
	else{
		cout<<"                       �Ƿ�����!"<<endl;
	}
	fclose(fp);
}

void COMPANY::del()
{
	FILE*fp;
	if((fp=fopen(file_name,"w"))==NULL){
		cout<<"���ܴ��ļ�"<<"\""<<file_name<<"\""<<endl;
		exit(1);
	}
	rewind(fp);
	fclose(fp);
	cout<<"                      ��ѡ��Ҫɾ������Ա!"<<endl;
	cout<<"                      1.��Ŀ����"<<endl
		<<"                      2.���۾���"<<endl
		<<"                      3.������Ա"<<endl
		<<"                      4.������Ա"<<endl;
	int id,j,flag=0,i;
	char ans;
	ans=getch();
	if(ans=='1'){
		cout<<"                      ����Ҫɾ������Ĺ���"<<endl;
		cin>>id;
		for(i=0;i<proj_mana_size;i++){
			if(id==proj_mana[i].get_id()){
				flag=1;
				if(proj_mana[i].empty()==false){
					cout<<"                 �˾������п�����Ա����ɾ��!"<<endl;
					break;
				}
				else{
					for(j=i;j<proj_mana_size-1;j++){
						proj_mana[j]=proj_mana[j+1];
					}
					personnel--;
					proj_mana_size--;
					cout<<"                     ��ɾ��!"<<endl;
				}
			}
		}
		if(flag==0){
			cout<<"����������������������û���������!"<<endl;
		}
	}
	else if(ans=='2'){
		cout<<"                      ����Ҫɾ������Ĺ���"<<endl;
		cin>>id;
		for(i=0;i<sales_mana_size;i++){
			if(id==sales_mana[i].get_id()){
				flag=1;
				if(sales_mana[i].empty()==false){
					cout<<"                 �˾�������������Ա,����ɾ��!"<<endl;
				}
				else{
					for(j=i;j<sales_mana_size-1;j++){
						sales_mana[j]=sales_mana[j+1];
					}
					personnel--;
					sales_mana_size--;
					cout<<"                     ��ɾ��!"<<endl;
				}
			}
		}
		if(flag==0){
			cout<<"����������������������û���������!"<<endl;
		}
	}
	else if(ans=='3'){
		cout<<"                      ����Ҫɾ���Ŀ�����Ա�Ĺ���"<<endl;
		cin>>id;
		for(i=0;i<proj_mana_size;i++){
			if(proj_mana[i].search(id)==true){
				proj_mana[i].del_deve(id);
				flag=1;
				personnel--;
			}
		}
		if(flag==0){
			cout<<"����������������������û���������!"<<endl;
		}
	}
	else if(ans=='4'){
		cout<<"                      ����Ҫɾ����������Ա����"<<endl;
		cin>>id;
		for(i=0;i<sales_mana_size;i++){
			if(sales_mana[i].search(id)==true){
				sales_mana[i].del_salesman(id);
				flag=1;
				personnel--;
			}
		}
		if(flag==0){
			cout<<"����������������������û���������!"<<endl;
		}
	}
	else{
		cout<<"                       �Ƿ�����"<<endl;
	}
	for(i=0;i<proj_mana_size;i++){
		proj_mana[i].write(file_name);
	}
	for(i=0;i<sales_mana_size;i++){
		sales_mana[i].write(file_name);
	}
}

int COMPANY::get_personnel()
{
	return personnel;
}

int COMPANY::get_tdeve_income()
{
	deve_income=0;
	for(int i=0;i<proj_mana_size;i++){
		deve_income+=proj_mana[i].get_deve_income();
	}
	return deve_income;
}

int COMPANY::get_tsalesman_income()
{
	salesman_income=0;
	for(int i=0;i<sales_mana_size;i++){
		salesman_income+=sales_mana[i].get_man_income();
	}
	return salesman_income;
}

int COMPANY::get_proj_mana_income()
{
	proj_mana_income=0;
	for(int i=0;i<proj_mana_size;i++){
		proj_mana_income+=proj_mana[i].get_income();
	}
	return proj_mana_income;
}

int COMPANY::get_sales_mana_income()
{
	sales_mana_income=0;
	for(int i=0;i<sales_mana_size;i++){
		sales_mana_income+=sales_mana[i].get_income();
	}
	return sales_mana_income;
}


int COMPANY::get_total_salary()
{
	total_salary=0;
	for(int i=0;i<proj_mana_size;i++){
		total_salary+=proj_mana[i].get_income();
		total_salary+=proj_mana[i].get_deve_income();
	}
	for(int i=0;i<sales_mana_size;i++){
		total_salary+=sales_mana[i].get_income();
		total_salary+=sales_mana[i].get_man_income();
	}
	return (int)total_salary;
}

int COMPANY::get_deve_num()
{
	deve_num=0;
	for(int i=0;i<proj_mana_size;i++){
		deve_num+=proj_mana[i].get_counter();
	}
	return deve_num;
}

int COMPANY::get_salesman_num()
{
	salesman_num=0;
	for(int i=0;i<sales_mana_size;i++){
		salesman_num+=sales_mana[i].get_counter();
	}
	return salesman_num;
}

void COMPANY::tav()
{
	for(int i=0;i<proj_mana_size;i++){
		proj_mana[i].trav();
		cout<<endl;
	}
	for(int i=0;i<sales_mana_size;i++){
		sales_mana[i].trav();
		cout<<endl;
	}
}

void COMPANY::output()
{
	cout<<"                      "<<com_name<<" �Ĺ����嵥"<<endl<<endl;
	cout<<"              ��˾������:    "<<personnel<<"  "<<" �ܹ���:"<<get_total_salary()<<endl;
	cout<<"              ��Ŀ��������:  "<<proj_mana_size<<"   ��Ŀ�����ܹ���: "<<get_proj_mana_income()<<endl;
	cout<<"              ���۾�������:  "<<sales_mana_size<<"   ���۾����ܹ���: "<<get_sales_mana_income()<<endl;
	cout<<"              ����Ա����:    "<<get_deve_num()<<"   ����Ա�ܹ���:  "<<get_tdeve_income()<<endl;
	cout<<"              ����Ա����:    "<<get_salesman_num()<<"   ����Ա�ܹ���:  "<<get_tsalesman_income()<<endl<<endl;
	cout<<"              ÿ��Ա������:"<<endl;
    cout<<"              Ա������"<<"  "<<"����"<<"    "<<"ְλ"<<"��     "<<"��н"<<endl;
	for(int i=0;i<proj_mana_size;i++){
		proj_mana[i].output();
	}
	for(int i=0;i<sales_mana_size;i++){
		sales_mana[i].output();
	}
}
int main()
{
	COMPANY my("lihao","���ʹ���ϵͳ.txt");
	cout<<"================================��ӭ���빤��ϵͳ!===============================";
	char ans;
	while(1){
		cout<<endl<<endl;
		cout<<"                      ��������Ҫ����:"<<endl;
		cout<<"                      1.���Ա��"<<endl
			<<"                      2.ɾ��Ա��"<<endl
			<<"                      3.��ʾ�����嵥"<<endl
			<<"                      4.�˳�"<<endl<<endl;
		ans=getch();
		switch(ans){
		case '1':my.add();
			break;
		case '2':my.del();
			break;
		case '3':my.output();
			break;
		case '4':return 0;
		}
		system("pause");
	}
   return 0;
}




















