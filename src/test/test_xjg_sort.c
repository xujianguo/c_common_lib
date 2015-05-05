/*************************************************************************
	> File Name: test_xjg_sort.c
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月23日 星期四 19时53分51秒
 ************************************************************************/

#include "../xjg_sort.h"

uint_t a[] = {5, 4, 3, 9, 20, 2, 7, 17, 12, 10, 8, 15, 36, 24, 18, 16, 10, 6, 11, 13};
uint_t len = 20;

int int_compare(void *a, void *b) {
	int *_a = (int *)a;
	int *_b = (int *)b;
	if(*_a > *_b)	return 1;
	if(*_a < *_b)	return -1;
	return 0;
}

void print_array(uint_t *a, uint_t len) {
	uint_t i;
	for(i = 0; i < len; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void xjg_test_sort_insert() {
	xjg_sort_insert(a, sizeof(int), int_compare, 0, 19);
	print_array(a, len);
}

void xjg_test_sort_bubble() {
	xjg_sort_bubble(a, sizeof(int), int_compare, 0, 19);
	print_array(a, len);
}

void xjg_test_sort_select() {
	xjg_sort_select(a, sizeof(int), int_compare, 0, 19);
	print_array(a, len);
}

void xjg_test_sort_shell() {
	xjg_sort_shell(a, sizeof(int), int_compare, 0, 19);
	print_array(a, len);
}

int main() {
	//xjg_test_sort_insert();
	//xjg_test_sort_bubble();
	//xjg_test_sort_select();
	xjg_test_sort_shell();
}
