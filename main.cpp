#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "scanner/scanner.h"
#include "parser/parser.h"

using namespace std;

void analyse()
{
    Scanner scanner;
    auto tokens = scanner.get_tokens("test.txt");
	//cout << "a" << endl;

    Parser parser;
    parser.openfile("G:/����ԭ��/project/Project3/Project3/parser/grammar1.txt");//G:\����ԭ��\project\Project3\Project3\parser
    parser.build();
    parser.analyse(tokens);

}
int main()
{
	cout << "�뽫Ҫ����Ĵ������뵽test.txt�У�Ҫ�����м����ѡ��1������ѡ��0" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		analyse();
		//out << "a" << endl;
	}
	else if (a == 0) 
		cout << "������test.txt��������룬Ȼ���ٴε���" << endl;
	system("pause");
	return 0;
	
}
