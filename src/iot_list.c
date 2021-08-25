/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-08-25 22:16:33
 * @attention: Do not edit
 *************************************************************************/

#include "iot_list.h"

// head 节点之后插入新节点 node，栈的应用
void iot_list_add(IOT_LIST_HEAD_T *node, IOT_LIST_HEAD_T *head)
{
    LIST_NODE_ADD(node, head, head->next);
}

// head 节点之前插入新节点 node, 队列的应用
void iot_list_add_tail(IOT_LIST_HEAD_T *node, IOT_LIST_HEAD_T *head)
{
    LIST_NODE_ADD(node, head->prev, head);
}

// 从链表中删除一个 node 节点
void iot_list_node_delete(IOT_LIST_HEAD_T *node)
{
    LIST_NODE_DEL(node->prev,node->next);
}
