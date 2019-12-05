//: [Previous](@previous)

import Foundation

// [wiki](https://www.cnblogs.com/chengxiao/p/6129630.html)

/**
 `Sift`: 这个函数名字很精妙，Sift本意是“筛”这个动作。
 因此，我所建立的思维模型如下：
 - defs:
    1. 有序树（平衡二叉树--饱和），有序是指--子节点比父节点小。
    2. Sift函数的含义是，将low这个节点筛到合适的位置。
    3. 外部调用Sift函数建立平衡二叉树时，必须从最后一个父节点开始sift，这样才能保证层层调用sift后，得到一棵平衡二叉树。
 */
func sift(_ result: inout [Int], low: Int, high: Int) {
    var i = low
    var j = 2 * i + 1 // left
    
    while j <= high {
        if j + 1 <= high, result[j] < result[j+1] { j += 1 } // fetch the bigger leaf
        
        guard result[i] < result[j] else { break }
        
        swap(&result, i: i, j: j) // 交换之后i位置元素是正确的了，但j位置就可能不正确了，所以才会继续筛
        
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

func swap(_ result: inout [Int], i: Int, j: Int) {
    let tmp = result[i]
    result[i] = result[j]
    result[j] = tmp
}

var arr = [49, 38, 65, 97, 13, 1, 129, 12]
HeapSort(&arr)
print(arr)

