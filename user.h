#pragma once
#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

typedef struct user
{
	string m_name;  //用户名
	string m_password;  //密码
	user* next_user;  //链表
}user;

class User
{
public:
	User();
	~User();
	user* findByName(const string& name) const;  //查找文件中的用户名
	//非静态成员函数名后加const修饰this指针，表示不允许修改成员变量
	void readFile();  //读取文件
	void saveFile();  //保存文件
	void login();  //注册函数
	bool logon();  //登陆函数
	unsigned headCount();  //结构计数函数
	bool insert(const user& astu);  //插入函数
	void deleteByName();  //删除函数
	void show();   //显示函数
private:
	user* head;
};

#endif
