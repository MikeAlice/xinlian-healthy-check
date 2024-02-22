#pragma once

#ifndef _TESTVALIDATOR_H_
#define _TESTVALIDATOR_H_

#include <string>  
#include <regex>  

/**
 * 参数校验包括
   非空校验：必填参数不为空
   去重校验：比如同一订单的体检人员中，身份证不能重复
   合规校验：身份证、社会信用代码等要校验是否符合规定
   ……
 */
class TestValidator
{
public:
	//统一社会信用代码校验
	bool is_valid_credit_code(const std::string& id) {
		std::regex code_regex("[0-9A-HJ-NPQRTUWXY]{2}\\d{6}[0-9A-HJ-NPQRTUWXY]{10}|[1-9]\\d{14}"); // 统一社会信用代码的正则表达式  
		return std::regex_match(id, code_regex);
	}

	//身份证校验
	bool is_valid_idCard(const std::string& a)
	{
		int k = ((a[0] - '0') * 7 + (a[1] - '0') * 9 + (a[2] - '0') * 10 + (a[3] - '0') * 5 + (a[4] - '0') * 8 + (a[5] - '0') * 4 + (a[6] - '0') * 2 + (a[7] - '0') * 1 + (a[8] - '0') * 6 + (a[9] - '0') * 3 + (a[10] - '0') * 7 + (a[11] - '0') * 9 + (a[12] - '0') * 10 + (a[13] - '0') * 5 + (a[14] - '0') * 8 + (a[15] - '0') * 4 + (a[16] - '0') * 2 ) % 11;
		char b;
		if (k == 0)
			b = '1';
		else if (k == 1)
			b = '0';
		else if (k == 2)
			b = 'X';
		else
			b = '0' + 12 - k;
		if (a[17] == b)
			return true;
		else
			return false;
	}

	//手机号校验
	bool is_valid_phone_number(const std::string& phone_number) {
		std::regex phone_regex("(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\\d{8}"); // 手机号正则表达式  
		return std::regex_match(phone_number, phone_regex);
	}
};

#endif // !_TESTVALIDATOR_H_