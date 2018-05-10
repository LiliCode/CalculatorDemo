//
//  Array.h
//  Calculator_C
//
//  Created by 唯赢 on 2018/5/10.
//  Copyright © 2018年 李立. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void *Any;

typedef struct __ListNode {
    Any value;
    struct __ListNode *next;
} ListNode;


/**
 创建节点

 @param initValue 初始化值，节点值
 @return 返回创建好的节点
 */
extern ListNode *allocNode(Any initValue);

/**
 删除所有节点

 @param mainNode 主节点
 */
extern void deleteAllNode(ListNode *mainNode);

/**
 插入节点到尾部

 @param mainNode 主节点
 @param node 需要插入的节点
 @return 返回插入之后的所有节点
 */
extern ListNode *insertNode(ListNode *mainNode, ListNode *node);

/**
 删除节点

 @param mainNode 主节点
 @param node 需要删除的节点
 @return 返回删除之后的所有节点
 */
extern ListNode *deleteNode(ListNode *mainNode, ListNode *node);

/**
 显示节点内容

 @param mainNode 主节点
 @param callback 回调函数
 */
extern void show(ListNode *mainNode, void (*callback)(Any value));

#endif /* Array_h */




