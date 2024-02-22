package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 消息发送实体
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Getter
@Setter
@TableName("t_message_send")
public class MessageSend implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    private String id;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 删除标记 0 未删除 1 已删除
     */
    private Integer delFlag;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 消息编号
     */
    private String messageId;

    /**
     * 消息状态 -1 未发送 0 已发送 1 已读
     */
    private Integer status;

    /**
     * 消息接收人
     */
    private String userId;


}
