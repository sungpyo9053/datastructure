#include <iostream>

#include <cstring>

#include <stdlib.h>

#include <cstdlib>

 

using namespace std;

 

class Node{

private:

  char data;

  Node *next;

  Node(int value)

  {data = value; next =0;}

  friend class linkedStack;

};

class linkedStack{

private:

  Node *head=NULL;

 

public:

  linkedStack(){head=0;}

 

  void createStack();

  void push(char data);

  void pop();

  int isEmptyStack();

  void displayStack();

  void searchStack(char);

  void LengthS();

};

 

 

void linkedStack::createStack()

{head = 0;}

 

void linkedStack::push(char data)

{

  Node *temp = new Node(data);

 

  if(head==0)

  head = temp;

  else{

    temp->next = head;

    head = temp;

  }

}

 

void linkedStack::pop()

{

  Node *p; char num;

 

  num = head->data;

  p=head;

  head = head->next;

  delete p;

  cout << num << "팝됨" << endl;

}

 

int linkedStack::isEmptyStack()

{

  if(head==0)

  return 1;

  else

  return 0;

}

 

void linkedStack::displayStack()

{

  Node *p;

  if(!isEmptyStack())

  {

    p=head;

    while(p)

    {

      cout << p->data;

      p=p->next;

    }

    cout << endl;

  }

  else

  cout << "스택이 비었습니다.\n";

}

 

 

 

 

 

class Node2{

private:

  char data;

  Node2 *next;

  Node2(char value)

  {data = value; next =0;}

  friend class link;

};

class link{

private:

  Node2 *front = NULL;

  Node2 *rear = NULL;

public:

  void linkedQueue(){front=0;rear=0;}

 

  void createQueue();

  void enqueue(char);

  void dequeue();

  int isEmpty();

 

  void LengthQ();

  void Displayqueue();

};

/*void link::Search(int num)

{

  Node2 *p = NULL;

  if(front!=0)

  {

    p=front;

    while(p!=0&&p->data!=num)

    {

      p= p->next;

    }

    if(p->data ==num)

    {

      cout << p->data << "있다" << endl;

    }

    else if(p->next ==NULL)

    cout << num << "없다" << endl;

  }

  else

  cout << "빔" << endl;

}*/

 

int link::isEmpty()

{

  if(front==0)

  return 1;

  else

  return 0;

}

 

void link::createQueue()

{

  front =0; rear=0;

}

 

void link::enqueue(char data)

{

  Node2 *temp = new Node2(data);

 

  if(front==0)

  {

    front = temp;

    rear = temp;

  }

  else{

    rear->next = temp;

    rear = temp;

  }

}

 

void link::dequeue()

{

  Node2 *p; char num;

  num = front->data;

  p=front;

 

  front=front->next;

 

  delete p;

  cout << num;

}

 

void link::Displayqueue(){

  Node2 *p;

 

  if(!isEmpty())

  {

    p=front;

    while(p)

    {

      cout << p->data;

      p=p->next;

    }

    cout << endl;

  }

  else

  cout << " 큐가 빔\n";

}

 

 

 

 

void linkedStack::LengthS()

{

  Node *temp;

  int count1 =0;

  if(head)

  {

    temp = head;

    do{

      count1++;

      temp = temp->next;

    }while(temp!=head);

  }

  cout << count1 << endl;

}

 

void link::LengthQ()

{

  Node2 *temp;

  Node2 *temp2;

  int count2 =0;

  if(front)

  {

    temp = front;

    temp2 = rear;

    do{

      count2++;

      temp = temp->next;

    }while(temp2!=rear);

  }

  cout << count2 << endl;

}

 

int main()

{

  char input[10];

  char k;

  linkedStack l;

  link l2;

  int num;

 

  while(1)

  {

  cout << "명령어를 입력(1.Push,2.Pop,3,enqueue,4.dequeue,5.display,6.Length,7.Quit)";

  cin >> input;

 

  if(strcmp(input,"1")==0)

  {

    cout << "push 할 값 입력 :";

    cin >>k;

    l.push(k);

  }

  else if(strcmp(input,"2")==0)

  {

    if(!l.isEmptyStack())

    {

    l.pop();

    }

    else

    cout << "스택이 빔";

  }

  else if(strcmp(input,"3")==0)

  {

    cout << "enqueue 할 값 입력";

    cin >> k;

    l2.enqueue(k);

  }

  else if(strcmp(input,"4")==0)

  {

    if(!l2.isEmpty())

    {

      l2.dequeue();

      cout << "디큐됨\n";

    }

    else

    cout << "큐가 빔\n";

  }

 

  else if(strcmp(input,"5")==0)

  {

    cout << "stack :";

    l.displayStack();

    cout << endl;

    cout<< "queue :";

    l2.Displayqueue();

    cout << endl;

  }

  else if(strcmp(input,"6")==0)

  {

    cout << "stack 의 길이 :";

    l.LengthS();

    cout << endl;

    cout << "qeueu 의 길이 :";

    l2.LengthQ();

    cout << endl;

 

  }

  else if(strcmp(input,"7")==0)

  {

    break;

  }

  else

  cout << "잘못된 커맨드";

 

}

  return 0;

 

}

 
