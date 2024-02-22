#pragma once
#ifndef _DictNameListAPICLIENT_H_
#define _DictNameListAPICLIENT_H_

//1 �������ͷ�ļ�
#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

/**
 * ��ȡ���������б�ApiClient��������ʽ����
 */
class DictNameListApiClient : public oatpp::web::client::ApiClient //2.�̳������
{
	// 3 ����ApiClient������ʹ�ú�---��ʼ
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 ��ʼ������
	API_CLIENT_INIT(DictNameListApiClient);

	// 5 ʹ��API_CALL��API_CALL_ASYNC�������÷���ӿ�

	API_CALL(API_M_GET, "/common/query-dictionary-list", queryDictNameList, API_HANDLER_AUTN_HEADER);
};

#include OATPP_CODEGEN_END(ApiClient);
//3 ȡ��ApiClient������ʹ�ú�-- - ����

#endif // !_DictNameListAPICLIENT_H_