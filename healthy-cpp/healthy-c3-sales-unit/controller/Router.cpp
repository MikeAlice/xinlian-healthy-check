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

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "get-unit-list/QueryUnitListController.h"
#include "update-unit/ModifyUnitController.h"
#include "get-unit-name/QueryUnitNameController.h"
#include "get-unit-detail/QueryUnitDetailController.h"
#include "add-unit/AddUnitController.h"
#include "delete-unit/RemoveUnitController.h"

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
	/*------  ��ȡ��λ�����б���������������б��    �����ˣ�Tutu��ͿͿ  ------*/
	ROUTER_SIMPLE_BIND(QueryUnitNameController);

	/*------  ��ȡ��λ�б����� + ��ҳ��    �����ˣ�Tutu��ͿͿ  ------*/
	ROUTER_SIMPLE_BIND(QueryUnitListController);

	/*------  ��ȡ��λ����    �����ˣ�duxlong  ------*/
	ROUTER_SIMPLE_BIND(QueryUnitDetailController);

	/*------  ������λ    �����ˣ�duxlong  ------*/
	ROUTER_SIMPLE_BIND(AddUnitController);

	/*------  �޸ĵ�λ    �����ˣ�kzz  ------*/
	ROUTER_SIMPLE_BIND(ModifyUnitController);

	/*------  ɾ����λ��֧������ɾ����    �����ˣ��޺�Ρ  ------*/
	ROUTER_SIMPLE_BIND(RemoveUnitController);

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
