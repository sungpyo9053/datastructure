#include <iostream>

using namespace std;


const int heapsize = 7;
int heap[heapsize];

static int n = 0;

class Node
{
    friend class Tree;
    int data;
    Node *left;
    Node *right;
};
class Tree
{    public:
        Node *root =0;
        void insertheap(int data);
        int deleteheap();
        bool HeapEmpty();
        bool HeapFull();
        void Printheap();
        void insert(int key);
        int LevelTest(Node *root);

};

int Tree::LevelTest(Node *root)
{
            int count = 0;
            int level = 0;

            if(n == 0) return 0;

            for (int i = 0; i < n; i++){
                if (heap[i] =!NULL){
                    count++;
                }
            }
            level = count/2 ;
            cout<<"LevelTest : ";
            cout<< level<<endl;           
}


bool Tree::HeapEmpty(){
    if ( n == 0 ){
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Tree::HeapFull(){
    if (n == heapsize){
        return true;
    }
    else
    {
        return false;
    }
}

void Tree::insertheap(int data){
    int i;
    
    
    if (HeapFull()){
        cout<<"heap is full"<<endl;
        exit(1);
    }
    
    i = ++n;

    while( (i!=1) && (data < heap[i/2]) ){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] =data;
}
int Tree::deleteheap(){
    int parent;
    int child;
    int temp;
    int item;
    
    item = heap[0];
    temp = heap[n--];
    parent =1;
    child = 2;
    while(child <= n){
        if (child < n && heap[child] > heap[child+1]) {
            child++;
        }
        if (temp < heap[child]){
        //    cout<<heap[child]<<endl;
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child = child *2;
        
    } 
    heap[parent] =temp;
    
    return item;
}

void Tree::Printheap(){

    if (n == 0){
        cout<< "heap is empty"<<endl;
    }
    else
    {   
        // cout<<heap[0] << " ";
        for (int i = 1; i<n+1; i++){
            cout<<heap[i]<<" ";
        }
        
    }
    // cout<<heap[n]<<endl;
}

int main()
{
    Tree t;
    int menuNum;
    int num;
    
    
    while(1){
        cout<<"1.Insert 2.Delete 3.Empty 4.Full 5.levelTest 6. Quit 7.Print"<<endl;
        cin >> menuNum;
    
    switch(menuNum)
    {
        case 1:
            cout<< "enter number to insert : ";
            cin >> num;
            t.insertheap(num);

            break;
        case 2:
            t.deleteheap();
            t.Printheap();
            cout<<endl;
            break;
        case 3:
            if (t.HeapEmpty()) {
                cout<< "heap is empty"<<endl;
            }
            else
            {
                cout<<"heap is not empty"<<endl;
            }
            break;
        case 4:
            if (t.HeapFull()){
                cout<< "heap is full"<<endl;
            }
            else
            {
                cout<< "heap is not full"<<endl;
            }
            break;
        
        case 5:
            t.LevelTest(t.root);
            break;
        case 6:
            exit(1);
            break;

        case 7:
            t.Printheap();
            cout<<endl;
             }
        }   
        return 0;
}    
    
   
