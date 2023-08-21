#include<iostream>
#include"adjmatrix.h"
#include"queue.h"
using namespace std;
void bfs(int** arr, int vertices,int start)
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
		for (int i = 0; i < vertices; i++) {
            		if (arr[obj_queue.valueAt(currentVertex)][i] && !visited[i]) {
                		visited[i] = true;
                		obj_queue.Insert(i);
            }
        }
	
    }
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
	bfs(arr,n,1);
return 0;
}
