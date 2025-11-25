// include/storage/BTree.h
#pragma once
#include "storage/IDataStore.h"
#include <string>
#include <optional>
#include <memory>
#include <vector>

struct BTreeNode {
    bool isLeaf;
    std::vector<std::string> keys;
    std::vector<std::string> values;
    std::vector<std::shared_ptr<BTreeNode>> children;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
};

class BTree : public IDataStore {
public:
    explicit BTree(int t = 3);
    ~BTree() override = default;

    bool set(const std::string& key, const std::string value) override;
    const std::optional<std::string> get(const std::string key) override;
    bool del(const std::string key) override;

private:
    std::shared_ptr<BTreeNode> root;
    size_t min_degree_;

    void insertNonFull(std::shared_ptr<BTreeNode> node, const std::string key, const std::string value);
    void splitChild(std::shared_ptr<BTreeNode> parent, int index, std::shared_ptr<BTreeNode> child);
    std::optional<std::string> search(std::shared_ptr<BTreeNode> node, const std::string key);
    void remove(std::shared_ptr<BTreeNode> node, const std::string key);
    size_t size();
};
