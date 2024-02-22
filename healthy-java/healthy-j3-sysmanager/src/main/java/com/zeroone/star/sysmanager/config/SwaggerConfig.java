package com.zeroone.star.sysmanager.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @author ZhangJF
 * @date 2024/01/19 17:25
 **/
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket DirectSourceApis() {
        return SwaggerCore.defaultDocketBuilder("sys实例模块", "com.zeroone.star.sysmanager.controller", "sys");
    }
}
