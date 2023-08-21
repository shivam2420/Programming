#include<iostream>
#include"adjlist.h"
#include"queue.h"
using namespace std;
void bfs(adjlist** list, int vertices,int start)
{
        bool visited[vertices]={false};
        queue obj_queue;
        visited[start]=true;
        obj_queue.Insert(start);
        while(obj_queue.front()!=-1 && obj_queue.front()<=obj_queue.rear() )
        {
                int currentVertex = obj_queue.front();
                cout << obj_queue.valueAt(currentVertex) << " ";
                obj_queue.Delete();
		adjlist* temp=list[obj_queue.valueAt(currentVertex)];
		while(temp != NULL)
		{
			if(visited[temp->value] == false)
			{
				visited[temp->value]=true;
				obj_queue.Insert(temp->value);
			}
			temp=temp->next;
		}


        }

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
	bfs(list,n,1);
	return 0;
}

