#include <storage/impl/BTree.h>
#include <string>
#include <optional>

BTree::BTree(int t) : min_degree_(t), root(nullptr) {}
