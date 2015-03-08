#ifndef __graph_h__
#define __graph_h__

#include <unordered_map>
#include "node.h"

class Graph {
private:
    std::unordered_map<int, Node *> m_adj_lst;
public:
    ~Graph();
    void AddNode(Node * n);
    void AddEdge(Node * n1, Node * n2);
    void BFS();
    void DFS(Node * n, std::unordered_map<int, Node *> visited);
};

#endif
