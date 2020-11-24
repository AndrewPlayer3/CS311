// Andrew Player
// CS311 - Project 7
// 11/16/2020
// Header for Project 7

#ifndef _TREESORT_H_
#define _TREESORT_H_

#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <algorithm>

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
    void insert(
        const value_type& key
    );
    
    // Insert data into the proper location in the tree
    // Guarantee: Strong
    // Preconditions: None
    Node<value_type>* insert(
        Node<value_type>* node,
        const value_type& key
    );

    // Wrapper for In-Order Traversal of the Binary Tree
    // Guarantee: Strong
    // Preconditions: None
    void traverse() {traverse(root);}

    // In-Order Traversal of the Binary Tree
    // Guarantee: Strong
    // Preconditions: None
    void traverse(Node<value_type>* node);

    // Wrapper for In-Order Traversal of the Binary Tree
    // Guarantee: Strong
    // Preconditions: None
    void traverse_to_vec(std::vector<value_type>& vec) {
        traverse_to_vec(root, vec);
    }

    // In-Order Traversal of the Binary Tree
    // Guarantee: Strong
    // Preconditions: None
    void traverse_to_vec(Node<value_type>* node, std::vector<value_type>& vec);

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

    if(node->key < key) {
        node->right = insert(node->right, key);
    } else {
        node->left = insert(node->left, key);
    }

    return node;
}

template<typename value_type>
void BSTree<value_type>::traverse(Node<value_type>* node) {
    if(node == nullptr) return;
    traverse(node->left);
    std::cout << node->key << std::endl;
    traverse(node->right);
}

template<typename value_type>
void BSTree<value_type>::traverse_to_vec(Node<value_type>* node, std::vector<value_type>& vec) {
    if(node == nullptr) return;
    traverse_to_vec(node->left, vec);
    vec.push_back(node->key);
    traverse_to_vec(node->right, vec);
}

template<typename value_type, typename FDIter>
void traverse_to_range(Node<value_type>* node, FDIter& first) {
    if(node == nullptr) return;
    traverse_to_range(node->left, first);
    *first++ = node->key;
    traverse_to_range(node->right, first);
}

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
