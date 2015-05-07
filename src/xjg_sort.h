/*************************************************************************
	> File Name: xjg_sort.h
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月23日 星期四 18时59分42秒
 ************************************************************************/

#ifndef _xjg_sort_h
#define _xjg_sort_h

#include "xjg_common.h"

/**
 * 插入排序
 * @param array 待排序数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_insert(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 冒泡排序
 * @param array 待排序数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_bubble(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 选择排序
 * @param array 待排序的数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_select(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 希尔排序
 * @param array 待排序的数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_shell(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 堆排序
 * @param array 待排序的数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_heap(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 归并排序
 * @param array 待排序的数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_merge(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

/**
 * 快速排序
 * @param array 待排序的数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 */
void xjg_sort_quick(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end);

#endif

