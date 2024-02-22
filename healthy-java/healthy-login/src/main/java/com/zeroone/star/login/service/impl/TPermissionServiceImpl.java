package com.zeroone.star.login.service.impl;

import com.zeroone.star.login.entity.TPermission;
import com.zeroone.star.login.mapper.TPermissionMapper;
import com.zeroone.star.login.service.ITPermissionService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 资源（菜单/操作权限） 服务实现类
 * </p>
 *
 * @author 阿布
 * @since 2024-01-24
 */
@Service
public class TPermissionServiceImpl extends ServiceImpl<TPermissionMapper, TPermission> implements ITPermissionService {

}
