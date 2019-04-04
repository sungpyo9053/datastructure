/**************************************************************************/
/**               project : Postfix                                      **/
/**             국민대학교 소프트웨어학부 20152900 홍성표                   **/
/**************************************************************************/

/**************************************************************************/
/*                     파일의 메인부분                                      */
/*************************************************************************/

#include "infix.h"
#include "infixADT.cpp"

int main()
{
  char input[100];
  int temp;
  int index = 0 ;
  int j = 0 ;

  create_stack(); //스택 생성

  cout << "수식을 입력하세요." << endl;
  cin >> input;

  temp = strlen(input);

  while(j!=temp)
  {

      if(isdigit(input[j])==1) //숫자일떄
      {
          postfix[index++] = input[j]; //숫자일 떄는 배열에 숫자를 저장
          j++;
      }

      else if( input[j] == '(' )   //좌괄호일떄
      {
          push( input[j] );
          j++;
      }

      else if( input[j] == ')' ) //우괄호일때
      {


            while( stack[top] != '(' )  //좌괄호가 나올때까지 pop
            {
                postfix[index++]=pop();
            }

            pop(); //좌괄호를 버린다

            j++;

    }
    else   //연산자일떄
    {
        if( prior(stack[top])<=prior(input[j])  )//스택의 top에 있는 연산자 우선순위가
        {                                        //input값보다 작은경우 push
              push(input[j]);
        }
        else
        {
            while(  !isEmpty() && ( prior(stack[top] )  >= prior(input[j]) ) )
            {                                       //스택의 top에 있는 연산자 우선순위가
                                                //input값보다 큰 경우 pop
                postfix[index++] = pop();
            }
            push(input[j]); //input값은 push
        }
            j++;
    }


  }


  while( !isEmpty() ) //스택에 데이터가 남아있으면 전부 pop
  {
        postfix[index++] = pop();
  }

  cout << input << endl; //input한 수식 출력

  for(int x = 0 ; x < index ; x++) //postfix가 실행된 후에 수식 출력
      cout << postfix[x] ;

  cout << endl;

  eval( postfix , index); //postfix를 계산한 결과값을 출력

  cout << endl;


  return 0;
}
