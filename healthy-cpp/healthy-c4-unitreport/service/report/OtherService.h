#ifndef _OTHERSERVICE_H_
#define _OTHERSERVICE_H_
#include <string>
using namespace std;

class TestPdf
{
public:
	// ���Ի����ı�
	static void testText();
	// ����ģ�����
	static void testTpl();
};

class TestFastDfs {
public:
	static void testDfs(string fileName);
	static string testDfsWithConf(string fileName);
};


#endif 