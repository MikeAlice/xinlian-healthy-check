package com.zeroone.star.sectionoffice.common;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.BeanUtils;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;


    public class ConvertUtil {
        private static final Logger logger = LoggerFactory.getLogger(ConvertUtil.class);

        /**
         * 单个对象值拷贝转化为目标对象
         * @param source 来源对象
         * @param target 目标对象class类
         * @return 转化后的目标对象
         * @param <T> 目标对象类型
         */
        public static <T> T sourceToTarget(Object source, Class<T> target){
            if (source == null){
                return null;
            }
            T targetObject = null;
            try {
                targetObject = target.newInstance();
                BeanUtils.copyProperties(source, targetObject);
            } catch (Exception e) {
                logger.error("convert error ", e);
            }
            return targetObject;
        }

        /**
         * 集合对象拷贝转化为目标集合对象
         * @param sourceList 来源对象集合
         * @param target 目标对象类型
         * @return 目标对象集合
         * @param <T> 目标对象类型
         */
        public static <T> List<T> sourceToTarget(Collection<?> sourceList, Class<T> target){
            if (sourceList == null) {
                return null;
            }
            List<T> targetList = new ArrayList<>(sourceList.size());
            try {
                for(Object source : sourceList) {
                    T targetObject = target.newInstance();
                    BeanUtils.copyProperties(source, targetObject);
                    targetList.add(targetObject);
                }
            } catch (Exception e){
                logger.error("convert error ", e);
            }
            return targetList;
        }
    }

