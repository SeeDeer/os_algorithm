/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: 冒泡排序的实现
 * @version: 1.0.0
 * @LastEditTime: 2021-07-05 09:07:25
 * @attention: Do not edit
 *************************************************************************/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "os_alg_sort.h"

#define SORT_DEBUG_ENABLED      1

static void __data_swap(int *a, int *b);
static int __parent(int i);
static int __left(int i);
static int __right(int i);
static void max_heap_adjust(int arr[], int start, int end);
static void min_heap_adjust(int arr[], int start, int end);

// 堆排序
void os_alg_heap_sort(int array[], int length, sort_order_t order)
{
    int i;
    printf("os_alg_heap_sort, length:%d\n", length);
    // 建堆初始化，i以最后一个父节点开始调整
    for (i = length / 2 - 1; i >= 0; i--){
        if (order == UP_ORDER_SORT)
            max_heap_adjust(array, i, length - 1);
        else
            min_heap_adjust(array, i, length - 1);
            
    }

    for (i = length - 1; i > 0; i--) {
        __data_swap(&array[0], &array[i]);  // 堆跟节点得最大元素和数组第i个元素交换
        if (order == UP_ORDER_SORT)         // 数组第i个元素从堆中移除，并重新初始化新堆
            max_heap_adjust(array, 0, i - 1);
        else
            min_heap_adjust(array, 0, i - 1);
    }
}

// 冒泡排序
void os_alg_bubble_sort(int array[], int length, sort_order_t order)
{
    if ((array == NULL) || (length == 0)){
        return;
    }
    
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
    int compare_cnt = 0, move_cnt = 0;
#endif
    int i,j,temp;
    uint8_t swapped = 1;
    // 外层循环控制排序趟数,最多执行 N-1 次
    for(i = 1; swapped && i < length; ++i) {
        swapped = 0;
        // 内层循环最多的时候执行N次，最少的时候执行1次，平均执行 (N+1)/2次
        // 所以循环体内的比较交换约执行 (N - 1)(N + 1) / 2 = (N^2 - 1)/2
        for(j = 0; j < length - i; ++j)
        {
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
            compare_cnt++;
#endif
            if (order == UP_ORDER_SORT){  // 升序
                if(array[j] > array[j+1]){
                    __data_swap(&array[j], &array[j+1]);
                    swapped = 1;
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
                    move_cnt += 3;
#endif
                }
            } 
            else {  // 降序
                if(array[j] < array[j+1]){
                    __data_swap(&array[j], &array[j+1]);
                    swapped = 1;
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
                    move_cnt += 3;
#endif
                }
            }
        }
    }
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
    printf("os_alg_bubble_sort end, compare_cnt:%d move_cnt:%d\n", compare_cnt, move_cnt);
#endif
}

static void __data_swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

//获取父节点的数组下标
static int __parent(int i)
{
    return (i - 1) / 2;
}

//获取左孩子的数组下标
static int __left(int i)
{
    return 2 * i + 1;
}

//获取右孩子的数组下标
static int __right(int i)
{
    return 2 * i + 2;
}

// 最大堆调整
static void max_heap_adjust(int arr[], int start, int end)
{
    int parent = start; // 父节点
    int child;
    while (__left(parent) <= end) {
        // 找出左右节点中最大的节点
        if (__right(parent) <= end && arr[__left(parent)] < arr[__right(parent)])
            child = __right(parent);
        else
            child = __left(parent);

        if (arr[parent] > arr[child])
            return;
        else{
            __data_swap(&arr[parent], &arr[child]);
        }

        parent = child;
    }
}

// 最小堆调整
static void min_heap_adjust(int arr[], int start, int end)
{
    int parent = start; // 父节点
    int child;
    while (__left(parent) <= end) {
        // 找出左右节点中最小的节点
        if (__right(parent) <= end && arr[__left(parent)] > arr[__right(parent)])
            child = __right(parent);
        else
            child = __left(parent);

        if (arr[parent] < arr[child])
            return;
        else{
            __data_swap(&arr[parent], &arr[child]);
        }

        parent = child;
    }
}

