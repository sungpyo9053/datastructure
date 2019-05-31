#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;

class Node 
{
    public:
        Node *link;
        int num;
        Node(int data) {num = data; link = NULL;};

        friend class Graph;
};

class Graph
{
    private:
        Node *front;
        Node *rear;
        Node *head;
    public:
        int visited[MAX_SIZE] = {0};
        Graph() {head = NULL; front = NULL; rear = NULL;};
        
        void insert(int data);
        void DFS(int v);
        void BFS(int v);
        void enqueue(int data);
        int dequeue();
        void printGraph();
        void traverse();
};

Graph graph[MAX_SIZE];

int main()
{
    Graph g1;
    Graph g2;
    
    ifstream in;
    in.open("graph.txt");
    
    int arr[10][10];

    for(int i=0; i<6; i++)          //4*4행렬
    {
        for(int j=0; j<6; j++)
        {
            in >> arr[i][j]; 
        }
    
    }

    for(int i=0; i<6; i++)
    {
        graph[i].insert(i);

        for(int j=0; j<6; j++)
        {
            if(arr[i][j] == 0)
            {
                continue;
            }

            else
            {
                graph[i].insert(j);
            }
            
        }
    }
    cout<<"LINKED LIST"<<endl;
    for(int i=0; i<=6; i++)
    {
        graph[i].traverse();
    }

    cout<<"DFS :";
    g1.DFS(0);
    cout << endl;
   
    
    return 0;
}

void Graph::insert(int data)
{
    Node *temp = new Node(data);
    Node *p;
    if(head == NULL)
    {
        head = temp;
    }

    else
    {
        p = head;

        while(p->link != NULL)
        {
            p = p->link;
        }

        p->link = temp;
    }
}

void Graph::DFS(int v)
{
    Node *w = graph[v].head;

    visited[v] = 1;
    cout << v << " ";

    for(w = graph[v].head; w!=0; w=w->link)
    {
        if(w->link != NULL)
        {
            if(!visited[(w->link)->num])
            DFS((w->link)->num);
        }
        
    }
}

void Graph::BFS(int v)
{
    Node *p;
    visited[v] = 1;

    enqueue(v);

    cout << v << " ";

    while(front)
    {
        for(p = graph[v].head; p; p=p->link)
        {
            if(!visited[p->num])
            {
                enqueue(p->num);
                visited[p->num] = 1;
                cout << p->num << " ";
            }
        }

        v = dequeue();
    }
}

void Graph::enqueue(int data)
{
    Node *temp = new Node (data);

    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }

    else
    {
        rear->link = temp;
        rear = temp;
    }
}

int Graph::dequeue()
{
    Node *p;
    int num;

    num = front->num;
    p = front;

    if(front == rear)
    {
        front = NULL;
        rear == NULL;
    }

    else
    {
        front = front->link;
    }

    delete p;

    return num;
    
}

void Graph::traverse()
{
    Node *p;
    p = head;

    while(p != 0)
    {
        cout << p->num << " ";
        p = p->link;
    }

    cout << endl;
}
