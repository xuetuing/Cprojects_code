#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "CStudent.h"
#include "CStudentMg.h"
 
using namespace std;
 
CStudentMg::CStudentMg()
{
}
 
CStudentMg::~CStudentMg()
{
}
 
// ��
CStudent CStudentMg:: addAStu(map<int,CStudent> & m1,CStudent & stu) {
	
	// �ȼ���id�����ظ���
	m1.insert(make_pair(stu.getId(),stu));
	return stu;
}
 
// ɾ
bool  CStudentMg:: deleteStuById(map<int, CStudent> & m1, const int & id) {
 
	bool b = false;
 
	map<int,CStudent> ::iterator iter;
	iter = m1.find(id);
	if (iter!=m1.end())
	{
		m1.erase(iter);
		b = true; // ɾ���ɹ�
	}
	
	return b;
}
 
// ��
CStudent CStudentMg:: updateStu(map<int,CStudent> & m1,const CStudent & cStu) {
 
	// ��������һ��smart point��
	// �ǿ���ͨ��������ȥ���ʵ� m1��Ķ��������������޸ĵģ�
	// ���ǵ�������const������
 
	CStudent stu;
	int id = cStu.getId();
	
	map<int,CStudent> :: iterator iter;
	iter = m1.find(id);
	if (iter!=m1.end())
	{
		// �޸�
		iter->second = cStu;
		stu = cStu; // ���޸ĺ�Ķ��󣬸�ֵ���ٷ����ϲ�
	}
 
	return stu;
}
 
// �� by id
CStudent  CStudentMg:: findById(const map <int, CStudent> & m1, const int & id) const{
 
	CStudent stu ;
 
	map<int,CStudent> ::const_iterator iter;
	iter = m1.find(id);
	if (iter!=m1.end())
	{
		stu = iter->second;
	}
 
	return stu;
}
 
// showAll
void  CStudentMg:: showAll(const map<int,CStudent> & m1) const{
 
	for (auto p : m1)
	{
		cout<<p.second<<endl;
	}
	
}
 
// save to file
bool CStudentMg::saveToFile(const map <int,CStudent> & m1,const string & pathName) const{
 
	bool b = true;
 
	//fstream ofs(pathName,ios::out+ios::binary); // Ϊʲô������binary���棿
	fstream ofs(pathName,ios::out);
	if (ofs) {
		stringstream ss;
 
		cout<<"�ļ���"<<endl;
		
		CStudent stu;
		for (auto p = m1.begin();p!=m1.end();p++)
		{
			stu = p->second;
			ss<<stu<<endl;
		}
		
		ofs<<ss.str(); // ע�⣬���һ���� ss.str();
		
		ofs.close();
	}
	else
	{
		cout<<"�ļ���ʧ��"<<endl;
		b = false;
	}
 
	return b;
}
 
 
// read from file
bool CStudentMg:: readFromFile(std::map<int,CStudent> & m1, std::string path) {
	bool b = true;
 
	m1.clear(); // ���ԭ����
	
	fstream ifs(path,ios::in);
	if (ifs) {
		cout<<"�ļ���"<<endl;
		string s;
		stringstream ss;
		while (getline(ifs,s)) // ��ôһ���еض�ȡ��
		{
			CStudent cStu;
			ss<<s;
			// cout<<ss.str();
			ss>>cStu;
 			ss.clear();
 
			m1.insert(make_pair(cStu.getId(),cStu));
			
		}
 
		ifs.close();
 
	}
	else {
		cout<<"�ļ���ʧ��"<<endl;
		b = false;
	}
 
	return b;
}
