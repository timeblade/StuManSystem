#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

User::User()
{
	head = new user;
	head->m_name = "admin";
	head->m_password = "123";
	head->next_user = nullptr;
}

User::~User()
{
	user* p = head;
	user* q = nullptr;
	while (p)
	{
		q = p;
		p = q->next_user;
		delete q;
	}
}

void User::readFile()
{
	string new_file = "user";
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "文件打开失败........." << endl;
		return;
	}
	int len = 0;
	file >> len;
	//cout << "len = " << len << endl;
	if (!len)
	{
		cout << "已新建管理员数据文件，请注册管理员账号....." << endl;
		login();
		return;
	}
	user pHead;
	file.get();
	while (len--)
	{
		file >> pHead.m_name;
		file >> pHead.m_password;
		insert(pHead);
	}
	file.close();
	
	cout << "请输入管理员账号以登陆......." << endl;
	return;
}

void User::saveFile()
{
	string new_file = "user";
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "文件打开失败.........." << endl;
		return;
	}
	int len = headCount() - 1;
	file << len << endl;
	user* pHead = head->next_user;
	while (pHead != nullptr)
	{
		file << pHead->m_name << endl;
		file << pHead->m_password << endl;
		pHead = pHead->next_user;
	}
	file.close();
	return;
}

bool User::insert(const user& astu)
{
	user* p = head;
	if (p->next_user == nullptr)  //当没有下一个堆，则新建一个堆来储存修改数据
	{
		p->next_user = new user(astu);  //用传入的已修改结构初始化
		p->next_user->next_user = nullptr;  //nullptr处理再下一个堆
		return true;
	}
	while (p->next_user)  //当存在下一个堆
	{
		if (p->next_user->m_name == astu.m_name)  //判重
		{
			cout << "用户名重复，插入失败......." << endl;
			return false;
		}
		p = p->next_user;  //既不大于也不重复就后移添加
	}
	p->next_user = new user(astu);
	p->next_user->next_user = nullptr;
	return true;
}

unsigned User::headCount()
{
	unsigned cnt = 0;
	user* p = nullptr;
	for (p = head; p; p = p->next_user, ++cnt);
	return cnt;
}

user* User::findByName(const string& name) const
{
	user* p = nullptr;
	for (p = head; p->next_user; p = p->next_user)
	{
		if (p->next_user->m_name == name)
		{
			return p;
		}
	}
	return nullptr;
}

void User::deleteByName()
{
	user* p = nullptr;
	user* q = nullptr;
	cout << "请输入要删除的用户名：" << endl;
	string name;
	cin >> name;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "没有找到账号 \"" << name << "\", 删除失败....." << endl;
	}
	q = p->next_user;
	p->next_user = nullptr;
	delete q;
	cout << "成功删除 \"" << name << "\"的账号......." << endl;
	saveFile();
}

void User::show()
{
	user* p = nullptr;
	cout << "------------------------------------\n" << endl;
	for (p = head->next_user; p; p = p->next_user)
	{
		cout << "用户名：" << p->m_name << "	密码：" << p->m_password << endl;
	}
	cout << "------------------------------------\n" << endl;
}

void User::login()
{
	user tmp;
	cout << "请输入注册用的用户名：";
	cin >> tmp.m_name;
	if (findByName(tmp.m_name) == nullptr)
	{
		cout << "请输入注册用的密码：";
		cin >> tmp.m_password;
		insert(tmp);
	}
	else
	{
		cout << "您输入的用户名：" << tmp.m_name << "已存在，请重新输入用户名" << endl;
		login();
	}
	saveFile();
}

bool User::logon()
{
	cout << "登陆" << endl;
	cout << "请输入登陆用户名：";
	string name;
	cin >> name;
	user* p = nullptr;
	if (findByName(name))
	{
		p = findByName(name);
		cout << "请输入登陆密码：";
		string password;
		cin >> password;
		if (p->next_user->m_password == password)
		{
			cout << "登陆成功.........." << endl;
			return true;
		}
		else
		{
			cout << "登陆密码错误，请重新输入...." << endl;
			logon();
		}
	}
	else
	{
		cout << "没有找到此用户名！" << endl;
		logon();
	}
	return false;
}