//: [Previous](@previous)

import Foundation

// [wiki](https://www.cnblogs.com/chengxiao/p/6129630.html)
// 构造大顶堆

func HEAP(_ result: inout [Int], target: Int) {
    guard target >= 1 else { return }

    let left = 2*target+1, right = 2*target+2
    var isLeft = false, isRight = false
    
    if left < result.count, result[target] < result[left] {
        let tmp = result[target]
        result[target] = result[left]
        result[left] = tmp
        isLeft = true
    }
    
    if right < result.count, result[target] < result[right] {
        let tmp = result[target]
        result[target] = result[right]
        result[right] = tmp
        isRight = true
    }
    
    if isLeft && isRight {
        HEAP(&result, target: left)
        HEAP(&result, target: right)
    }
}

func HeapSort(_ input: [Int]) -> [Int] {
    var result = input
    
    var count = input.count
    var target = count/2-1
    
    while count >= 2 {
        HEAP(&result, target: target)
        
        let max = result[0]
        result[0] = result[count-1]
        result[count-1] = max
        
        count -= 1
        target = count/2-1
    }
    
    return result
}



print(HeapSort([49, 38, 65, 97, 13, 1, 129, 12]))
