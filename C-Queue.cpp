#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

const char stackSize = 2;
char stack[stackSize];
int top;

using namespace std;

void create_stack();
void push(int num);
void displayStack();
int pop();
int isFull();
int isEmpty();



  int front; int rear;
  const char sizeQueue=3 ;
  char queue[sizeQueue];

  void create_queue();
  void enQueue(int value);
  int deQueue();
  int queue_full();
  int queue_empty();
  void print();



void create_queue() { front = -1;
rear = -1; }



void Enqueue (int item)
{

  if (rear == sizeQueue-1)
  {
    queue_full();
    return ;
  }
  queue[++rear] = item;
}



int queue_full()
{
  if (rear==sizeQueue-1)
    return 1;
  else
   return 0;
 }

int queue_empty()
{
  if (front ==rear)
    return 1;
  else
    return 0;
 }



int dequeue ()
{

  if (front == rear)
    return queue_empty();
  else /* 에러 key를 반환 */
    return queue[++front];
}

void print_queue() {
int i;
if (queue_empty())
cout << "Queue is Empty!\n";
else {
i = front + 1;
cout << "-- Print Queue --\n";
while (i <= rear) {
cout << queue[i];
i = i + 1;
}
}
}


const int cq_size = 3;

char Cqueue[cq_size];
int c_front , c_rear;

void create_c_queue(){
    c_front = -1;
    c_rear = -1;
}

void CEnque(char value){
       if ((c_front == 0 && c_rear == cq_size-1) || (c_rear == (c_front-1)%(cq_size-1))) { 
            cout << "Queue is Full" << endl; 
            return; 
        } 
  
         else if (c_front == -1) /* Insert First Element */{ 
            c_front = c_rear = 0; 
            Cqueue[c_rear] = value; 
        } 
  
        else if (c_rear == cq_size-1 && c_front != 0) { 
            c_rear = 0; 
            Cqueue[c_rear] = value; 
        } 
  
        else{ 
            c_rear++; 
            Cqueue[c_rear] = value; 
        } 
}

char CDeque(){
    if (c_front == -1) 
    { 
       cout << "Queue is Empty" << endl; 
        return -1; 
    } 
  
    char data = Cqueue[c_front]; 
    Cqueue[c_front] = -1; 

    if (c_front == c_rear) 
    { 
        c_front = -1; 
        c_rear = -1; 
    } 
    else if (c_front == cq_size-1) 
        c_front = 0; 
    else
        c_front++; 
  
    return data; 
}

void display_cq(){
    if (c_front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (c_rear >= c_front) 
    { 
        for (int i = c_front; i <= c_rear; i++) 
            printf("%c \n",Cqueue[i]); 
    } 
    else
    { 
        for (int i = c_front; i < cq_size; i++) 
            printf("%c \n", Cqueue[i]); 
  
        for (int i = 0; i <= c_rear; i++) 
            printf("%c \n", Cqueue[i]); 
    } 
}

int main()
{
  
  char input[5];
  create_stack();
  create_queue();
  create_c_queue();

    

  while(1)
  {

    cout << "1.Push 2.Pop 3.Enque  4.Deque 5.Displaystack 6.Displayque 7.exit 8 Cenque 9.CDeque 10. displayCQ \n";
    cin >> input;
    char num;
    if(strcmp(input,"1")==0) //푸쉬
    {
      if(!isFull())
        {
          cout << "Enter an char to push => " ;
          cin >> num;
          push(num);
        }
      else
        cout << "Stack is full!\n";
    }

    else if(strcmp(input,"2")==0) //팝
    {
      if(!isEmpty())
      {
        num=pop();
        cout << num << endl;
      }
      else
        cout << "Stack Empty!\n";
    }
    else if (strcmp(input,"3")==0) //3  enque
    {
          if(!queue_full()){
            cout << "Enter char to Enque => " ;
            cin >> num ;
            Enqueue(num);
          }
          else
            cout << "Queue Full!\n";

    }
    else if (strcmp(input,"4")==0) //4   deque
    {
      if(!queue_empty())
      {
          num=dequeue();
          cout << num << endl;
      }
      else
        cout << "Queue empty!\n";
    }

    else if(strcmp(input,"5")==0) //디스플레이스택
      displayStack();

    else if (strcmp(input,"6")==0) //6 displayque
      {
          print_queue();
      }

    else if(strcmp(input,"7")==0) //나가기
      exit(0);
    else if(strcmp(input,"8")==0){
         
         cout << "Enter an char to push => " ;
         cin>>num;
        CEnque(num);
    }
    else if(strcmp(input,"9")==0){
        CDeque();
    }
    else if(strcmp(input,"10")==0){
        display_cq();
    }

    else{
      cout << "Bad Command!\n";
    }
  }

  return 0;
}

 //스택 정의
//함수 정의
void create_stack() //스텍 생성
{
  top=-1;
}

void push(int num) //값 입력
{
  ++top;
  stack[top] = num;
}

int pop()  //출력
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
