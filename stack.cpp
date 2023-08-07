#include<iostream>
#include "singlyLL.cpp"
using namespace std;
int main()
{
	Node<int> x;
	int value;
	int res;
	while(1)
	{
		cout<<endl<<endl<<"1.push\n"<<"2.pop\n"<<"3.Display\n"<<"4.Top\n"<<"5.Exit\n"<<"Select input:";
		cin>>value;
		switch(value)
		{
			case 1:
				x.insert();
				break;
			case 2:
				res=x.pop();
				if(res!=-1)
					cout<<"Popped Element:"<<res<<endl;
				break;
			case 3:
				x.display();
				break;
			case 4:
				x.top();
				break;
			case 5:
				return 0;
			default:
				cout<<"Wrong input!!";
				break;
		}
	}
return 0;
}
