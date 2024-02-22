#include "stdafx.h"
#include "AddPackDAO.h"

uint64_t AddPackDAO::insert(const AddPackDO& iObj)
{
	string sql = "INSERT INTO `t_combo` (`id`, `name`, `url`, `type`, `simple_spell`, `fit_sex`, `order_num`, `remark`, `career_stage`, `hazard_factors`, `hazard_factors_text`, `occupational_diseases`, `occupational_taboo`, `occupational_diseases_code`, `occupational_taboo_code`, `diagnostic_criteria`, `symptom_inquiry`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%i%s%s%s%s%s%s%s%s%s%s",
		iObj.getId(),
		iObj.getName(), iObj.getUrl(), iObj.getType(),
		iObj.getSimpleSpell(), iObj.getFitSex(), iObj.getOrderNum(),
		iObj.getRemark(), iObj.getCareerStage(), iObj.getHazardFactors(),
		iObj.getHazardFactorsText(), iObj.getOccupationalDiseases(),
		iObj.getOccupationalTaboo(), iObj.getOccupationalDiseasesCode(),
		iObj.getOccupationalTabooCode(), iObj.getDiagnosticCriteria(),
		iObj.getSymptomInquiry()
	);
}
