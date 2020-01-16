#include "CMainView.h"
#include "command.h"
//#define CLS (IS_WINDOWS == 0?"cls" : "clear") 
//#define PAUSE (IS_WINDOWS == 0?"pause" : "read -n 1")
CMainView::CMainView()
{
}
 
CMainView::~CMainView()
{
}
 
/* 欢迎 */
void CMainView:: welcome() {
	Command::cls();
	std::cout<<"欢迎来到xxx大系统"<<std::endl;
}
 
/* 显示菜单 */
void CMainView:: showMenu() {
 
	std::cout<<"\n";
	std::cout<<"操作步骤"<<std::endl;
 
	std::cout<<"1. 录入"<<std::endl;
	std::cout<<"2. 修改"<<std::endl;
	std::cout<<"3. 查找"<<std::endl;
	std::cout<<"4. 删除"<<std::endl;
	std::cout<<"5. 显示所有"<<std::endl;
	std::cout<<"6. 保存至文件"<<std::endl;
	std::cout<<"7. 从文件导入"<<std::endl;
	std::cout<<"0. 退出"<<std::endl;
	std::cout<<"\n";
 
	std::cout<<"Author：qcy"<<std::endl;
	std::cout<<"2016/11/28"<<std::endl;
 
	std::cout<<"\n";
	std::cout<<"请选择操作：";
}
 
 
/* view 显示所有学生 */
void CMainView:: showAllStuAtView(const std::map<int, CStudent> & stu_m1 )
{
 
	//Command::cls();
	std::cout<<"Id    |"<<"Name    |"<<"Age    |"<<"Chinese    |"<<"Math    |"<<"English    |"<<"Politics    |"<<"Sum    |"<<"Average    "<<std::endl;
	CStudentMg cStuMg;
	cStuMg.showAll(stu_m1);
 
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
}
 
/* view层 添加一个学生 */
void  CMainView:: addStuAtView( std::map<int, CStudent> & stu_m1 )
{
	CStudentMg cStuMg;
 
	int id; 
	std::string name;
	int age;
    int scores[CLASSES];
    
	CStudent cStu;
 
	Command::cls();
 
	std::cout<<"录入\n";
	std::cout<<"Id:";
	std::cin>>id;
 
	std::cout<<"Name:";
	std::cin>>name;
 
	std::cout<<"Age:";
	std::cin>>age;

    std::cout<<"Chinese:";
	std::cin>>scores[0];

    std::cout<<"Math:";
	std::cin>>scores[1];

    std::cout<<"Englist:";
	std::cin>>scores[2];

    std::cout<<"Politics:";
	std::cin>>scores[3];
 
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);
    cStu.setScores(scores, CLASSES);
    cStu.setSum(111);
    cStu.setAverage(111);
	// 保存
	cStuMg.addAStu(stu_m1,cStu);
 
	//Command::cls();
	welcome();
	showMenu();
}
 
 
 
/* view 查找一个学生 */
void  CMainView::  findStuAtView(const std::map<int, CStudent> & m1) {
 
	//Command::cls();
	std::cout<<"请输入要查找学生的id"<<std::endl;
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
		std::cout<<"查无此人"<<std::endl;
	}
 
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
 
}
 
/* view层删除一个学生 */
void   CMainView:: deleteByIdAtView(std::map<int, CStudent> & v1) {
 
	Command::cls();
	std::cout<<"请输入要删除的学生的id"<<std::endl;
	int id;
	std::cin>>id;
 
	CStudentMg cStuMg;
	bool b = cStuMg.deleteStuById(v1,id);
 
	if (b)
	{
		std::cout<<"删除成功"<<std::endl;
	}
	else {
		std::cout<<"查无此人"<<std::endl;
	}
 
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
 
}
 
/* view层 更新一个学生 */
void   CMainView:: updateByIdAtView(std::map<int, CStudent> & m1) {
 
	Command::cls();
 
	std::cout<<"请输入要修改的学生的id"<<std::endl;
	int id;
	std::cin>>id;
	std::string name;
    int age;
    int scores[CLASSES];
    char flag = 'n';

    CStudent cStu;
 
	std::cout<<"Name:";
	std::cin>>name;
	
	std::cout<<"Age:";
	std::cin>>age;

    std::cout<<"update the scores(y/n)?: ";
    std::cin>>flag;
    if(flag == 'y') {
        std::cout<<"Chinese:";
        std::cin>>scores[0];

        std::cout<<"Math:";
        std::cin>>scores[1];

        std::cout<<"Englist:";
        std::cin>>scores[2];

        std::cout<<"Politics:";
        std::cin>>scores[3];

        cStu.setScores(scores, CLASSES);
    }
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);
 
	CStudentMg cStuMg;
 
	CStudent cStu2 = cStuMg.updateStu(m1,cStu);
 
	if (cStu2.getId()!=-1)
	{
		std::cout<<cStu2<<std::endl;
		std::cout<<"修改成功"<<std::endl;
	}
	else
	{
		std::cout<<"查无此人"<<std::endl;
	}
 
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
 
}
 
/* view层 把vec保存进文件 */
void   CMainView:: saveToFileAtView(const std::map<int, CStudent> & m1, std::string pathName) {
 
	if (m1.begin()==m1.end()) {
		Command::cls();
		std::cout<<"还没有任何学生信息，无法保存"<<std::endl;
	}
	else {
		// 保存
		CStudentMg cStuMg;
		bool b = cStuMg.saveToFile(m1,pathName);
		if (b) {
			Command::cls();
			std::cout<<"保存成功"<<std::endl;
		}
		else  {
			std::cout<<"保存失败"<<std::endl;
		}
	}
 
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
 
}
 
/* view层 把文件中的东西导入 vec */
void  CMainView::  readFromFileAtView(std::map<int, CStudent> & m, std::string pathName) {
 
	Command::cls();
 
	CStudentMg cStuMg;
	bool b = cStuMg.readFromFile(m,pathName);
	if (b){
		std::cout<<"读取成功"<<std::endl;
	}
	else {
		std::cout<<"读取失败"<<std::endl;
	}
	Command::pause();
	//Command::cls();
	welcome();
	showMenu();
}
