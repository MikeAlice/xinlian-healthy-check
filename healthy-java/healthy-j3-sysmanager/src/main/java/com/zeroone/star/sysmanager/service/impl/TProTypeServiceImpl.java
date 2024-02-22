package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.dto.j3.typeLibrary.TypeLibDeleteDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeAddDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeLibraryTreeDTO;
import com.zeroone.star.project.dto.j3.typeLibrary.typeUpdateDTO;
import com.zeroone.star.project.query.j3.TypeLibraryQuery;
import com.zeroone.star.project.vo.j3.typeLibrary.TProTypeVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeAddVO;
import com.zeroone.star.project.vo.j3.typeLibrary.typeUpdateVO;
import com.zeroone.star.sysmanager.entity.ProType;
import com.zeroone.star.sysmanager.mapper.ProTypeMapper;
import com.zeroone.star.sysmanager.service.ITProTypeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import io.micrometer.core.instrument.util.StringUtils;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Mapper(componentModel = "spring")
interface MsTypeMapper {
    /**
     * 将TypeDO 转换成 TypeVO
     * @param tProType 待转换的DO
     * @return 转换结果
     */
    List<TProTypeVO> TProTypeTOtypeLibraryTreeVO(List<ProType> tProType);
    typeAddVO TProTypeTOtypeAddTypeVO(ProType tProType);
    typeUpdateVO TProTypeTOtypeUpdateTypeVO(ProType tProType);
    ProType AddTypeDTOTOProType(typeAddDTO typeadddto);
    ProType UpdateTypeDTOTOProType(typeUpdateDTO typeUpdateDTO);

    ProType removeTypeDTO(TypeLibDeleteDTO typeLibDeleteDTO);
}
@Service
public class TProTypeServiceImpl extends ServiceImpl<ProTypeMapper, ProType> implements ITProTypeService {

    @Resource
    MsTypeMapper msTypeMapper;
    @Override
    public List<TProTypeVO> getAllProTypeByTree(typeLibraryTreeDTO typeLibraryTreedto) {
        QueryWrapper<ProType> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag",0);

        if(StringUtils.isNotBlank(typeLibraryTreedto.getTypeName())){
            queryWrapper.like("type_name",typeLibraryTreedto.getTypeName());
        }else{
            queryWrapper.eq("parent_id",StringUtils.isNotBlank(typeLibraryTreedto.getParentId()) ? typeLibraryTreedto.getParentId() : "0");
        }
        List<ProType> tProTypes = baseMapper.selectList(queryWrapper);

        if(StringUtils.isBlank(typeLibraryTreedto.getTypeName())){
            QueryWrapper<ProType> tProTypeQueryWrapper = new QueryWrapper<>();
            tProTypeQueryWrapper.eq("del_flag",0);
            List<ProType> list = baseMapper.selectList(tProTypeQueryWrapper);
            List<TProTypeVO> tProTypeVOS = msTypeMapper.TProTypeTOtypeLibraryTreeVO(tProTypes);
            recursion(tProTypeVOS,list);

            return tProTypeVOS;
        }
        return msTypeMapper.TProTypeTOtypeLibraryTreeVO(tProTypes);
    }

    @Override
        public List<TProTypeVO> getTProTypeListByPage(TypeLibraryQuery query) {
            QueryWrapper<ProType> queryWrapper = new QueryWrapper<>();
            queryWrapper.eq("del_flag",0);
            //Page<TProType> page = new Page<>(query.getPageIndex(), query.getPageSize());
            if(StringUtils.isBlank(query.getTypeCode())&&StringUtils.isBlank(query.getTypeName())){
                queryWrapper.eq("parent_id","0");
            }
            if(StringUtils.isNotBlank(query.getTypeCode())) {
                queryWrapper.like("type_code",query.getTypeCode());
            }
            if(StringUtils.isNotBlank(query.getTypeName())) {
                queryWrapper.like("type_name", query.getTypeName());
            }
        if(query.getStartDate()!=null&&query.getEndDate()!=null){
            queryWrapper.lambda().and(i->i.between(ProType::getCreateTime,query.getStartDate(),query.getEndDate()));
        }
            //Page<TProType> result = baseMapper.selectPage(page, queryWrapper);
            //List<TProTypeVO> tProTypeVOS = msTypeMapper.TProTypeTOtypeLibraryTreeVO((List<TProType>) result);
            List<ProType> tProTypes = baseMapper.selectList(queryWrapper);
            List<TProTypeVO> tProTypeVOS = msTypeMapper.TProTypeTOtypeLibraryTreeVO(tProTypes);
            if(StringUtils.isBlank(query.getTypeCode())&&StringUtils.isBlank(query.getTypeName())){
                QueryWrapper<ProType> tProTypeQueryWrapper = new QueryWrapper<>();
                tProTypeQueryWrapper.eq("del_flag",0);
                List<ProType> list = baseMapper.selectList(tProTypeQueryWrapper);
                recursion(tProTypeVOS,list);
            }
            return tProTypeVOS;
        }
    @Override
    public typeAddVO addType(typeAddDTO typeadddto) {
        ProType proType = msTypeMapper.AddTypeDTOTOProType(typeadddto);
        proType.setCreateTime(LocalDateTime.now());
        baseMapper.insert(proType);
        return msTypeMapper.TProTypeTOtypeAddTypeVO(proType);
    }


    @Override
    public typeUpdateVO updateType(typeUpdateDTO typeupdatedto) {
        QueryWrapper<ProType> queryWrapper = new QueryWrapper<>();
        //queryWrapper.ne("del_flag",1);
        if(StrUtil.isNotBlank(typeupdatedto.getTypeCodePre())){
            queryWrapper.eq("type_code",typeupdatedto.getTypeCodePre());
        }
        else{
            return null;
        }
        if(StrUtil.isNotBlank(typeupdatedto.getTypeNamePre())){
            queryWrapper.eq("type_name",typeupdatedto.getTypeNamePre());
        }
        else{
            return null;
        }
        ProType proType = msTypeMapper.UpdateTypeDTOTOProType(typeupdatedto);
        proType.setUpdateTime(LocalDateTime.now());
        int update = baseMapper.update(proType, queryWrapper);
        if(update!=0){
            return msTypeMapper.TProTypeTOtypeUpdateTypeVO(proType);
        }
        return null;
    }

    @Override
    public Integer removeType(String[] ids) {
        //根据id获取对象
        List<String> list = Arrays.asList(ids);
        List<ProType> proTypes = baseMapper.selectBatchIds(list);
        //更新日期 更新标记
        LocalDateTime now = LocalDateTime.now();
        int i = 0;
        for ( ;i < proTypes.size(); i++) {
            ProType proType = proTypes.get(i);
            proType.setDeleteTime(now);
            proType.setDelFlag(1);
            //根据id更新type
            baseMapper.updateById(proType);
        }
        return i;
    }


    /**
     * 递归找类型树的子集
     * @param tProTypes
     * @param list
     */
    public void recursion(List<TProTypeVO> tProTypes, List<ProType> list) {
        for(TProTypeVO father:tProTypes){
            List<ProType> children = list.stream().filter(i -> i.getParentId().equals(father.getId())).collect(Collectors.toList());
            List<TProTypeVO> tProTypeVOS = msTypeMapper.TProTypeTOtypeLibraryTreeVO(children);
            father.setChildren(tProTypeVOS);
//            redisTemplate.opsForList().rightPush("typeTree",father);
            recursion(tProTypeVOS,list);
        }
    }
}
