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
#include "unknownmodulebasicinformation/BasicInformationController.h"
#include "unknownmodulelifehistory/LifeHistoryController.h"
#include "unknownmodulepastmedicalhistory/PastMedicalHistoryController.h"
#include "unknownmoduleprofessionalhistory/ProfessionalHistoryController.h"
#include "GroupPerson/GroupPersonController.h"
#include "Personinfo/PersoninfoController.h"
#include"samplebarcodesview/SampleBarcodesBiewController.h"
#include"reportpreview/ReportPreviewController.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "controller/interro/InterroController.h"
#include "saveRes/saveResController.h"
#include "checkitem/BaseProjectController.h"
#include "checkitem/PersonController.h"

#include "controller/interro/InterroController.h"
#include "result-entry/ClAbanProjController.h"
#include "GroupPersonInfo/GroupPersonInfoController.h"

#include "file_chengfeng/UpFileController.h"

// 如果定义了关闭Swagger文档�?
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定�?
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定�?
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

	//#TIP :系统扩展路由定义，写在这个后�?
	//ROUTER_SIMPLE_BIND(SaveResController);
	ROUTER_SIMPLE_BIND(SaveResController);
	ROUTER_SIMPLE_BIND(GroupPersonController);
	ROUTER_SIMPLE_BIND(ClAbanProjController);
	ROUTER_SIMPLE_BIND(BasicInformationController);
	ROUTER_SIMPLE_BIND(LifeHistoryController);
	ROUTER_SIMPLE_BIND(PastMedicalHistoryController);
	ROUTER_SIMPLE_BIND(ProfessionalHistoryController);
	ROUTER_SIMPLE_BIND(InterroController);
	ROUTER_SIMPLE_BIND(SampleBarcodesViewController);//�����
	ROUTER_SIMPLE_BIND(ReportPreviewController);//�����
	ROUTER_SIMPLE_BIND(InterroController);
	ROUTER_SIMPLE_BIND(BaseProjectController);
	ROUTER_SIMPLE_BIND(PersonController);
	ROUTER_SIMPLE_BIND(UpFileController);
	ROUTER_SIMPLE_BIND(GroupPersonInfoController);
    ROUTER_SIMPLE_BIND(PersoninfoController);
	
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制�?
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制�?
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制�?
	ROUTER_SIMPLE_BIND(FileController);

	// 绑定WebSocket控制�?
	router->addController(WSContorller::createShared());
}
#endif
