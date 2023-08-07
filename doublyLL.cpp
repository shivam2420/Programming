#include<iostream>
using namespace std;
template<class T>
class Node
{
	public:
		T data;
		Node* next;
		Node* prev;
		Node* Head=NULL;
		void insert()
		{
			T value;
			cout<<"Enter value to be inserted:";
	       		cin>>value;
	 		Node* newNode=new Node();
			newNode->next=NULL;
			newNode->data=value;
			if(Head==NULL)
			{
				Head=newNode;
				newNode->prev=NULL;
			}
			else
			{
			Node* temp=Head;
			while(temp->next != NULL)	
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->prev=temp;
			}
		}
		void del()
		{
			T value;
			cout<<"Enter value to be deleted:";
			cin>>value;
			Node* temp=Head;
			if(temp==NULL)
			{
				cout<<"Linked list is empty!!\n";
				return;
			}
			while(temp->next != NULL)
			{
				if(Head->data==value)
				{
					Head=Head->next;
					(Head->next)->prev=Head;
					cout<<"Deletion successful\n";
					return;
				}
				if(temp->data==value)
				{
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					cout<<"Deletion successful\n";
					return;
				}
				temp=temp->next;
			}
			if(temp->data==value)
			{
				temp->prev->next=NULL;
				cout<<"Deletion Successful\n";
				return;
			}
			cout<<"Element not found!!\n";
			return;
		}
		void display()
		{
			Node* temp=Head;
			while(temp->next != NULL)
			{
				cout<<temp->data<<"<-->";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
			return;
		}
};
int main()
{
	Node<int> x;
	int input;
	while(1)
	{
		cout<<endl<<"1.Insert"<<endl<<"2.Delete\n"<<"3.Display\n"<<"4.exit\n"<<"Select:";
		cin>>input;

		switch(input)
		{
			case 1:
				x.insert();
				break;
			case 2:
				x.del();
				break;
			case 3:
				x.display();
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"Wrong input!!"<<endl;
		}
	}
	return 0;
}

