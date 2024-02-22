package com.zeroone.star.percenter.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 初始化自定义组件
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.jwt",
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.sms.aliyun",
        "com.zeroone.star.project.components.mail"
})
public class ComponentInit {
}
