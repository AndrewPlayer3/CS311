// Andrew Player, Robert Lawton, Gannon Higgins
// CS311 - Project 7
// 11/16/2020
// Header for Project 7

#ifndef _TREESORT_H_
#define _TREESORT_H_

#include <vector>

template<typename T>
class Node {
    public: 
        T key;
        
        Node<T>* right;
        Node<T>* left;

        Node()
            : key(0), right(nullptr), left(nullptr) {}

        Node(const T& value)
            : key(value), right(nullptr), left(nullptr) {}
};


// Invariants:
//  Value Type must have operator< defined.
template<typename T>
class BSTree {
// Member Types:
public:
    typedef T value_type;

// Member Variables
public:
    Node<value_type>* root;

// Constructors and Destructors
public:
    // Default Constructor
    // Guarantee: Strong
    // Preconditions: None
    BSTree() :
        root(nullptr) {}

    // Value Constructor
    // Guarantee: Strong
    // Preconditions: None
    BSTree(value_type key) :
        root(new Node<value_type>(key)) {}

    ~BSTree() {delete_tree(root);}

// Member Functions
public:
    // Delete all the nodes in the tree
    // Guarantee: Basic
    // Preconditions: None
    void delete_tree(Node<value_type>* current) {
        if(current == nullptr) return;
        delete_tree(current->left);
        delete_tree(current->right);
        delete(current);
    }
    
    // Wrapper for insert data
    // Guarantee: Strong
    // Preconditions: None
    void insert(const value_type& key);
    
    // Insert data into the proper location in the tree
    // Guarantee: Strong
    // Preconditions: None
    Node<value_type>* insert(
        Node<value_type>* node,
        const value_type& key
    );
};

template<typename value_type>
void BSTree<value_type>::insert(const value_type& key) {
    if(root == nullptr) {
        root = new Node<value_type>(key);
    } else {
        root = insert(root, key);
    }
}


template<typename value_type>
Node<value_type>* BSTree<value_type>::insert(
    Node<value_type>* node,
    const value_type& key
) {

    if(!node) return new Node<value_type>(key);

    if(node->key < key || !(key < node->key)) {
        node->right = insert(node->right, key);
    } else {
        node->left = insert(node->left, key);
    }

    return node;
}


// Insert data into the proper location in the tree
// Guarantee: Strong
// Preconditions: None
template<typename value_type, typename FDIter>
void traverse_to_range(Node<value_type>* node, FDIter& first) {
    if(node == nullptr) return;
    traverse_to_range(node->left, first);
    *first++ = node->key;
    traverse_to_range(node->right, first);
}


// Insert data into the proper location in the tree
// Guarantee: Strong
// Preconditions: None
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Value is the type that FDIter points to
    using Value = typename std::iterator_traits<FDIter>::value_type;

    std::vector<Value> buff(std::distance(first, last));
    std::move(first, last, buff.begin());
    BSTree<Value> tree;
    for(Value v : buff) {
        tree.insert(v);
    }
    traverse_to_range(tree.root, first);
}

#endif
