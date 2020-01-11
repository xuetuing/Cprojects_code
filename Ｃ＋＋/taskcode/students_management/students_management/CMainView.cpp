
#include "CMainView.h"
 
CMainView::CMainView()
{
}
 
CMainView::~CMainView()
{
}
 
/* ��ӭ */
void CMainView:: welcome() {
	system("cls");
	std::cout<<"��ӭ����xxx��ϵͳ"<<std::endl;
}
 
/* ��ʾ�˵� */
void CMainView:: showMenu() {
 
	std::cout<<"\n";
	std::cout<<"��������"<<std::endl;
 
	std::cout<<"1. ¼��"<<std::endl;
	std::cout<<"2. �޸�"<<std::endl;
	std::cout<<"3. ����"<<std::endl;
	std::cout<<"4. ɾ��"<<std::endl;
	std::cout<<"5. ��ʾ����"<<std::endl;
	std::cout<<"6. �������ļ�"<<std::endl;
	std::cout<<"7. ���ļ�����"<<std::endl;
	std::cout<<"0. �˳�"<<std::endl;
	std::cout<<"\n";
 
	std::cout<<"Author��qcy"<<std::endl;
	std::cout<<"2016/11/28"<<std::endl;
 
	std::cout<<"\n";
	std::cout<<"��ѡ�������";
}
 
 
/* view ��ʾ����ѧ�� */
void CMainView:: showAllStuAtView(const std::map<int, CStudent> & stu_m1 )
{
 
	system("cls");
	std::cout<<"id    |"<<"name  |"<<"age"<<std::endl;
	CStudentMg cStuMg;
	cStuMg.showAll(stu_m1);
 
	system("pause");
	system("cls");
	welcome();
	showMenu();
}
 
/* view�� ���һ��ѧ�� */
void  CMainView:: addStuAtView( std::map<int, CStudent> & stu_m1 )
{
	CStudentMg cStuMg;
 
	int id; 
	std::string name;
	int age;
	CStudent cStu;
 
	system("cls");
 
	std::cout<<"¼��\n";
	std::cout<<"id:";
	std::cin>>id;
 
	std::cout<<"name:";
	std::cin>>name;
 
	std::cout<<"age:";
	std::cin>>age;
 
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);
 
	// ����
	cStuMg.addAStu(stu_m1,cStu);
 
	system("cls");
	welcome();
	showMenu();
}
 
 
 
/* view ����һ��ѧ�� */
void  CMainView::  findStuAtView(const std::map<int, CStudent> & m1) {
 
	system("cls");
	std::cout<<"������Ҫ����ѧ����id"<<std::endl;
	int id;
	std::cin>>id;
 
	CStudentMg cStuMg;
	CStudent cStu;
	cStu = cStuMg.findById(m1,id);
 
	if (cStu.getId()!=-1)
	{
		std::cout<<cStu<<std::endl;
	}
	else
	{
		std::cout<<"���޴���"<<std::endl;
	}
 
	system("pause");
	system("cls");
	welcome();
	showMenu();
 
}
 
/* view��ɾ��һ��ѧ�� */
void   CMainView:: deleteByIdAtView(std::map<int, CStudent> & v1) {
 
	system("cls");
	std::cout<<"������Ҫɾ����ѧ����id"<<std::endl;
	int id;
	std::cin>>id;
 
	CStudentMg cStuMg;
	bool b = cStuMg.deleteStuById(v1,id);
 
	if (b)
	{
		std::cout<<"ɾ���ɹ�"<<std::endl;
	}
	else {
		std::cout<<"���޴���"<<std::endl;
	}
 
	system("pause");
	system("cls");
	welcome();
	showMenu();
 
}
 
/* view�� ����һ��ѧ�� */
void   CMainView:: updateByIdAtView(std::map<int, CStudent> & m1) {
 
	system("cls");
 
	std::cout<<"������Ҫ�޸ĵ�ѧ����id"<<std::endl;
	int id;
	std::cin>>id;
	std::string name;
 
	std::cout<<"name:";
	std::cin>>name;
 
	int age;
	std::cout<<"age:";
	std::cin>>age;
 
	CStudent cStu;
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);
 
	CStudentMg cStuMg;
 
	CStudent cStu2 = cStuMg.updateStu(m1,cStu);
 
	if (cStu2.getId()!=-1)
	{
		std::cout<<cStu2<<std::endl;
		std::cout<<"�޸ĳɹ�"<<std::endl;
	}
	else
	{
		std::cout<<"���޴���"<<std::endl;
	}
 
	system("pause");
	system("cls");
	welcome();
	showMenu();
 
}
 
/* view�� ��vec������ļ� */
void   CMainView:: saveToFileAtView(const std::map<int, CStudent> & m1, std::string pathName) {
 
	if (m1.begin()==m1.end()) {
		system("cls");
		std::cout<<"��û���κ�ѧ����Ϣ���޷�����"<<std::endl;
	}
	else {
		// ����
		CStudentMg cStuMg;
		bool b = cStuMg.saveToFile(m1,pathName);
		if (b) {
			system("cls");
			std::cout<<"����ɹ�"<<std::endl;
		}
		else  {
			std::cout<<"����ʧ��"<<std::endl;
		}
	}
 
	system("pause");
	system("cls");
	welcome();
	showMenu();
 
}
 
/* view�� ���ļ��еĶ������� vec */
void  CMainView::  readFromFileAtView(std::map<int, CStudent> & m, std::string pathName) {
 
	system("cls");
 
	CStudentMg cStuMg;
	bool b = cStuMg.readFromFile(m,pathName);
	if (b){
		std::cout<<"��ȡ�ɹ�"<<std::endl;
	}
	else {
		std::cout<<"��ȡʧ��"<<std::endl;
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();
}
