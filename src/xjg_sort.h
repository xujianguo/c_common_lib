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

#endif

