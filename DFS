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
        
        Node* search(int data);
        void deleteBST(int key);
        
        void printBST(Node *head, int level);
        
        Node* findMax(Node *root);
        void minvalue(Node *root);
        
        void inorder(Node *root);
        void postorder(Node *root);
        void preorder(Node *root);
        int Leaf(Node *root){

            int count = 0;

            if(root == 0) return 0;
            

            if(root->left == 0 && root->right == 0) count++;
            else{
                count = Leaf(root->left) + Leaf(root->right);
            }

            return count;
        }
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

Node* Tree::search(int data)
{

  Node *cp;

  if (root ==0) {
      return 0;
  }
  else
  {
      cp = root;
      while(cp !=0){
          if (cp ->data == data){
              return cp;
          }
          else if ( cp->data <data){
              cp = cp->right;
          }
          else
          {
              cp = cp->left;
          }
      }
    return cp;
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


// Node*Tree::deleteBST(int data){

//     Node *delp = root;
//     Node *parentp = root;
//     Node *sonp;

//     if (root==0){
//         return 0;
//     }
//     while(delp !=0){
//         if (delp->data == data)
//         {
//             break;
//         }
//         parentp = delp;
        
//         if (delp->data <data){
//             delp = delp ->right;
//         }
//         else{
//             delp= delp ->left;
//         }   
//     }
//     if (delp ==0){
//         return 0;
//     }
//     if (delp->right == 0){
//         sonp = delp->left;
//     }
//     else if(delp->right->left ==0){
//         sonp = delp->right;
//         sonp ->left = delp ->left;
//     }
//     else
//     {
//         Node *temp;
//         temp = delp ->right;
//         while(temp->left->left !=0){
//             temp= temp->left;
//         }
//         sonp = temp->left;
//         temp->left = sonp ->right;

//         sonp ->left =delp ->left;
//         sonp ->right = delp ->right;
//     }
//     if (delp == root){
//         root =sonp;
//     }
//     else if(delp->data < parentp ->data){
//         parentp ->left =sonp;
//     }
//     else
//     {
//         parentp ->right =sonp;
//     }
//     delete(delp);

//     return parentp;

// }
void Tree::deleteBST(int key)
{
    Node *p, *q, *temp;
    p = root;

    if(root == 0)       //공백트리일때
    {
        cout << "Tree empty" << endl;
        return;
    }

    else if(root->data == key)      //루트 노드의 값을 삭제
    {
        if(p->left == 0 && p->right == 0)       // tree에 루트노드 하나만 있는 경우
        {
            delete p;
        }

        else if(p->left == 0)       //root에 right child만 있는 경우
        {
            p = p->right;
            p->left = p->right->left;
            delete p;
        }

        else if(p->right == 0)      //root에 left child만 있는 경우
        {
            p = p->left;
            p->right = p->left->right;
            delete p;
        }

        else        //root에 left, right child가 모두 있는 경우
        {
            root = p->left;
            root->right = p->right;
        }
        
    }

    else
    {
        while(p != 0 && p->data != key)
        {
            q = p;

            if(p->data > key)
            {
                p = p->left;
            }

            else if(p->data < key)
            {
                p = p->right;
            }
        }

        if(p != 0)  // 일치하는 값을 찾은 경우
        {
            if(q->data > key)    //삭제할 노드의 값이 부모노드의 값보다 작은 경우
            {
                if(p->left == 0 && p->right == 0)        //삭제할 노드가 leaf노드인 경우
                {
                    q->left = 0;
                    delete p;
                }

                else if(p->left == 0)
                {
                    q->left = p->right;
                    delete p;
                }

                else if(p->right == 0)
                {
                    q->left = p->left;
                    delete p;
                }

                else         //삭제할 노드가 left, right child를 모두 가지고 있는 경우
                {
                    temp = findMax(p->left);
                    q->left = temp;
                    temp->left = p->left;
                    temp->right = p->right;
                    delete p;
                }
               
            }

            else        //삭제할 노드의 값이 부모노드의 값보다 큰 경우
            {
                if(p->left == 0 && p->right == 0)        //삭제할 노드가 leaf노드인 경우
                {
                    q->right = 0;
                    delete p;
                }

                else if(p->left == 0)
                {
                    q->right = p->right;
                    delete p;
                }

                else if(p->right == 0)
                {
                    q->right = p->left;
                    delete p;
                }

                else         //삭제할 노드가 left, right child를 모두 가지고 있는 경우
                {
                    temp = findMax(p->left);
                    q->right = temp;
                    temp->left = p->left;
                    temp->right = p->right;
                    delete p;
                }
            }
            
        }
    }
    
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
            cout << " / " <<endl; 
        }
        else if (head->left !=0){
            cout << "  \\ "<<endl;
        }
        else
        {
            cout <<endl;
        }
        
        printBST(head->left,level+1);
    }
}
Node *Tree::findMax(Node *head)
{
    Node *p = head;
    Node *q, *qparent;

    while(p)
    {
        qparent = q;
        q = p;
        p = p->right;
    }

    qparent->right = q->left;

    return q;
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
    int menuNum;
    int num;
    
    
    while(1){
        cout<<"1. insert 2. Delete 3. search 4.print 5.traverse 6.leaf :";
        cin >> menuNum;
    
    switch(menuNum)
    {
        case 1:
            cout<< "enter number to insert :";
            cin >> num;
            t.insert(num);
            
            break;
        case 2:
            // cout<< "enter number to delete :";
            
                cin >>num;
                t.deleteBST(num);
                t.printBST(t.root,1);
                cout<< num << " is deleted" <<endl;
            
            break;
        case 3:
            
                cin>>num;
            if (t.search(num) == 0){
                cout<<"not found"<<endl;
            }
           
            else
            {   
                cin>>num;
                cout << t.search(num) <<endl;
                cout<<"find"<<endl;
            }
            break;
        case 4:
            t.printBST(t.root,1);
            break;
        
        case 5:
            
            if (t.root == 0){
                cout<<"tree empty"<<endl;
            }
            else{
            cout<<"inoder :";
            t.inorder(t.root);
            cout<<endl;
            cout<<"postorder : ";
            t.postorder(t.root);
            cout<<endl;
            cout<<"preorder : ";
            t.preorder(t.root);
            cout<<endl;
     }
            break;
        case 6:
            cout<<t.Leaf(t.root)<<endl;
            break;
        default : 
            exit(1);
            break;
    }
}
return 0;
}
