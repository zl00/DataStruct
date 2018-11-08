//: [Previous](@previous)

import Foundation

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
    let count: Int

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

func visit(g: AGraph, v: Int) {
    print("Index:\(v) \(g.adjlist[v].data)")
}

var vset = [Int].init(repeating: 0, count: 100)

func BFS(g: AGraph, v0: Int) {
    var que = [Int].init(repeating: -1, count: 100)
    var front = -1, rear = -1
    var p: ArcNode?
    
    rear += 1
    que[rear] = v0
    vset[v0] = 1
    
    while front != rear {
        front += 1
        let v = que[front]
        visit(g: g, v: v)
        
        p = g.adjlist[v].firstarc
        while p != nil {
            if vset[p!.adjvex] == 0 {
                rear += 1
                que[rear] = p!.adjvex
                vset[p!.adjvex] = 1
            }
            
            p = p?.nextarc
        }
        
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

BFS(
    g: AGraph(
        adjlist: [
            node0,
            node1,
            node2,
            node3,
            node4
        ],
        n: 5,
        e: 6
    ),
    v0: 0
)
