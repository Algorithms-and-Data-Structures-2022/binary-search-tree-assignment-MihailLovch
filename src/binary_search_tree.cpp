#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key,value,root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* node = find(key,root_);
    if (node == nullptr) {
      return std::nullopt;
    }
    return node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    return Find(key) != std::nullopt;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    Node* node = find_min(root_);
    if (node == nullptr){
      return std::nullopt;
    }
    return node->key;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    Node* node = find_max(root_);
    if (node == nullptr){
      return std::nullopt;
    }
    return node->key;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr){
      node = new Node(key,value);
      return;
    }
    if (key > node->key){
      return insert(key,value,node->right);
    }
    if (key < node->key){
      return insert(key,value,node->left);
    }
    if (key == node->key){
      node->value = value;
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr){
      return false;
    }
    if (key > node->key){
      return remove(key,node->right);
    }
    if (key < node->key){
      return remove(key,node->left);
    }
    if (key == node->key){
      if (node->left == nullptr && node->right == nullptr){
        node = nullptr;
        return true;
      }
      if (node->right != nullptr && node->left != nullptr){
        Node* right_min = find_min(node->right);
        node->value = right_min->value;
        node->key = right_min->key;
        return remove(node->key, node->right);
      }
      if (node->left != nullptr){
        node = node->left;
        return true;
      }
      if (node->right != nullptr) {
        node = node->right;

        return true;
      }
    }
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (key == node->key){
      return node;
    }
    if (key > node->key){
      return find(key,node->right);
    }
    if (key < node->key){
      return find(key,node->left);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    while (node->left != nullptr){
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    while (node->right != nullptr){
      node = node->right;
    }
    return node;
  }

}  // namespace assignment