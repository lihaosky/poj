#ifndef SUDU_H_INCLUDED
#define SUDU_H_INCLUDED
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


#endif // SUDU_H_INCLUDED
