//: [Previous](@previous)

import Foundation

struct VNode {
    let data: Int
}

struct MGraph {
    let edges: [[Int]]
    let n: Int
    let e: Int
}

/**
 @path: path[i] = j; path存放i的前驱
 */
func Dijkstra(g: MGraph, v: Int) -> (dist: [Int], path: [Int]) {
    var dist = [Int]()
    var path = [Int]()
    var set = [Int]()
    var u = 0
    
    // init
    for i in 0..<g.n {
        dist.append(g.edges[v][i])
        path.append(g.edges[v][i] == .max ? -1 : v)
        set.append(0)
    }
    
    set[v] = 1
    dist[v] = .max
    path[v] = -1
    
    //
    for _ in 0..<g.n-1 { // 选出剩余节点
        // 选出当前最短边
        var min = Int.max
        for j in 0..<g.n {
            if (set[j] == 0 && dist[j] < min) {
                u = j
                min = dist[j]
            }
        }
        set[u] = 1
        
        // 更新dist
        for j in 0..<g.n {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j]
                path[j] = u
            }
        }
    }
    
    return (dist: dist, path: path)
}

func printPath(path: [Int], a: Int) {
    var stack = [Int](repeating: -1, count: 100)
    var top = -1
    
    var iter = a
    
    while path[iter] != -1 {
        top += 1
        stack[top] = iter
        iter = path[iter]
    }
    top += 1
    stack[top] = iter
    while top >= 0 {
        print(stack[top])
        top -= 1
    }
}


let result = Dijkstra(
    g: MGraph(
        edges: [
            [0,     5,      1,      .max],
            [.max,  0,      2,      1],
            [.max,  1,      0,      7],
            [.max,  .max,   .max,   0]
        ],
        n: 4,
        e: 6),
    v: 0
)

print(result)

printPath(path: result.path, a: 3)
