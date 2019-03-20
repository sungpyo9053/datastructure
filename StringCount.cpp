#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int WordCount(char arr[],int num)
{
  int i =0;
  int in =1;
  int out =0;
  int state =out; // 0 이 대입됌.

  while (arr[i] != '\0'){ // NULL 표시 
    if (isalpha(arr[i])){
      if(state == out){
        num++;
        state =in;
      }
    }
    else if(arr[i] == char(' ')){
      state = out;
          }
    i++;
  }
   cout<< "number of words :" <<num<<endl;
   return num;
}

int main(){
  int a = 0;
  ifstream infile;
  char buffer[80];
  infile.open("lab0-1",ios::in);
  if(infile.fail())
  {
    cout<<"can't open the input file"<<endl;
    exit(1);
  }
  while(infile.getline(buffer,80)){
    int b= WordCount(buffer,0);
    a = a+ b;
  }
  cout<<"ToTal number of words : "<<a<<endl;
}
