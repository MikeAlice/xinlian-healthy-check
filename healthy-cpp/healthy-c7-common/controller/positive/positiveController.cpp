#include "stdafx.h"
#include "positiveController.h"
#include "../../service/positive/PositiveListService.h"

#include "stdafx.h"
using namespace std;
#include "ServerInfo.h"
#include "ExcelComponent.h"

PositiveListPageJsonVO::Wrapper PositiveConrtoller::execQueryPositive(const PositiveQuery::Wrapper& query)
{	// 定义一个Service
	PositiveListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PositiveListPageJsonVO::createShared();
	jvo->success(result);

	std::vector<std::vector<std::string>> data;
	stringstream ss;

	for (const auto& positiveListDTO : *result->rows) {

		std::vector<std::string> row;
		// row.push_back((positiveListDTO->getId() ? std::string(positiveListDTO->getId()) : ""));
		row.push_back((positiveListDTO->getPersonName() ? std::string(positiveListDTO->getPersonName()) : ""));
		row.push_back((positiveListDTO->geTest_num() ? std::string(positiveListDTO->geTest_num()) : ""));
		row.push_back((positiveListDTO->getOfficeName() ? std::string(positiveListDTO->getOfficeName()) : ""));
		row.push_back((positiveListDTO->getOrder_group_item_project_name() ? std::string(positiveListDTO->getOrder_group_item_project_name()) : ""));
		row.push_back((positiveListDTO->getResult() ? std::string(positiveListDTO->getResult()) : ""));
		row.push_back((positiveListDTO->getUnit_name() ? std::string(positiveListDTO->getUnit_name()) : ""));
		row.push_back((positiveListDTO->getScope() ? std::string(positiveListDTO->getScope()) : ""));
		row.push_back((positiveListDTO->getDiagnose_sum() ? std::string(positiveListDTO->getDiagnose_sum()) : ""));
		row.push_back((positiveListDTO->getCrisis_degree() ? std::string(positiveListDTO->getCrisis_degree()) : ""));
		row.push_back((positiveListDTO->getCheckDate() ? std::string(positiveListDTO->getCheckDate()) : ""));
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = "./public/excel/1.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1") ,
		ZH_WORDS_GETTER("excel.header.h2") ,
		ZH_WORDS_GETTER("excel.header.h3") ,
		ZH_WORDS_GETTER("excel.header.h4") ,
		ZH_WORDS_GETTER("excel.header.h5") ,
		ZH_WORDS_GETTER("excel.header.h6") ,
		ZH_WORDS_GETTER("excel.header.h7") ,
		ZH_WORDS_GETTER("excel.header.h8") ,
		ZH_WORDS_GETTER("excel.header.h9") ,
		ZH_WORDS_GETTER("excel.header.h10") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);

	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PositiveConrtoller::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/excel/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}
