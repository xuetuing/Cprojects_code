#include <iostream>
#include <string>
#include "CStudent.h"
using namespace std;
 
// ѧ��Ĭ��id��-1��˵������ʱ��һ����Ч��ѧ����
CStudent::CStudent(){this->id = -1;}
CStudent::~CStudent(){}
 
 
int CStudent::getId() const { return id; }
void CStudent:: setId(int val) { id = val; }
 
std::string CStudent:: getName() const { return name; }
void CStudent:: setName(std::string val) { name = val; }
 
 
int CStudent:: getAge() const { return age; }
void CStudent:: setAge(int val) { age = val; }
 
 
std::ostream & operator<<(std::ostream & os, CStudent & stu) {
 
	// �����ʱ��ǧ��Ҫ��,Ҳ�����ȥ����Ȼ�����ʱ�򣬷ǳ����ý����-_-!
	// ss >> x; ��ʧ�ܣ����ж��ţ���
// 	os<<"id: "<<stu.getId()<<", name: "<<stu.getName()<<", age: "
// 		<<stu.getAge();
 
	os<<stu.getId()<<"     "<<stu.getName()<<"     "<<stu.getAge();
 
	return os;
}
 
std::istream & operator>>(std::istream & is, CStudent & stu) {
	is>>stu.id>>stu.name>>stu.age;
	return is;
}
