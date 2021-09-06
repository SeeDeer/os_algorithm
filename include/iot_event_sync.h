/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-06 17:52:40
 * @attention: Do not edit
 *************************************************************************/

#ifndef _IOT_EVENT_SYNC_H
#define _IOT_EVENT_SYNC_H

#include "iot_list.h"

typedef struct iot_event_sync_init_s {
    void (*__printf)(char* format, ...);
    void *(*__malloc)(size_t size);
    void (*__free)(void *ptr);
    int (*__mutex_lock)(void *handle);
    int (*__mutex_unlock)(void *handle);
}iot_event_sync_init_t;

#define EVENT_NAME_STRING_MAX_LEN 32

typedef struct event_node_s {
    char name[EVENT_NAME_STRING_MAX_LEN + 1];
    iot_list_head_t node;
    iot_list_head_t subscribe_list;     //挂载所有订阅者
}event_node_t;

typedef int (*event_cb_t)(void *data);

typedef struct subscribe_node_s {
    char name[EVENT_NAME_STRING_MAX_LEN + 1];
    char desc[EVENT_NAME_STRING_MAX_LEN + 1];
    event_cb_t cb;
    iot_list_head_t node;
}subscribe_node_t;

int iot_publish_event(const char *name, void *data);

int iot_subscribe_event(const char *name, const char *desc, event_cb_t cb);

/************************************************************
 * 一些错误码定义
*************************************************************/

#define IOT_EVENT_SYNC_ERR_CODE_MASK                (0)
#define IOT_EVENT_SYNC_ERR_CODE_INIT                (0x01 << IOT_EVENT_SYNC_ERR_CODE_MASK)
#define IOT_EVENT_SYNC_ERR_CODE_INVALID_PARM        (0x02 << IOT_EVENT_SYNC_ERR_CODE_MASK)
#define IOT_EVENT_SYNC_ERR_CODE_NALLOC_FAILED       (0x03 << IOT_EVENT_SYNC_ERR_CODE_MASK)


#endif /* _IOT_EVENT_SYNC_H */
