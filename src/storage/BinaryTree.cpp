#include <storage/impl/BinaryTree.h>
#include <string>
#include <iostream>
#include <optional>
#include <memory>

BinaryTree::BinaryTree() : root(nullptr) {}

// PUBLIC METHODS

bool BinaryTree::set(const std::string& key, const std::string& value) {
    return insert(std::move(key), std::move(value));
}

const std::optional<std::string> BinaryTree::get(const std::string& key) {
    return search(std::move(key));
}

bool BinaryTree::del(const std::string& key) {
    return remove(std::move(key));
}

// PROTECTED METHODS

bool BinaryTree::insert(
    const std::string& key, 
    const std::string& value
) {
    std::shared_ptr<BinaryTreeNode> node = std::make_unique<BinaryTreeNode>(false, std::move(key), std::move(value));

    if (!size_) {
        root = node;
    } else {
        std::shared_ptr<BinaryTreeNode> c = root;
        while (true) {
            auto diff = key.compare(c -> key);
            if (diff == 0) {
                c -> value = value;
                return true;
            } else if (diff > 0) {
                if (c -> right) {
                    c = c -> right;
                    continue;
                } else {
                    c -> right = node;
                    break;
                }
            } else {
                if (c -> left) {
                    c = c -> left;
                    continue;
                } else {
                    c -> left = node;
                    break;
                }
            }
        }

    }
    size_++;
    return true;
}

bool BinaryTree::remove(const std::string& key) {
    bool removed = false;
    root = removeNode(root, key, removed);
    if (removed) size_--;
    return removed;
}

const std::optional<std::string> BinaryTree::search(const std::string& key) {
    if (!size_) return std::nullopt;

    std::shared_ptr<BinaryTreeNode> c = root;
    while (c) {
        auto diff = c -> key.compare(key);
        if (diff == 0) {
            return c -> value;
        } else if (diff > 0) {
            c = c -> right;
            continue;
        } else {
            c = c -> left;
            continue;
        }
    }

    return std::nullopt;
}

// PRIVATE METHODS

const std::shared_ptr<BinaryTreeNode> BinaryTree::removeNode(
    std::shared_ptr<BinaryTreeNode> node,
    const std::string& key,
    bool& removed
) {
    if (!node) return nullptr;

    auto diff = key.compare(node->key);

    if (diff < 0) {
        node->left = removeNode(node->left, key, removed);
    } else if (diff > 0) {
        node->right = removeNode(node->right, key, removed);
    } else {
        removed = true;

        if (!node->left && !node->right)
            return nullptr;

        if (!node->left)
            return node->right;
        if (!node->right)
            return node->left;

        std::shared_ptr<BinaryTreeNode> succ = node->right;
        while (succ->left)
            succ = succ->left;

        node->key = succ->key;
        node->value = succ->value;
        node->right = removeNode(node->right, succ->key, removed);
    }

    return node;
}
