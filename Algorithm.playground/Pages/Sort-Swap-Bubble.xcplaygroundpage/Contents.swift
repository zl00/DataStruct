//: [Previous](@previous)

import Foundation

func bubbleSort(_ input: [Int]) -> [Int] {
    guard input.count >= 2 else { return input }
    
    var result = input
    
    var i = result.count - 1
    
    repeat {
        var max: Int?
        
        /**
         一轮冒泡
         根据a < b, b < c... <传递性，所以max不存在时则排序结束
         */
        var j = 1
        repeat {
            
            if result[j-1] > result[j] {
                max = result[j-1]
                result[j-1] = result[j]
                result[j] = max!
            }
            
            j += 1
        } while j <= i
        
        guard let _ = max else { break }
        
        i -= 1
    } while i > 0
    
    return result
}

print(bubbleSort([49, 38, 65, 97, 13, 1, 129, 12]))
