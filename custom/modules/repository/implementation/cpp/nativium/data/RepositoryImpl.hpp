#pragma once

#include "SQLiteCpp/SQLiteCpp.h"
#include "nativium/data/Repository.hpp"
#include "nativium/data/RepositoryColumn.hpp"
#include "nativium/data/RepositoryInfo.hpp"
#include "nativium/data/RepositoryRows.hpp"
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
    std::vector<RepositoryColumn> getColumns(const std::string &name) override;
    RepositoryRows getRows(const std::string &name, const std::string &sortBy, bool descending, int32_t page, int32_t rowsPerPage) override;

private:
    static std::shared_ptr<RepositoryImpl> instance;
    std::filesystem::path dbPath;
    std::shared_ptr<SQLite::Database> db;

    std::string getColumnTypeName(const std::string &columnType);
};

} // namespace data
} // namespace nativium
