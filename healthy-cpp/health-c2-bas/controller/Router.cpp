
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "sample/ObtainSampleDetailsController.h"//获取样本详情-睡不着
#include "sample/DeletesampleController.h"//删除样本-睡不着
#include "positive/resRuleController.h" //puck
#include "positive/DeatilController.h" //圈圈
#include "positive/ModifyResultController.h" //圈圈
#include "positive/resultController.h" //elysia
#include "sample/SampleController.h" //快乐五香蛋

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleLibController.h"//--注意--
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "sample/ObtainSampleListController.h"//获取样本列表-无人
#include "sample/InsertSampleController.h"//新增样本-无人	

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

	// 绑定样本详情控制器-睡不着
	ROUTER_SIMPLE_BIND(ObtainSampleDetailsController);
	//绑定删除样本控制器-睡不着
	ROUTER_SIMPLE_BIND(DeleteSampleController);
	ROUTER_SIMPLE_BIND(ObtainSampleListController);//获取样本列表-无人
	ROUTER_SIMPLE_BIND(InsertSampleController);//新增样本-无人	
	// -puck
	ROUTER_SIMPLE_BIND(resRuleController);
	//绑定阳性结果详细控制器-圈圈
	ROUTER_SIMPLE_BIND(DeatilController);
	//绑定修改阳性结果控制器-圈圈
	ROUTER_SIMPLE_BIND(ModifyResultController);
	// -elysia
	ROUTER_SIMPLE_BIND(resultController);
	//快乐五香蛋
	ROUTER_SIMPLE_BIND(SampleController);
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
#endif // !_ROUTER_
