cmake_minimum_required(VERSION 2.8)
project(barcode)

# for finding FindZBar0.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

# opencv
find_package(OpenCV REQUIRED)

# zbar
find_package (ZBar0)

#find_package(json)

#include_directories(${PROJECT_SOURCE_DIR}/include)
#
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${barcode_SOURCE_DIR}/lib)
#set(SRC_JSONCPP
#        include/lib_json/json_reader.cpp
#        include/lib_json/json_value.cpp
#        include/lib_json/json_writer.cpp
#        include/lib_json/json_internalarray.inl
#        include/lib_json/json_internalmap.inl
#        include/lib_json/json_valueiterator.inl)
#set(HDRS_JSONCPP
#        include/json/json.h
#        include/json/autolink.h
#        include/json/config.h
#        include/json/features.h
#        include/json/forwards.h
#        include/json/reader.h
#        include/json/value.h
#        include/json/writer.h)

#add_library(jsoncpp  SHARED ${SRC_JSONCPP} )

add_executable(${PROJECT_NAME}  src/barcode.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${ZBAR_LIBRARIES} libjson.a) # libjson.a is a link
