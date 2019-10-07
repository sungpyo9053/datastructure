#include <iostream>

using namespace std;

class Path
{
    private:
        int found[8];
        int distance1[8];
    public:
        void shortestpath1(int v, int n);
        void shortestpath2(int v, int n);
        int choose(int v, int n);

};

const int MAX1 = 100;
const int MAX2 = 10000;

int array1[7][7] = {        // 문제 1번
    {0, 2, 4, 5, 100, 100, 100}, 
    {100, 100, 100, 2, 7, 100, 100},
    {100, 100, 100, 1, 100, 4, 100},
    {100, 2, 1, 100, 4, 3, 100},
    {100, 7, 100, 4, 100, 1, 5},
    {100, 100, 4, 3, 1, 100, 7},
    {100, 100, 100, 100, 7, 5, 100}
};

int array2[8][8] = {        // 문제 2번 
    {0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
    {300, 0, 10000, 10000, 10000, 10000, 10000, 10000},
    {1000, 800, 0, 10000, 10000, 10000, 10000, 10000},
    {10000, 10000, 1200, 0, 10000, 10000, 10000, 10000},
    {10000, 10000, 10000, 1500, 0, 250, 10000, 10000},
    {10000, 10000, 10000, 1000, 10000, 0, 900, 1400},
    {10000, 10000, 10000, 10000, 10000, 10000, 0, 1000},
    {1700, 10000, 10000, 10000, 10000, 10000, 10000, 0}
};

int main()
{
    Path p;
    
    cout << "cost matrix" << endl;

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout << array1[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << endl;
    cout << "short path distance" << endl;
    p.shortestpath1(0,7);
    cout << endl;

    cout << "cost matrix" << endl;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout << array2[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
    cout << "short path distance" << endl;
    p.shortestpath2(4,8);
    
    return 0;
}

void Path::shortestpath1(int v, int n)
{
    int cost[n][n];
    int u, w;

    for(int i=0; i<n; i++)      // 배열의 값 복사
    {
        for(int j=0; j<n; j++)
        {
            cost[i][j] = array1[i][j];
        }
    }

    for(int i=0; i<n; i++)      // found 와 distance 초기값 설정
    {
        found[i] = false;
        distance1[i] = cost[v][i];
    }

    found[v] = true;

    for(int i=0; i<n; i++)
    {
        cout << distance1[i] << " ";
    }

    cout << endl;

    for(int i=0; i<n-1; i++)
    {
        u = choose(i, n);
        found[u] = true;

        for(w=0; w<n; w++)
        {
            if(found[w] == false)
            {
                if(distance1[w] > distance1[u] + cost[u][w])
                {
                    distance1[w] = distance1[u] + cost[u][w];
                }
            }

            cout << distance1[w] << " ";
        }
        cout << endl;
    }
       
}

void Path::shortestpath2(int v, int n)
{
    int cost[n][n];
    int u, w;

    for(int i=0; i<n; i++)      // 배열의 값 복사
    {
        for(int j=0; j<n; j++)
        {
            cost[i][j] = array2[i][j];
        }
    }

    for(int i=0; i<n; i++)      // found 와 distance 초기값 설정
    {
        found[i] = false;
        distance1[i] = cost[v][i];
    }

    found[v] = true;

    for(int i=0; i<n; i++)
    {
        cout << distance1[i] << " ";
    }

    cout << endl;

    for(int i=0; i<n-1; i++)
    {
        u = choose(i, n);
        found[u] = true;

        for(w=0; w<n; w++)
        {
            if(found[w] == false)
            {
                if(distance1[w] > distance1[u] + cost[u][w])
                {
                    distance1[w] = distance1[u] + cost[u][w];
                }
            }

            cout << distance1[w] << " ";
        }
        cout << endl;
    }
}

int Path::choose(int v, int n)
{
    int i, min, node;
    if(n == 7)
    {
        min = MAX1;
        for(i=0; i<n; i++)
        {
            if(distance1[i] < min && found[i] == false)
            {
                min = distance1[i];
                node = i;
            }
        }
    }

    else
    {
        min = MAX2;
        for(i=0; i<n; i++)
        {
            if(distance1[i] < min && found[i] == false)
            {
                min = distance1[i];
                node = i;
            }
        }
    }
    
    return node;
}