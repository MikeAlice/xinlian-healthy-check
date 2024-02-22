#include "pch.h"
#include "GetDate.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>


std::string GetDate::getCurrentDate()
{
	return getCurrentDateFormatted();
}

std::string GetDate::getCurrentDateFormatted()
{
    auto now = std::chrono::system_clock::now();

    // ����ǰʱ��ת��Ϊʱ��ṹ��
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // ʹ�ñ���ʱ������
    std::tm localTime = *std::localtime(&currentTime);

    // ���������ַ���
    std::stringstream dateStream;
    dateStream << std::setfill('0') << std::setw(4) << (localTime.tm_year + 1900) << '-'
        << std::setfill('0') << std::setw(2) << (localTime.tm_mon + 1) << '-'
        << std::setfill('0') << std::setw(2) << localTime.tm_mday;

    return dateStream.str();
}

std::string GetDate::getPreviousMonthDate()
{
    return getPreviousMonthDateFormatted();
}

std::string GetDate::getPreviousMonthDateFormatted()
{
    auto now = std::chrono::system_clock::now();

    // ����ǰʱ��ת��Ϊʱ��ṹ��
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // ʹ�ñ���ʱ������
    std::tm localTime = *std::localtime(&currentTime);

    // ��ȥһ����
    localTime.tm_mon -= 1;
    if (localTime.tm_mon < 0) {
        localTime.tm_mon += 12;
        localTime.tm_year -= 1;
    }

    // ���������ַ���
    std::stringstream dateStream;
    dateStream << std::setfill('0') << std::setw(4) << (localTime.tm_year + 1900) << '-'
        << std::setfill('0') << std::setw(2) << (localTime.tm_mon + 1) << '-'
        << std::setfill('0') << std::setw(2) << localTime.tm_mday;

    return dateStream.str();
}
