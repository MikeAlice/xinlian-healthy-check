package com.zeroone.star.sysmanager.service.impl;


import com.alibaba.cloud.commons.lang.StringUtils;
import com.alibaba.nacos.shaded.com.google.protobuf.ServiceException;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.sysmanager.entity.StopWord;
import com.zeroone.star.sysmanager.mapper.StopWordMapper;
import com.zeroone.star.sysmanager.service.ITStopWordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestParam;

import javax.annotation.Resource;
import javax.management.Query;
import java.time.LocalDateTime;
import java.util.Optional;

/**
 * StopWord对应MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface  MsStopWordMapper{
    /**
    * 查询停用词
     * 将实体类DO转换为dto
     * @param stopWord 待转换DO
     * @return 转换结果
     */
    StopWordDTO StopWordToStopWordDTO(StopWord stopWord);
}
/**
 * <p>
 * 禁用词 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TStopWordServiceImpl extends ServiceImpl<StopWordMapper, StopWord> implements ITStopWordService {
    @Resource
    private StopWordMapper stopWordMapper;
    @Resource
    private UserHolder userHolder;
    @Resource
    MsStopWordMapper msStopWordMapper;

    @Override
    public PageDTO<StopWordDTO> listpage(StopWordQuery query) {
        //构建分页条件对象
        Page<StopWord> page = new Page<>(query.getPageIndex(),query.getPageSize());
        //构建查询条件
        QueryWrapper<StopWord> queryWrapper = new QueryWrapper<>();
        if (StringUtils.isNotBlank(query.getTitle())) {
        queryWrapper.like("title",query.getTitle());
        }
        //执行查询
        Page<StopWord> result = baseMapper.selectPage(page,queryWrapper);
        return PageDTO.create(result,src->msStopWordMapper.StopWordToStopWordDTO(src));
    }
    @Override
    @Transactional
    public boolean addWord(StopWordDTO addWord)  {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！",e);
        }
        if (addWord == null || addWord.getTitle() == null ||
                findByTitle(addWord.getTitle()) != null) {
            return false;
        }else {
            StopWord stopWord = new StopWord();
            stopWord.setId(addWord.getId());
            stopWord.setCreateBy(currentUser != null ? currentUser.getUsername() : "unknown"); // 若无用户信息，设置为未知
            stopWord.setCreateTime(LocalDateTime.now());
            stopWord.setUpdateBy(currentUser != null ? currentUser.getUsername() : "unknown"); // 若无用户信息，设置为未知
            stopWord.setUpdateTime(LocalDateTime.now());
            stopWord.setDelFlag(0);
            stopWord.setTitle(addWord.getTitle());
            return save(stopWord);
        }
    }
    @Override
    public int updateWord(UpdateWordDTO updateWord) {
        UserDTO user = null;
        try {
            user = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！");
        }
        //数据封装
        StopWord stopWord = new StopWord();
        stopWord.setId(updateWord.getId());
        stopWord.setTitle(updateWord.getTitle());
        stopWord.setUpdateBy(user.getUsername());
        stopWord.setUpdateTime(LocalDateTime.now());
        int count = stopWordMapper.updateById(stopWord);
        return count;
    }
    @Override
    public StopWordDTO findByTitle(String title) {
        LambdaQueryWrapper<StopWord> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(StopWord::getTitle, title);
        StopWord stopWord = baseMapper.selectOne(wrapper);
        if (stopWord == null) {
            return null;
        }
        return msStopWordMapper.StopWordToStopWordDTO(stopWord);
    }
}
