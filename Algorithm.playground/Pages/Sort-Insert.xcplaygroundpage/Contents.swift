//: [Previous](@previous)

import Foundation

func InsertSort(_ input: [Int]) -> [Int] {
    guard input.count > 1 else { return input }
    
    var result = input

    for i in 1..<result.count {
        let toInsert = result[i]
        
        var j = i - 1
        while j >= 0, toInsert < result[j] {
            result[j+1] = result[j]
            j -= 1
        }
        result[j+1] = toInsert
    }
    
    return result
}

print(InsertSort([49, 38, 65, 97, 13, 1, 129, 12]))
