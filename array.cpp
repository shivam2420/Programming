#include<iostream>
using namespace std;
template<class T>
class array
{
	public:
	T arr[100];
	int index=-1;
	void insert()
	{
		T value;
		cout<<"Enter value to be inserted:";
		cin>>value;
		if(index>=100)
		{
			cout<<"array is full"<<endl;
			return;
		}
		arr[++index]=value;
	}
	void del()
	{
		if(index==-1)
		{
			cout<<"No element to delete"<<endl;
		}
		T value;
		cout<<"Enter value to be deleted"<<endl;
		cin>>value;
		for(int i=0;i<=index;i++)
		{
			if(arr[i]==value)
			{
				for(int j=i;j<=index;j++)
				{
					arr[j]=arr[j+1];
				}
				cout<<"Element deleted successfully"<<endl;
				index--;
				return;
			}
		}
		cout<<"Element not found!!"<<endl;
		return;
	}
	void display()
	{
		for(int i=0;i<=index;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	void search()
	{
		T value;
		cout<<"Enter value to search:";
		cin>>value;
		for(int i=0;i<=index;i++)
		{
			if(arr[i]==value)
			{
				cout<<"Element is in position:"<<i<<endl;
				return;
			}
		}
		cout<<"Element not found!!"<<endl;
	}
};
int main()
{
	array<int> x;
	int input;
	while(1)
	{
		cout<<endl<<"1.Insert"<<endl<<"2.Delete\n"<<"3.Display\n"<<"4.Search\n"<<"5.exit\n"<<"Select:";
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
				x.search();
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"Wrong input!!"<<endl;
		}
	}
	return 0;
}
