package com.zeroone.star.portfolioitems.service.impl;

import com.zeroone.star.portfolioitems.entity.TPortfolioProject;
import com.zeroone.star.portfolioitems.mapper.PortfolioProjectMapper;
import com.zeroone.star.portfolioitems.service.PortfolioProjectService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j4.dto.TPortfolioProjectDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;
/**
 * @author rakkaus
 */
@Service
@ComponentScan({
        "com.zeroone.star.project.components.jwt",
        "com.zeroone.star.project.components.user"
})
public class PortfolioProjectServiceImpl implements PortfolioProjectService {

    @Autowired
    private PortfolioProjectMapper portfolioProjectMapper;
    @Autowired(required = false)
    private UserHolder userHolder;
    @Override
    public JsonVO save(TPortfolioProjectDTO TPortfolioProjectDTO) {
        // 获取当前用户
//        UserDTO currUser = null;
//        try {
//              currUser = userHolder.getCurrentUser();
//        } catch (Exception e) {
//            System.out.println(currUser);
//            return JsonVO.create(e, ResultStatus.FAIL.getCode(), "获取用户失败");
//        }
//        if (currUser == null) return JsonVO.create(null, ResultStatus.FAIL.getCode(), "用户不存在");
        TPortfolioProject tPortfolioProject = new TPortfolioProject();
        TPortfolioProjectDTO.setDelFlag(0);
        TPortfolioProjectDTO.setCreateTime(new Date());
//        tPortfolioProject.setOfficeId();
//        System.out.println(portfolioProjectMapper.selectByOfficeName(TPortfolioProjectDTO.getOfficeName()));
        BeanUtils.copyProperties(TPortfolioProjectDTO,tPortfolioProject);
        portfolioProjectMapper.insert(tPortfolioProject);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @Override
    public JsonVO delete(List<String> ids) {
        portfolioProjectMapper.deleteBatchIds(ids);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @Override
    public JsonVO updateById(TPortfolioProjectDTO tPortfolioProjectDTO) {
        TPortfolioProject tPortfolioProject = new TPortfolioProject();
        tPortfolioProject.setUpdateTime(new Date());
        BeanUtils.copyProperties(tPortfolioProjectDTO,tPortfolioProject);
        portfolioProjectMapper.updateById(tPortfolioProject);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
}
