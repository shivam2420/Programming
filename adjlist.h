#include<iostream>
using namespace std;
class adjlist{
	public:
		int value;
		adjlist* next;
		void addEdge(int index,adjlist** list,int node)
		{
			if(list[index]==NULL)
			{
				adjlist* temp=new adjlist();
				temp->value=node;
				temp->next=NULL;
				list[index]=temp;
				return;
			}
			adjlist* temp=new adjlist();
			temp=list[index];
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			adjlist* temp1=new adjlist();
			temp1->value=node;
			temp1->next=NULL;
			temp->next=temp1;
		}
};


