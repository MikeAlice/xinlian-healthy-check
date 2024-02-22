package com.zeroone.star.login.controller;

import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.login.service.UserService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Api(tags = "login")
public class LoginController implements LoginApis {
    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Resource
    RedisTemplate redisTemplate;
    @Resource
    UserService userService;
    @Resource
    IMenuService menuService;
    @Autowired
    private CaptchaService captchaService;
    @Value("${secure.open-captcha}")
    private Boolean openCaptcha;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        //TODO:未实现验证码验证
        if (openCaptcha) {
            CaptchaVO captchaVO = new CaptchaVO();
            captchaVO.setCaptchaVerification(loginDTO.getCode());
            ResponseModel response = captchaService.verification(captchaVO);
            if (!response.isSuccess()) {
                JsonVO<Oauth2TokenDTO> fail = JsonVO.fail(null);
                fail.setMessage(response.getRepCode() + response.getRepMsg());
                //验证码校验失败，返回信息告诉前端
                //repCode  0000  无异常，代表成功
                //repCode  9999  服务器内部异常
                //repCode  0011  参数不能为空
                //repCode  6110  验证码已失效，请重新获取
                //repCode  6111  验证失败
                //repCode  6112  获取验证码失败,请联系管理员
                return fail;
            }
        }

        //账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", loginDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        // 获取Token
        JsonVO<Oauth2TokenDTO> oauth2TokenDTO = oAuthService.postAccessToken(params);
        if (oauth2TokenDTO.getData() == null) {
            JsonVO<Oauth2TokenDTO> fail = JsonVO.fail(null);
            fail.setCode(ResultStatus.SERVER_ERROR.getCode());
            fail.setMessage(ResultStatus.SERVER_ERROR.getMessage());
            return fail;
        }
        //将授权token存储到Redis中，记录登录状态
        String token = oauth2TokenDTO.getData().getToken();
        String userTokenKey = RedisConstant.USER_TOKEN + ":" + token;
        redisTemplate.opsForValue().set(userTokenKey, 1, Long.valueOf(oauth2TokenDTO.getData().getExpiresIn()), TimeUnit.SECONDS);

        return oauth2TokenDTO;
        //TODO:未实现认证成功后如何实现注销凭证（如记录凭证到内存数据库）
    }
    


    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO) {
        //TODO:未实现注销凭证验证
        //检查缓存中是否存在对应的旧token
        if (Boolean.FALSE.equals(redisTemplate.hasKey(RedisConstant.USER_TOKEN + ":" + oauth2TokenDTO.getToken()))) {
            JsonVO<Oauth2TokenDTO> fail = JsonVO.fail(null);
            fail.setCode(ResultStatus.UNAUTHORIZED.getCode());
            fail.setMessage(ResultStatus.UNAUTHORIZED.getMessage());
            return fail;
        }
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", oauth2TokenDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("refresh_token", oauth2TokenDTO.getRefreshToken());
        // 使用refresh_token调用远程接口获取新token
        JsonVO<Oauth2TokenDTO> refreshedTokenDTO = oAuthService.postAccessToken(params);
        if (refreshedTokenDTO.getData() == null) {
            JsonVO<Oauth2TokenDTO> fail = JsonVO.fail(null);
            fail.setCode(ResultStatus.SERVER_ERROR.getCode());
            fail.setMessage(ResultStatus.SERVER_ERROR.getMessage());
            return fail;
        }
        redisTemplate.delete(RedisConstant.USER_TOKEN + ":" + oauth2TokenDTO.getToken());
        //将授权token存储到Redis中，记录登录状态
        String token = refreshedTokenDTO.getData().getToken();
        String userTokenKey = RedisConstant.USER_TOKEN + ":" + token;
        redisTemplate.opsForValue().set(userTokenKey, 1, Long.valueOf(refreshedTokenDTO.getData().getExpiresIn()), TimeUnit.SECONDS);
        return oAuthService.postAccessToken(params);
    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            //TODO:这里需要根据业务逻辑接口，重新实现
            LoginVO loginVO = userService.getUserById(currentUser.getId());
            return JsonVO.success(loginVO);
        }
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        //TODO:登出逻辑，需要配合登录逻辑实现
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        String token=null;
        if (servletRequestAttributes != null) {
            HttpServletRequest request = servletRequestAttributes.getRequest();
            String authorizationHeader = request.getHeader("Authorization");
            if (authorizationHeader != null && authorizationHeader.startsWith("Bearer ")) {
                token = authorizationHeader.replace("Bearer ", "");
            }
        }

        String tokenKeyInRedis = RedisConstant.USER_TOKEN + ":" + token;
        if (Boolean.FALSE.equals(redisTemplate.hasKey(tokenKeyInRedis))) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), ResultStatus.UNAUTHORIZED.getMessage());
        }
        redisTemplate.delete(tokenKeyInRedis);
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), "退出成功");
    }

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        // TODO:未实现根据实际数据库设计业务逻辑，下面逻辑属于示例逻辑
        //1 获取当前用户
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), e.getMessage());
        }

        //2 获取当前用户拥有的菜单
        try {
            List<MenuTreeVO> menus = menuService.listMenuByRoleName(currentUser.getRoles());
            return JsonVO.success(menus);
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }

    }
}
