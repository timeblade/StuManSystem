#include "student.h"
#include <iostream>

using namespace std;

string filename("untitled");
void show(student* p);

Student::Student()
{
	head = new student;
	head->stu_id = 0;
	head->stu_name = "No name";
	head->stu_next = nullptr;
}

Student::~Student()
{
	student* p = head;
	student* q = nullptr;
	while (p)
	{
		q = p;
		p = q->stu_next;
		delete q;
	}
}

//注册函数
void Student::logon()
{
	student tmp;
	cout << "学号(0结束输入)：";
	cin >> tmp.stu_id;

	while (tmp.stu_id)
	{
		if (findById(tmp.stu_id) == nullptr)
		{
			cout << "姓名：";
			cin >> tmp.stu_name;
			cout << "年龄：";
			cin >> tmp.stu_age;
			cout << "性别：";
			cin >> tmp.stu_sex;
			cout << "籍贯：";
			cin >> tmp.stu_birth;
			cout << "系别：";
			cin >> tmp.stu_department;
			cout << "专业：";
			cin >> tmp.stu_major;
			cout << "班级：";
			cin >> tmp.stu_class;
			cout << "电话：";
			cin >> tmp.stu_tel;
			cout << "电子邮箱：";
			cin >> tmp.stu_email;
			insert(tmp);
		}
		else
		{
			cout << "重复的学号：" << tmp.stu_id << endl;
		}
		cout << "学号(0结束输入)：";
		cin >> tmp.stu_id;
	}
}

//查找函数
void Student::Query() const
{
	int select;
	unsigned id;
	string name;
	string sex;
	string email;
	student* p;
	cout << "1.按学号查询\n2.按姓名查询\n3.按性别查询\n4.按email查询\n0.返回\n";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "请输入要查找的学号：";
		cin >> id;
		if ((p = findById(id)))
		{
			show(p->stu_next);
		}
		break;
	case 2:
		cout << "请输入要查找的姓名：";
		cin >> name;
		if ((p = findByName(name)))
		{
			show(p->stu_next);
		}
		break;
	case 3:
		cout << "请输入要查找的性别：";
		cin >> sex;
		if ((p = findBySex(sex)))
		{
			show(p->stu_next);
		}
		break;
	case 4:
		cout << "请输入要查找的email：";
		cin >> email;
		if ((p = findByEmail(email)))
		{
			show(p->stu_next);
		}
		break;
	case 0:
		return;
	default:
		cout << "查找失败，请重新选择查找的方式！" << endl;
	}
}

student* Student::findByEmail(const string& email) const
{
	student* p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_email == email)
		{
			return p;
		}
	}
	cout << "没有找到输入的email!" << endl;
	return nullptr;
}

student* Student::findBySex(const string& sex) const
{
	student* p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_sex == sex)
		{
			return p;
		}
	}
	cout << "没有找到输入的性别的用户！" << endl;
	return nullptr;
}

student* Student::findByName(const string& name) const
{
	student* p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_name == name)
		{
			return p;
		}
	}
	cout << "没有找到输入的姓名！" << endl;
	return nullptr;
}

student* Student::findById(unsigned id) const
{
	student* p;
	for (p = head; p->stu_next; p = p->stu_next)
	{
		if (p->stu_next->stu_id == id)
		{
			return p;
		}
	}
	cout << "没有找到输入的ID！" << endl;
	return nullptr;
}

//删除函数
void Student::deleteBy()
{
	int select;
	unsigned id;
	string name;
	cout << "1.按学号删除\n2.按姓名删除\n0.返回\n";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "请输入您要删除的学号：";
		cin >> id;
		deleteById(id);
		break;
	case 2:
		cout << "请输入与您要删除的姓名：";
		cin >> name;
		deleteByName(name);
		break;
	case 0:
		return;
	default:
		cout << "删除失败，请重新选择删除的方式！" << endl;
	}
}

bool Student::deleteById(unsigned& id)
{
	student* p = nullptr;
	student* q = nullptr;
	p = findById(id);
	if (p == nullptr)
	{
		cout << "没有找到学号是：\"" << id << "\"的学生，删除失败！" << endl;
		return false;
	}
	q = p->stu_next;
	p->stu_next = q->stu_next;
	delete q;
	cout << "成功删除学号为：\"" << id << "\"的学生的信息" << endl;
	return true;
}

bool Student::deleteByName(string& name)
{
	student* p = nullptr;
	student* q = nullptr;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "没有找到姓名为：\"" << name << "\"的学生，删除失败！" << endl;
		return false;
	}
	q = p->stu_next;
	p->stu_next = q->stu_next;
	delete q;
	cout << "成功删除姓名为：\"" << name << "\"的信息\n";
	return true;
}

//修改函数
void Student::modify()
{
	int select;
	cout << "1.按学号修改\n2.按姓名修改\n0.返回\n";
	cin >> select;
	switch (select)
	{
	case 1:
		if (modifyById())
		{
			cout << "修改成功！\n";
		}
		break;
	case 2:
		if (modifyByName())
		{
			cout << "修改成功！\n";
		}
		break;
	case 0:
		return;
	default:
		cout << "修改失败，请重新选择修改的方式！" << endl;
		break;
	}
}

bool Student::modifyById()
{
	student* p = nullptr;
	unsigned id;
	cout << "请输入要修改的学号：" << endl;
	cin >> id;
	p = findById(id);
	if (p == nullptr)
	{
		cout << "没有找到学号是：\"" << id << "\"的学生，修改失败！\n";
		return false;
	}
	createByStdin(1, *(p->stu_next));
	return true;
}

bool Student::modifyByName()
{
	student* p;
	string name;
	cout << "请输入您要修改的姓名：";
	cin >> name;
	p = findByName(name);
	if (p == nullptr)
	{
		cout << "没有找到姓名为：\"" << name << "\"的学生，修改失败！\n";
		return false;
	}
	createByStdin(2, *(p->stu_next));
	return true;
}

student* Student::createByStdin(int model, student& tmp)
{
	if (model == 1)
	{
		cout << "学号：";
		cin >> tmp.stu_id;
	}
	if (model == 2)
	{
		cout << "姓名：";
		cin >> tmp.stu_name;
	}
	cout << "年龄：";
	cin >> tmp.stu_age;
	cout << "性别：";
	cin >> tmp.stu_sex;
	cout << "籍贯：";
	cin >> tmp.stu_birth;
	cout << "系别：";
	cin >> tmp.stu_department;
	cout << "专业：";
	cin >> tmp.stu_major;
	cout << "班级：";
	cin >> tmp.stu_class;
	cout << "手机：";
	cin >> tmp.stu_tel;
	cout << "电子邮箱：";
	cin >> tmp.stu_email;
	return &tmp;
}

//文件操作函数
void Student::saveToFile()
{
	string new_file;
	cout << "请输入要保存的文件名：";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	int len = headCount();
	file << len << endl;
	student* pHead = head->stu_next;
	while (pHead != nullptr)
	{
		file << pHead->stu_id << endl;
		file << pHead->stu_name << endl;
		file << pHead->stu_sex << endl;
		file << pHead->stu_age << endl;
		file << pHead->stu_birth << endl;
		file << pHead->stu_department << endl;
		file << pHead->stu_major << endl;
		file << pHead->stu_class << endl;
		file << pHead->stu_email << endl;
		file << pHead->stu_tel << endl;
		pHead = pHead->stu_next;
	}
	file.close();
	cout << "保存成功！" << endl;
	filename = new_file;
	return;
}

void Student::readFile()
{
	string new_file;
	cout << "请输入要读取的文件名：";
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	int len = 0;
	file >> len;
	while (!len)
	{
		cout << "文件数据异常！" << endl;
		return;
	}
	student pHead;
	file.get();
	while (len--)
	{
		file >> pHead.stu_id;
		file >> pHead.stu_name;
		file >> pHead.stu_sex;
		file >> pHead.stu_age;
		file >> pHead.stu_birth;
		file >> pHead.stu_department;
		file >> pHead.stu_major;
		file >> pHead.stu_class;
		file >> pHead.stu_email;
		file >> pHead.stu_tel;
		insert(pHead);
	}
	file.close();
	cout << "文件读入成功！" << endl;
	filename = new_file;
	return;
}

bool Student::insert(const student& astu)
{
	student* newnode = nullptr;
	student* p = head;
	if (p->stu_next == nullptr)  //当没有下一个堆，这新建一个堆来存储数据
	{
		p->stu_next = new student(astu);  //用传入的已修改结构初始化
		p->stu_next->stu_next = nullptr;  //nullptr处理再下一个堆
		return true;
	}
	while (p->stu_next)  //当存在下一个堆
	{
		if (p->stu_next->stu_id == astu.stu_id)  //判重
		{
			cout << "学号重复，插入失败！" << endl;
			return false;
		}
		if (p->stu_next->stu_id > astu.stu_id)  //如果下一个堆的id大于传入的id
		{
			newnode = new student(astu);   //newnode指向初始修改结构
			newnode->stu_next = p->stu_next;
			p->stu_next = newnode;
			return true;
		}
		p = p->stu_next;
	}
	p->stu_next = new student(astu);
	p->stu_next->stu_next = nullptr;
	return true;
}

//显示函数
void Student::Show() const
{
	student* p = nullptr;
	cout << "--------------------------------------------" << endl;
	for (p = head->stu_next; p; p = p->stu_next)
	{
		show(p);
	}
	cout << "--------------------------------------------" << endl;
}

void show(student* p)
{
	cout << "  学号：" << p->stu_id << "  姓名： " << p->stu_name << "  年龄： " << p->stu_age << "  性别： ";
	cout << p->stu_sex << "  籍贯： " << p->stu_birth << "  系别： " << p->stu_department << endl;
	cout << "  专业： " << p->stu_major << "  班级： " << p->stu_class << "  手机： " << p->stu_tel << "  Email： " << p->stu_email << endl;
}

//结构数量计算函数
unsigned Student::headCount() const
{
	unsigned cnt = 0;
	student* p;
	for (p = head->stu_next; p; p = p->stu_next, ++cnt);
	return cnt;
}