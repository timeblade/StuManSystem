#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
using namespace std;

typedef struct student
{
	//unsigned若省略后一个关键字，大多数编译器会默认为unsigned int
	unsigned stu_id;  //学号
	string stu_name;  //姓名
	unsigned stu_age; //年龄
	string stu_sex;  //性别
	string stu_birth;  //籍贯
	string stu_tel;  //电话
	string stu_email;  //电子邮件
	string stu_department;  //系别
	string stu_major;   //专业
	string stu_class;  //班级
	student* stu_next;  //射线结构链表
}student;

class Student
{
public:
	Student();  //构造函数
	~Student();  //析构函数

	//录入学生信息
	//从标准输入中创建学生，model = 1:不读取学号，2：不读取姓名，其他，读取所有信息
	student* createByStdin(int model, student& tmp);
	void logon();  //连续录入学生信息

	//查找
	void Query() const;  //查询学生信息
	student* findById(unsigned id) const;  //根据学号查找
	student* findByName(const string& name) const;  //根据姓名查找
	student* findBySex(const string& sex) const;  //根据性别查找
	student* findByEmail(const string& email) const; //根据电子邮件查找

	//删除
	void deleteBy();  //删除
	bool deleteById(unsigned& id);  //根据学号删除
	bool deleteByName(string& name);  //根据姓名删除

	//修改
	void modify();  //修改
	bool modifyById();  //根据学号修改
	bool modifyByName();  //根据姓名修改

	//显示
	void Show() const;  //列出学生信息

	//文件操作
	void saveToFile();  //保存到文件
	void readFile();  //读取文件
	bool insert(const student& astu);

	unsigned headCount() const;
private:
	student* head;  //全局的引导进入链表的指针
};

#endif