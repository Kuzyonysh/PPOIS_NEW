project(PatientSortTests)

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

add_executable(PatientSortTests ${TEST_SOURCES})

target_link_libraries(PatientSortTests PRIVATE PatientSortLib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(PatientSortTests)
