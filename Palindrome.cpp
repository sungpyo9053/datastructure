#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Stack{
private:
    int stacksize=10;
    int top;
    char *stack;

public:
    Stack(); // 생성자 초기화
    void push(char num);
    int pop();
    int isEmpty();
    int isFull();
    void display();
};

Stack::Stack(){
    top = -1;
    stack = new char[stacksize];
}
void Stack::push(char num){
    stack[++top] = num;
}
int Stack::pop(){
    return stack[top--];
}
int Stack::isEmpty(){
    if (top == -1)
        return 0;
    else {
        return 1;
    }
}
int Stack::isFull(){
    if(top == stacksize-1){
        cout<< "full"<<endl;
        return 0;
    }
    else 
    {
        cout<<"is not full"<<endl;
        return 1;
    }
    
}
void Stack::display(){
    for(int i =0; i<top; i++){
        cout<<stack[i]<<endl;
    }
}

int main(){
    ifstream infile;
    infile.open("lab3.txt"); 
    Stack s;
    int i =0;
    string str;
    
    
    for(int j = 0 ; j < 4 ; j++){
        infile >> str;
        cout << str << endl;
        if(str.size() % 2 == 0 ){
            for(int i = 0 ; i < str.size()/2 ; i++){
                // cout<< str[i]<<endl;
                s.push(str[i]);
            }
            int j;
            
            for(j = str.size()/2 ; j < str.size() ; j++){
                if(str[j] == s.pop() ) continue;
                else{
                    cout << "not" << endl;
                    break;
                }
               
            }
              if(j == str.size()) cout << " valid" << endl;
        }
        else{
              for(int i = 0 ; i < str.size()/2 ; i++){
                s.push(str[i]);
              }
               int j;
                for(j = str.size()/2 + 1 ; j < str.size() ; j++){
                  if(str[j] == s.pop() ) continue;
                 else{
                    cout << "not" << endl;
                    break;
                 }
              
                }
                  if(j == str.size()) cout << " valid" << endl;
        }

       
    }
}
    
   
   
