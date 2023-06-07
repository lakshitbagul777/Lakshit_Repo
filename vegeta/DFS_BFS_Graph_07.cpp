#include<iostream>
using namespace std ;

void bfs(int arr[6][6] , int n)
{
    int vis[n] ;
    int que[2*n] ;
    int fr = 0 , re = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        vis[i] = 0 ;
    }
    que[re] = 0 ;
    vis[0] = 1 ;
    re++ ;
    while(fr != re)
    {
        int node = que[fr] ;
        fr++ ;
        cout << node+1 << " " ;
        for(int i = 0 ; i<n ; i++)
        {
            if(arr[node][i] == 1 && vis[i] == 0)
            {
                que[re] = i ;
                re++ ;
                vis[i] = 1 ;
            }
        }

    }
}

void dfs(int arr[6][6] , int n)
{
    int vis[n] ;
    int st[2*n] ;
    int top = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        vis[i] = 0 ;
    }
    st[top] = 0 ;
    while(top != -1)
    {
        int node = st[top] ;
        top-- ;
        if(vis[node] == 0)
        {
            cout << node+1 << " " ;
            vis[node] = 1 ;
            for(int i = 0 ; i<n ; i++)
            {
                if(arr[node][i] == 1)
                {
                    top++ ;
                    st[top] = i ;
                }
            }
        }
    }
}

int main()
{
    int gr[6][6] = {
        {0,1,0,1,0,0},
        {1,0,0,0,1,1},
        {0,0,0,1,1,1},
        {1,0,1,0,0,0},
        {0,1,1,0,0,0},
        {0,1,1,0,0,0}
    };
    cout << "BFS TRAVERSAL OF THE GRAPH IS : " ;
    bfs(gr,6) ;
    cout << endl ;
    cout << "DFS TRAVERSAL OF THE GRAPH IS : " ;
    dfs(gr,6) ;

    cout<<endl;

}
