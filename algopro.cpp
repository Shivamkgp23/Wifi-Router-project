/*
ALGORITHMS - 1 Project (Prof. Palash Dey and Prof. Partha Pratim Chakrabarti)


19CH10074 : Gaurav Jha
19CH10072 : Ayush Airan


"Motivation : In the modern era of ""Digital India"" internet connectivity for fun and productivity has become a necessity. Particularly in Institutions ensuring wireless Internet access is now almost as important a feature of building facilities as the access to water and electricity. Typically, buildings are connected to the Internet using a fiber backbone. In order to provide wireless Internet access, wireless routers are placed around the building and connected using fiber cables to the
backbone.

Task: Given a building plan (for instance Nalanda Complex) or a budding technology hub in a ""Smart City"", decide where to put wireless routers and how to connect them to the fiber backbone to maximize coverage and minimize cost.

Problem Statement : Let us represent a building using a 2-D matrix in which each cell is one of the following :
1. a wall cell (or any other obstruction) , represented as “#”
2. a target cell, represented as “.” :- these are cells in which we need to have wireless coverage
3. a void cell, represented as “-”  :- these are cells in which we don’t need to have wireless coverage

We place a router at any grid such that the signal strength decreases as we move away from the router in each direction. A wall cell blocks the network.
We need to connect the routers to fiber backbone which are provided in the 2-D matrix.

Budget : Placing a single router and connecting a router to the fiber backbone costs some money. We are given a budget B and have to optimally reach the maximum number of dots (target cell) in the matrix."*/


#include <iostream>
#include <math.h>
#define ll long long int
#define ull long long int
using namespace std;

//----------code for C++ implementation of Queue starts -----------------

struct QNode
{
    int x;
    int y;
    QNode *next;
    QNode(int i, int j)
    {
        x = i;
        y = j;
        next = NULL;
    }
};

struct Queue
{
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void push(int x, int y)
    {

        // Create a new LL node
        QNode *temp = new QNode(x, y);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void pop()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        QNode *temp = front;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};

//----------code for C++ implementation of Queue ends -----------------



int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};



//---------print function for any 2-D array starts ----------------------

void print(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------\n";
}

//---------print function for any 2-D array ends ----------------------



//-----------update array using bfs starts ----------------

bool isValidforBFS(int **a, int **vis, int **global_vis, int x, int y, int m, int n)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || a[x][y] == -1 || vis[x][y] >0 )
        return false;

    return true;
}

int bfs_val(int **b, int **a, int **global_vis, int n, int m, int srcX, int srcY, int k)
{
    int **vis = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        vis[i] = (int *)calloc(m, sizeof(int));

    int **dist = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        dist[i] = (int *)calloc(m, sizeof(int));

    Queue q;
    q.push(srcX, srcY);
    dist[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;
    int coverage = 0;

    while ((q.front) != NULL)
    {
        int curX = q.front->x;
        int curY = q.front->y;
        q.pop();

        if (dist[curX][curY] > k)
        {
            break;
        }
        if (a[curX][curY] == 1 && global_vis[curX][curY]==0)
        {
            coverage++;
            //b[curX][curY] = value; can be used for debugging purposes
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (isValidforBFS(a, vis, global_vis, newX, newY, m, n))
            {
                dist[newX][newY] = dist[curX][curY] + 1;
                if (dist[newX][newY] <= k)
                {
                    vis[newX][newY] = dist[newX][newY];
                    q.push(newX, newY);
                }
            }
        }
    }

    /* the below comments can be used for DEBUGGING purposes 
    // cout << "For x = " << srcX << ", y = " << srcY << ", val = " << value << endl;
    // print(vis,n,m);
   

    //b[srcX][srcY] = value;
    */
    return coverage;
}

//-----------update array using BFS ends ----------------

//-----------mark routers using bfs starts ----------------

bool isValidformarking(int **a, int **vis, int **global_vis, int x, int y, int m, int n)
{
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || a[x][y] == -1 || vis[x][y] == true )
        return false;

    return true;
}

void put_router(int **b, int **a, int **global_vis, int n, int m, int srcX, int srcY, int k)
{
    //cout << "(" << srcX << ", " << srcY << ")" << endl;
    int **vis = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        vis[i] = (int *)calloc(m, sizeof(int));

    int **dist = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        dist[i] = (int *)calloc(m, sizeof(int));

    Queue q;
    q.push(srcX, srcY);

    dist[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;
    global_vis[srcX][srcY] = 1;

    while ((q.front) != NULL)
    {
        
        int curX = q.front->x;
        int curY = q.front->y;

        q.pop();

        if (dist[curX][curY] > k)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (isValidformarking(a, vis, global_vis, newX, newY, m, n))
            {
                dist[newX][newY] = dist[curX][curY] + 1;
                if (dist[newX][newY] <= k)
                {
                    vis[newX][newY] = 1;
                    global_vis[newX][newY] = 1;
                    q.push(newX, newY);
                }
            }
        }
    }
}

//-----------mark routers using bfs ends ----------------


void solve()
{
    int n, m;
    cout << "Enter matrix dimensions : ";
    cin >> n >> m;
    
    char **ch = (char **)calloc(n, sizeof(char *)); // array to take the input from the user
    for (int i = 0; i < n; i++)
        ch[i] = (char *)calloc(m, sizeof(char));

    int **a = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = (int *)calloc(m, sizeof(int)); // to store the character array in form of integer array where "*" -> 1 , "-" -> 0 and "#" -> -1;

    int **b = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        b[i] = (int *)calloc(m, sizeof(int)); // separate array which can be used at several places for degugging purposes , initially b=a;

    int **global_vis = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        global_vis[i] = (int *)calloc(m, sizeof(int)); // global viaited array which stores the points coveres by the router at any point of time


    cout << "Enter matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '-')
                a[i][j] = 0;
            else if (ch[i][j] == '*')
                a[i][j] = 1;
            else
                a[i][j] = -1;
            b[i][j] = a[i][j];
        }
    }
    // cout << "a  :\n";
    // print(a, n, m);

    int B, cost, strength; // Budget, cost of 1 router and strength of one router

    cout << "Enter Budget : "; cin >> B;
    cout << "Enter Cost : "; cin >> cost;
    cout << "Enter signal strength : "; cin >> strength;
    

    int max_router = B / cost; // maximum routers which can be used

    // ------------ Apply BFS ---------------

    
    int mx = -1;
    int t = 1;
    while (t <= max_router)
    {
        //search optimal index for each router one by one
       
        cout << "Router No. : " << t << endl;
        t++;
        int x, y;
        mx = -1;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != -1 && global_vis[i][j] != 1)
                {
                    int coverage = bfs_val(b, a, global_vis, n, m, i, j, strength);
                    if (coverage > mx)
                    {
                        mx = coverage;
                        x = i, y = j;
                    }
                }
            }
        }
        if (mx == 0)
        {
            cout << "No need of this router as all coverage points already covered\n";
            break;
        }
           
        cout << "Points covered : " << mx << endl;
        cout << "x : " << x << ", y : " << y << endl;
        put_router(b, a, global_vis, n, m, x, y, strength);
        cout << "global_visited : \n";
        print(global_vis, n, m);
    }

   
}
int main()
{
    solve();
}