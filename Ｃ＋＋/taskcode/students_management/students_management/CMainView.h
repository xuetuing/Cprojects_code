#ifndef C_MAIN_VIEW_H
#define C_MAIN_VIEW_H
 
#include <iostream>
#include <map>
#include <string>
#include "CStudent.h"
#include "CStudentMg.h"
 
class CMainView
{
public:
	CMainView();
	~CMainView();
 
	/* ��ӭ */
	void welcome();
 
	/* ��ʾ�˵� */
	void showMenu();
 
	/* view ��ʾ����ѧ�� */
	void showAllStuAtView(const std::map<int, CStudent> & stu_m1);
 
	/* view�� ���һ��ѧ�� */
	void addStuAtView( std::map<int, CStudent> & stu_m1 );
 
	/* view ����һ��ѧ�� */
	void findStuAtView(const std::map<int, CStudent> & m1) ;
 
	/* view��ɾ��һ��ѧ�� */
	void deleteByIdAtView(std::map<int, CStudent> & v1);
 
	/* view�� ����һ��ѧ�� */
	void updateByIdAtView(std::map<int, CStudent> & m1);
 
	/* view�� ��map������ļ� */
	void saveToFileAtView(const std::map<int, CStudent> & m1, std::string pathName);
 
	/* view�� ���ļ��еĶ������� map */
	void readFromFileAtView(std::map<int, CStudent> & m, std::string pathName);
 
private:
 
};
 
#endif
