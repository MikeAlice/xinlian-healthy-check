/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

#include "delete-order/RemoveOrderController.h"
#include "get-order-item/QueryItemController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "get-order-list/QueryOrderListController.h"
#include "get-order-detail/QueryOrderDetailController.h"
#include "download-entrust-template/DownloadEntrustController.h"
#include "get-order-person/QueryPersonController.h"
#include "add-order/AddOrderController.h"
#include "get-order-approval/QueryOrderApprovalController.h"
#include "export-person/ExportPersonController.h"
#include "preview-entrust/PreviewEntrustController.h"
#include "confirm-order/ConfirmOrderController.h"
#include "download-person-template/DownloadPersonController.h"
#include "update-order/ModifyOrderController.h"
#include "import-person/ImportPersonController.h"
#include "upload-entrust/UploadEntrustController.h"



// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	/*------  ����  ------*/
	/*------  ��ȡ���������б�����+��ҳ��    �����ˣ�Chloe  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderListController);

	/*------  ��ȡ��������    �����ˣ����ǹ�  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderDetailController);

	/*------  ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam  ------*/
	ROUTER_SIMPLE_BIND(QueryItemController);

	/*------  ��ȡ���������Ա��Ϣ    �����ˣ�ronaldo  ------*/
	ROUTER_SIMPLE_BIND(QueryPersonController);

	/*------  ��������    �����ˣ�ronaldo  ------*/
	ROUTER_SIMPLE_BIND(AddOrderController);

	/*------  �޸Ķ���    �����ˣ�jimyy  ------*/
	ROUTER_SIMPLE_BIND(ModifyOrderController);

	/*------  ɾ������    �����ˣ�Adam  ------*/
	ROUTER_SIMPLE_BIND(RemoveOrderController);

	/*------  ����ȷ��    �����ˣ�jimyy  ------*/
	ROUTER_SIMPLE_BIND(ConfirmOrderController);

	/*------  �鿴������Ϣ    �����ˣ��޵а�����  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderApprovalController);

	/*------  ��Ա  ------*/
	/*------  ���ɵ���ģ��    �����ˣ�Gary  ------*/
	ROUTER_SIMPLE_BIND(DownloadPersonController);
	/*------  ���浼����Ϣ    �����ˣ�Gary  ------*/
	ROUTER_SIMPLE_BIND(ImportPersonController);

	/*------  ������Ա��Ϣ    �����ˣ��޵а�����  ------*/
	ROUTER_SIMPLE_BIND(ExportPersonController);

	/*------  ��ͬ  ------*/
	/*------  ����ģ��    �����ˣ����ǹ�  ------*/
	ROUTER_SIMPLE_BIND(DownloadEntrustController);

	/*------  ���渽��    �����ˣ�y  ------*/
	ROUTER_SIMPLE_BIND(UploadEntrustController);

	/*------  ����Ԥ��    �����ˣ�kzz  ------*/
	ROUTER_SIMPLE_BIND(PreviewEntrustController);

}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);
	
	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
