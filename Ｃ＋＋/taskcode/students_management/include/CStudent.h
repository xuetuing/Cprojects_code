#ifndef C_STUDENT_H
#define C_STUDENT_H
#include <string>
#include <iostream>

#define CLASSES 4 
class CStudent
{
	/* friend function */
	friend std::ostream & operator<<(std::ostream & os, CStudent & stu);
	friend std::istream & operator>>(std::istream & is, CStudent & stu);
 
public:
 
	CStudent();
	~CStudent();
 
	int getId() const;
	void setId(int val);
 
	std::string getName() const;
	void setName(std::string val);
 
	int getAge() const;
	void setAge(int val);

	int* getScores();
	void setScores(int* scores, int len);

    int getSum(int id) const;
    void setSum(int sum);

    int getAverage(int id) const;
    void setAverage(int average);

    void toString();
 
private:
	int id;
	std::string name;
	int age;
	int scores[CLASSES];
    int sum;
    int average;
};
 
 
#endif
