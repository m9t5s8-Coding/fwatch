cmake_minimum_required(VERSION 3.20)

project(fwatch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenSSL REQUIRED)


file(GLOB_RECURSE APP_SRC "${CMAKE_SOURCE_DIR}/src/*cpp")
add_executable(fwatch ${APP_SRC})


target_include_directories(fwatch PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(fwatch PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
)

install(TARGETS fwatch DESTINATION /usr/local/bin)
