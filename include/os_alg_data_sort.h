/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-07-05 23:14:25
 * @attention: Do not edit
 *************************************************************************/

#ifndef __OS_ALG_DATA_SORT_H__
#define __OS_ALG_DATA_SORT_H__

#include <stdint.h>

#define UP_ORDER_SORT   1   // 升序排序
#define DN_ORDER_SORT   2   // 降序排序
typedef uint8_t sort_order_t;

/*************************************************
 * @brief: 冒泡排序的实现
 * @param {int} array[]
 * @param {int} order, 指定升序还是降序
 * @return void
 *************************************************/
void os_alg_bubble_sort(int array[], int length, sort_order_t order);


/*************************************************
 * @brief: 堆排序
 * @param {int} array[]
 * @param {int} length
 * @param {int} order, 指定升序还是降序
 * @return void
 *************************************************/
void os_alg_heap_sort(int array[], int length, sort_order_t order);


#endif
