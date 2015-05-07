/*************************************************************************
	> File Name: test_xjg_find.c
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年05月05日 星期二 23时56分48秒
 ************************************************************************/

#include "../xjg_find.h"

uint_t a[] = {5, 4, 3, 9, 20, 2, 7, 17, 12, 10, 8, 15, 36, 24, 18, 16, 10, 6, 11, 13};
uint_t len = 20;

uint_t a_sort[] = {2, 5, 6, 8, 9, 12};

int int_compare(void *a, void *b) {
		int *_a = (int *)a;
		int *_b = (int *)b;
		if(*_a > *_b)
			return 1;
		if(*_a < *_b)	
			return -1;
		return 0;
}

int target = 5;
//void *key = &target;

void show_result(int result) {
	printf("index of key is %d\n", result);
}

void xjg_test_find_sequence() {
	int result = xjg_find_sequence(a, sizeof(int), int_compare, 0, 19, target);
	show_result(result);
}

void xjg_test_find_binary() {
	int result = xjg_find_binary(a_sort, sizeof(int), int_compare, 0, 5, target);
	show_result(result);
}

int main() {
	//xjg_test_find_sequence();
	xjg_test_find_binary();
	return 0;
}
