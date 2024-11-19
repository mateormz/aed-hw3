#ifndef HW3_IMPL_H
#define HW3_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw3.h"

template <typename T>
BST<T>::BST() : root(nullptr), nodeCount(0) {}

template <typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
void BST<T>::insert(T const& value) {
  auto insertHelper = [](Node*& node, T const& value) -> Node* {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insertHelper(node->left, value);
        else if (value > node->data) node->right = insertHelper(node->right, value);
        return node; // No inserta duplicados
    };
    root = insertHelper(root, value);
    ++nodeCount;
}

template <typename T>
bool BST<T>::search(T const& value) const {
  auto searchHelper = [](Node* node, T const& value) -> bool {
        if (!node) return false;
        if (value < node->data) return searchHelper(node->left, value);
        else if (value > node->data) return searchHelper(node->right, value);
        return true;
    };
    return searchHelper(root, value);
}

template <typename T>
void BST<T>::remove(T const& value) {
  auto removeHelper = [](Node*& node, T const& value) -> Node* {
        if (!node) return nullptr;
        if (value < node->data) node->left = removeHelper(node->left, value);
        else if (value > node->data) node->right = removeHelper(node->right, value);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = node->right;
                while (successor->left) successor = successor->left;
                node->data = successor->data;
                node->right = removeHelper(node->right, successor->data);
            }
        }
        return node;
    };
    root = removeHelper(root, value);
    --nodeCount;
}

template <typename T>
size_t BST<T>::size() const {
  return nodeCount;
}

template <typename T>
T BST<T>::findMin() const {
  if (!root) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->left) current = current->left;
    return current->data;
}

template <typename T>
T BST<T>::findMax() const {
  if (!root) throw std::runtime_error("Tree is empty");
    Node* current = root;
    while (current->right) current = current->right;
    return current->data;
}

template <typename T>
bool BST<T>::isEmpty() const {
  return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
  auto clearHelper = [](Node*& node) {
        if (!node) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
        node = nullptr;
    };
    clearHelper(root);
    root = nullptr;
    nodeCount = 0;
}


#endif