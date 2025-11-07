project(Fitness)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем все cpp-файлы в библиотеку
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(FitnessLib STATIC ${SOURCES})

# Include-директории
target_include_directories(FitnessLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
