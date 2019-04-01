#include <iostream>
#include <fstream>
#include <string>
//후위수식
//전위수식 중간고사다.!
using namespace std;

class Stack{
private:
    int top;
    int stacksize;
    char *stack;
    char oper[2][6];
public:
    Stack();
    void push(char n);
    char pop();
    void display();
    int empty();
    int isfull();
    int operator1(char n);
    char getTop();
};

Stack::Stack(){
    int top =-1;
    int stacksize = 10;
    stack = new char[stacksize];

    oper[0][0] =')';
    oper[1][0] ='3';

    oper[0][1] ='*';
    oper[1][1] ='2';

    oper[0][2] = '/';
    oper[1][2] ='2';
    
    oper[0][3] = '+';
    oper[1][3] = '1';

    oper[0][4] ='-';
    oper[1][4] = '1';

    oper[0][5] ='(';
    oper[1][5] = '0';

}

void Stack::push(char n){
    stack[++top] = n;
}
char Stack::pop(){
    return stack[top--];
}
void Stack::display(){
    for (int i = 0; i<top; i++){
        cout<<stack[i]<<endl;
    }
}
int Stack::empty(){
    if ( top == -1){
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::isfull(){
    if(top == stacksize){
        return 0;
    }
    else
    {
        return 1;
    }
}
int Stack::operator1(char exp){
    
   for ( int i = 0; i<6; i++){
       if (oper[0][i]==exp){
           return oper[1][i] -'0';
       }
       
   }
   return -1;
}
char Stack::getTop(){
    return stack[top];
}

int main(){
    int priority;
    int topvalue;
    ifstream infile;
    infile.open("hw2.txt");
    string str;
    Stack s;
    
    for (int i = 0; i<4; i++ ){
        infile >> str;
        for (int j = 0; j<str.size(); j++){
            topvalue =s.getTop();


            if (str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '(' || str[j] =='/' || str[j] ==')' ){
        
                if (str[j] == '('){
                    
                    s.push(str[j]);
                }
                else if (str[j] == ')'){
                    
                    while(s.getTop() != '('){
                        
                        cout << s.pop() << ' ';
                        
                    }
                    s.pop();
                }
               
                else if(s.empty() || s.operator1(str[j]) > s.operator1(topvalue)){
                    s.push(str[j]);
                }
                else if(s.operator1(str[j]) <= s.operator1(topvalue)){
                    cout << s.pop() << ' ';
                    s.push(str[j]);
                }
                
            }
    
            else if(s.operator1(str[j])== -1){
                cout <<str[j];
                
            }
    }
    while(!s.empty())
    {
        cout << s.pop()<< ' ';
    }
    cout << endl;
        }
}

