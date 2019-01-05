//: [Previous](@previous)

import Foundation

// [wiki](https://www.cnblogs.com/chengxiao/p/6129630.html)

func swap(_ result: inout [Int], i: Int, j: Int) {
    let tmp = result[i]
    result[i] = result[j]
    result[j] = tmp
}

func sift(_ result: inout [Int], low: Int, high: Int) {
    var i = low
    var j = 2 * i + 1 // left
    
    while j <= high {
        if j + 1 <= high, result[j] < result[j+1] { j += 1 } // fetch the bigger leaf
        
        guard result[i] < result[j] else { break }
        
        swap(&result, i: i, j: j)
        
        i = j
        j = 2 * i + 1
    }
}

func HeapSort(_ result: inout [Int]) {
    // 建立堆
    var low = result.count / 2 - 1
    while low >= 0 {
        sift(&result, low: low, high: result.count - 1)
        low -= 1
    }
    
    var i = result.count - 1
    while i > 0 {
        swap(&result, i: 0, j: i) // heap[0]: 最大的数，将其交换到heap的尾部。
        sift(&result, low: 0, high: i-1) // 此时的堆除了[0]，其余都是排序好的。所以只需要sift一轮即可。
        i -= 1
    }
}

var arr = [49, 38, 65, 97, 13, 1, 129, 12]
HeapSort(&arr)
print(arr)

