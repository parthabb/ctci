#include <iostream>
#include <utility>
#include "graph.h"

void Graph::AddNode(Node * n) {
    if (m_adj_lst.count(n->GetVal())) {
        std::cout << "Node already exists!!" << std::endl;
        return;
    }
    m_adj_lst.insert({n->GetVal(), n});
}

void Graph::AddEdge(Node * n1, Node * n2) {
    std::vector<Node *> temp = m_adj_lst[n1->GetVal()]->GetChildren();
    for (int j = 0; j < temp.size(); j++) {
        if (n2 == temp[j]) {
            std::cout << "Edge already exists!!" << std::endl;
            return;
        }
    }
    n1->AddChild(n2);
}

void Graph :: BFS () {
    
}

void Graph :: DFS (Node * n, std::unordered_map<int, Node *> visited) {
}

Graph :: ~Graph() {
    std::cout << "Graph destructor" << std::endl;
    for (std::pair<int, Node *> n: m_adj_lst) {
        Node * temp = n.second;
        if (temp != 0) delete temp;
    }
}