project(PatientSort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(PatientSortLib STATIC ${SOURCES})

target_include_directories(PatientSortLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
