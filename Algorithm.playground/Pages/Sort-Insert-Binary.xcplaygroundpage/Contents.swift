//: [Previous](@previous)

import Foundation

/**
 时间复杂度 o(n*log₂ⁿ)
 空间复杂度 o(1)
 */
func binaryInsertSort(_ input: [Int]) -> [Int] {
    guard input.count > 1 else { return input }
    
    print("----0: \(input)")
    
    var result = input
    
    for i in 1..<input.count {
        var L = 0, R = i - 1, M = (L + R) / 2
        
        let tmp = result[i]
        let insert: Int
        
        repeat {
            M = (L+R) / 2
            
            if tmp < result[M] {
                R = max(M - 1, L)
            } else if tmp > result[M] {
                L = min(M + 1, R)
            } else {
                assert(false)
            }
        } while L != R
        
        print("\n\(i) -- \(L) \(R)")
        
        if tmp < result[L] {
            insert = L
        } else {
            insert = L + 1
        }
        
        var j = i
        while j > insert {
            result[j] = result[j-1]
            j -= 1
        }
        result[insert] = tmp
        print("----\(i): \(result)")
    }
    
    return result
}

print(binaryInsertSort([49, 38, 65, 97, 13, 1, 129, 12]))
