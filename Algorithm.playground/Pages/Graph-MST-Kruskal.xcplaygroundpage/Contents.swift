//: [Previous](@previous)

import Foundation

// MARK: - 并查集
struct DisjointSet {
    init(num: Int) {
        for i in 0..<num { set.append(i) }
    }
    
    func root(i: Int) -> Int {
        var r = i
        while (r != set[r]) { r = set[r] }
        return r
    }
    
    /**
     存放的是:该index节点对应的前驱.
     根节点的前驱是自己
     */
    var set = [Int]()
}

struct MGraph {
    let edges: [[Int]]
    let n: Int
    let e: Int
    
    struct Road {
        let a, b: Int
        let w: Int
    }
    
    var sortedRoads: [Road] {
        var results = [Road]()
        
        edges.enumerated().forEach { (arg) in let a = arg.offset, row = arg.element
            row.enumerated().forEach { (arg) in let b = arg.offset, w = arg.element
                results.append(Road.init(a: a, b: b, w: w))
            }
        }
        
        return results.sorted { $0.w < $1.w }
    }
}


// return sum
func Kruskal(g: MGraph) -> Int {
    var sum = 0
    var disjointSet = DisjointSet(num: g.n)
    let roads = g.sortedRoads
    
    var mst = [MGraph.Road]()
    
    roads.forEach { r in
        let a = disjointSet.root(i: r.a)
        let b = disjointSet.root(i: r.b)
        guard a != b else { return } // 非同宗
        
        disjointSet.set[b] = a
        sum += r.w
        
        mst.append(r)
    }
    
    mst.forEach { print("w(\($0.w)): \($0.a) -> \($0.b)") }
    return sum
}


Kruskal(
    g: MGraph(
    edges: [
        [.max,     1,      3,      15],
        [.max,  .max,      .max,      3],
        [.max,  .max,      .max,      2],
        [.max,  .max,   .max,   .max]
    ],
    n: 4,
    e: 6)
)
