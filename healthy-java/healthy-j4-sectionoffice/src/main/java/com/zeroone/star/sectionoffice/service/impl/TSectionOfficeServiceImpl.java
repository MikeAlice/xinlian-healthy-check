package com.zeroone.star.sectionoffice.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sectionoffice.common.ConvertUtil;
import com.zeroone.star.sectionoffice.entity.TSectionOffice;
import com.zeroone.star.sectionoffice.mapper.TSectionOfficeMapper;
import com.zeroone.star.sectionoffice.service.ITSectionOfficeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.val;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsTSectionOfficeMapper {
    /**
     * tSectionOffice 转换成 tSectionOfficeDTO
     *
     * @param tSectionOffice 待转换的DO
     * @return 转换结果
     */
    TSectionOfficeDTO tSectionOfficeTotSectionOfficeDTO(TSectionOffice tSectionOffice);
}


/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
@Service
@Transactional
public class TSectionOfficeServiceImpl extends ServiceImpl<TSectionOfficeMapper, TSectionOffice> implements ITSectionOfficeService {
    @Resource
    private TSectionOfficeMapper tSectionOfficeMapper;

    @Resource
    private UserHolder userHolder;

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 新增科室
     **/
    @Override
    public JsonVO<ResultStatus> saveSectionOffice(TSectionOfficeDTO tSectionOfficeDTO) {
        // 判断数据是否重复
        TSectionOffice tSectionOffice1 = getSectionOffice(tSectionOfficeDTO.getId());
        if (tSectionOffice1 != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "数据已经存在");
        }

        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

        val tSectionOffice = new TSectionOffice();
        // 拷贝数据
        BeanUtils.copyProperties(tSectionOfficeDTO, tSectionOffice);
        // 设定修改人
        // tSectionOffice.setUpdateId(String.valueOf(currentUser.getId()));
        // 设定修改时间
        // tSectionOffice.setUpdateTime(LocalDateTime.now());
        // 设定创建人
        tSectionOffice.setCreateId(String.valueOf(currentUser.getId()));
        // 设定创建时间
        tSectionOffice.setCreateTime(LocalDateTime.now());
        // 设定删除标志
        tSectionOffice.setDelFlag(0);
        // 设置部门
        tSectionOffice.setDepartmentId(getDepartmentId(String.valueOf(currentUser.getId())));
        // 执行插入
        int result = tSectionOfficeMapper.insert(tSectionOffice);
        // 判断插入是否成功
        if (result <= 0) return JsonVO.fail(ResultStatus.FAIL);

        return JsonVO.success(ResultStatus.SUCCESS);
    }

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 修改科室
     **/
    @Override
    public JsonVO<ResultStatus> updateSectionOffice(TSectionOfficeDTO tSectionOfficeDTO) {
        // 判断数据是否已经被删除
        TSectionOffice tSectionOffice1 = getSectionOffice(tSectionOfficeDTO.getId());
        if (tSectionOffice1 == null || tSectionOffice1.getDelFlag() == 1) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "数据不存在或已经被删除");

        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

        val tSectionOffice = new TSectionOffice();
        // 拷贝数据
        BeanUtils.copyProperties(tSectionOfficeDTO, tSectionOffice);
        // 设定修改人
        tSectionOffice.setUpdateId(String.valueOf(currentUser.getId()));
        // 设定修改时间
        tSectionOffice.setUpdateTime(LocalDateTime.now());
        // 执行修改
        int result = tSectionOfficeMapper.updateById(tSectionOffice);
        // 判断更新是否成功
        if (result <= 0) return JsonVO.fail(ResultStatus.FAIL);

        return JsonVO.success(ResultStatus.SUCCESS);
    }

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: void
     * @Description: 批量删除科室
     **/
    @Override
    public JsonVO<ResultStatus> removeSectionOffice(List<String> ids) {
        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

        // 逐条删除
        for(String id: ids) {
            val tSectionOffice = new TSectionOffice();
            tSectionOffice.setId(id);
            // 设定修改人
            tSectionOffice.setDeleteId(String.valueOf(currentUser.getId()));
            // 设定修改时间
            tSectionOffice.setDeleteTime(LocalDateTime.now());
            // 设定删除标志
            tSectionOffice.setDelFlag(1);
            tSectionOfficeMapper.updateById(tSectionOffice);
        }

        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), "删除成功");
    }

    /**
     * @Author: ayuan
     * @param: [id]
     * @return: com.zeroone.star.tsectionoffice.entity.TSectionOffice
     * @Description: 根据id查询科室
     **/
    public TSectionOffice getSectionOffice(String id) {
        QueryWrapper<TSectionOffice> wrapper = new QueryWrapper<>();
        wrapper.eq("id", id);
        TSectionOffice tSectionOffice = tSectionOfficeMapper.selectOne(wrapper);
        return tSectionOffice;
    }

    /**
     * @Author: ayuan
     * @param: [id]
     * @return: java.lang.String
     * @Description: 根据用户id查询科室id
     **/
    public String getDepartmentId(String id) {
        return tSectionOfficeMapper.selectByUserId(id);
    }

}
