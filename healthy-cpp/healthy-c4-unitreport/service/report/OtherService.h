#ifndef _OTHERSERVICE_H_
#define _OTHERSERVICE_H_
#include <string>
using namespace std;

class TestPdf
{
public:
	// 测试绘制文本
	static void testText();
	// 测试模板绘制
	static void testTpl();
};

class TestFastDfs {
public:
	static void testDfs(string fileName);
	static string testDfsWithConf(string fileName);
};


#endif 