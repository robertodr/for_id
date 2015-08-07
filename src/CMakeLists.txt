list(APPEND headers_list "Foo.hpp" "ForId1D.hpp" "ForId.hpp" "TypeLists.hpp")
list(SORT headers_list)

find_package(Boost 1.54.0)
if (NOT Boost_FOUND)
    include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/external)
else()
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

add_executable(example_1D.x example_1D.cpp)
add_executable(example.x example.cpp)
