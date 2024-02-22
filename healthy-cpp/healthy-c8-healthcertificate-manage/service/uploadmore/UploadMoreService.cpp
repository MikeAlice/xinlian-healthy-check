#include "UploadMoreService.h"
#include "dao/uploadmore/UploadMoreDAO.h"
#include "domain/do/uploadmore/UploadMoreDO.h"
#include "controller/uploadmore/UploadMoreController.h"
#include "PdfComponent.h"

// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


//���ƽ���֤pdf
void generateHealthcertificatePdf(UploadMoreDO& iObj)
{
	// ����֤�ļ���Ⱦģ��
	PdfComponent::registerTplRender("healthcertificate", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			//���ƽ���֤
			// ����һ��ҳ��
			HPDF_Page newPage = pdf->getNewPage();
			// ����ҳ������
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 12);
			// ��ȡҳ���Ⱥ͸߶�
			float pageWidth = HPDF_Page_GetWidth(newPage);
			float pageHeight = HPDF_Page_GetHeight(newPage);
			// ���Ʊ���������
			HPDF_Page_SetRGBFill(newPage, 0.1, 0.6, 1); // ������ɫ�����ɫ
			HPDF_Page_Rectangle(newPage, pageWidth / 4, pageHeight / 2, pageWidth / 2, pageHeight / 18); // ����С����ɫ����������
			HPDF_Page_Fill(newPage);
			// �������ݳ�����
			HPDF_Page_Rectangle(newPage, pageWidth / 4, pageHeight / 2.8, pageWidth / 2, pageHeight / 7); // ���ƴ�����ݳ�����
			HPDF_Page_Stroke(newPage); // ���

			// ���ƾ�̬����
			// ���ƽ���֤����
			HPDF_Page_SetRGBFill(newPage, 1, 1, 1); // ���ð�ɫ�����ɫ
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.title"), 200, 440, newPage);
			HPDF_Page_SetRGBFill(newPage, 0, 0, 0); // ���ú�ɫ�����ɫ
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.name") + ":", 170, 400, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.sex") + ":", 170, 380, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.age") + ":", 300, 380, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.termOfValidity") + ":", 170, 360, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.code") + ":", 170, 340, newPage);
			pdf->drawText(ZH_WORDS_GETTER("uploadmore.filed.unitOfIssue") + ":", 170, 320, newPage);

			//���ƶ�̬����
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

			//�����ļ�
			//�ļ����ƣ� ����֤���+Healthcertificate.pdf
			string address = code + "Healthcertificate.pdf";
			pdf->saveDocToFile(address);
		});

	// ���Ի���
	PdfComponent pdf;
	pdf.drawWithTemplate("zh-dict.yaml", "healthcertificate", &iObj);
}


UploadMoreDTO::Wrapper UploadMoreService::UploadHealthcertificate(const string& personId)
{
	// �������ض���
	auto dto = UploadMoreDTO::createShared();
	UploadMoreDAO dao;
	UploadMoreDO Healthcertificatedo = dao.selectBypersonId(personId);
	//���personId�����ڣ�dto->personId��ֵΪNull,������;
	if (Healthcertificatedo.getCode().empty()) {
		dto->personId = "null";
		return dto;
	}
	else
	{
		dto->personId = personId;
	}
	//����ļ��Ѿ��ϴ��������ļ���ַ
	if (Healthcertificatedo.getIsUpload() == 1) {
		//����֤�ļ�����׺
		string suffix = "Healthcertificate.pdf";
		//����֤�����ǰ׺
		string documentname = Healthcertificatedo.getCode() + suffix;
		UploadMoreDO urldo = dao.getUrlByDocumentName(documentname);
		cout << documentname << " have uploaded." << '\n';
		cout << "URL:" << urldo.getUrl() << endl;
		return dto;
	}

	//���ɽ���֤�ļ�
	generateHealthcertificatePdf(Healthcertificatedo);

	//�ϴ�����֤�ļ�
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	//�ļ��ϴ�
	//����֤�ļ�����׺
	string suffix = "Healthcertificate.pdf";
	//����֤�����ǰ׺
	string filename = Healthcertificatedo.getCode() + suffix;
	std::string fieldname = client.uploadFile(filename);
	std::cout << "upload fieldname is : " << fieldname << std::endl;
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldname;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;

	//�޸�t_certificate_manage��is_uploadΪ1
	dao.updateIsUpload(personId);
	//t_document_file����ӽ���֤�ļ���Ϣ��ȡ����֤�����Ϊt_document_file��id
	dao.insertHealthcertificateFile(Healthcertificatedo.getCode(), filename, "pdf", downloadUrl);

	return dto;
}
