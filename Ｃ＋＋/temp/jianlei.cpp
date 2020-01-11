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
	  cout<<"我很爱你！"<<endl;
	  cout<<"我只能偷偷地爱你！"<<endl;
	  cout<<"怎样都无法摆脱自卑的心理！"<<endl;
	  cout<<"我心意无法让你明白！"<<endl;
	  cout<<"我会把握好下一个目标！"<<endl;
      cout<<endl;
	}
void main()
{
   Ghost gt("聂小倩",200);
   
   cout<<"姓名:  "<<gt.getName()<<endl;
   cout<<"年龄： "<<gt.getAge()<<endl;
   cout<<endl;

   gt.display();
}


