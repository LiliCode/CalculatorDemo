//
//  Calculator.c
//  Calculator_C
//
//  Created by 唯赢 on 2018/5/10.
//  Copyright © 2018年 李立. All rights reserved.
//

#include "Calculator.h"

void parseExpression(String exp, Node *node) {
    if (!exp || !node) {
        return;
    }
    
}

double compute(Node *node) {
    if (!node) {
        return .0f;
    }
    
    if (!node->nodeList) {
        return node->value;
    }
    
    
    
    return .0f;
}

double evaluate(const String expression) {
    if (!expression) {
        return .0f;
    }
    
    
    
    
    return .0f;
}



