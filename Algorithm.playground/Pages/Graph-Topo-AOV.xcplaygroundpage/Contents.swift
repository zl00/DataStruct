//: [Previous](@previous)

import Foundation

// Activity Of Vertex

class ArcNode {
    let adjvex: Int
    let nextarc: ArcNode?
    
    init(adjvex: Int, nextarc: ArcNode?) {
        self.adjvex = adjvex
        self.nextarc = nextarc
    }
}

class VNode {
    let data: String
    let firstarc: ArcNode?
    var count: Int
    
    init(data: String, firstarc: ArcNode?, count: Int) {
        self.data = data
        self.firstarc = firstarc
        self.count = count
    }
}

class AGraph {
    let adjlist: [VNode]
    let n: Int
    let e: Int
    
    init(adjlist: [VNode], n: Int, e: Int) {
        self.adjlist = adjlist
        self.n = n
        self.e = e
    }
}

func TopoSort(g: AGraph) -> Bool {
    var n = 0
    var stack = [Int](repeating: -1, count: 100)
    var top = -1
    
    g.adjlist.enumerated().forEach { // ⚠️找出所有入度为0
        guard $0.element.count == 0 else { return }
        top += 1
        stack[top] = $0.offset
    }
    
    guard top != -1 else { return false }
    
    while top != -1 {
        let v = stack[top]
        top -= 1
        print("V(\(v)) \(g.adjlist[v].data)")
        n += 1
        
        var adjedge = g.adjlist[v].firstarc
        while adjedge != nil {
            g.adjlist[adjedge!.adjvex].count -= 1
            if g.adjlist[adjedge!.adjvex].count == 0 {
                top += 1
                stack[top] = adjedge!.adjvex
            }
            adjedge = adjedge?.nextarc
        }
    }
    
    return n == g.e
}

var stack = [Int].init(repeating: -1, count: 100)
var top = -1
var vsetr = [Int].init(repeating: 0, count: 100)
var sum = 0

func DFS(g: AGraph, v0: Int) {
    guard sum <= g.n else { return }
    
    top += 1
    stack[top] = v0
    vsetr[v0] = 1
    
    var p = g.adjlist[v0].firstarc
    var b = false
    while p != nil {
        if vsetr[p!.adjvex] == 0 {
            DFS(g: g, v0: p!.adjvex)
            b = true
        }
        p = p!.nextarc
    }
    
    if !b {
        var v = stack[top]
        top -= 1
        let vnode = g.adjlist[v]
        print("V.(\(v)) \(vnode.data)")
        sum += 1
        
        if top >= 0 {
            v = stack[top]
            vsetr[v] = 0
            top -= 1
            if top >= 0 {
                DFS(g: g, v0: v)
            }
        }
    }
 
}

func rTopoSort(g: AGraph) {
    DFS(g: g, v0: 0)
    while top != -1 {
        let i = stack[top]
        top -= 1
        print("V\(i) \(g.adjlist[i].data)")
    }
}

let arc3 = ArcNode.init(adjvex: 3, nextarc: nil)
let arc2 = ArcNode.init(adjvex: 2, nextarc: arc3)
let arc1 = ArcNode.init(adjvex: 1, nextarc: arc2)
let arc4 = ArcNode.init(adjvex: 4, nextarc: nil)
let arc5 = ArcNode.init(adjvex: 4, nextarc: nil)
let arc6 = ArcNode.init(adjvex: 4, nextarc: nil)
let node0 = VNode.init(data: "原材料", firstarc: arc1, count: 0)
let node1 = VNode.init(data: "部件1", firstarc: arc4, count: 1)
let node2 = VNode.init(data: "部件2", firstarc: arc5, count: 1)
let node3 = VNode.init(data: "部件3", firstarc: arc6, count: 1)
let node4 = VNode.init(data: "成品", firstarc: nil, count: 3)


let g = AGraph(
    adjlist: [
        node0,
        node1,
        node2,
        node3,
        node4
    ],
    n: 5,
    e: 6
)

TopoSort(g:g)

rTopoSort(g: g)

