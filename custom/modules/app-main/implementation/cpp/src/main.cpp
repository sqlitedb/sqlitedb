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
#include "nativium/data/RepositoryInfo.hpp"
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
    Repository::shared()->getTableList();
    Repository::shared()->getViewList();

    return EXIT_SUCCESS;
}

#endif
