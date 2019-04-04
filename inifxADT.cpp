/****************************************************************************/
/*              함수와 전역변수를 선언하고 정의하는 파일                            */
/****************************************************************************/



#include "infix.h"


 const int Stacksize = 100;
 char stack[Stacksize]; //스택
 char postfix[Stacksize];  //postfix가 실행된 결과를 저장하는 배열
 int top ;

void create_stack()   //스택생성하는 함수
{
  top = -1;
}

void push(char num)  // push함수
{
  ++top;
  stack[top] = num;
}

int pop() //pop함수
{
  return stack[top--];
}

int prior(char num)  //연산자 우선순위를 확인하는 함수
{

  switch(num)   //리턴값이 큰 수가 우선순위가 위에 있다.
  {
      case ')' :
      return 3;
      break;
    case '*' : case '/'  :
      return 2;
      break;
    case '+' : case '-' :
      return 1;
      break;
    case '(' :
      return 0;
      break;
    default :
      return 0;
      break;
  }

}

int isEmpty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}

void eval(char *a , int b) //후위표기된 식을 계산하는 함수
{
    int result;
    char arry[100];
    int j = 0 ;
    int op1 , op2 ;


  for(int i = 0 ; i < b ; i++)
  {
        arry[i] = *(a++);
  }

  while(j!=b)
  {
        if(isdigit(arry[j])==1) //숫자일때
        {
            push(arry[j]-48); //입력된 숫자는 스트링으로 인식되기 때문에 아스키코드상으로 48을
            j++;              //빼주면 원래 숫자를 입력할 수 있다.
        }
        else
        {
            op1 = pop(); //연산자를 만나면 피연산자를 pop해서 연산을 실행한다
            op2 = pop();

            switch(arry[j])
            {
                case '+':
                  push(op1+op2);
                  break;
                case '-' :
                  push(op2-op1);
                  break;
                case '*' :
                  push(op1*op2);
                  break;
                case '/' :
                  push(op1/op2);
                  break;
              }
              j++;
          }
    }
    result = pop();

    cout << result;
  }
