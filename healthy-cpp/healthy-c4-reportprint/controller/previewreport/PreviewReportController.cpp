#include "stdafx.h"
#include "PreviewReportController.h"
#include "../../service/previewreport/PreviewReportService.h"

PreviewReportJsonVO::Wrapper PreviewReportController::execQueryPreviewReport(const PreviewReportQuery::Wrapper& query)
{
    // ����һ��Service
    PreviewReportService service;
    // ��ѯ����
    auto result = service.listId(query);
    // ��Ӧ���
    auto jvo = PreviewReportJsonVO::createShared();
    jvo->success(result);
    return jvo;
}