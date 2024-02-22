package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dict.WordTypeListDTO;
import com.zeroone.star.project.dto.j3.dictdata.DictDataDTO;
import com.zeroone.star.project.query.j3.DictData.DictDataQuery;
import com.zeroone.star.project.query.j3.WordTypeListQuery;

import cn.hutool.core.lang.Snowflake;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j3.dictdata.AddDictDataDTO;
import com.zeroone.star.project.dto.j3.dictdata.ModifyDictData;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.DictData;
import com.zeroone.star.sysmanager.mapper.DictDataMapper;
import com.zeroone.star.sysmanager.service.ITDictDataService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

/**
 * DictData对应MapperStruct映射接口
 */
@Mapper(componentModel = "spring")
interface MsDictDataMapper{

    /**
     * 将DO 转换成 DTO
     * @param dictData
     * @return
     */
    DictDataDTO DictDataToDictDataDto(DictData dictData);
    /**
     * 将DictData转为WordTypeListDTO
     * @param dictData
     * @return
     */
    WordTypeListDTO dictDataToWordTypeListDTO(DictData dictData);
}


/**
 * <p>
 * 字典数据 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TDictDataServiceImpl extends ServiceImpl<DictDataMapper, DictData> implements ITDictDataService {
    @Resource
    MsDictDataMapper msDictDataMapper;

    @Override
    public void removeById(String id) {
        baseMapper.deleteById(id);
    }
    @Resource
    private DictDataMapper dictDataMapper;
    @Resource
    private UserHolder userHolder;
    @Resource
    private Snowflake snowflake;
    @Override
    public JsonVO<Boolean>AddDictData(AddDictDataDTO addDictDataDTO) {
        UserDTO user = null;
        try {
            user = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！");
        }
        DictData dictData = new DictData();
        dictData.setId(String.valueOf(snowflake.nextId()));
        dictData.setDictId(addDictDataDTO.getDictId());
        dictData.setDelFlag(false);
        dictData.setTitle(addDictDataDTO.getTitle());
        dictData.setCreateBy(user.getUsername());
        dictData.setValue(addDictDataDTO.getValue());
        dictData.setDescription(addDictDataDTO.getDescription());
        dictData.setSortOrder(addDictDataDTO.getSort_order());
        dictData.setStatus(addDictDataDTO.getStatus());
        dictData.setCreateTime(LocalDateTime.now());
        boolean success = dictDataMapper.insert(dictData) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }

    @Override
    public DictData getById(String id) {
        DictData dictData = baseMapper.selectById(id);
        return dictData;
    }

    @Override
    public PageDTO<WordTypeListDTO> listPage(WordTypeListQuery wordTypeListQuery) {
        //构建分页条件对象
        Page<DictData> page= new Page<>(wordTypeListQuery.getPageIndex(),wordTypeListQuery.getPageSize());
        //构建查询条件
        QueryWrapper<DictData> wrapper = new QueryWrapper<>();
        wrapper.like("title", wordTypeListQuery.getTitle());
        //执行查询语句
        Page<DictData> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result,src -> msDictDataMapper.dictDataToWordTypeListDTO(src));
    }
    @Override
    public JsonVO<Boolean> ModifyDictData(ModifyDictData modifyDictData){
        UserDTO user = null;
        try {
            user = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！");
        }
        DictData dictData= new DictData();
        dictData.setId(modifyDictData.getId());
        dictData.setTitle(modifyDictData.getTitle());
        dictData.setValue(modifyDictData.getValue());
        dictData.setUpdateBy(user.getUsername());
        dictData.setDescription(modifyDictData.getDescription());
        dictData.setSortOrder(modifyDictData.getSort_order());
        dictData.setStatus(modifyDictData.getStatus());

        dictData.setUpdateTime(LocalDateTime.now());
        boolean success = dictDataMapper.updateById(dictData) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }
    /**
     * dictData.stream(): 将dictData列表转换为一个流（Stream），这使得我们可以使用流式操作来处理数据。
     * .map(dictData::getName): 使用map操作将每个dictData对象映射为其name属性，即提取字典数据的名称。
     * .collect(Collectors.toList()): 将映射后的结果收集到一个新的List<String>中，并作为方法的最终返回值。
     * @return
     */
    @Override
    public List<String> getDictDataTitle() {
        //使用MyBatis-Plus提供的list方法从数据库中查询所有的字典数据实体，将结果存储在dictData列表中。
        List<DictData> dictData = list();
        // 使用Java 8 Stream API对字典数据实体列表进行处理
        // 将每个字典数据实体的名称提取出来，并构成一个新的列表
        return dictData.stream().map(DictData::getTitle).collect(Collectors.toList());
    }

    @Override
    public PageDTO<DictDataDTO> ListPage(DictDataQuery query) {
        //构建分页对象
        Page<DictData> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询对象
        QueryWrapper<DictData> wrapper = new QueryWrapper<>();
        wrapper.like("title", query.getTitle());
        wrapper.like("status", query.getStatus());
        //执行查询
        Page<DictData> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msDictDataMapper.DictDataToDictDataDto(src));
    }
}
