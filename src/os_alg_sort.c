/************************************************************************
 * @file: Do not edit
 * @author: xxx
 * @brief: 冒泡排序的实现
 * @version: 1.0.0
 * @LastEditTime: 2021-07-05 00:24:45
 * @attention: Do not edit
 *************************************************************************/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define SORT_DEBUG_ENABLED      0

static void __data_swap(uint32_t *a, uint32_t *b);
static uint32_t __parent(uint32_t i);
static uint32_t __left(uint32_t i);
static uint32_t __right(uint32_t i);
static void max_heapify(uint32_t arr[], uint32_t start, uint32_t end);

// 堆排序
void os_alg_heap_sort(uint32_t array[], uint32_t length)
{
    uint32_t i;
    // 建堆初始化，i以最后一个父节点开始调整
    for (i = length / 2 - 1; i >= 0; i--){
        max_heapify(array, i, length - 1);
    }

    for (i = length - 1; i > 0; i--) {
        __data_swap(&array[0], &array[i]);  // 堆跟节点得最大元素和数组第i个元素交换
        max_heapify(array, 0, i - 1);       // 数组第i个元素从堆中移除，并重新初始化新堆
    }
}

// 冒泡排序
void os_alg_bubble_sort(uint32_t array[], uint32_t length)
{
    if ((array == NULL) || (length == 0)){
        return;
    }
    
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
    uint32_t compare_cnt = 0, move_cnt = 0;
#endif
    uint32_t i,j,temp;
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
            // 升序，交互数据
            if(array[j] > array[j+1]){
                __data_swap(&array[j], &array[j+1]);
                swapped = 1;
#if defined(SORT_DEBUG_ENABLED) && (SORT_DEBUG_ENABLED == 1)
                move_cnt += 3;
#endif
            }
        }
    }

    // printf("os_alg_bubble_sort end, compare_cnt:%d move_cnt:%d\n", compare_cnt, move_cnt);
}

static void __data_swap(uint32_t *a, uint32_t *b)
{
    uint32_t temp = *b;
    *b = *a;
    *a = temp;
}

//获取父节点的数组下标
static uint32_t __parent(uint32_t i)
{
    return (i - 1) / 2;
}

//获取左孩子的数组下标
static uint32_t __left(uint32_t i)
{
    return 2 * i + 1;
}

//获取右孩子的数组下标
static uint32_t __right(uint32_t i)
{
    return 2 * i + 2;
}

// 最大堆调整
static void max_heapify(uint32_t arr[], uint32_t start, uint32_t end)
{
    // uint32_t parent = start; // 父节点
    // uint32_t child;
    // while (__left(parent) <= end) { // 若子節點指標在範圍內才做比較
    //     // 找出左右节点中最大的节点
    //     if (__right(parent) <= end && arr[__left(parent)] < arr[__right(parent)])
    //         child = __right(parent);
    //     else
    //         child = __left(parent);
        
    //     // 如果父节点大于子节点，代表调整结束，跳出函数
    //     if (arr[parent] > arr[child])
    //         return;
    //     else {
    //         __data_swap(&arr[parent], &arr[child]);
    //         parent = child;
    //     }
    // }

    printf("start %d\n",start);
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        printf("son:%d dad:%d \n", son, dad);
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比较
            __data_swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

