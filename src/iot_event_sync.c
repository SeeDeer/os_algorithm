/************************************************************************
 * @file: iot_event_sync.c
 * @author: xxx
 * @brief: 同步事件通知机制实现
 * @version: 1.0.0
 * @LastEditTime: 2021-09-02 23:18:07
 * @attention: Do not edit
 *************************************************************************/

#include "iot_event_sync.h"
#include <string.h>

/*************************************************************************
 * 内部变量、数据类型定义
**************************************************************************/
typedef struct event_manage_s{
    int inited;                 // 事件系统是否初始化
    void *mutex;                // 事件管理锁
    int event_count;            // 事件数量
    iot_list_head_t event_list; // 发布者事件链表
    iot_list_head_t free_subscribe_list;    // 空闲订阅者链表，对应事件尚未创建发布
}event_manage_t;

static event_manage_t g_event_manage;

static int __event_manage_init(void)
{
    memset(&g_event_manage, 0, sizeof(g_event_manage));
    INIT_LIST_HEAD(&g_event_manage.event_list);
    INIT_LIST_HEAD(&g_event_manage.free_subscribe_list);
    // 创建锁

    g_event_manage.inited = 1;

    return 0;
}

static int __event_node_create(char *name)
{
    event_node_t *event = (event_node_t *)malloc(sizeof(event_node_t));
}

int iot_publish_event(const char *name, void *data)
{
    
}

int iot_subscribe_event(const char *name, const char *desc, event_cb_t cb)
{

}


