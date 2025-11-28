project(GraphTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(GraphTestsExe ${TEST_SOURCES})

# Подключаем .h из Graph
target_include_directories(GraphTestsExe PUBLIC
    ${CMAKE_SOURCE_DIR}/Graph
)

# Линкуем GoogleTest
target_link_libraries(GraphTestsExe PRIVATE
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GraphTestsExe)
