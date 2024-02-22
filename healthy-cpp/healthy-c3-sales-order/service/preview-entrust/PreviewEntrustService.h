#pragma once

#ifndef _PREVIEWENTRUSTSERVICE_H_
#define _PREVIEWENTRUSTSERVICE_H_

#include <list>
#include <string>

class PreviewEntrustService
{
public:
	std::string getInfo(const std::string& orderId);
};

#endif // !_PREVIEWENTRUSTSERVICE_H_
