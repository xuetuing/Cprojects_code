#include<iostream>
#include<string>

using namespace std;

int func(int x);
void main()
{
	int a;
	a = func(9999);
	cout<<a<<endl;
};

int func(int x)
{
	int count=0;
	while(x)
	{
		count++;
		x=x&(x-1);
	}
	return count;
};