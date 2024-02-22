package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.j1.dto.sysmanager.DepartmentManagementDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;

/**
 * 系统管理-用户管理，导入导出相关接口（导入用户数据、导出全部数据）
 */
public interface ImportOrExportApis {

    /**
     * 个人中心-科室管理，导出本页数据
     */
    JsonVO exportFormOfDepartment() throws Exception;

    /**
     * 导入用户数据
     * @param file 用户数据文件
     * @return
     */
    JsonVO<String> importUserData(MultipartFile file) throws Exception;
}
