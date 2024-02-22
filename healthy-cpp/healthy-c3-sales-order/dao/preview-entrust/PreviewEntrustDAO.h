#pragma once

#ifndef _PREVIEWENTRUSTDAO_H_
#define _PREVIEWENTRUSTDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/preview-entrust/PreviewEntrustDO.h"
#include <list>

class PreviewEntrustDAO : public BaseDAO
{
public:
	std::list<PreviewEntrustUrlDO> selectUrl(const std::string& orderId);
	std::list<PreviewEntrustInfoDO> selectInfo(const std::string& orderId);
	int updateUrl(const std::string& orderId, const std::string& url);
};

#endif // !_PREVIEWENTRUSTDAO_H_
