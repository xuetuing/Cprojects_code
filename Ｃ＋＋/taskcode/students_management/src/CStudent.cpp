#include <iostream>
#include <string>
#include "CStudent.h"
#include <iomanip>

using namespace std;
 
// 学生默认id是-1，说明这暂时是一个无效的学生。
CStudent::CStudent(){this->id = -1;}
CStudent::~CStudent(){}
 
 
int CStudent::getId() const { return id; }
void CStudent:: setId(int val) { id = val; }
 
std::string CStudent:: getName() const { return name; }
void CStudent:: setName(std::string val) { name = val; }
 
 
int CStudent:: getAge() const { return age; }
void CStudent:: setAge(int val) { age = val; }

int* CStudent:: getScores() { return scores; }
void CStudent:: setScores(int* s, int len) 
{ 
    memcpy(this->scores,s,len*sizeof(s));
}

int CStudent:: getSum(int id) const{return 111;}
void CStudent:: setSum(int sum) { sum = sum; }

int CStudent:: getAverage(int id) const{return 111;}
void CStudent:: setAverage(int average) { average = average; }

void CStudent:: toString(){
    cout<<this->id<<"    "<<this->name<<"    "<<this->age<<"    ";
    //打印数组
    int len = sizeof(this->scores)/sizeof(this->scores[0]);
    for(auto score : this->scores){
        cout<<score<<"  ";
    }
    cout<<this->sum<<"    "<<this->average<<endl;
}
std::ostream & operator<<(std::ostream & os, CStudent & stu) {
 
	// 保存的时候，千万不要把,也保存进去！不然输入的时候，非常不好解决！-_-!
	// ss >> x; 会失败！！有逗号！！
// 	os<<"id: "<<stu.getId()<<", name: "<<stu.getName()<<", age: "
// 		<<stu.getAge();
 
	os<<stu.getId()<<"     "<<stu.getName()<<"     "<<stu.getAge();
	os<<stu.getScores()[0]<<"     "<<stu.getScores()[1]<<"     "<<stu.getScores()[2]<<"     "<<stu.getScores()[3];
 
	return os;
}
 
std::istream & operator>>(std::istream & is, CStudent & stu) {
	is>>stu.id>>stu.name>>stu.age>>stu.scores[0]>>stu.scores[1]>>stu.scores[2]>>stu.scores[3];
	return is;
}
