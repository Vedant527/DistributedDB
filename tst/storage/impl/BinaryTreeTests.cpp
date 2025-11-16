#include "storage/impl/BinaryTree.h"
#include "storage/IDataStoreTestSuite.h"

class BinaryTreeTests : public IDataStoreTestSuite {
protected:
    std::unique_ptr<IDataStore> createDB() override {
        return std::make_unique<BinaryTree>();
    }
};

TEST_F(BinaryTreeTests, TestPutAndGet) {
    testPutAndGet();
}