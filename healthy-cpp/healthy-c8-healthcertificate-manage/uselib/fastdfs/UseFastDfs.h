#pragma once
#include <string>
#include <iostream>

using std::string;
class UseFastDfs
{
public:
	static string uploadFile(const string& fileName);
	static string downloadFile(const string& url, string path = "./public/fastdfs");
};
