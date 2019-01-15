//: [Previous](@previous)

import Foundation

/**
 时间：o(n²)
 空间：o(1)
 */
func SelectSort(_ input: [Int]) -> [Int] {
    let n = input.count
    var result = input
    var k: Int
    
    for i in 0..<n { // i 即将插入的位置
        k = i
        
        // k 此轮循环最小数字
        for j in i+1..<n {
            if result[j] < result[k] { k = j }
        }
        
        let temp = result[i]
        result[i] = result[k]
        result[k] = temp
    }
    
    return result
}

print(SelectSort([49, 38, 65, 97, 13, 1, 129, 12]))
