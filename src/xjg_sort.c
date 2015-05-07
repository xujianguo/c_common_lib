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

int get_left_child(int i) {
	return 2 * i + 1;
}

void build_heap(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	int child;
	uchar_t *temp = (uchar_t*)malloc(size);

	for(memcpy(temp, array+start*size, size); get_left_child(start) <= end; start = child) {
		child = get_left_child(start);
		if(child != end && compare(array+child*size, array+(child+1)*size) < 0)
			child++;
		if(compare(temp, array+child*size) < 0)
			memcpy(array+size*start, array+child*size, size);
		else
			break;
	}
	memcpy(array+start*size, temp, size);
}

void xjg_sort_heap(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	int i;
	uchar_t *temp = (uchar_t*)malloc(size);

	for(i = (end-start+1)/2; i >= 0; i--)
		build_heap(array, size, compare, i, end);
	for(i = end; i > 0; i--) {
		memcpy(temp, array+i*size, size);
		memcpy(array+i*size, array, size);
		memcpy(array, temp, size);
		build_heap(array, size, compare, 0, i-1);
	}
}

void merge(void *array, void *copy, uint_t size, xjg_compare compare, uint_t left, uint_t center, uint_t right) {
	int left_end = center - 1;
	int copy_position = left;
	int total = right - left + 1;
	int i;

	while(left <= left_end && center <= right) {
		if(compare(array+left*size, array+center*size) < 0) {
			memcpy(copy+copy_position*size, array+left*size, size);
			copy_position++;
			left++;
		} else {
			memcpy(copy+copy_position*size, array+center*size, size);
			copy_position++;
			center++;
		}
	}

	while(left <= left_end) {
		memcpy(copy+copy_position*size, array+left*size, size);
		copy_position++;
		left++;
	}

	while(center <= right) {
		memcpy(copy+copy_position*size, array+center*size, size);
		copy_position++;
		center++;
	}

	for(i = 0; i < total; i++, right--) {
		memcpy(array+right*size, copy+right*size, size);
	}

}

void merge_sort(void *array, void *copy, uint_t size, xjg_compare compare, uint_t left, uint_t right) {
	int middle;
	if(left < right) {
		middle = (left+right)/2;
		merge_sort(array, copy, size, compare, left, middle);
		merge_sort(array, copy, size, compare, middle+1, right);
		merge(array, copy, size, compare, left, middle+1, right);
	}
}

void xjg_sort_merge(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	void* copy = (void*)malloc((end-start+1)*size);
	merge_sort(array, copy, size, compare, start, end);
}

void xjg_sort_quick(void *array, uint_t size, xjg_compare compare, uint_t start, uint_t end) {
	int i, j;
	uchar_t *target = (uchar_t*)malloc(size);
	uchar_t *temp = (uchar_t*)malloc(size);

	if(start < end) {
		memcpy(target, array+end*size, size);
		i = start;
		j = end - 1;
		for(;;) {
			while(compare(array+i*size, target) < 0)
				i++;
			while(compare(array+j*size, target) > 0)
				j--;
			if(i < j) {
				memcpy(temp, array+i*size, size);
				memcpy(array+i*size, array+j*size, size);
				memcpy(array+j*size, temp, size);
				i++;
				j--;
			} else {
				break;
			}
		}
		memcpy(temp, array+i*size, size);
		memcpy(array+i*size, array+end*size, size);
		memcpy(array+end*size, temp, size);
		xjg_sort_quick(array, size, compare, start, i - 1);
		xjg_sort_quick(array, size, compare, i + 1, end);
	}
}
