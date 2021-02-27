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
    parser.openfile("G:/编译原理/project/Project3/Project3/parser/grammar1.txt");//G:\编译原理\project\Project3\Project3\parser
    parser.build();
    parser.analyse(tokens);

}
int main()
{
	cout << "请将要处理的代码输入到test.txt中，要生成中间代码选择1，否则选择0" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		analyse();
		//out << "a" << endl;
	}
	else if (a == 0) 
		cout << "重新在test.txt中输入代码，然后再次调试" << endl;
	system("pause");
	return 0;
	
}
