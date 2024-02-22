#include "UpdateTBPDAO.h"
#include "stdafx.h"
#include <sstream>
#include <iomanip>

int UpdateTBPDAO::UpdateTBP(const UpdateTBPDO& uObj)
{

    // 根据系统时间创建create_time
    std::time_t now = std::time(0); // 获取日历时间
    std::tm* timeinfo = localtime(&now); // 转换为本地时间的tm结构体
    std::stringstream ss; // 创建一个字符串流对象
    ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // 将tm结构体格式化为字符串流
    std::string create_time = ss.str(); // 从字符串流中获取字符串


    string sql = "UPDATE `t_base_project` SET `office_id`=?, `name`=?,\
                   `short_name`=?, `order_num`=?, `result_type`=?,\
                   `unit_name`=?, `default_value`=?, `in_conclusion`=?,\
                   `in_report`=?, `relation_code`=?, `create_id`=?\
                  WHERE `code`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%d%s%s%s%s%s%s%dt%s",
        uObj.getOffice_id(), uObj.getName(),
        uObj.getShort_name(),uObj.getOrder_num(), uObj.getResult_type(),
        uObj.getUnit_name(),uObj.getDefault_value(),uObj.getIn_conclution(),
        uObj.getInreport(), uObj.getRelation_code(), create_time, 
        uObj.getCode());
}
