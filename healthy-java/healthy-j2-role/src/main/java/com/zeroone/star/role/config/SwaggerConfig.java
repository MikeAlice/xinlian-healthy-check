package com.zeroone.star.role.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;


@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig  {
    @Bean
    Docket roleApi(){
        return SwaggerCore.defaultDocketBuilder("角色模块","com.zeroone.star.role.controller","role");

    }
}
