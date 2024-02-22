#pragma once

#ifndef _PERSONALREVIEW_DTO_
#define _PERSONALREVIEW_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PersonalReviewDTO : public oatpp::DTO
{
	DTO_INIT(PersonalReviewDTO, DTO);

	// 体检人员id		person_id
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("personalReview.field.personId");
	}
	// 修改人id			update_id
	DTO_FIELD(String, updateId);
	DTO_FIELD_INFO(updateId) {
		info->description = ZH_WORDS_GETTER("personalReview.field.updateId");
	}
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_SAMPLE_DTO_