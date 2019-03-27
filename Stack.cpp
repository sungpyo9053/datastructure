#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>


const char stackSize = 30;
char stack[stackSize];
int top;

using namespace std;

void create_stack();
void push(char num);
void displayStack();
char pop();
int isFull();
int isEmpty();

void create_stack() //스텍 생성
{
  top = -1;
}

void push(char num) //값 입력
{

  stack[++top] = num;
}

char pop()  //출력
{

  return stack[top--];
}

int isFull()
{
  if(top==stackSize-1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}

void displayStack()  //스택 나열
{

  if(isEmpty())
    cout << "Stack is empty!" << endl;
  else
  {
    for(int sp = 0 ; sp <=top ; sp++)
    {
      cout << stack[sp] << " ";
    }
    cout << endl;
  }
} 

int main(){
}
