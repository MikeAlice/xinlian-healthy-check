package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO;
import com.zeroone.star.term.entity.TProType;
import com.zeroone.star.term.mapper.TProTypeMapper;
import com.zeroone.star.term.service.ITProTypeService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsTPortfolioProjectStruct {
    OccupationalHazardTreeDTO pDoToTDto(TProType tProType);
}

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） 服务实现类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
@Service
public class TProTypeServiceImpl extends ServiceImpl<TProTypeMapper, TProType> implements ITProTypeService {

    @Resource
    private MsTPortfolioProjectStruct msTPortfolioProjectStruct;

    @Override
    public List<OccupationalHazardTreeDTO> listOccupationalHazardTree(String typeCode) {
        List<TProType> list = this.list();
        List<OccupationalHazardTreeDTO> data = new ArrayList<>();
        List<OccupationalHazardTreeDTO> result = new ArrayList<>();

        for (TProType l : list) {
            OccupationalHazardTreeDTO dto = msTPortfolioProjectStruct.pDoToTDto(l);
            data.add(dto);
            if ("0".equals(dto.getParentId()) && typeCode.equals(dto.getTypeCode())) {
                result.add(dto);
            }
        }
        for (OccupationalHazardTreeDTO r : result) {
            r.setChild(this.getTree(r.getId(), data));
        }
        return result;
    }

    /*
     * @description: 递归地获取当前节点的子节点
     * @author: Laputa
     * @date: 2024/1/30 14:51
     * @param:  parentId
     * @param data
     * @return: java.util.List<com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO>
     **/
    @Override
    public List<OccupationalHazardTreeDTO> getTree(String parentId, List<OccupationalHazardTreeDTO> data) {
        if (parentId == null || parentId.equals("")) {
            return null;
        }
        List<OccupationalHazardTreeDTO> list = new ArrayList<>();
        // 查询子节点
        for (OccupationalHazardTreeDTO d : data) {
            if (d.getParentId().equals(parentId)) {
                list.add(d);
            }
        }

        for (OccupationalHazardTreeDTO l : list) {
            l.setChild(getTree(l.getId(), data));
        }
        return list;
    }
}
