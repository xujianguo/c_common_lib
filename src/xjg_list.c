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

void list_add_base(xjg_list_node *target, xjg_list_node *prev, xjg_list_node *next) {
    
    
    if(prev && next) {
        
    } else {
    
    }
    
    if(next) {
    
    } else {
    
    }
}

xjg_list *list_add_node(xjg_list *list, uint_t position, void *value) {
    
}

xjg_list *list_add_node_head(xjg_list *list, void *value) {
    xjg_list_node *node = (xjg_list_node *)malloc(sizeof(xjg_list_node));
    if(NULL == node)
        xjg_show_allocate_error("list_add_node_head", sizeof(xjg_list_node));
    
    node->value = value;
    if(list->len == 0) {
        list->head = list->tail = node;
        node->prev = NULL;
        node->next = NULL;
    } else {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
        list->head = node;
    }
    list->len++;
    
    return list;
}

xjg_list *list_add_node_tail(xjg_list *list, void *value) {
    xjg_list_node *node = (xjg_list_node *)malloc(sizeof(xjg_list_node));
    if(NULL == node)
        xjg_show_allocate_error("list_add_node_head", sizeof(xjg_list_node));
    
    node->value = value;
    if(list->len == 0) {
        list->head = list->tail = node;
        node->prev = NULL;
        node->next = NULL;
    } else {
        node->next = NULL;
        node->prev = head->tail;
        list->tail->next = node;
        list->tail = node;
    }
    list->len--;
    
    return list;
}

void *list_del_node(xjg_list *list, uint_t position) {

}

void *list_del_node_tail(xjg_list *list) {

}

void *list_del_node_head(xjg_list *list) {

}

void list_del_node(xjg_list *list, xjg_list_node *node) {
    if(node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    
    if(node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    
    if(list->free)
        list->free(node->value);
    free(node);
    list->len--;
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

void *list_set(xjg_list *list, uint_t position, void *value) {

}

