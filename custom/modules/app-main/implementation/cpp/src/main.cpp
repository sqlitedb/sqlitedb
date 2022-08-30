#ifdef __EMSCRIPTEN__
#include "nativium/core/ApplicationCore.hpp"

#include <iostream>
#include <string>

using namespace nativium::core;

int main(int argc, char **argv)
{
    std::cout << "Application Version: " << ApplicationCore::shared()->getVersion() << std::endl;

    return EXIT_SUCCESS;
}

#else

#include "nativium/core/ApplicationCore.hpp"
#include "nativium/data/DatabaseFileData.hpp"
#include "nativium/data/Repository.hpp"
#include "nativium/data/RepositoryColumn.hpp"
#include "nativium/data/RepositoryInfo.hpp"
#include "nativium/data/RepositoryRow.hpp"
#include "nativium/data/RepositoryRows.hpp"
#include "nativium/data/RepositoryTable.hpp"
#include "nativium/data/RepositoryView.hpp"

#include <iostream>
#include <string>

using namespace nativium::core;
using namespace nativium::data;

int main(int argc, char **argv)
{
    std::cout << "Application Version: " << ApplicationCore::shared()->getVersion() << std::endl;
    std::cout << "SQLite Version: " << Repository::shared()->getSqliteVersion() << std::endl;

    auto dbPath = ApplicationCore::shared()->getEnv("DBPATH");

    if (dbPath.empty())
    {
        std::cerr << "Database path is empty" << std::endl;
        return EXIT_FAILURE;
    }

    Repository::shared()->open(dbPath);
    Repository::shared()->test();
    Repository::shared()->getSqliteVersion();
    Repository::shared()->getInfo();
    auto tables = Repository::shared()->getTableList();
    auto views = Repository::shared()->getViewList();

    try
    {
        auto columns = Repository::shared()->getColumns(tables[0].name);
        std::cout << "Column name from table 1: " << columns[0].name << ", group: " << columns[0].groupType << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No tables or columns" << std::endl;
    }

    try
    {
        auto columns = Repository::shared()->getColumns(tables[0].name);
        auto values = Repository::shared()->getRows(tables[0].name, columns[0].name, true, 1, 10);
        std::cout << "Value from table 1: " << values.list[0].values[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No values" << std::endl;
    }

    return EXIT_SUCCESS;
}

#endif
