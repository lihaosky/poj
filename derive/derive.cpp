//
//show how to use derivatives in class
//LiHao 2008/11/10
//


#include<iostream>
using namespace std;
class person
{private:
         string name;
         int age;
public:
       person(string name,int age){this->name=name;this->age=age;}
       string get_name()const{return name;};
       int get_age()const{return age;};
};

class student:public person
{private:
         int stu_num;
         int grade;
public:
       student(string name,int age,int stu_num,int grade):person(name,age){this->stu_num=stu_num;this->grade=grade;}
       int get_stu_num()const{return stu_num;};
       int get_grade()const{return grade;};
};
int main()
{
    student me("lihao",21,2008,100);
    cout<<"name: "<<me.get_name()<<" age: "<<me.get_age()<<" student number: "<<me.get_stu_num()<<" grade: "<<me.get_grade()<<endl;
    system("PAUSE");
}
