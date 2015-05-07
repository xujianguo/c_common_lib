/*************************************************************************
	> File Name: xjg_find.h
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年05月05日 星期二 23时43分14秒
 ************************************************************************/

#ifndef _xjg_find_h
#define _xjg_find_h

#include "xjg_common.h"

/**
 * 顺序查找
 * @param array 待排序数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 * @param key 目标
 * @return 返回索引
 */
int xjg_find_sequence(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end, uint_t key);

/**
 * 二分查找
 * @param array 待排序数组指针
 * @param size 数组元素大小字节数
 * @param compare 比较函数指针
 * @param start 开始位置
 * @param end 结束位置
 * @param key 目标
 * @return 返回索引
 */
int xjg_find_binary(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end, uint_t key);

#endif
