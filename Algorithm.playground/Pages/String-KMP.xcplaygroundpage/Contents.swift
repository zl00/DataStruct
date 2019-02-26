//: [Previous](@previous)

import Foundation

var str = "Hello, playground"

// MARK: - Util
extension String {
    subscript(index: Int) -> unichar {
       return (self as NSString).character(at: index)
    }
}

// MARK: - Sub string
extension String {
    var next: [Int] {
        guard self.count > 0 else { return [Int]() }
        
        var i = 0, j = -1
        var next = [Int](repeating: 0, count: self.count)
        next[i] = j
        
        while i < self.count - 1 {
            if j == -1 || self[i] == self[j] {
                i += 1
                j += 1
                next[i] = j
            } else {
                j = next[j]
            }
        }
        
        return next
    }
    
    var nextVal: [Int] {
        guard self.count > 0 else { return [Int]() }
        
        var i = 0, j = -1
        var nextval = [Int](repeating: 0, count: self.count)
        nextval[i] = j
        
        while i < self.count - 1 {
            if j == -1 || self[i] == self[j] {
                i += 1
                j += 1
                
                if self[i] != self[j] {
                    nextval[i] = j
                } else {
                    nextval[i] = nextval[j]
                }
            } else {
                j = nextval[j]
            }
        }
        return nextval
    }
}

// MARK: - Primary string
extension String {
    func search(_ sub: String, _ next: [Int]) -> Bool {
        var i = 0, j = 0
        
        while i < self.count && j < sub.count {
            if j == -1 || self[i] == sub[j] {
                i += 1
                j += 1
            } else {
                j = next[j]
            }
        }

        return j == sub.count
    }
}

let primary = "abcdadadaaddadcaadadadadadasdadasdadsadsadadaaddaa"
let sub = "aaaabc"

//primary.search(sub, sub.next)
primary.search(sub, sub.nextVal)
