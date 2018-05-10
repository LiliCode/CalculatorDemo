//
//  main.c
//  Calculator_C
//
//  Created by 唯赢 on 2018/5/10.
//  Copyright © 2018年 李立. All rights reserved.
//

#include <stdio.h>
#include "Calculator.h"

void print(Any value) {
    printf("%d", *((int *)value));
}

int main(int argc, const char * argv[])
{
    
    String exp = "2 * 7 - 4";
    double result = evaluate(exp);
    printf("%s = %lg\n", exp, result);
    
    int initValue = 3;
    ListNode *mainNode = allocNode(&initValue);
//    for (int i = 0; i < 5; i++) {
//        int value = i;
//        ListNode *node = allocNode(&value);
//        insertNode(mainNode, node);
//    }
    
    int value1 = 5;
    ListNode *node = allocNode(&value1);
    insertNode(mainNode, node);
    
    int value2 = 4;
    ListNode *node2 = allocNode(&value2);
    insertNode(mainNode, node2);
    
    show(mainNode, print);
    deleteAllNode(mainNode);
    
    return 0;
}






