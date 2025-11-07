project(FitnessTests)

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

# Все тестовые cpp
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(FitnessTests ${TEST_SOURCES})

# Подключаем библиотеку Fitness и GoogleTest
target_link_libraries(FitnessTests PRIVATE FitnessLib GTest::gtest_main)

# Автоматически регистрируем тесты
include(GoogleTest)
gtest_discover_tests(FitnessTests)
