#pragma once

#include "SQLiteCpp/SQLiteCpp.h"
#include "nativium/data/DatabaseFileData.hpp"
#include "nativium/data/Repository.hpp"
#include "nativium/data/RepositoryInfo.hpp"
#include "nativium/data/RepositoryTable.hpp"
#include "nativium/data/RepositoryView.hpp"

#include <filesystem>
#include <memory>

namespace nativium
{
namespace data
{

class RepositoryImpl : public Repository
{
public:
    RepositoryImpl();
    virtual ~RepositoryImpl() {}

    static std::shared_ptr<RepositoryImpl> internalSharedInstance();

    void open(const std::string &path) override;
    void test() override;
    void close() override;

    RepositoryInfo getInfo() override;
    std::string getSqliteVersion() override;
    std::vector<RepositoryTable> getTableList() override;
    std::vector<RepositoryView> getViewList() override;

private:
    static std::shared_ptr<RepositoryImpl> instance;
    std::filesystem::path dbPath;
    std::shared_ptr<SQLite::Database> db;
};

} // namespace data
} // namespace nativium
