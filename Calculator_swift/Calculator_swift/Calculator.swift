//
//  Calculator.swift
//  Calculator_swift
//
//  Created by 唯赢 on 2018/5/9.
//  Copyright © 2018年 李立. All rights reserved.
//

import Foundation


let operatorList: [String] = ["+", "-", "*", "/"]


enum OperatorType {
    case add, sub, mul, div, undefined
}

struct OperatorLevel {
    var opMode: OperatorType = OperatorType.undefined
    var level: Int = 0  // 数字越大，优先级越低
    var symbol: String = String()
    
    init(symbol: String) {
        self.symbol = symbol
        
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
            opMode = .undefined
            level = Int.max
        }
    }
}

/// 计算节点
struct Node {
    var level: OperatorLevel?   // 节点优先级
    var value: Double = 0.0     // 节点的值
    var nodeList: [Node] = []   // 节点下属节点列
    
    /// 解析节点表达式
    ///
    /// - Parameter exp: 表达式参数
    mutating func parse(expression: String) -> Void {
//        print("expression = \(expression)")
        // 检测是否包含运算符
        let isContains = expression.contains { (char) -> Bool in
            return operatorList.contains(String(char))
        }
        
        if !isContains {
            // 不包含运算符就直接转换这个值
            if let value = Double(expression) {
                self.value = value
            } else {
                self.value = Double(0)
            }
            
            return
        }
        
        // 拆分规则：先加减，后乘除
        var exps: [String] = []
        var opSymbol: String = String()
        
        for op in operatorList {
            if expression.contains(op) {
                self.level = OperatorLevel(symbol: op)
                opSymbol = op
                break
            }
        }
        
        exps = expression.components(separatedBy: CharacterSet(charactersIn: opSymbol))
        for exp in exps {
            var node = Node()
            node.parse(expression: exp)
            self.nodeList.insert(node, at: self.nodeList.endIndex)
        }
    }
    
    /// 计算节点的值
    ///
    /// - Returns: 返回计算之后的节点值
    mutating func compute() -> Double {
        guard !nodeList.isEmpty else {
            return value    // 如果没有下属节点，那么就返回该节点的值
        }
        
        for index in 0 ..< nodeList.count {
            var node = nodeList[index]
            if index == 0 {
                value = node.compute()  // 将节点列表的第一个节点的值赋值给当前节点的值
                continue
            }
            
            if let l = self.level {
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
        
        if exp!.isEmpty {
            return Double(0)
        }
        
        // 过滤空格
        let expression: NSMutableString = NSMutableString(string: exp!)
        var r = expression.range(of: " ")
        while r.location != NSNotFound {
            expression.deleteCharacters(in: r)
            r = expression.range(of: " ")
        }
        
        // 主节点
        var mainNode = Node()
        // 解析节点
        mainNode.parse(expression: expression as String)
        // 计算节点
        return mainNode.compute()
    }
}








