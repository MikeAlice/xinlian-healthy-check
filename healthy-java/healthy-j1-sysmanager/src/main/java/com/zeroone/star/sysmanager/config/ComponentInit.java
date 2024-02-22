package com.zeroone.star.sysmanager.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

/**
 * 初始化自定义组件
 */
@Configuration
@ComponentScan({
        "com.zeroone.star.project.components.jwt",
        "com.zeroone.star.project.components.user",
        "com.zeroone.star.project.components.fastdfs",
        "com.zeroone.star.project.components.easyexcel"
})
public class ComponentInit {
}
