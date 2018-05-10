//
//  Calculator.h
//  Calculator_C
//
//  Created by 唯赢 on 2018/5/10.
//  Copyright © 2018年 李立. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h

#include <stdio.h>
#include "String.h"
#include "Array.h"



typedef enum {
    OperatorUndefined,
    OperatorAdd,
    OperatorSub,
    OperatorMul,
    OperatorDiv,
} Operator;


/**
 计算节点
 */
typedef struct Node {
    double value;           // 节点值
    Operator opera;         // 运算方法
    struct Node *nodeList;  // 节点下属节点（列表）
} Node;


/**
 计算节点值

 @param node 节点指针
 @return 返回结果
 */
double compute(Node *node);

/**
 解析表达式

 @param exp 表达式
 @param node 节点
 */
void parseExpression(String exp, Node *node);




/**
 计算表达式的结果

 @param expression 表达式字符串
 @return 返回计算好的结果
 */
extern double evaluate(const String expression);

#endif /* Calculator_h */
