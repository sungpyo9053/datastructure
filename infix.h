/*************************************************************************/
/*                         헤더파일(함수 선언)                               */
/*************************************************************************/


//postfix에 필요한 함수들을 선언한다.
//메인에서 필요한 헤더파일들을 참조한다.


#include <iostream>
#include <cstring>

using namespace std;

void create_stack();
void push(char num);
int pop();
int prior(char num);
int isEmpty();
void eval(char *a , int b);
