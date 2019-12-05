#include <iostream>
#include "student.h"
#include "user.h"

using namespace std;

void menu()
{
	cout << "+-----------------------------------------------+\n";
	cout << "|              学生学籍信息管理系统             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1、注册新管理员账号  |  6、添加新学生信息   |\n";
	cout << "|   2、查看管理员账号    |  7、修改学生信息     |\n";
	cout << "|   3、删除管理员账号    |  8、显示学生信息     |\n";
	cout << "|   4、读取学生信息      |  9、查询学生信息     |\n";
	cout << "|   5、保存学生信息      | 10、删除学生信息     |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|                     0、退出                   |\n";
	cout << "+-----------------------------------------------+\n";
}
int main(int argc, char* argv[])
{
	User u1;
	u1.readFile();
	if (u1.logon())
	{
		Student m_stu;
		int choice;
		char str[20];
		menu();
		do
		{
			cout << "请输入指令：";
			cin >> choice;
			while (!cin)  //判断cin输入的是否是整数，如果是正确类型，cin = 0
			{
				cin.clear();  //清空cin流
				cin >> str;   //赋值错误输入到str数组
				cout << "请输入正确的指令：" << endl;
				cin >> choice;
			}
			switch (choice)
			{
			case 1:
				u1.login();
				break;
			case 2:
				u1.show();
				break;
			case 3:
				u1.deleteByName();
			case 4:
				m_stu.readFile();
				break;
			case 5:
				m_stu.saveToFile();
				break;
			case 6:
				m_stu.logon();
				break;
			case 7:
				m_stu.modify();
				break;
			case 8:
				m_stu.Show();
				break;
			case 9:
				m_stu.Query();
				break;
			case 10:
				m_stu.deleteBy();
				break;
			case 0:
				break;
			default:
				cout << "请输入正确的选项!" << endl;
				menu();
				break;
			}
		} while (choice);
	}
	return 0;
}