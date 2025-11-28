project(BubbleSortTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Загружаем GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Собираем тестовые *.cpp
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(BubbleSortTests ${TEST_SOURCES})

# Линкуем основную библиотеку + GoogleTest
target_link_libraries(BubbleSortTests PRIVATE BubbleSortLib GTest::gtest_main)

# Автоматическая регистрация тестов
include(GoogleTest)
gtest_discover_tests(BubbleSortTests)
