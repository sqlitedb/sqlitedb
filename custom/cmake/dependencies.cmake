# dependencies for tests
include(${NATIVIUM_ROOT_PATH}/cmake/dependencies-tests.cmake)

# sqlite3
find_package(SQLite3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)

# sqlitecpp
find_package(SQLiteCpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SQLiteCpp)
