/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-02 23:19:56
 * @attention: Do not edit
 *************************************************************************/

#include "iot_list.h"


void iot_list_add(iot_list_head_t *node, iot_list_head_t *head)
{
    __LIST_NODE_ADD(node, head, head->next); 
}

