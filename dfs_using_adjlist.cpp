#include<iostream>
#include"adjlist.h"
using namespace std;
void dfsRecursive(adjlist** arr,int vertex, bool* visited,int vertices) {
        visited[vertex] = true;
        cout << vertex << " ";
	adjlist* temp=arr[vertex];
	while(temp != NULL)
	{
		if(visited[temp->value] == false)
		{
			dfsRecursive(arr,temp->value,visited,vertices);
		}
		temp=temp->next;
	}
            }
 void dfs(adjlist** arr,int startVertex,int vertices) {
        bool visited[vertices]={false};
        dfsRecursive(arr,startVertex, visited,vertices);
        cout << endl;
    }
int main()
{
        int n;
        cout<<"Enter the number of Nodes:";
        cin>>n;
        adjlist obj;
        adjlist* list[n]={NULL};
        for(int i=0;i<n;i++)
                {
                        int x;
                        cout<<"For vertex "<<i<<" Enter number of adjacent edges:";
                        cin>>x;
                        for(int j=0;j<x;j++)
                        {
                                int node;
                                cout<<"Enter edge:";
                                cin>>node;
                                obj.addEdge(i,list,node);
                        }
                }
        cout<<"----------------------Adjacency List-------------------------"<<endl;
        for(int i=0;i<n;i++)
        {
                adjlist* temp=list[i];
                cout<<"["<<i<<"]";
                while(temp != NULL)
                {
                        cout<<"->"<<temp->value;
                        temp=temp->next;
                }
                cout<<endl;
        }
        cout<<"-------------------------------------------------------------"<<endl;
        dfs(list,1,n);
        return 0;
}                                                                                            
