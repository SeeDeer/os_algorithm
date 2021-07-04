/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: xxx
 * @version: 1.0.0
 * @LastEditTime: 2021-07-04 23:59:36
 * @attention: Do not edit
 *************************************************************************/

#ifndef __OS_ALG_SORT_H__
#define __OS_ALG_SORT_H__

#include <stdint.h>

/*************************************************
 * @brief: 冒泡排序的实现
 * @param {uint32_t} array[]
 * @param {uint32_t} length
 * @return void
 *************************************************/
void os_alg_bubble_sort(uint32_t array[], uint32_t length);


/*************************************************
 * @brief: 堆排序
 * @param {uint32_t} array[]
 * @param {uint32_t} length
 * @return void
 *************************************************/
void os_alg_heap_sort(uint32_t array[], uint32_t length);


#endif
