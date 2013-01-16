//At last I got this programm
//the method is simple...
//input the number in sudoku 0 for number to be completed
//output the outcome
//if input is invalid  I will warn you
//LIHAO NOV 26th 2008
//HKU Libarary
//////////////////////////////////////////////////////////////

#include<iostream>
#include<ctime>

using namespace std;
struct grid
{
       int row;
       int col;
       int value;
       int val[9];
       int val_size;
       int num;
};



class sudu
{private:
        grid cell[9][9];
        grid buffer[81];
        int size;
        int pos;
  public:
         sudu();
         void indata();
         bool isvalid();
         bool check();
         void forward();
         void backward();
         void increase();
         bool isflow();
         bool isfail();
         bool isend();
         void show();
         void print();
         ~sudu();
};

sudu::sudu()
{
    pos=-1;
    size=0;
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                    cin>>cell[i][j].value;
                    cell[i][j].row=i;
                    cell[i][j].col=j;
                    cell[i][j].val_size=0;
                    cell[i][j].num=0;
            }
     }
}


bool sudu::isvalid()
{
     for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                     if(!cell[i][j].value){continue;}
                     for(int m=0;m<9;m++){
                             if(m==i||m==j){continue;}
                             if(cell[i][j].value==cell[i][m].value||cell[i][j].value==cell[m][j].value){return false;}
                     }
                     for(int k=i/3*3;k<i/3*3+3;k++){
                             for(int l=j/3*3;l<j/3*3+3;l++){
                                     if(i==k&&j==l){continue;}
                                     if(cell[i][j].value==cell[k][l].value){return false;}
                                     }
                     }
             }
     }
     return true;
}

void sudu::show()
{
     cout<<"The original sudoku is:"<<endl;
     for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                     cout<<cell[i][j].value<<"  ";
                     }
                     cout<<endl;
     }
}

void sudu::indata()
{
     int temp[9];
     int num=0;
     for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                     if(cell[i][j].value){continue;}
                     num=0;
                     for(int m=0;m<9;m++){
                             if(cell[i][m].value){
                                                  temp[num++]=cell[i][m].value;
                                                  }
                             if(cell[m][j].value){
                                                  int k;
                                                  for( k=0;k<num;k++){
                                                          if(temp[k]==cell[m][j].value){
                                                                                        break;
                                                                                        }
                                                          }
                                                          if(k==num){
                                                                     temp[num++]=cell[m][j].value;
                                                          }
                                  }
                     }
                     int p=i/3*3;
                     int q=j/3*3;
                     for(int s=p;s<p+3;s++){
                             for(int t=q;t<q+3;t++){
                                     if(cell[s][t].value){
                                                  int k;
                                                  for( k=0;k<num;k++){
                                                          if(temp[k]==cell[s][t].value){
                                                                                        break;
                                                                                        }
                                                          }
                                                          if(k==num){
                                                                     temp[num++]=cell[s][t].value;
                                                          }
                                  }
                             }
                     }

                     for(int k=1;k<10;k++){
                             int n;
                             for( n=0;n<num;n++){
                                     if(temp[n]==k){break;}
                             }
                             if(n==num){
                                        cell[i][j].val[cell[i][j].val_size++]=k;
                             }
                     }
                     buffer[size++]=cell[i][j];
             }
     }
}

void sudu::print()
{
     int k=0;
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                    if(!cell[i][j].value){
                                          cell[i][j].value=buffer[k++].value;
                                          }
                    cout<<cell[i][j].value<<"  ";
                    }
                    cout<<endl;
    }

}

bool sudu::isflow()
{
     if(buffer[pos].num>=buffer[pos].val_size){
                                               return true;
                                               }
     return false;
}
void sudu::forward()
{
     pos++;
     if(pos==size){return ;}
     buffer[pos].value=buffer[pos].val[buffer[pos].num];
     buffer[pos].num++;
}

void sudu::backward()
{
     buffer[pos].value=0;
     buffer[pos].num=0;
     int flag=0;
     pos--;
     while(!flag){
                  if(buffer[pos].num>=buffer[pos].val_size){buffer[pos].value=0;buffer[pos].num=0;pos--;}
                  else{flag=1;}
     }
     if(pos<0){return;}
     buffer[pos].value=buffer[pos].val[buffer[pos].num];
     buffer[pos].num++;
}

bool sudu::check()
{
     for(int i=0;i<pos;i++){
             if((buffer[i].row==buffer[pos].row)&&(buffer[i].value==buffer[pos].value)){
                     return false;
             }
             if((buffer[i].col==buffer[pos].col)&&(buffer[i].value==buffer[pos].value)){
                     return false;
             }
             if((buffer[i].row>=buffer[pos].row/3*3)&&(buffer[i].row<(buffer[pos].row/3*3+3))&&(buffer[i].col>=buffer[pos].col/3*3)&&(buffer[i].col<(buffer[pos].col/3*3+3))&&(buffer[i].value==buffer[pos].value)){
             return false;
             }
             }
     return true;
}

void sudu::increase()
{
     buffer[pos].value=buffer[pos].val[buffer[pos].num++];
}
bool sudu::isfail()
{
     if(pos<0){return true;}
     return false;
}

bool sudu::isend()
{
     if(pos==size){return true;}
     return false;
}

sudu::~sudu()
{
}


int main()
{

    bool end=false;
    bool fail=false;
    cout<<"********************************************************************************"<<endl;
    cout<<"        ___      _   _       ___           ___        _  _        _   _      "<<endl;
    cout<<"      /  __|    | | | |     |  _ \\        / _ \\      | |/ /      | | | |      "<<endl;
    cout<<"      \\__  \\    | |_| |     | (_| |      | (_| |     |   |       | |_| |      "<<endl;
    cout<<"      |____/     \\__,_|     |___ /        \\___/      |_|\\_\\       \\__,_|     "<<endl;
    cout<<"                                                                            "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"Input your number, input space as 0"<<endl;
    sudu a;
    cout<<endl<<endl;
    clock_t start=clock();
    a.show();
    if(!a.isvalid()){cout<<"This sudoku is invalid!"<<endl;system("PAUSE");return 0;}
    a.indata();
    while(1){
            if(a.check()){a.forward();}
            else{
                 if(!a.isflow()){a.increase();}
                 else{a.backward();};
                 }
            if(a.isend()){end=true;break;}
            if(a.isfail()){fail=true;break;}
    }
    if(fail){cout<<endl<<endl<<"No answer"<<endl;}
    if(end){ cout<<endl<<endl<<"The answer is:"<<endl; a.print();}
}




