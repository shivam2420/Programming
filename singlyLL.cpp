#include<iostream>
using namespace std;
template<class T>
class Node
{
	public:
		T data;
		Node* next;
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
			}
			else
			{
			Node* temp=Head;
			while(temp->next != NULL)	
			{
				temp=temp->next;
			}
			temp->next=newNode;
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
					cout<<"Deletion successful\n";
					return;
				}
				if(temp->next->data==value)
				{
					temp->next=(temp->next)->next;
					cout<<"Deletion successful\n";
					return;
				}
				temp=temp->next;
			}
			cout<<"Element not found!!\n";
			return;
		}
		void display()
		{
			Node* temp=Head;
			if(Head==NULL)
			{
				cout<<"Empty Stack";
				return;
			}
			while(temp->next != NULL)
			{
				cout<<temp->data<<"-->";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
			return;
		}
		int pop()
		{
			if(Head==NULL)
			{
				cout<<"Empty Stack!!\n";
				return -1;
			}
			if(Head->next==NULL)
			{
				T value=Head->data;
				Head=NULL;
				return value;
			}
			Node* temp=Head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			T value=temp->next->data;
			temp->next=NULL;
			return value;
		}
		void top()
		{
			Node*temp=Head;
			if(Head==NULL)
			{
				cout<<"Top = -1";
				return;
			}
			if(Head->next==NULL)
			{
				cout<<"Top = "<<Head->data;
				return;
			}
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			cout<<"Top = "<<temp->data;
			return;
		}



};
/*int main()
{
	Node<int> x;
	int input;
	int res;
	while(1)
	{
		cout<<endl<<"1.Insert"<<endl<<"2.Delete\n"<<"3.Display\n"<<"4.push\n"<<"5.Pop\n"<<"6.exit\n"<<"Select:";
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
				x.insert();
				break;
			case 5:
				res=x.pop();
				if(res!=-1)
					cout<<"Popped element:"<<res<<endl;
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"Wrong input!!"<<endl;
		}
	}
	return 0;
}
*/
