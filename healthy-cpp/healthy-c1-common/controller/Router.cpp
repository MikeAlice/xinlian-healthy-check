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
#include "ApiHelper.h"
#include "Router.h"
#include "basis/contraindications/ContraindicationsController.h"
#include "basis/package/PackageController.h"

#include "ApiHelper.h"


#include "./combo/ComboController.h"
#include "xiebao/Controller.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "base/ReferenceModController.h"
#include "base/ReferenceDelController.h"
#include"rules/RulesListController.h"
#include "database/addCritValueController/addCritValueController.h"
#include "database/querycritvaluecontroller/QueryCritValueController.h"

#include "controller/referencevalue/addrefvalue/AddRefValueController.h"
#include "controller/referencevalue/queryrefvalue/QueryRefValueController.h"
#include "critical/criticalDeleteController.h"
#include "critical/criticalModifyController.h"


#include "baseProject/BaseProjectController.h"

// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
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

	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(ReferenceModController);
	ROUTER_SIMPLE_BIND(ReferenceDelController);
	ROUTER_SIMPLE_BIND(RulesListController);
	ROUTER_SIMPLE_BIND(QueryCritValueController);
	ROUTER_SIMPLE_BIND(AddCritValueController);
	ROUTER_SIMPLE_BIND(BaseProjectController);
	// 基础数据-基础项目-配置指定项目-新增指定项目危急值 负责人：超能
	ROUTER_SIMPLE_BIND(AddRefValueController);
	// 基础数据-基础项目-配置指定项目-获取指定项目参考值列表（分页） 负责人：超能
	ROUTER_SIMPLE_BIND(QueryRefValueController);
	ROUTER_SIMPLE_BIND(ComboController);
	ROUTER_SIMPLE_BIND(ContraindicationsController);
	ROUTER_SIMPLE_BIND(PackageController);
	ROUTER_SIMPLE_BIND(XiebaoController);
	ROUTER_SIMPLE_BIND(CriticalDeleteController);
	ROUTER_SIMPLE_BIND(CriticalModifyController);
	ROUTER_SIMPLE_BIND(QueryCritValueController);
	ROUTER_SIMPLE_BIND(AddCritValueController);

}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
