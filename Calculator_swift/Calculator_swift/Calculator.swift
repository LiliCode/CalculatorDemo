//
//  Calculator.swift
//  Calculator_swift
//
//  Created by 唯赢 on 2018/5/9.
//  Copyright © 2018年 李立. All rights reserved.
//

import Foundation


enum OperatorType {
    case add, sub, mul, div
}

struct OperatorLevel {
    var opMode: OperatorType
    var level: Int = 0  // 数字越大，优先级越低
    
    var symbol: String {
        didSet {
            switch symbol {
            case "+":
                opMode = .add
                level = 1
            case "-":
                opMode = .sub
                level = 1
            case "*":
                opMode = .mul
                level = 0
            case "/":
                opMode = .div
                level = 0
            default:
                print("不能识别的运算符")
            }
        }
    }
}

/// 计算节点
struct Node {
    var level: OperatorLevel?   // 节点优先级
    var value: Double = 0.0     // 节点的值
    var nodeList: [Node] = []   // 节点下属节点列表
    
    /// 解析节点表达式
    ///
    /// - Parameter exp: 表达式参数
    mutating func parse(exp: String) -> Void {
        
    }
    
    /// 计算节点的值
    ///
    /// - Returns: 返回计算之后的节点值
    mutating func compute() -> Double {
        guard !nodeList.isEmpty else {
            return value    // 如果没有下属节点，那么就返回该节点的值
        }
        
        for var node in nodeList {
            if let l = node.level {
                switch l.opMode {
                case .add:
                    value += node.compute()
                case .sub:
                    value -= node.compute()
                case .mul:
                    value *= node.compute()
                case .div:
                    value /= node.compute()
                default:
                    value += Double(0)
                }
            }
        }
        
        return value
    }
}




class Calculator: NSObject {
    var lastReult: Double = 0.0
    
    static func evaluate(_ exp: String?) -> Double {
        if exp == nil {
            return Double(0)
        }
        
        var expression: String = exp!
        // 过滤空格
        if let r = expression.range(of: " ") {
            for index in r {
                expression.remove(at: index)
            }
        }
        
        // 主节点
        var mainNode = Node()
        // 解析节点
        mainNode.parse(exp: expression)
        // 几点节点
        return mainNode.compute()
    }
}








