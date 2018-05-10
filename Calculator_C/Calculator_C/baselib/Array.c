//
//  Array.c
//  Calculator_C
//
//  Created by 唯赢 on 2018/5/10.
//  Copyright © 2018年 李立. All rights reserved.
//

#include "Array.h"

ListNode *allocNode(Any initValue) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) {
        return NULL;    // 节点分配失败
    }
    
    node->value = initValue;
    node->next = NULL;
    return node;
}

void deleteAllNode(ListNode *mainNode) {
    if (!mainNode) {
        return;
    }
    
    while (mainNode) {
        ListNode *tempNode = mainNode;  // 记录主节点
        mainNode = tempNode->next;      // 让下一个节点变成主节点
//        printf("删除节点：%p\n", tempNode);
        free(tempNode); // 释放上一次的主节点
        tempNode = NULL;
    }
    
    printf("删除完成\n");
}

ListNode *insertNode(ListNode *mainNode, ListNode *node) {
    if (!node || !mainNode) {
        return mainNode;
    }
    
    ListNode *tempNode = mainNode;  // 游标
    while (tempNode) {
        if (!tempNode->next) {
            tempNode->next = node;
            break;
        }
        
        tempNode = tempNode->next;
    }
    
    return mainNode;
}

ListNode *deleteNode(ListNode *mainNode, ListNode *node) {
    if (!node || !mainNode) {
        return mainNode;
    }
    
    return mainNode;
}

void show(ListNode *mainNode, void (*callback)(Any value)) {
    if (!mainNode) {
        return;
    }
    
    ListNode *tempNode = mainNode;
    printf("[");
    while (tempNode) {
        if (callback) {
            callback(tempNode->value);
        }
        tempNode = tempNode->next;
        if (tempNode) {
            printf(", ");
        }
    }
    printf("]\n");
}














