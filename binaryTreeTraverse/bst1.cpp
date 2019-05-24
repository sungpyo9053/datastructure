//이진 탐색 트리
#include <iostream>
#include <fstream>

using namespace std;

class Node 
{
    friend class Tree;

    int data;
    Node *left;
    Node *right;
};

class Tree
{
    public:
        Node *root;
        Tree();
        void insert(int key);
        void search(Node *root, int data);
        Node* deleteBST(int key);
        void printBST(Node *head, int level);
        void maxvalue(Node *root);
        void minvalue(Node *root);
        void inorder(Node *root);
        void postorder(Node *root);
        void preorder(Node *root);
};

void Tree::preorder(Node *p){
    if( p!= 0){
        cout<< p->data<< " ";
        preorder(p->left);
        preorder(p->right);
    } 
    return ;  
}
void Tree::inorder(Node *p)
{
    if(p!=0){
        inorder(p->left);
        cout<< p->data<< " ";
        inorder(p->right);
    }
    return;
}
void Tree::postorder(Node *p){
    
    if(p!=0){
        postorder(p->left);
        postorder(p->right);
        cout<< p->data<< " ";
    }
    return ;
}

Tree::Tree()
{
    root = 0;
}

void Tree::search(Node *head, int key)
{

    if(head == 0)
    {
        cout << "Empty Tree" << endl;
        return ;
    }

    else
    {
        if(head->data == key)
        {
            cout << "value Found " << endl;
        }

        else if(head->data > key)
        {
            return search(head->left, key);
        }

        else if(head->data < key)
        {
            return search(head->right, key);
        }
    }
    
}

void Tree::insert(int key)
{
    Node *temp = new Node();
    temp->data = key;
    Node *p, *q;

    if(root != 0)       //루트 노드가 공백이 아닐 때
    {
        p = root;
        q = p;

        while(p)  //현재 노드가 null이 아닐 때, 현재노드가 null이됨
        {
            q = p;  //현재 노드를 저장하는 역할

            if(p->data == key)
            {
                cout << "already exist" << endl;
                return ;
            }
            
            if(p->data < key)   //현재 노드의 value가 key값보다 작으면
            {
                p = p->right;   //오른쪽으로 이동
            }

            else if(p->data > key)  //현재 노드의 value가 key값보다 크면
            {
                p = p->left;        //왼쪽으로 이동
            }
        }

        if(q->data < key)
        {
            q->right = temp;
        }

        else if(q->data > key)
        {
            q->left = temp;
        }
    }

    else    //root노드가 null일 때
    {
            root = temp;
    }

}


Node*Tree::deleteBST(int data){

    Node *delp = root;
    Node *parentp = root;
    Node *sonp;

    if (root==0){
        return 0;
    }
    while(delp !=0){
        if (delp->data == data)
        {
            break;
        }
        parentp = delp;
        
        if (delp->data <data){
            delp = delp ->right;
        }
        else{
            delp= delp ->left;
        }   
    }
    if (delp ==0){
        return 0;
    }
    if (delp->right == 0){
        sonp = delp->left;
    }
    else if(delp->right->left ==0){
        sonp = delp->right;
        sonp ->left = delp ->left;
    }
    else
    {
        Node *temp;
        temp = delp ->right;
        while(temp->left->left !=0){
            temp= temp->left;
        }
        sonp = temp->left;
        temp->left = sonp ->right;

        sonp ->left =delp ->left;
        sonp ->right = delp ->right;
    }
    if (delp == root){
        root =sonp;
    }
    else if(delp->data < parentp ->data){
        parentp ->left =sonp;
    }
    else
    {
        parentp ->right =sonp;
    }
    delete(delp);

    return parentp;

}



void Tree::printBST(Node *head, int level){
   
    if ( head !=0 && level <= 7 ){
        printBST(head->right, level+1);
        for(int i = 1; i<= (level-1); i++){
            cout << "    ";
        }

        cout<< head->data;

        if (head->left !=0 && head->right !=0){
            cout << "<" <<endl;
        }
        else if( head->right !=0){
            cout << "  / " <<endl; 
        }
        else if (head->left !=0){
            cout << " \\  "<<endl;
        }
        else
        {
            cout <<endl;
        }
        
        printBST(head->left,level+1);
    }
}
void Tree::maxvalue(Node *p){
    
    Node *q;
    while( p!=0){
        q = p;
        p= p->right;
    }

  cout<<"Max Value : "<< q->data<<endl;
}

void Tree::minvalue(Node *p){
    Node *q;
   
    while(p !=0){
        q = p;
        p= p->left;
    }
    cout<<"Min value : "<< q->data;
}

int main()
{
    Tree t;

    int num;

    ifstream infile;
    infile.open("input.txt");
    for (int i = 0; i<7; i++){
        infile>>num;
        
        t.insert(num);
    }

    // t.printBST(t.root,1);
    // t.deleteBST(10);
   
    cout<<"inoder : ";
    t.inorder(t.root);
    cout<<endl;
    cout<< "postorder :";;
    t.postorder(t.root);
    cout<<endl;
    cout<< "preorder :";
    t.preorder(t.root);
    cout<<endl;
   
    t.maxvalue(t.root);
    t.minvalue(t.root);
    cout<<endl;
    
    cout<<"delete : ";
    t.deleteBST(10);
    t.inorder(t.root);
    cout<<endl;

    t.search(t.root,20);
    t.printBST(t.root,1);
    return 0;
}