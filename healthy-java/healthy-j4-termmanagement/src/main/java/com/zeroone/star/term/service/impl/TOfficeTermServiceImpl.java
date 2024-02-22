package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.dto.TermDetailDto;
import com.zeroone.star.project.j4.dto.TermNameDto;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.vo.TermDetailVo;
import com.zeroone.star.project.j4.vo.TermNameVo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.entity.TOfficeTerm;
import com.zeroone.star.term.entity.TSectionOffice;
import com.zeroone.star.term.mapper.TOfficeTermMapper;
import com.zeroone.star.term.service.ITOfficeTermService;
import lombok.val;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * @author lj
 * 时间：2024.1.1
 * 功能：
 */
@Mapper(componentModel = "spring")
interface MsTermMapper {
    /**
     * 将TermDO 转换成 TermDTO
     * @param tOfficeTerm 待转换的DO
     * @return 转换结果
     */
    TermDTO termToTermDto(TOfficeTerm tOfficeTerm);
}

@Service
public class TOfficeTermServiceImpl extends ServiceImpl<TOfficeTermMapper, TOfficeTerm> implements ITOfficeTermService {

    @Resource
    private TOfficeTermMapper tOfficeTermMapper;
    @Resource
    private UserHolder userHolder;

    @Override
    public PageDTO<TermDTO> queryTermList(TermQuery query) {
        // 构建分页条件对象
        //表示要查询的分页条件
        Page<TermDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<TermDTO> termVoPage = tOfficeTermMapper.selectAll(page, query);

        List<TermDTO> records = termVoPage.getRecords();

        return PageDTO.create(termVoPage);
    }

    @Override
    public PageDTO<TermNameVo> queryTermnameList(TermNameQuery query) {
        Page<TermNameDto>page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<TermNameDto> wrapper = new QueryWrapper<>();
        wrapper.like("hazard_factors_text", query.getHazardFactors());
        wrapper.like("inspect_type", query.getInspectType());
        wrapper.like("type", query.getType());
        wrapper.like("content", query.getContent());
        Page<TermNameVo> termName = tOfficeTermMapper.getTermName(page, query);
        List<TermNameVo> records = termName.getRecords();
        return PageDTO.create(termName);
    }

    @Override
    public TermDetailVo queryTermDetail(String id) {

        return baseMapper.selectId(id);
    }

    @Override
    public JsonVO<Boolean> addTerm(TermDetailDto termDetailDto) throws Exception {
        //根据科室名称获取科室表的id，即术语表的office_id
        TSectionOffice tSectionOffice = new TSectionOffice();
        //然后添加数据到术语表
        TOfficeTerm tOfficeTerm = new TOfficeTerm();
        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");
        BeanUtils.copyProperties(termDetailDto,tOfficeTerm);
        tOfficeTerm.setCreateId(String.valueOf(currentUser.getId()));
        tOfficeTerm.setCreateTime(LocalDateTime.now());
        tOfficeTerm.setOfficeId("1456834407368364032");//测试数据
        tOfficeTerm.setInspectType(termDetailDto.getInspectType());
        tOfficeTerm.setType(termDetailDto.getType());
        tOfficeTerm.setHazardFactorsText(termDetailDto.getHazardFactorsText());
        tOfficeTerm.setStatus(termDetailDto.getStatus());
        tOfficeTerm.setContent(termDetailDto.getContent());
        tOfficeTerm.setOrderNum(termDetailDto.getOrderNum());
        int insert = tOfficeTermMapper.insert(tOfficeTerm);

        return JsonVO.success(true);
    }

    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    @Override
    public JsonVO<ResultStatus> updateOfficeTerm(TermDTO termDTO) {
        // 判断数据是否已经被删除
        TOfficeTerm tOfficeTerm1 = getOfficeTerm(termDTO.getId());
        if (tOfficeTerm1.getDelFlag() == 1) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "数据已经被删除");

        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

        // 封装数据
        val tOfficeTerm = new TOfficeTerm();
        // 拷贝数据
        BeanUtils.copyProperties(termDTO, tOfficeTerm);
        // 设定修改人
        tOfficeTerm.setUpdateId(String.valueOf(currentUser.getId()));
        // 设定修改时间
        tOfficeTerm.setUpdateTime(LocalDateTime.now());
        // 执行修改
        int result = tOfficeTermMapper.updateById(tOfficeTerm);
        // 更新失败
        if (result <= 0) return JsonVO.fail(ResultStatus.FAIL);

        return JsonVO.success(ResultStatus.SUCCESS);
    }

    /**
     * @Author: ayuan
     * @param: [id]
     * @return: com.zeroone.star.term.entity.TOfficeTerm
     * @Description: 根据id获取术语
     **/
    public TOfficeTerm getOfficeTerm(String id) {
        return tOfficeTermMapper.selectById(id);
    }


    @Override
    public Boolean switchTerm(SwitchTermQuery query) throws Exception {
        UpdateWrapper updateWrapper = new UpdateWrapper();
        updateWrapper.eq("id", query.getId());
        updateWrapper.set("status", query.getStatus());
        int num = baseMapper.update(null, updateWrapper);
        if (num == 0) {
            return false;
        }
        return true;
    }
}
