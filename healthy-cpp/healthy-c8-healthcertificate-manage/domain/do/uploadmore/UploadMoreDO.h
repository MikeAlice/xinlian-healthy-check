#ifndef _UPLOADMORE_DO_
#define _UPLOADMORE_DO_
#include "../DoInclude.h"

/**
 * ����֤�ļ���Ϣ���ݿ�ʵ����
 */
class UploadMoreDO
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ����֤���
	CC_SYNTHESIZE(string, code, Code);
	// ��֤��λ
	CC_SYNTHESIZE(string, unitOfIssue, UnitOfIssue);
	// ��֤����
	CC_SYNTHESIZE(string, dateOfIssue, DateOfIssue);
	// ��Ч��
	CC_SYNTHESIZE(string, termOfValidity, TermOfValidity);
	// �Ƿ��ϴ�
	CC_SYNTHESIZE(int, isUpload, IsUpload);
	// �ļ�����
	CC_SYNTHESIZE(string, documentName, DocumentName);
	// �ļ���ַ
	CC_SYNTHESIZE(string, url, Url);
public:
	UploadMoreDO() {
	}
};

#endif
