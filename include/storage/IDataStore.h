#pragma once
#include <string>
#include <optional>

class IDataStore {
public:
    virtual ~IDataStore() = default;

    virtual bool set(const std::string& key, const std::string& value) = 0;
    virtual bool del(const std::string& key) = 0;
    virtual const std::optional<std::string> get(const std::string& key) = 0;
    virtual size_t size() const { return size_; }

protected:
    size_t size_ = 0;

    virtual bool insert(const std::string& key, const std::string& value) = 0;
    virtual bool remove(const std::string& key) = 0;
    virtual const std::optional<std::string> search(const std::string& key) = 0;
};