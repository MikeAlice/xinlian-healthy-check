package com.zeroone.star.project.j3.stopword;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @Author Qi
 * @Date 2024/1/16
 */
public interface StopWordApis {
    /**
     * 查询禁用词
     *
     * @param  query 查询条件
     * @return 包含禁用词详情的分页结果
     */
    JsonVO<PageDTO<StopWordDTO>> queryStopWord(StopWordQuery query);
    /**
     * 增加禁用词
     *
     * @param word 要添加的禁用词
     * @return 添加禁用词的结果
     */
    JsonVO<Boolean> addStopWord(StopWordDTO word);

    /**
     * @description:x修改禁用词
     * @author: ZhangJF
     * @date: 2024/1/23 20:14
     * @param: [title]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.dto.j3.stopword.StopWordDTO>
     **/
    JsonVO<Boolean> updateWord(UpdateWordDTO word);

    /**
     * @description:批量删除禁用词
     * @author: ZhangJF
     * @date: 2024/1/23 20:18
     * @param: [ids]
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    JsonVO<Boolean> deleteWordsByIds(List<String> ids);

}
