/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-09-06 13:06:57
 * @attention: 借鉴于 https://github.com/SeeDeer/linux/blob/v2.6.35/include/linux/list.h 
 *************************************************************************/


#ifndef _IOT_LIST_H
#define _IOT_LIST_H

#include <stddef.h>
// #include <linux/poison.h>
// #include <linux/prefetch.h>
// #include <asm/system.h>

#ifndef LIST_POISON1
#define LIST_POISON1  ((void *) 0x00100100 )
#endif

#ifndef LIST_POISON2
#define LIST_POISON2  ((void *) 0x00200200 )
#endif

#ifndef OFFSETOF
#define OFFSETOF(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifndef CONTAINER_OF
#define CONTAINER_OF(ptr, type, member) \
        ({(type *)( (char *)(ptr) - OFFSETOF(type,member) );})
#endif

// 双向链表的通用管理结构，不含数据域，简单的美
typedef struct iot_list_head_s {
	struct iot_list_head_s *next, *prev;
}iot_list_head_t;

// 链表的初始化方式1：只用传入名称即可，不用定义变量
#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	iot_list_head_t name = LIST_HEAD_INIT(name)

// 链表的初始化方式2：初始化链表函数宏
#define INIT_LIST_HEAD(p_list) do { \
	(p_list)->next = (p_list); (p_list)->prev = (p_list); \
} while (0)

// 在两个节点中间插入一节点
#define __LIST_NODE_ADD(node,__prev,__next) do { \
	(__next)->prev = (node); (node)->next = (__next); \
	(node)->prev = (__prev); (__prev)->next = (node); \
} while (0)

// 删除两个节点中间的一个节点
#define __LIST_NODE_DEL(__prev,__next) do { \
(__next)->prev = (__prev); (__prev)->next = (__next); \
} while (0)

/*************************************************
 * @brief: head 节点之后插入新节点 node，类似栈
 * @param node, iot_list_head_t 类型，要插入的节点
 * @param head, iot_list_head_t 类型，要插入链表头部节点
 * @return {*}
 *************************************************/
void iot_list_add(iot_list_head_t *node, iot_list_head_t *head);

/*************************************************
 * @brief: head 节点之前插入新节点 node, 类似队列
 * @param node, iot_list_head_t 类型，要插入的节点
 * @param head, iot_list_head_t 类型，要插入链表头部节点
 * @return {*}
 *************************************************/
void iot_list_add_tail(iot_list_head_t *node, iot_list_head_t *head);

/*************************************************
 * @brief: 从链表中删除一个节点
 * @param entry, iot_list_head_t 类型，要删除的节点
 * @return {*}
 *************************************************/
void iot_list_del(iot_list_head_t *entry, iot_list_head_t *head);

/*************************************************
 * @brief: 将链表中old节点替换为new_node节点
 * @param {*}
 * @return {*}
 *************************************************/
#define IOT_LIST_REPLACE(old,new_node) do { \
	(new_node)->next = (old)->next; \
	(new_node)->next->prev = (new_node); \
	(new_node)->prev = (old)->prev; \
	(new_node)->prev->next = (new_node); \
} while (0)

/*************************************************
 * @brief: 节点node是否是链表head的最后一个
 * @param {*}
 * @return {*}
 *************************************************/
void iot_list_is_last(iot_list_head_t *node, iot_list_head_t *head);

/*************************************************
 * @brief: 判断链表是否为空
 * @param {iot_list_head_t} *head
 * @return {*}
 *************************************************/
void iot_list_is_empty(iot_list_head_t *head);

/*************************************************
 * @brief: 	get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 *************************************************/
#define iot_list_entry(ptr, type, member) \
	CONTAINER_OF(ptr, type, member)

#define IOT_LIST_FIRST_ENTRY(ptr, type, member) \
	IOT_LIST_ENTRY((ptr)->next, type, member)

#define iot_list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); (pos) = (pos)->next)

#define iot_list_for_each_safe(pos, n, head) \
	for ((pos) = (head)->next, n = (pos)->next; (pos) != (head); \
		(pos) = (n), (n) = (pos)->next)

#endif

