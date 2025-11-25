#pragma once
#include <string>
#include <optional>
#include <memory>
#include <storage/IDataStore.h>

struct BinaryTreeNode {
    bool is_leaf;
    std::string key;
    std::string value;
    std::shared_ptr<BinaryTreeNode> left;
    std::shared_ptr<BinaryTreeNode> right;

    BinaryTreeNode(bool leaf, std::string key, std::string value) : is_leaf(leaf), key(key), value(value) {}
};

class BinaryTree : public IDataStore {
public:
    explicit BinaryTree();
    ~BinaryTree() override = default;

    bool set(const std::string key, const std::string value) override;
    const std::optional<std::string> get(const std::string key) override;
    bool del(const std::string key) override;

protected:
    bool insert(const std::string key, const std::string value) override;
    bool remove(const std::string key) override;
    const std::optional<std::string> search(const std::string key) override;

private:
    std::shared_ptr<BinaryTreeNode> root;
    
    const std::shared_ptr<BinaryTreeNode> removeNode(
        std::shared_ptr<BinaryTreeNode> node,
        const std::string key,
        bool& removed
    );
};