/*************************************************************************
	> File Name: xjg_list.h
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月22日 星期三 18时38分09秒
 ************************************************************************/
 

/*************************************************************************
	介绍：
	    下面实现了一个双向链表，包含关于链表的一些基本的操作
	    
	扩展：
	    用双向链表实现一个栈
	        入栈操作：调用list_add_node_tail方法从尾部插入
	        出栈操作：调用list_del_node_tail方法从尾部移出
	         
	    用双向链表实现一个队列
			入队操作：调用list_add_node_tail方法从尾部插入
			出队操作：调用list_del_node_head方法从头部删除
 ************************************************************************/
 
#ifndef _xjg_list_h
#define _xjg_list_h

#include "xjg_common.h"

//链表节点
typedef struct xjg_list_node {
	//前驱
	struct list_node *prev;
	//后继
	struct list_node *next;
	//节点值
	void *value;
}xjg_list_node;

//链表
typedef struct xjg_list {
	//头
	xjg_list_node *head;
	//尾
	xjg_list_node *tail;
	//释放时对value指针的操作
	void (*free)(void *ptr);
	//匹配比较
	int (*match)(void *ptr, void *key);
	//容量
	ulong_t len;
}xjg_list;

//迭代器
typedef struct xjg_list_iterator {
    xjg_list_node *next;
    int direction;
} xjg_list_iterator;
//方向
#define START_HEAD 0
#define START_TAIL 1

/**
 * 使用宏表示方法
 */

//获取长度
#define list_length(list) ((list)->len)
//获取头节点
#define list_head(list) ((list)->head)
//获取尾节点
#define list_tail(list) ((list)->tail)
//获取上个节点
#define list_prev_node(list_node) ((list_node)->prev)
//获取下个节点
#define list_next_node(list_node) ((list_node)->next)
//获取节点值
#define list_node_value(list_node) ((list_node)->value)

/**
 * 实现方法
 */

/**
 * 创建链表
 * @return 链表
 */
xjg_list *list_create(void);

/**
 * 释放链表
 * @param list 链表指针
 */
void list_free(xjg_list *list);

/**
 * 插入节点的基础实现
 * @param list 链表
 * @param target 目标
 * @param prev 前驱
 * @param next 后继
 */
void list_add_base(xjg_list *list, xjg_list_node *target, xjg_list_node *prev, xjg_list_node *next);

/**
 * 在指定位置插入节点
 * @param list 链表
 * @param position 位置
 * @param value 节点值
 * @return 链表
 */
xjg_list *list_add_node(xjg_list *list, uint_t position, void *value);

/**
 * 在头位置插入节点
 * @param list 链表
 * @param value 节点值
 * @return 链表
 */
xjg_list *list_add_node_head(xjg_list *list, void *value);

/**
 * 在尾位置插入节点
 * @param list 链表
 * @param value 节点值
 * @return 链表
 */
xjg_list *list_add_node_tail(xjg_list *list, void *value);

/**
 * 删除节点的基础实现
 * @param list 链表
 * @param target 目标
 * @param prev 前驱
 * @param next 后继
 */
void list_del_base(xjg_list *list, xjg_list_node *target, xjg_list_node *prev, xjg_list_node *next);

/**
 * 移除指定位置的节点
 * @param list 链表
 * @param position 位置
 * @return 返回删除的节点值
 */
void *list_del_node(xjg_list *list, uint_t position);

/**
 * 在尾位置删除节点
 * @param list 链表
 * @param value 节点值
 * @return 返回删除的节点值
 */
void *list_del_node_tail(xjg_list *list);

/**
 * 在头位置删除节点
 * @param list 链表
 * @param value 节点值
 * @return 返回删除的节点值
 */
void *list_del_node_head(xjg_list *list);

/**
 * 获取链表的迭代器
 * @param list 链表
 * @param direction 方向
 * @return 返回迭代器
 */
xjg_list_iterator *list_get_iterator(xjg_list *list, int direction);

/**
 * 释放链表的迭代器
 * @param iterator 迭代器
 */
void list_release_iterator(xjg_list_iterator *iterator);

/**
 * 迭代器的下个元素
 * @param iterator 迭代器
 * @return 节点
 */
xjg_list_node *list_iterator_next(xjg_list_iterator *iterator);

/**
 * 查找节点
 * @param list 链表
 * @param key 值
 * @return 节点
 */
xjg_list_node *list_search_key(xjg_list *list, void *key);

/**
 * 定位节点
 * @param list 链表
 * @param index 索引
 * @return 节点
 */
xjg_list_node *list_index(xjg_list *list, ulong_t index);

#endif
