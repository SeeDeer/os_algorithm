/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-06 12:49:55
 * @attention: Do not edit
 *************************************************************************/

#include "iot_list.h"


void iot_list_add(iot_list_head_t *node, iot_list_head_t *head)
{
    __LIST_NODE_ADD(node, head, head->next); 
}

void iot_list_add_tail(iot_list_head_t *node, iot_list_head_t *head)
{
    __LIST_NODE_ADD(node, head->prev, head);
}

void iot_list_del(iot_list_head_t *entry, iot_list_head_t *head)
{
    __LIST_NODE_DEL(entry->prev,entry->next);
	(entry)->next = LIST_POISON1;
    (entry)->prev = LIST_POISON2;
}

void iot_list_is_last(iot_list_head_t *node, iot_list_head_t *head)
{
	return node->next == head;
}

void iot_list_is_empty(iot_list_head_t *head)
{
	return head->next == head;
}

