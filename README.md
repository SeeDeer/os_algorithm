# os_sort_algorithm

- [数据结构与算法](https://www.yuque.com/docs/share/8df3832e-e964-44f2-b2a4-ff440db0f571?# 《数据结构与算法》)


## 组件接口

1. 冒泡排序

```c
/*************************************************
 * @brief: 冒泡排序的实现
 * @param {int} array[]
 * @param {int} order, 指定升序还是降序
 * @return void
 *************************************************/
void os_alg_bubble_sort(int array[], int length, sort_order_t order);
```

2. 堆排序

```c
/*************************************************
 * @brief: 堆排序
 * @param {int} array[]
 * @param {int} length
 * @param {int} order, 指定升序还是降序
 * @return void
 *************************************************/
void os_alg_heap_sort(int array[], int length, sort_order_t order);
```
