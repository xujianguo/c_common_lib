/*************************************************************************
	> File Name: xjg_common.h
	> Author: xujianguo
	> Mail: ray_xujianguo@yeah.net 
	> Created Time: 2015年04月22日 星期三 17时16分58秒
 ************************************************************************/

#ifndef _xjg_common_h
#define _xjg_common_h

//头文件
#include <stdio.h>
#include <stdlib.h>

//设置类型别名，方便使用
typedef long long int					llong_t;
typedef unsigned long long int			ullong_t;
typedef long int						long_t;
typedef unsigned long int				ulong_t;
typedef unsigned int					uint_t;
typedef unsigned short					ushort_t;
typedef unsigned char					uchar_t;
typedef char *							cstring;

//比较函数的别名设置
typedef int (*xjg_compare)(void *, void *);

//打印内存分配错误的信息
#define xjg_show_allocate_error(func, bytes)	\
	 do { \
		     printf("<ERROR> : Allocate Error In Function <%s> For %d Bytes.\n", func, bytes);	\
		     return NULL; \
	 } while (0)

#endif
