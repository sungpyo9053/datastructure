#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack{
    private:
      int StackSize = 10;
      int top;
      char *stack;

    public:
      Stack();
      void push(char num);
      char pop();
      int isEmpty();
      int isFull();
      void displayStack();
};

Stack::Stack(){
    top = -1;
    stack = new char [ StackSize ];
}

void Stack::push(char num){

    stack[++top] = num;

}
char Stack::pop(){
    
    return stack[top--];

}

int Stack::isEmpty(){
    if(top == -1)
      return 1;
    else
      return 0;
}

int Stack::isFull(){
    if(top == StackSize - 1)
      return 1;
    else
      return 0;
}
void Stack::displayStack(){
    for(int i = 0 ; i <= top ; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}
int main(){
    ifstream in;

    in.open("lab3.txt");

    string str;

    int j;
    for(int i = 0 ; i < 9 ; i++){
        Stack s;

        in >> str;
       // cout << str << endl;
       // cout << str.size() << endl;
        for( j = 0 ; j < str.size(); j++){
            if(str[j] == '(' || str[j] == '{' || str[j] == '['){
                s.push(str[j]);
            }
            else if( str[j] == ')' ){
                if(s.isEmpty()) {
                  cout << "Invalid" << endl;
                  break;
                }

                char tmp = s.pop();

                if(tmp == '(') continue;

                else{
                    cout << "Invalid" << endl;
                    break;
                }
            }
            else if( str[j] == '}' ){
                if(s.isEmpty()) {
                  cout << "Invalid" << endl;
                  break;
                }

                char tmp = s.pop();

                if(tmp == '{') continue;

                else{
                    cout << "Invalid" << endl;
                    break;
                }
            }
            else if( str[j] == ']' ){
                if(s.isEmpty()) {
                  cout << "Invalid" << endl;
                  break;
                }

                char tmp = s.pop();

                if(tmp == '[') continue;

                else{
                    cout << "Invalid" << endl;
                    break;
                }
            }
        }

        if(j == str.size() ){
            if(!s.isEmpty()){
                cout << "Invalid" << endl;
          
            }
            else  
              cout << "Valid" << endl;
        }
    }

    in.close();
}
