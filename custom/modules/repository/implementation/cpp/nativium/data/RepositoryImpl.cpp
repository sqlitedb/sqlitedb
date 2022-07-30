#include "RepositoryImpl.hpp"
#include <iostream>

namespace nativium
{
namespace data
{

std::shared_ptr<RepositoryImpl> RepositoryImpl::instance = nullptr;

RepositoryImpl::RepositoryImpl()
{
    // ignore
}

std::shared_ptr<Repository> Repository::shared()
{
    return RepositoryImpl::internalSharedInstance();
}

std::shared_ptr<RepositoryImpl> RepositoryImpl::internalSharedInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_shared<RepositoryImpl>();
    }

    return instance;
}

void RepositoryImpl::open(const std::string &path)
{
    db = std::make_shared<SQLite::Database>(path, SQLite::OPEN_READWRITE);
    test();

    dbPath = std::filesystem::path(path);

    std::cout << "Database opened for " << path << std::endl;
}

void RepositoryImpl::close()
{
    db = nullptr;
    std::cout << "Database closed" << std::endl;
}

void RepositoryImpl::test()
{
    auto sql = "PRAGMA schema_version;";
    SQLite::Statement query(*db, sql);
    query.executeStep();
}

RepositoryInfo RepositoryImpl::getInfo()
{
    auto fileData = DatabaseFileData{
        dbPath.stem(),
        static_cast<int64_t>(std::filesystem::file_size(dbPath)),
        std::filesystem::absolute(dbPath),
    };

    return RepositoryInfo{
        getSqliteVersion(),
        fileData,
        getTableList(),
        getViewList(),
    };
}

std::string RepositoryImpl::getSqliteVersion()
{
    return std::string(SQLite::VERSION);
}

std::vector<RepositoryTable> RepositoryImpl::getTableList()
{
    auto sql = R"""(SELECT name FROM sqlite_master
    WHERE type IN ('table') AND name NOT LIKE 'sqlite_%'
    UNION ALL
    SELECT name FROM sqlite_temp_master
    WHERE type IN ('table')
    ORDER BY 1)""";

    SQLite::Statement query(*db, sql);

    auto result = std::vector<RepositoryTable>{};

    while (query.executeStep())
    {
        auto columns = getColumns(query.getColumn("name").getString());

        auto table = RepositoryTable{
            query.getColumn("name").getString(),
            columns,
        };

        result.push_back(table);
    }

    return result;
}

std::vector<RepositoryView> RepositoryImpl::getViewList()
{
    auto sql = R"""(SELECT name FROM sqlite_master
    WHERE type IN ('view') AND name NOT LIKE 'sqlite_%'
    UNION ALL
    SELECT name FROM sqlite_temp_master
    WHERE type IN ('view')
    ORDER BY 1)""";

    SQLite::Statement query(*db, sql);

    auto result = std::vector<RepositoryView>{};

    while (query.executeStep())
    {
        auto columns = getColumns(query.getColumn("name").getString());

        auto table = RepositoryView{
            query.getColumn("name").getString(),
            columns,
        };

        result.push_back(table);
    }

    return result;
}

std::vector<RepositoryColumn> RepositoryImpl::getColumns(const std::string &name)
{
    auto sql = "PRAGMA table_info(\"" + name + "\");";

    auto result = std::vector<RepositoryColumn>{};

    try
    {
        SQLite::Statement query(*db, sql);

        while (query.executeStep())
        {
            auto column = RepositoryColumn{
                query.getColumn("cid").getInt64(),
                query.getColumn("name").getString(),
                query.getColumn("type").getString(),
                query.getColumn("notnull").getInt() == 1,
                query.getColumn("dflt_value").getString(),
                query.getColumn("pk").getInt() == 1,
            };

            result.push_back(column);
        }
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return result;
}

std::vector<RepositoryRow> RepositoryImpl::getRows(const std::string &name)
{
    auto sql = "SELECT * FROM \"" + name + "\";";

    auto result = std::vector<RepositoryRow>{};

    try
    {
        SQLite::Statement query(*db, sql);

        while (query.executeStep())
        {
            auto values = std::vector<std::string>{};

            for (int x = 0; x < query.getColumnCount(); x++)
            {
                values.push_back(query.getColumn(x).getString());
            }

            auto row = RepositoryRow{
                values,
            };

            result.push_back(row);
        }
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return result;
}

} // namespace data
} // namespace nativium
