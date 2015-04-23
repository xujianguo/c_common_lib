/*************************************************************************
	> File Name: xjg_list.c
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月22日 星期三 19时44分07秒
 ************************************************************************/

#include "xjg_list.h"

xjg_list *list_create(void) {
	xjg_list *list = (xjg_list *)malloc(sizeof(xjg_list));
	
	if(NULL == list)
		xjg_show_allocate_error("list_create", sizeof(xjg_list));
	
	list->head = list->tail = NULL;
	list->free = NULL;
	list->match = NULL;
	list->len = 0;
	
	return list;
}

void list_free(xjg_list *list) {
	ulong_t len;
	xjg_list_node *current, *next;
	
	len = list->len;
	current = list->head;

	while(len--) {
		next = current->next;
		if(list->free != NULL)
			list->free(current->value);
		free(current);
		current = next;
	}

	free(list);
}

void list_add_base(xjg_list *list, xjg_list_node *target, xjg_list_node *prev, xjg_list_node *next) {
    if(list->len == 0) {
		list->head = list->tail = target;
		target->prev = NULL;
		target->next = NULL;
	} else {
		if(prev) {
			prev->next = target;
			target->prev = prev;
		} else {
			list->head = target;
			target->prev = NULL;
		}
		
		if(next) {
			next->prev = target;
			target->next = next;
		} else {
			list->tail = target;
			target->next = NULL;
		}
	}
	list->len++;
}

xjg_list *list_add_node(xjg_list *list, uint_t position, void *value) {
	xjg_list_node *target = (xjg_list_node *)malloc(sizeof(xjg_list_node));
	if(NULL == target)
        xjg_show_allocate_error("list_add_node", sizeof(xjg_list_node));
    xjg_list_node * next = list_index(list, position);
    list_add_base(list, target, next->prev, next);
    return list;
}

xjg_list *list_add_node_head(xjg_list *list, void *value) {
    return list_add_node(list, 1, value);
}

xjg_list *list_add_node_tail(xjg_list *list, void *value) { 
    return list_add_node(list, xjg_list->len, value);
}

void list_del_base(xjg_list *list, xjg_list_node *target, xjg_list_node *prev, xjg_list_node *next) {
	if(list->len > 0) {
		if(prev == NULL) {
			list->head = next;
			next->prev = NULL;
		} else {
			prev->next = next;
		}
		
		if(next == NULL) {
			list->tail = prev;
			prev->next = NULL;
		} else {
			next->prev = prev;
		}
		
		if(list->free)
			list->free(target->value);
		free(target);
		
		list->len--;
	}
}

void *list_del_node(xjg_list *list, uint_t position) {
	xjg_list_node *target = list_index(list, position);
	list_del_base(list, target, target->prev, target->next);
	if(list->free)
		return NULL;
	return target->value;
}

void *list_del_node_tail(xjg_list *list) {
	return list_del_node(list, list->len);
}

void *list_del_node_head(xjg_list *list) {
	return list_del_node(list, 1);
}

xjg_list_iterator *list_get_iterator(xjg_list *list, int direction) {
    xjg_list_iterator iterator = (xjg_list_iterator *)malloc(sizeof(xjg_list_iterator));
    
    if(NULL == iterator)
        xjg_show_allocate_error("list_get_iterator", sizeof(xjg_list_iterator));
    
    if(direction == START_HEAD)
        iterator->next = list->head;
    else
        iterator->next = list->tail;
    
    iterator->direction = direction;
    return iterator;
}

void list_release_iterator(xjg_list_iterator *iterator) {
    free(iterator);
}

xjg_list_node *list_iterator_next(xjg_list_iterator *iterator) {
    xjg_list_node current = iterator->next;
    
    if(current != NULL) {
        if(iterator->director == START_HEAD)
            iterator->next = current->next;
        else 
            iterator->next = current->prev;
    }
    
    return current;
}

xjg_list_node *list_search_key(xjg_list *list, void *key) {
    xjg_list_node node;
    xjg_list_iterator *iterator = list_get_iterator(list, START_HEAD);
    
    while((node = ist_iterator_next(iterator)) != NULL) {
        if(list->match) {
            if(list->match(node->value, key)) {
                list_release_iterator(iterator);
                return node;
            }
        } else {
            if(node->value == key) {
                list_release_iterator(iterator);
                return node;
            }
        }
    }
    
    list_release_iterator(iterator);
    return NULL;
}

xjg_list_node *list_index(xjg_list *list, ulong_t index) {
    xjg_list_node *node;

    if (index < 0) {
        index = (-index)-1;
        node = list->tail;
        while(index-- && node) 
            node = node->prev;
    } else {
        node = list->head;
        while(index-- && node) 
            node = node->next;
    }
    return node;
}

