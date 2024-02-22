#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"

#include "Dangerous/DepartController.h"
#include "result/ResultController.h"
#include "info-inspectionSave/InfoController.h"
#include "Term/TermController.h"
#include "getUserName/UnitController.h"
#include "personDetail/DetailController.h"
#include "positive/positiveController.h"
#include "review/ReviewController.h"
#include "addNewItems/AddNewItemsController.h"
#include "personalReview/PersonalReviewController.h"
#include "downloadWord/DownloadWordController.h"
#include "groupItemIgno/GroupItemIgnoController.h"
#include "itemResult/ItemResultController.h"
#include "evalue/InquiryDetailController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"

#endif
#include "ReportView/ReportController.h"


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
	ROUTER_SIMPLE_BIND(DepartController);
	ROUTER_SIMPLE_BIND(ResultController);
	ROUTER_SIMPLE_BIND(InfoController);
	ROUTER_SIMPLE_BIND(ReportController);
	ROUTER_SIMPLE_BIND(TermController);
	ROUTER_SIMPLE_BIND(PositiveConrtoller);
	ROUTER_SIMPLE_BIND(ItemResultController);
	ROUTER_SIMPLE_BIND(InquiryDetailController);
	ROUTER_SIMPLE_BIND(ReviewController);
	ROUTER_SIMPLE_BIND(AddNewItemsController);
	ROUTER_SIMPLE_BIND(PersonalReviewController);
	ROUTER_SIMPLE_BIND(DownloadWordController);
	ROUTER_SIMPLE_BIND(GroupItemIgnoController);
	ROUTER_SIMPLE_BIND(DetailController);
	ROUTER_SIMPLE_BIND(UnitController);
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