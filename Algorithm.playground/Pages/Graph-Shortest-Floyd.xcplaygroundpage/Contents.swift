import UIKit

struct VNode {
    let data: Int
}

struct MGraph {
    let edges: [[Int]]
    let n: Int
    let e: Int
}

func floyd(g: MGraph) {
    var A: [[Int]] = g.edges
    var path: [[Int]] = g.edges.map { row in
        row.map({ _ -> Int in
            return -1
        })
    }

    
    let K = [0, 1, 2, 3]
    let I = K, J = K
    
    K.forEach { k in
        I.forEach({ i in
            J.forEach({ j in
                if (A[i][k] != .max && A[k][j] != .max && A[i][j] > A[i][k] + A[k][j] && i != j && j != k) {
                    A[i][j] = A[i][k] + A[k][j]
                    path[i][j] = k
                }
            })
        })
        printMatrix(A)
    }
    printMatrix(path, seperator: "******************")
}

func printMatrix(_ m: [[Int]], seperator: String = "--------------------") {
    print(seperator)
    m.forEach { print($0.map { $0 == .max ? "∞" : $0 == -1 ? " " : "\($0)"} ) }
}

floyd(g: MGraph(
    edges: [
        [0,     5,      1,      .max],
        [.max,  0,      2,      1],
        [.max,  1,      0,      7],
        [.max,  .max,   .max,   0]
    ],
    n: 4,
    e: 6)
)

print("\n\n")

floyd(g: MGraph(
    edges: [
        [.max,      1,      3,      .max],
        [.max,      .max,   1,      3],
        [.max,      3,      .max,   1],
        [.max,      .max,   .max,   .max]
    ],
    n: 4,
    e: 6)
)
