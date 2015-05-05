/*************************************************************************
	> File Name: xjg_sort.c
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月23日 星期四 19时05分02秒
 ************************************************************************/

#include "xjg_sort.h"

void xjg_sort_insert(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	uchar_t *temp = (uchar_t*)malloc(size);
	int i, j;
	uchar_t *current;

	for(i = start+1; i <= end; i++) {
		memcpy(temp, array+i*size, size);
		for(j = i; j > start && compare(temp, (current=array+(j-1)*size)) < 0; j--) {
			memcpy(current+size, current, size);
		}
		if(j < i)
			memcpy(array+j*size, temp, size);
	}
}

/**
 * 冒泡排序：
 *		优化一：加入了hashChange标志，如果标记没有被改变，证明序列中已经排序好来，不必要进行下次操作
 *		优化二：加入了mark和index标记，用于确定最终改变行的位置，下次就从那个位置开始，因为可能之前的已经排序好
 */
void xjg_sort_bubble(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	uchar_t *temp = (uchar_t*)malloc(size);
	int i, j, mark, hasChange, index;
	mark = end - 1;
	hasChange = 0;
	index = 0;

	for(i = 1; i <= end-start; i++) {
		for(j = 0; j <= mark; j++) {
			if(compare(array+j*size, array+(j+1)*size) > 0) {
				memcpy(temp, array+j*size, size);
				memcpy(array+j*size, array+(j+1)*size, size);
				memcpy(array+(j+1)*size, temp, size);
				hasChange = 1;
				index = j;
			}
		}
		if(hasChange == 0)
			break;
		mark = index;
	}
}

void xjg_sort_select(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	int i, j, min;
	uchar_t *temp = (uchar_t*)malloc(size);

	for(i = start; i < end; i++) {
		min = i;
		for(j = i+1; j <= end; j++) {
			if(compare(array+j*size, array+size*min) < 0) {
				min = j;
			}
		}
		if(min != i) {
			memcpy(temp, array+i*size, size);
			memcpy(array+i*size, array+min*size, size);
			memcpy(array+min*size, temp, size);
		}
	}
}

void xjg_sort_shell(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	int i, j, increment;
	uchar_t *temp = (uchar_t*)malloc(size);

	for(increment = (end-start)/2; increment > 0; increment /= 2) {
		for(i = increment; i <= end; i++) {
			memcpy(temp, array+i*size, size);
			for(j = i; j >= increment; j -= increment) {
				if(compare(array+(j-increment)*size, temp) > 0) {
					memcpy(array+j*size, array+(j-increment)*size, size);
				} else {
					break;
				}
			}
			memcpy(array+j*size, temp, size);
		}
	}
}

