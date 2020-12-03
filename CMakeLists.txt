cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(untitled2)




#add_library(template STATIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/sources/delete.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
#        )


#target_link_libraries(untitled2 template)

find_package(Boost 1.65.1 COMPONENTS filesystem REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(untitled2 source/main.cpp source/relatedFunctions.cpp source/tkk.cpp source/findAntecedents)
    include_directories(untitled2 include/)
    target_link_libraries(untitled2 ${Boost_LIBRARIES})
endif ()


