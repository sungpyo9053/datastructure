#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};
class List{
    private:
        Node *head;
    public:
        List() { 
            head =0;
            }
        void insertNode(int data);
        void deleteNode(int num);
        bool isEmpty();
        void traverseList(int num);
        void invertList();
        void printLast();
        void printNth(int N);
        // void serchList(int num);
        void display();
};

bool List::isEmpty(){
    if (head == 0){
        return true;
    }
    else{
        return false;
    }
} 

void List::display()
{
    Node *ptr = head;
    
    while(ptr){
    cout<< ptr->data <<endl;
    ptr = ptr->next;
    }
}
void List::insertNode(int data){
    
    Node *temp = new Node();
    Node *p,*q; 

    temp->data = data;

    if (head == 0 ){
        cout << "Head is null" << endl;
        head = temp;
    } 
    else if(temp->data  <  head->data){ // 앞에다 삽입
        temp->next = head; 
        head = temp;
    }
    else{
        p = head;
        while((p!=0)&&(p->data < temp ->data)){
            q = p;
            p = p->next;
        }
        if (p!=0){
            temp ->next =p;
            q ->next =temp;
        }
        else
        {
            q->next = temp;
        }
        
    }
}
void List::deleteNode(int num){
    Node *p,*q;

    if(head->data == num){
        p = head;
        head = head -> next;
        delete p;
        //지워야하는게 해드면
    }
    else
    {
        p = head;
        while(p!=0 && p->data != num){
            q = p;
            p = p->next;
        } // 숫자 찾기
        if(p!=0){
            q->next = p->next;
            delete p;
        } // 찾으면 지우기
        else
        {
            cout<< num << "is not in the list"<<endl;
        } // 없으면 리스트에 없는수
        
    }
}
// void List::serchList(int num){
//     Node *p;

//     if (!isEmpty()){
//         p = head;
//         while(p){
//             cout<<p->data;
//             p = p -> next;
//         }
//         cout<< endl;
//     }
//     else
//     {
//         cout<<"List is empty"<<endl;
//     }
    
// }

// List::~List(){
//     Node*p;
//     while (head !=0){
//         p = head;
//         head = head -> next;
//         delete p;
//     }
// }

void List::traverseList(int num){
    Node *p;
    if (head != 0){
        p = head;
        while( p!= 0 && p->data != num){
            p = p ->next;
        }
        if (p){
            cout<< p ->data <<" is found"<<endl;
        }
        else
        {
            cout<< num << " is not in the list"<<endl;
        }
        
    }
    else
    {
        cout<< "List is empty"<<endl;
    }
    
}

  void List::invertList(){
      stack<int> s;
      Node *p = head;

      if(head == 0){
          cout << "List is empty" << endl;
      }
      else{
          while(p != 0){
              s.push(p->data);
              p = p->next;
          }

          while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
          }
      }

  }
  void List::printLast(){
      Node *p = head;

      if(head == 0){
        cout << "List is empty" << endl;
      }
      else{
        while(p->next != 0){
            p = p-> next;
        }

        cout << p->data << endl;
      }
  }

  void List::printNth(int N){
      Node *p = head;
      if(head == 0) {
        cout << "List is empty" << endl;
        return;
      }

      for(int i =0 ; i < N-1 ; i++){
         p = p-> next;
         if(p == 0){
            cout << "List error" << endl;
            return;
         }
      }

      cout << p->data << endl;
  }

int main(){
    List l;

    // l.deleteNode(10);
    l.insertNode(10);
    l.insertNode(5);
    l.display();

    l.insertNode(30);
    l.traverseList(5);

    l.deleteNode(5);
    l.display();

    l.traverseList(3);


    l.printLast();
    
    l.insertNode(40);
    l.invertList();
    
    
    return 0;
}
