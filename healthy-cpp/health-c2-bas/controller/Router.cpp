
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "sample/ObtainSampleDetailsController.h"//��ȡ��������-˯����
#include "sample/DeletesampleController.h"//ɾ������-˯����
#include "positive/resRuleController.h" //puck
#include "positive/DeatilController.h" //ȦȦ
#include "positive/ModifyResultController.h" //ȦȦ
#include "positive/resultController.h" //elysia
#include "sample/SampleController.h" //�������㵰

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleLibController.h"//--ע��--
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "sample/ObtainSampleListController.h"//��ȡ�����б�-����
#include "sample/InsertSampleController.h"//��������-����	

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

	// ���������������-˯����
	ROUTER_SIMPLE_BIND(ObtainSampleDetailsController);
	//��ɾ������������-˯����
	ROUTER_SIMPLE_BIND(DeleteSampleController);
	ROUTER_SIMPLE_BIND(ObtainSampleListController);//��ȡ�����б�-����
	ROUTER_SIMPLE_BIND(InsertSampleController);//��������-����	
	// -puck
	ROUTER_SIMPLE_BIND(resRuleController);
	//�����Խ����ϸ������-ȦȦ
	ROUTER_SIMPLE_BIND(DeatilController);
	//���޸����Խ��������-ȦȦ
	ROUTER_SIMPLE_BIND(ModifyResultController);
	// -elysia
	ROUTER_SIMPLE_BIND(resultController);
	//�������㵰
	ROUTER_SIMPLE_BIND(SampleController);
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
#endif // !_ROUTER_
