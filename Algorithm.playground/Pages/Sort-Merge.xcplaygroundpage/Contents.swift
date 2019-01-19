//: [Previous](@previous)

import Foundation

func mergeSort(_ input: inout [Int], _ low: Int, _ high: Int) {
    guard low < high else { return }
    
    let mid = (low + high) / 2
    
    mergeSort(&input, low, mid)
    mergeSort(&input, mid + 1, high)
    merge(&input, low, mid, high)
}

func merge(_ input: inout [Int], _ low: Int, _ mid: Int, _ high: Int) {
    guard low < high else { return }
    
    print("merge")
    var i = low, j = mid + 1
    var temp = [Int]()
    
    // prior to append the smaller ones
    while i <= mid, j <= high {
        if input[i] < input[j] {
            temp.append(input[i])
            i += 1
        } else {
            temp.append(input[j])
            j += 1
        }
    }
    
    // handle remains
    while i <= mid {
        temp.append(input[i])
        i += 1
    }
    
    // handle remains
    while j <= high {
        temp.append(input[j])
        j += 1
    }
    
    // rewrite into `input` array
    var k = low
    while k <= high {
        input[k] = temp[k-low]
        k += 1
    }
}

var arr = [49, 38, 65, 97, 13, 1, 129, 12, 132, 12, 38, 13, 49, 38, 65, 97, 13, 1, 129, 12, 132, 12, 38, 13]
mergeSort(&arr, 0, arr.count-1)
print(arr)
