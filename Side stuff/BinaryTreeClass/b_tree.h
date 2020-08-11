#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template<class TypeValue>
class binary_tree{
    struct Node{
        TypeValue value;
        Node* next_r;
        Node* next_l;
        Node* prev;
    };
    Node *head;
public:
    typedef Node* leaf;
    binary_tree();
    ~binary_tree();
    //-------------Placement-------------
    leaf insert_c(leaf,TypeValue);
    leaf insert_l(leaf,TypeValue);
    leaf insert_r(leaf,TypeValue);
    //-------------Navigation-------------
    std::pair<leaf,bool> back(leaf);
    leaf goto_head();
    std::pair<leaf,bool> goto_left(leaf);
    std::pair<leaf,bool> goto_right(leaf);
    //-------------Value-------------
    TypeValue get_value(leaf);
    //-------------Destruction-------------
    void destroy_current(leaf);


private:
    Node* create_Node();
    Node* create_Node(TypeValue);
    void destroy(Node*);
    std::pair<leaf,bool> go_to(leaf,char);
    void insert(Node**,TypeValue);
};


#endif //BINARY_TREE_H
