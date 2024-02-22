#include "./AddPackService.h"
#include "dao/combo/addPack/AddPackDAO.h"
#include "domain/dto/combo/AddPackDTO.h"
#include "domain/do/combo/AddPackDO.h"

uint64_t AddPackService::saveData(const AddPackDTO::Wrapper& dto)
{
    // 组装数据
    AddPackDO data;
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
    AddPackDAO dao;
    return dao.insert(data);
}
