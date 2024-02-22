package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import javax.validation.constraints.NotNull;
import java.util.List;

public interface TermanagementApi {
    /**
     * 删除术语
     * @param ids
     * @return
     */
    JsonVO<ResultStatus> deletetermanagement(@NotNull(message = "List不能为空") List<String> ids);
}
