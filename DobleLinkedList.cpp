#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


using namespace std;



struct Node{
    Node *next;
    Node *prev;
    string name;
    int weight;
    int height;   
    };
class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        void intsertList(string name,int weight, int height);
        void deleteList(string name, int weight, int height);
        void forwardList();
        void backwardList();
        void searchList(string name);
        int isEmpty();
        // void locateCurrent(char data);
        void displayList();
        void insertBefore(string name,int count);
        void insertAfter(string name, int weight, int height,int count);
        int length();
        void locateCurrent(int data);

};


int List::length(){
 Node *p;
 int count;
 p =head;

 if(head ==0){
     count = 1;
 }
 else 
 { 
    while(p->next !=0){
        count ++;
        p = p ->next;   
    }
 }
 
return count++;
}

void List::displayList(){
    
    Node *ptr = head;
  //  cout << ptr>name << endl;   
    while(ptr){ 
    cout<< ptr->name << " " << ptr->weight << " " << ptr->height <<endl;
    ptr = ptr->next;
    }
}

int List::isEmpty(){
    
    if (head ==0){
        return 1;
    }
    else 
        return 0;
}

List::List(){
    head = 0;
   // int current = 0;
}
List::~List(){
    Node *p;

    while(head!=0){
        p = head;
        head = head ->next;
        delete p;
    }
}
void List::intsertList(string name, int weight, int height){
    Node *temp = new Node();
    Node *p,*q;

    temp->name = name;
    temp->weight = weight;
    temp->height = height;
    temp->next = 0;
    temp->prev = 0;

    if(head ==0){
        head = temp;
    }
    else if( temp -> name < head->name ){
        temp->next = head;
        head ->prev =temp;
        head = temp;
    }
    else
    {
        p =head;
        q = head;
        while((p!=0)&& (p->name < temp->name)){
            q = p;
            p = p->next;
        }
        if ( p!=0){
            temp -> next =p;
            temp -> prev = q;
            q->next =temp;
            p->prev = temp;
        }
        else
        {
            q -> next =temp;
            temp -> prev =q;
        }
    }
}
    
void List::deleteList(string name, int weight, int height){
    Node *p , *q;

    if(head ==0){
        cout<< "list is empty"<<endl;
    }
    else{
        if (head -> name ==name){
            if (head->next !=0){
                p = head;
                head = head->next;
                head ->prev = 0;
                delete p;
            }
        }
        else{   
           q = head;
           p = head;
           while( p!=0 && p->name !=name){
               q = p;
               p = p->next;
           }
           if(p ==0 )
                cout<< name << "is not in the list"<<endl;
           else if ( p->next !=0 && p->name ==name){
               q->next = p->next;
               p->next->prev =q;
               delete p;
           }
           else if( p->next ==0 && p->name ==name){
               q->next = 0;
               delete p;
           }
           
        }
    }
}
    void List::forwardList(){
        
        if(!isEmpty()){
            Node *p = head;
            cout<< "====== Forward List ======="<<endl;
            
            while(p!=0){
                cout<< p->name <<" "<<p->weight<<" "<< p->height<< endl;
                p = p->next;
            }
        }
        else
        {
            cout<< "List is empty"<<endl;
        }
    }
    void List::backwardList(){
        if (!isEmpty()){
            Node *p = head;
            while(p->next !=0){
                p= p->next;
            }
            cout<<"========Backward List =========="<<endl;
            while(p!=0){
                cout<< p->name <<" "<<p->weight<<" "<<p->height<<endl;
                p = p->prev;
            }
        }
        else
        { 
            cout<<"list is empty"<<endl;
        }
        
    }
    void List::searchList(string name){
        
        if (!isEmpty()){
            Node *p = head;
            while( p!=0 && p->name !=name){
                p = p->next;
            }
            if (p!=0){
                cout<< p->name <<" "<<"is in the list"<<endl;
            }
            else
            {
                cout<< name <<" "<<"is not in the list"<<endl;
            }
        }
        else
        {
            cout<< "list is empty"<<endl;
        }
        
    }
void List::insertAfter(string name, int weight, int height,int count)
{

    Node *temp = new Node();
    temp ->name = name;
    temp ->weight = weight;
    temp ->height = height;
    Node *p , *q;

 

    p=head;

    q=head;

    for(int i = 0 ; i < count; i++)

    {

      q=p;

      p=p->next;

    }

    if(p==0)

    {

      q->next = temp;

      temp->prev=q;

    }

    else

    {

      q->next=temp;

      temp->prev = q;

      temp->next = p;

      p->prev=temp;

 

    }

}
void List::insertBefore(string name,int count)
{
    Node *temp = new Node();
    temp->name = name;

    Node *p , *q;
    p=head;
    q=head;
    for(int i = 0 ; i < count-1; i++)
    {
      q=p;
      p=p->next;
    }
    if(p==0)
    {
      q->next = temp;

      temp->prev=q;
    }
    else
    {
      q->next=temp;

      temp->prev = q;

      temp->next = p;

      p->prev=temp;

    }
}
    void List::locateCurrent(int data){
        Node *p ;
        int pos =1;

        if ( head ==0){
            cout<< "list is empty"<<endl;
        }
        else if (length() >= data)
        {
            p = head;
            while(pos!=data){
                p = p->next;
                pos++;
            }
            cout<< pos<<"번"<<" ";
            cout<< p->name <<" "<< p->weight<<" "<<p->height<<endl;
        }
        else
        {
            cout<< "no such a line"<<endl;
        }
        
    }

    int main(){
        List l; 
        ifstream infile;
        infile.open("input3.txt");
        // if (infile.fail()){
        //     cout<< "no "<<endl;
        // }
        // Node N[ch];
        for(int i = 0; i<4; i++){
            string name;
            int weight,height;

            infile >> name >> weight >> height;
           // cout << name << endl;
            l.intsertList(name,weight,height);
        }

    
        

        cout << endl;
        l.forwardList();
        cout<<endl;
        l.searchList("lee");
        cout<<endl;

        l.deleteList("lee",75,175);
        l.displayList();
        cout<<endl;
        l.insertAfter("park" ,73 ,176,2);
        l.displayList();
        cout<<endl;
        l.locateCurrent(2);
        cout<<endl;
        l.backwardList();
    }
    
