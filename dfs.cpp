#include<iostream>
#include"adjmatrix.h"
using namespace std;
void dfsRecursive(int** adjMatrix, bool* visited, int vertices, int currentVertex) {
    visited[currentVertex] = true;
    cout << currentVertex << " ";

    for (int i = 0; i < vertices; ++i) {
        if (adjMatrix[currentVertex][i] && !visited[i]) {
            dfsRecursive(adjMatrix, visited, vertices, i);
        }
    }
}
void dfs(int** adjMatrix, int vertices, int startVertex) {
    bool visited[vertices] = {false};
    dfsRecursive(adjMatrix, visited, vertices, startVertex);
    cout<<endl;
}

int main()
{
        adj obj;
        int n;
        cout<<"Enter number of nodes:";
        cin>>n;
        int** arr;
        arr=obj.createAdjMat(n);
        cout<<"-------------------Adjacency Matrix----------------------"<<endl;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;

        }
        cout<<"---------------------------------------------------------"<<endl;
        dfs(arr,n,1);
return 0;
}
