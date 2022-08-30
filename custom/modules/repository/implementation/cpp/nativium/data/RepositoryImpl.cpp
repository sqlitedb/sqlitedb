#include "RepositoryImpl.hpp"
#include <cctype>
#include <iostream>
#include <regex>

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
        auto table = RepositoryTable{
            query.getColumn("name").getString(),
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
        auto table = RepositoryView{
            query.getColumn("name").getString(),
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
            std::string groupType = "";
            auto columnType = query.getColumn("type").getString();
            auto columnTypeName = getColumnTypeName(columnType);

            // reference: https://www.sqlite.org/datatype3.html
            if (columnTypeName == "int")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "integer")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "tinyint")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "smallint")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "mediumint")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "bigint")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "unsigned big int")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "int2")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "int8")
            {
                groupType = "integer";
            }
            else if (columnTypeName == "character")
            {
                groupType = "text";
            }
            else if (columnTypeName == "varchar")
            {
                groupType = "text";
            }
            else if (columnTypeName == "varying character")
            {
                groupType = "text";
            }
            else if (columnTypeName == "nchar")
            {
                groupType = "text";
            }
            else if (columnTypeName == "native character")
            {
                groupType = "text";
            }
            else if (columnTypeName == "nvarchar")
            {
                groupType = "text";
            }
            else if (columnTypeName == "text")
            {
                groupType = "text";
            }
            else if (columnTypeName == "clob")
            {
                groupType = "text";
            }
            else if (columnTypeName == "date")
            {
                groupType = "text";
            }
            else if (columnTypeName == "datetime")
            {
                groupType = "text";
            }
            else if (columnTypeName == "char")
            {
                groupType = "text";
            }
            else if (columnTypeName == "string")
            {
                groupType = "text";
            }
            else if (columnTypeName == "timestamp")
            {
                groupType = "text";
            }
            else if (columnTypeName == "blob")
            {
                groupType = "blob";
            }
            else if (columnTypeName == "none")
            {
                groupType = "blob";
            }
            else if (columnTypeName == "linestring")
            {
                groupType = "blob";
            }
            else if (columnTypeName == "multipolygon")
            {
                groupType = "blob";
            }
            else if (columnTypeName == "point")
            {
                groupType = "blob";
            }
            else if (columnTypeName == "real")
            {
                groupType = "real";
            }
            else if (columnTypeName == "double")
            {
                groupType = "real";
            }
            else if (columnTypeName == "double precision")
            {
                groupType = "real";
            }
            else if (columnTypeName == "float")
            {
                groupType = "real";
            }
            else if (columnTypeName == "numeric")
            {
                groupType = "numeric";
            }
            else if (columnTypeName == "decimal")
            {
                groupType = "numeric";
            }
            else if (columnTypeName == "boolean")
            {
                groupType = "numeric";
            }

            auto column = RepositoryColumn{
                query.getColumn("cid").getInt64(),
                query.getColumn("name").getString(),
                query.getColumn("type").getString(),
                query.getColumn("notnull").getInt() == 1,
                query.getColumn("dflt_value").getString(),
                query.getColumn("pk").getInt() == 1,
                groupType,
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

RepositoryRows RepositoryImpl::getRows(const std::string &name, const std::string &sortBy, bool descending, int32_t page, int32_t rowsPerPage)
{
    auto list = std::vector<RepositoryRow>{};
    auto amount = 0;

    // get database rows
    try
    {
        // prepare query
        auto sql = "SELECT * FROM \"" + name + "\"";

        if (!sortBy.empty())
        {
            if (descending)
            {
                sql += " ORDER BY " + sortBy + " DESC ";
            }
            else
            {
                sql += " ORDER BY " + sortBy + " ASC ";
            }
        }

        if (rowsPerPage > 0)
        {
            sql += " LIMIT " + std::to_string(page * rowsPerPage) + "," + std::to_string(rowsPerPage) + " ";
        }

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

            list.push_back(row);
        }
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    // get database rows amount
    try
    {
        // prepare query
        auto sql = "SELECT COUNT(*) as qty FROM \"" + name + "\"";

        SQLite::Statement query(*db, sql);

        while (query.executeStep())
        {
            amount = query.getColumn(0).getInt64();
        }
    }
    catch (const std::exception &e)
    {
        // ignore
    }

    return RepositoryRows{
        list,
        amount,
    };
}

std::string RepositoryImpl::getColumnTypeName(const std::string &columnType)
{
    std::regex rgx("([A-Z])\\w+");
    std::smatch match;

    if (std::regex_search(columnType.begin(), columnType.end(), match, rgx))
    {
        std::string data = match[0];

        std::transform(data.begin(), data.end(), data.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        return data;
    }

    return "";
}

} // namespace data
} // namespace nativium
