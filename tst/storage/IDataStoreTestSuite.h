#ifndef IDATASTORETESTSUITE_H
#define IDATASTORETESTSUITE_H

#include <gtest/gtest.h>
#include "storage/IDataStore.h" 
class IDataStoreTestSuite : public testing::Test {
protected:
    std::unique_ptr<IDataStore> db;

    virtual std::unique_ptr<IDataStore> createDB() = 0;
    void SetUp() {
        db = createDB();
        ASSERT_NE(db, nullptr);
    } 

    void testPutAndGet() {
        const std::string key = "key1";
        const std::string value = "value1";
        db->set(key, value);
        EXPECT_EQ(db->get(key), value);
    }
};

#endif
