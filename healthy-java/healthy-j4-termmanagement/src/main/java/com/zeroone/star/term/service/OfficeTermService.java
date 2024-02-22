package com.zeroone.star.term.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.entity.OfficeTermEntity;

import java.util.List;


/**
 * 科室术语表(OfficeTerm)表服务接口
 *
 * @author makejava
 * @since 2024-01-30 14:43:18
 */
public interface OfficeTermService extends IService<OfficeTermEntity> {
    /**
     * 删除术语
     * @param ids
     */
    JsonVO<ResultStatus> deletetermanagement(List<String> ids);
}
