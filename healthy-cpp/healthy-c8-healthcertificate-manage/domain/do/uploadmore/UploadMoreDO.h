#ifndef _UPLOADMORE_DO_
#define _UPLOADMORE_DO_
#include "../DoInclude.h"

/**
 * 健康证文件信息数据库实体类
 */
class UploadMoreDO
{
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 健康证编号
	CC_SYNTHESIZE(string, code, Code);
	// 发证单位
	CC_SYNTHESIZE(string, unitOfIssue, UnitOfIssue);
	// 发证日期
	CC_SYNTHESIZE(string, dateOfIssue, DateOfIssue);
	// 有效期
	CC_SYNTHESIZE(string, termOfValidity, TermOfValidity);
	// 是否上传
	CC_SYNTHESIZE(int, isUpload, IsUpload);
	// 文件名称
	CC_SYNTHESIZE(string, documentName, DocumentName);
	// 文件地址
	CC_SYNTHESIZE(string, url, Url);
public:
	UploadMoreDO() {
	}
};

#endif
