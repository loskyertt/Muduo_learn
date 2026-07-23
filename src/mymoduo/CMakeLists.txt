# src/mymoduo/CMakeLists.txt
add_library(mymuduo STATIC
        impl/inet_address.cpp
)

target_include_directories(mymuduo
        PUBLIC include
        PRIVATE impl
)

target_link_libraries(mymuduo
        PRIVATE utility::g3log
)

add_subdirectory(tests)