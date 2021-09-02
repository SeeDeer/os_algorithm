/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-02 23:16:09
 * @attention: Do not edit
 *************************************************************************/

#ifndef _IOT_EVENT_SYNC_H
#define _IOT_EVENT_SYNC_H

#include "iot_list.h"

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


#endif /* _IOT_EVENT_SYNC_H */
