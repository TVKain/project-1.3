cmake_minimum_required (VERSION 3.12)

project(project1-2)

set(SOURCES 
    src/main.cpp 
    src/menu.cpp
    src/util.cpp
)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs test EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} ${SOURCES})


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/text.txt 
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/stop_word.txt 
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

target_link_libraries(${PROJECT_NAME}
    ds::array_list
    ds::priority_queue
    ds::undirected_graph
    ds::hash_table
    ds::binary_search_tree
    algo::sort
    algo::heap
)