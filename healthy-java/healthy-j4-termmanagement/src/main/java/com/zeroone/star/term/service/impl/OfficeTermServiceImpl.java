package com.zeroone.star.term.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.common.OrgStructureException;
import com.zeroone.star.term.entity.OfficeTermEntity;
import com.zeroone.star.term.entity.TOfficeTerm;
import com.zeroone.star.term.entity.TSectionOffice;
import com.zeroone.star.term.mapper.TOfficeTermMapper;
import com.zeroone.star.term.mapper.TermanagementMapper;
import com.zeroone.star.term.service.OfficeTermService;
import lombok.val;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * 科室术语表(OfficeTerm)表服务实现类
 *
 * @author makejava
 * @since 2024-01-30 14:43:18
 */
@Service("officeTermService")
public class OfficeTermServiceImpl extends ServiceImpl<TermanagementMapper, OfficeTermEntity> implements OfficeTermService {
    @Autowired
    OfficeTermService officeTermService;
    @Resource
    private UserHolder userHolder;
    @Resource
    private TOfficeTermMapper tOfficeTermMapper;

    @Override
    public JsonVO<ResultStatus> deletetermanagement(List<String> ids) {
        // 获取当前用户
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取当前用户失败");
        }
        if (currentUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前用户不存在");

//        删除科室false返回异常
        for(String id: ids) {
            val tOfficeTerm = new TOfficeTerm();
            tOfficeTerm.setId(id);
            // 设定修改人
            tOfficeTerm.setDeleteId(String.valueOf(currentUser.getId()));
            // 设定修改时间
            tOfficeTerm.setDeleteTime(LocalDateTime.now());
            // 设定删除标志
            tOfficeTerm.setDelFlag(1);
            tOfficeTermMapper.updateById(tOfficeTerm);
        }

        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), "删除成功");
    }
}
