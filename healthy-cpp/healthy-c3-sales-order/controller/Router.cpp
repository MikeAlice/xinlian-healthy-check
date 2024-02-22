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
	/*------  订单  ------*/
	/*------  获取订单名称列表（条件+分页）    负责人：Chloe  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderListController);

	/*------  获取订单详情    负责人：星星果  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderDetailController);

	/*------  获取订单体检项目信息    负责人：Adam  ------*/
	ROUTER_SIMPLE_BIND(QueryItemController);

	/*------  获取订单体检人员信息    负责人：ronaldo  ------*/
	ROUTER_SIMPLE_BIND(QueryPersonController);

	/*------  新增订单    负责人：ronaldo  ------*/
	ROUTER_SIMPLE_BIND(AddOrderController);

	/*------  修改订单    负责人：jimyy  ------*/
	ROUTER_SIMPLE_BIND(ModifyOrderController);

	/*------  删除订单    负责人：Adam  ------*/
	ROUTER_SIMPLE_BIND(RemoveOrderController);

	/*------  订单确认    负责人：jimyy  ------*/
	ROUTER_SIMPLE_BIND(ConfirmOrderController);

	/*------  查看审批信息    负责人：无敌霸王龙  ------*/
	ROUTER_SIMPLE_BIND(QueryOrderApprovalController);

	/*------  人员  ------*/
	/*------  生成导入模板    负责人：Gary  ------*/
	ROUTER_SIMPLE_BIND(DownloadPersonController);
	/*------  保存导入信息    负责人：Gary  ------*/
	ROUTER_SIMPLE_BIND(ImportPersonController);

	/*------  导出人员信息    负责人：无敌霸王龙  ------*/
	ROUTER_SIMPLE_BIND(ExportPersonController);

	/*------  合同  ------*/
	/*------  下载模板    负责人：星星果  ------*/
	ROUTER_SIMPLE_BIND(DownloadEntrustController);

	/*------  保存附件    负责人：y  ------*/
	ROUTER_SIMPLE_BIND(UploadEntrustController);

	/*------  附件预览    负责人：kzz  ------*/
	ROUTER_SIMPLE_BIND(PreviewEntrustController);

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
