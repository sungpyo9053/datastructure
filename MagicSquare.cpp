#include <iostream>
 
#define MAX_SIZE 100


using namespace std;

void magic(int n);

int main()

{

  int numdata;
  cout << "size" << endl;

  cin >> numdata;

  magic(numdata);
  return 0;

}

void magic(int num)

{

  int sqr[MAX_SIZE][MAX_SIZE]={{0},{0}};

  int k , l;

  sqr[0][(num-1)/2]=1;
  int key = 2;
  int i = 0 ;
  int j = (num-1)/2;

  if((num%2)!=0)

    {

      while(key<=num*num)

      {

        if(i-1<0)  
   	      k=num-1;   
          else

   	      k=i-1;
          if(j-1<0) 

    	     l=num-1;
           else

    	      l=j-1;

          if(sqr[k][l])

            i=(i+1)%num;  

          else
          {

            i=k;

            j=l;

          }

        sqr[i][j]=key;

        key++;

      }
      for(int x = 0  ; x < num ; x++)

      {

        for(int y = 0 ; y < num ; y++)

        cout << sqr[x][y] << " ";
        cout << endl;

      }
    }

else

  cout << "잘못된 입력입니다." << endl;



}
