#include "stdafx.h"
#include "InsertSampleController.h"
#include "../../service/sample/InsertSampleService.h"
#include "../ApiDeclarativeServicesHelper.h"




Uint64JsonVO::Wrapper InsertSampleController::execAddSample(const InsertSampleDTO::Wrapper & dto)
	{
		// 定义返回数据对象
		auto jvo = Uint64JsonVO::createShared();
		// 参数校验
		// 非空校验
		if (!dto->code || !dto->name || !dto->liscode)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 有效值校验
		if (dto->code->empty() || dto->name->empty() || dto->liscode->empty()//||
			//dto->id->empty() || dto->is_print<0 || dto->capacity->empty()||
			//dto->barcode_num<0|| dto->need_take_blood < 0 || dto->order_num <0||
			//dto->spec->empty()
			)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}

		// 定义一个Service
		InsertSampleService service;
		// 执行数据新增
		uint64_t id = service.saveData(dto);

		if (id > 0) {
			jvo->success(UInt64(id));
		}
		else
		{
			jvo->fail(UInt64(id));
		}
		//响应结果
		return jvo;
	}
