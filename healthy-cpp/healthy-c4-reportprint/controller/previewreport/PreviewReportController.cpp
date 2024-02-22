#include "stdafx.h"
#include "PreviewReportController.h"
#include "../../service/previewreport/PreviewReportService.h"

PreviewReportJsonVO::Wrapper PreviewReportController::execQueryPreviewReport(const PreviewReportQuery::Wrapper& query)
{
    // 定义一个Service
    PreviewReportService service;
    // 查询数据
    auto result = service.listId(query);
    // 响应结果
    auto jvo = PreviewReportJsonVO::createShared();
    jvo->success(result);
    return jvo;
}