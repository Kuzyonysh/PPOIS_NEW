project(Graph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем EXE только если есть cpp
file(GLOB_RECURSE SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(GraphExe ${SRC})

# Доступ ко всем .h файлам
target_include_directories(GraphExe PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)