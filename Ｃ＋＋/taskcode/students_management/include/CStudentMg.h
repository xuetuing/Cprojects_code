#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include "CStudent.h"
#include <map>
#include <string>
 
class CStudentMg
{
public:
	CStudentMg();
	~CStudentMg();
 
	// 增
	CStudent addAStu(std::map<int,CStudent> & m1,CStudent & stu);
 
	// 删
	bool deleteStuById(std::map<int, CStudent> & m1,const int & id);
 
	// 改
	CStudent updateStu(std::map<int, CStudent> & m1, const CStudent & stu);
 
	// 查 by id
	CStudent findById(const std::map<int, CStudent> & m1, const int & id) const;
	
	
	// showAll
	void showAll(const std::map<int, CStudent> & m1 ) const;
	
	// save to file
	bool saveToFile(const std::map <int,CStudent> & m1,const std::string & pathName) const;
 
	// read from file
	bool readFromFile(std::map<int, CStudent> & m1, std::string path);
	
 
private:
 
};
 
 
#endif
