#include "UploadMoreService.h"
#include "dao/uploadmore/UploadMoreDAO.h"
#include "domain/do/uploadmore/UploadMoreDO.h"
#include "controller/uploadmore/UploadMoreController.h"
#include "PdfComponent.h"

// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


//绘制健康证pdf
void generateHealthcertificatePdf(UploadMoreDO& iObj)
{
	// 健康证文件渲染模板
	PdfComponent::registerTplRender("healthcertificate", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			//绘制健康证
			// 创建一个页面
			HPDF_Page newPage = pdf->getNewPage();
			// 设置页面字体
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 12);
			// 获取页面宽度和高度
			float pageWidth = HPDF_Page_GetWidth(newPage);
			float pageHeight = HPDF_Page_GetHeight(newPage);
			// 绘制背景长方形
			HPDF_Page_SetRGBFill(newPage, 0.1, 0.6, 1); // 设置蓝色填充颜色
			HPDF_Page_Rectangle(newPage, pageWidth / 4, pageHeight / 2, pageWidth / 2, pageHeight / 18); // 绘制小的蓝色背景长方形
			HPDF_Page_Fill(newPage);
			// 绘制内容长方形
			HPDF_Page_Rectangle(newPage, pageWidth / 4, pageHeight / 2.8, pageWidth / 2, pageHeight / 7); // 绘制大的内容长方形
			HPDF_Page_Stroke(newPage); // 描边

			// 绘制静态数据
			// 绘制健康证标题
			HPDF_Page_SetRGBFill(newPage, 1, 1, 1); // 设置白色填充颜色
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.title"), 200, 440, newPage);
			HPDF_Page_SetRGBFill(newPage, 0, 0, 0); // 设置黑色填充颜色
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.name") + ":", 170, 400, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.sex") + ":", 170, 380, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.age") + ":", 300, 380, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.termOfValidity") + ":", 170, 360, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.code") + ":", 170, 340, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.unitOfIssue") + ":", 170, 320, newPage);

			//绘制动态数据
			UploadMoreDO iobj = *static_cast<UploadMoreDO*>(realData);
			string name = iobj.getName();
			string sex = iobj.getSex();
			string    age = to_string(iobj.getAge());
			string termOfValidity = iobj.getTermOfValidity();
			string code = iobj.getCode();
			string unitOfIssue = iobj.getUnitOfIssue();
			pdf->drawText(name, 210, 400, newPage);
			pdf->drawText(sex, 210, 380, newPage);
			pdf->drawText(age, 340, 380, newPage);
			pdf->drawText(termOfValidity, 220, 360, newPage);
			pdf->drawText(code, 245, 340, newPage);
			pdf->drawText(unitOfIssue, 230, 320, newPage);

			//保存文件
			//文件名称： 健康证编号+Healthcertificate.pdf
			string address = code + "Healthcertificate.pdf";
			pdf->saveDocToFile(address);
		});

	// 测试绘制
	PdfComponent pdf;
	pdf.drawWithTemplate("zh-dict.yaml", "healthcertificate", &iObj);
}


UploadMoreDTO::Wrapper UploadMoreService::UploadHealthcertificate(const string& personId)
{
	// 构建返回对象
	auto dto = UploadMoreDTO::createShared();
	UploadMoreDAO dao;
	UploadMoreDO Healthcertificatedo = dao.selectBypersonId(personId);
	//如果personId不存在，dto->personId赋值为Null,并返回;
	if (Healthcertificatedo.getCode().empty()) {
		dto->personId = "null";
		return dto;
	}
	else
	{
		dto->personId = personId;
	}
	//如果文件已经上传，返回文件地址
	if (Healthcertificatedo.getIsUpload() == 1) {
		//健康证文件名后缀
		string suffix = "Healthcertificate.pdf";
		//健康证编号作前缀
		string documentname = Healthcertificatedo.getCode() + suffix;
		UploadMoreDO urldo = dao.getUrlByDocumentName(documentname);
		cout << documentname << " have uploaded." << '\n';
		cout << "URL:" << urldo.getUrl() << endl;
		return dto;
	}

	//生成健康证文件
	generateHealthcertificatePdf(Healthcertificatedo);

	//上传健康证文件
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	//文件上传
	//健康证文件名后缀
	string suffix = "Healthcertificate.pdf";
	//健康证编号作前缀
	string filename = Healthcertificatedo.getCode() + suffix;
	std::string fieldname = client.uploadFile(filename);
	std::cout << "upload fieldname is : " << fieldname << std::endl;
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldname;
	// 输出下载路径
	std::cout << "download url: " << downloadUrl << std::endl;

	//修改t_certificate_manage表is_upload为1
	dao.updateIsUpload(personId);
	//t_document_file表添加健康证文件信息，取健康证编号作为t_document_file的id
	dao.insertHealthcertificateFile(Healthcertificatedo.getCode(), filename, "pdf", downloadUrl);

	return dto;
}
