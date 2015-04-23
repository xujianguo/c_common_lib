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

