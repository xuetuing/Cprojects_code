#include<iostream>
using namespace std;
#include<string>

class Ghost
{
private:
	string name;
	int age;
public:
	Ghost(string s,int i)
	{
	  name=s;
	  age=i;
	}
	string getName()
	{
	   return name;
	}
	int getAge()
	{
	   return age;
	}
    void display();
};

void Ghost::display()
	{
	  cout<<endl;
	  cout<<"�Һܰ��㣡"<<endl;
	  cout<<"��ֻ��͵͵�ذ��㣡"<<endl;
	  cout<<"�������޷������Ա�������"<<endl;
	  cout<<"�������޷��������ף�"<<endl;
	  cout<<"�һ���պ���һ��Ŀ�꣡"<<endl;
      cout<<endl;
	}
void main()
{
   Ghost gt("��Сٻ",200);
   
   cout<<"����:  "<<gt.getName()<<endl;
   cout<<"���䣺 "<<gt.getAge()<<endl;
   cout<<endl;

   gt.display();
}


