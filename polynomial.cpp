#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Matrix{
    float coefficient;
    int exponential;
};

int main()
{
  ifstream inStream;
  inStream.open("input.txt");

  Matrix *A;
  Matrix *B;

  int cnt_a, coe_a, exp_a;
  int cnt_b, coe_b, exp_b;
  
  inStream >> cnt_a;

  A = new Matrix[cnt_a];

  for(int x1 = 0 ; x1 < cnt_a ; x1++){
    
        inStream >> exp_a >> coe_a;

        A[x1].coefficient = coe_a;
        A[x1].exponential = exp_a;
    
  }

  inStream >> cnt_b;

  B = new Matrix[cnt_b];

  for(int x2 = 0 ; x2 < cnt_b ; x2++){

        inStream >> exp_b >> coe_b;

        B[x2].coefficient = coe_b;
        B[x2].exponential = exp_b;
  }

  for(int i = 0 ; i < cnt_a ; i++){
      cout << A[i].coefficient << " " << A[i].exponential << endl;
  }

  for(int i = 0 ; i < cnt_b ; i++){
      cout << B[i].coefficient << " " << B[i].exponential << endl;
  }

  Matrix C[100] ;

  int sa = 0 , sb = 0 , fa = cnt_a-1 , fb = cnt_b-1 ; //각 다항식의 배열 인덱스를 설정하기 위한 변수선언
  int i ;
  int num;

  cout << "1.덧셈 2.뺄셈 " << endl;
  cin >> num;

  if( num == 1 ) //덧셈연산
  {
    i = 0;

    while((sa<=fa)&&(sb<=fb))
    {
      if(A[sa].exponential < B[sb].exponential)  //
      {
            C[i].coefficient = B[sb].coefficient;
            C[i].exponential = B[sb].exponential;
            sb++;
            i++;
      }
      else if(A[sa].exponential == B[sb].exponential)
      {
             C[i].exponential = A[sa].exponential;
             C[i].coefficient = A[sa].coefficient + B[sb].coefficient;
             sa++;
             sb++;
             i++;

      }
      else if(A[sa].exponential > B[sb].exponential)
      {
            C[i].exponential = A[sa].exponential;
            C[i].coefficient = A[sa].coefficient;
            sa++;
            i++;
      }
    }
    if((sb==fb)&&(sa!=fa)){
      for(int j = sa ; j < fa; j++){
            C[i].exponential = A[j].exponential;
            C[i].coefficient = A[j].coefficient;
            i++;
      }

    }
   
    else if((sa==fa)&&(sb!=fb)){
        for(int k = sb ; k < fb; k++){
            C[i].exponential = B[k].exponential;
            C[i].coefficient = B[k].coefficient;
            i++;
        }
    }

    for(int x = 0 ; x < i  ; x++){
        cout << C[x].coefficient << " " << C[x].exponential << endl;
    }
  }

  else if( num == 2)
  {
    i = 0;
    
    while((sa<=fa)&&(sb<=fb))
    {
      if(A[sa].exponential < B[sb].exponential)
      {
        C[i].exponential = B[sb].exponential;
        C[i].coefficient = -B[sb].coefficient;
        sb++;
        i++;
      }
      else if(A[sa].exponential == B[sb].exponential)
      {
        C[i].exponential = A[sa].exponential;
        C[i].coefficient = A[sa].coefficient - B[sb].coefficient;
        sa++;
        sb++;

        if(C[i].coefficient != 0)
            i++;

      }
      else if(A[sa].exponential > B[sb].exponential)
      {
        C[i].exponential = A[sa].exponential;
        C[i].coefficient = A[sa].coefficient;
        sa++;
        i++;
      }
    }

    if((sb==fb)&&(sa!=fa))
    {
        for(int j = sa ; j < fa; j++)
        {
            C[i].exponential = A[j].exponential;
            C[i].coefficient = A[j].coefficient;
            i++;
        }

    }
    else if((sa==fa)&&(sb!=fb))
    {
        for(int k = sb ; k < fb; k++)
        {
            C[i].exponential = B[k].exponential;
            C[i].coefficient = -B[k].coefficient;
            i++;
        }
    }

    for(int x = 0 ; x < i  ; x++){
        cout << C[x].coefficient << " " << C[x].exponential << endl;
    }
 
}
  return 0;
}  
