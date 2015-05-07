/*************************************************************************
	> File Name: xjg_find.c
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年05月05日 星期二 23时49分06秒
 ************************************************************************/

#include "xjg_find.h"

int xjg_find_sequence(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end, uint_t key) {
	int i;
	for(i = start; i <= end; i++) {
		if(compare(array+i*size, &key) == 0)
			return i;
	}
	return -1;
}

int xjg_find_binary(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end, uint_t key) {
	int middle;
	while(start <= end) {
		middle = (start + end)/2;
		if(compare(array+middle*size, &key) < 0) 
			start = middle + 1;
		else if(compare(array+middle*size, &key) > 0) 
			end = middle - 1;
		else 
			return middle;
	}
	return -1;
}
