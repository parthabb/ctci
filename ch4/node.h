#ifndef __node_h__
#define __node_h__

#include <vector>

class Node {
private:
    int m_val;
protected:
    std::vector<Node *> m_children;
public:
    Node ();
    ~Node();
    void SetVal(int val);
    int GetVal();
    void AddChild(Node *);
    std::vector <Node *> GetChildren();
};

#endif
