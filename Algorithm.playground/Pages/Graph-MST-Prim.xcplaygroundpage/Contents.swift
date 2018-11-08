//: [Previous](@previous)

import Foundation

struct MGraph { // 自己到自己: .max
    let edges: [[Int]]
    let n, e: Int
}

func visit(b: Int, path: [Int], cost: [Int]) {
    guard path[b] != -1 else { print("Start: \(b)"); return }
    
    print("\(path[b]) -> \(b): \(cost[b])")
}

func Prim(g: MGraph) {
    var lowcost = [Int]()
    var path = [Int]() // 存放前驱
    var v = 0
    var vset = [Int]()
    
    for i in 0..<g.n {
        lowcost.append(g.edges[v][i])
        vset.append(0)
        path.append(g.edges[v][i] == .max ? -1: v)
    }
    
    vset[v] = 1
    path[v] = -1
    visit(b: v, path: path, cost: lowcost)
    
    for i in 0..<g.n-1 {
        var min = Int.max
        
        for j in 0..<g.n {
            guard vset[j] == 0, lowcost[j] < min else { continue }
            
            v = j
            min = lowcost[v]
        }
        
        vset[v] = 1
        visit(b: v, path: path, cost: lowcost)
        
        for j in 0..<g.n {
            guard vset[j] == 0, g.edges[v][j] < lowcost[j] else { continue }
            
            lowcost[j] = g.edges[v][j]
            path[j] = v
        }
    }
}

Prim(
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
