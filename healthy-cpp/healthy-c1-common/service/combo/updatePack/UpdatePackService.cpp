#include "UpdatePackService.h"
#include "dao/combo/updatePack/UpdatePackDAO.h"
#include "domain/dto/combo/UpdatePackDTO.h"
#include "domain/do/combo/UpdatePackDO.h"

int UpdatePackService::modifyData(const UpdatePackDTO::Wrapper& dto)
{
    // 组装数据
    UpdatePackDO data;
    // 组装DO对象数据
    data.setId(dto->id.getValue(""));
    data.setName(dto->name.getValue(""));
    data.setUrl(dto->url.getValue(""));
    data.setType(dto->type.getValue(""));
    data.setSimpleSpell(dto->simpleSpell.getValue(""));
    data.setFitSex(dto->fitSex.getValue(""));
    data.setOrderNum(dto->orderNum.getValue(0));
    data.setRemark(dto->remark.getValue(""));
    data.setCareerStage(dto->careerStage.getValue(""));
    data.setHazardFactors(dto->hazardFactors.getValue(""));
    data.setHazardFactorsText(dto->hazardFactorsText.getValue(""));
    data.setOccupationalDiseases(dto->occupationalDiseases.getValue(""));
    data.setOccupationalTaboo(dto->occupationalTaboo.getValue(""));
    data.setOccupationalDiseasesCode(dto->occupationalDiseasesCode.getValue(""));
    data.setOccupationalTabooCode(dto->occupationalTabooCode.getValue(""));
    data.setDiagnosticCriteria(dto->diagnosticCriteria.getValue(""));
    data.setSymptomInquiry(dto->symptomInquiry.getValue(""));
    // 使用宏定义来进行DTO到DO的转换
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Name, name, Url, url, Type, type,
        SimpleSpell, simpleSpell, FitSex, fitSex, OrderNum, orderNum,
        Remark, remark, CareerStage, careerStage, HazardFactors, hazardFactors,
        HazardFactorsText, hazardFactorsText, OccupationalDiseases, occupationalDiseases);
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        OccupationalTaboo, occupationalTaboo, OccupationalDiseasesCode, occupationalDiseasesCode,
        OccupationalTabooCode, occupationalTabooCode, DiagnosticCriteria, diagnosticCriteria,
        SymptomInquiry, symptomInquiry);
    // 执行数据添加
    UpdatePackDAO dao;
    return dao.update(data);
}