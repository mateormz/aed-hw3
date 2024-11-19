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
    Node** current = &root;
    while (*current) {
        if (value < (*current)->data)
            current = &((*current)->left);
        else if (value > (*current)->data)
            current = &((*current)->right);
        else
            return; // El valor ya está en el árbol.
    }
    *current = new Node(value);
    ++nodeCount;
}

template <typename T>
bool BST<T>::search(T const& value) const {
    Node* current = root;
    while (current) {
        if (value == current->data)
            return true;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

template <typename T>
void BST<T>::remove(T const& value) {
    Node** current = &root;
    while (*current && (*current)->data != value) {
        if (value < (*current)->data)
            current = &((*current)->left);
        else
            current = &((*current)->right);
    }

    if (!*current)
        return; // El valor no se encontró.

    Node* target = *current;
    if (!target->left) {
        *current = target->right;
    } else if (!target->right) {
        *current = target->left;
    } else {
        Node** minParent = &(target->right);
        Node* minNode = target->right;
        while (minNode->left) {
            minParent = &(minNode->left);
            minNode = minNode->left;
        }
        target->data = minNode->data;
        *minParent = minNode->right;
        target = minNode;
    }

    delete target;
    --nodeCount;
}

template <typename T>
size_t BST<T>::size() const {
    return nodeCount;
}

template <typename T>
T BST<T>::findMin() const {
    if (isEmpty()){
        std::cout << "Tree empty";
    }
    Node* current = root;
    while (current->left)
        current = current->left;
    return current->data;
}

template <typename T>
T BST<T>::findMax() const {
    if (isEmpty()){
        std::cout << "Tree empty";
    }
    Node* current = root;
    while (current->right)
        current = current->right;
    return current->data;
}

template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
    while (!isEmpty()) {
        remove(root->data);
    }
}


#endif
