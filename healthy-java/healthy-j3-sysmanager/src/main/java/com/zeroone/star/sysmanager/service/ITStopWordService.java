package com.zeroone.star.sysmanager.service;

import com.alibaba.nacos.shaded.com.google.protobuf.ServiceException;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.sysmanager.entity.StopWord;

/**
 * <p>
 * 禁用词 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITStopWordService extends IService<StopWord> {

    /**
     * 查询禁用词列表
     * @param query 分页条件
     * @return 查询结果
     */
    PageDTO<StopWordDTO>listpage(StopWordQuery query);
    /**
    * 查询禁用词
     * 根据名称查询禁用词
     * @param title 待查询的禁用词
     * @return DTO
     */
    StopWordDTO findByTitle(String title);
    boolean addWord(StopWordDTO addWord);
    int updateWord(UpdateWordDTO updateWord);
}
