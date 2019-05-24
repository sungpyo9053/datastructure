#include <iostream>
#include <string>
#include <fstream>
//트리를 탐색하고 괄호를 

using namespace std;

char prec[4][2] = {'*',2, '/',2, '+',1, '-',1};

class Node
{
    friend class Tree;

    char data;
    Node *left;
    Node *right;
    int prior;
};

class Tree
{
    public:        
        Node *head;
    
        Tree();
        void createTree(string s);

        void inorder(Node *head);
        void inorder2(Node *head);
        void preorder(Node *head);
        void postorder(Node *head);
        
        void operand(Node *temp);
        void operator1(Node *temp);
        int evaluation(Node *head);
        
};

int main(){
    string s;
    ifstream infile;
    infile.open("input.txt");
    for (int i = 0; i<3; i++){
        infile >> s; 
    
    int ans;

    Tree t;
    t.createTree(s);
    cout<<"InOrder :";
    t.inorder(t.head);
    cout << endl;
    cout<<"PostOder :";
    t.postorder(t.head);
    cout << endl;
    cout<<"PreOrder :";
    t.preorder(t.head);
    cout << endl;
    
    ans = t.evaluation(t.head);
    cout << "Evaluation : " << ans << endl;

    cout<<"Tree structure"<<endl;
    t.inorder2(t.head);
    cout <<endl;

    cout<<endl;
    
    }
    return 0;
}

Tree::Tree()
{
    head = 0;
}

void Tree::createTree(string s)
{
    
    int prec[4][2] = {'*',2, '/',2, '+',1, '-',1};

    cout<< s.size()<<endl;

    for(int i=0; i<s.size(); i++)
    {
        
        Node *temp = new Node();
        
        temp->data = s[i];
        temp->prior = 4;

        int j;
    
        for(j=0; j<4; j++)
        {
            if(temp->data == prec[j][0])
            {
                temp->prior = prec[j][1];
                break;
            }
        }

        if(j == 4)
        {
            operand(temp); // 피연산자
        }

        else
        {
            operator1(temp); //연산자
        }   
    }
}

void Tree::operand(Node *temp)
{
    Node *p;
    
//head가 없으면 temp를 head로 설정
    if(head == 0)       
    {
        head = temp;
    }

//이미 head가 있는 경우
    else        
    {
        p = head;
        
        if(p->right == 0)   //두번째 피연산자가 처음 들어가는 경우
        {
            p->right = temp;
        }
        
        else
        {
            while(p->right != 0)
            {
                p = p->right;
            }
             p->right = temp;
        }
        
    }
}

void Tree::operator1(Node *temp)
{
    if(head->prior >= temp->prior)
    {
        temp->left = head;
        head = temp;
    }

    else
    {
        temp->left = head->right;
        head->right = temp;
    }
    
}

void Tree::inorder(Node *head)
{
    if(head)
    {
        inorder(head->left);
        cout << head->data;
        inorder(head->right);
    }
}

void Tree::inorder2(Node *head){
        
    if(head){ 
        if(head->data == '+' || head->data == '-' || head->data == '*' || head->data == '/')  
            cout<<"(";
        inorder2(head->left);
        cout<<head->data;
        inorder2(head->right);
        if(head->data == '+' || head->data == '-' || head->data == '*' || head->data == '/') 
            cout<<")";

    }
}

void Tree::postorder(Node *head)
{
    if(head)
    {
        postorder(head->left);
        postorder(head->right);
        cout << head->data;
    }
}

void Tree::preorder(Node *head)
{
    if(head)
    {
        cout << head->data;
        preorder(head->left);
        preorder(head->right);
    }
}

int Tree::evaluation(Node *head1){
    Node *p ;
    p = head1;
    int value;
    if ( p!= 0){
        if (  p->data >= '0' && p-> data <= '9' ){
            
            value = p-> data -'0';
        
        }
        else
        {
            
            int left = evaluation(p->left);
            int right = evaluation(p->right);
        
            switch(p->data){
                case '+': value = left +right;
                break;
                case '-': value = left - right;
                break;
                case '*': value = left * right;
                break;
                case '/': value = left / right;
                break;

            }
        }
    }
    else
    {
        cout << "Empty tree"<<endl;
    }
    return value;
}
