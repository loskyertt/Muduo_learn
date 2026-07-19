# 3rdparty/muduo-2.0.2/lib/cmake/muduo/muduoConfig
get_filename_component(_pkg_root
        "${CMAKE_CURRENT_LIST_DIR}/../../.."
        ABSOLUTE
)

if(NOT TARGET muduo::base)
    add_library(muduo::base STATIC IMPORTED)

    set_target_properties(muduo::base PROPERTIES
            IMPORTED_LOCATION "${_pkg_root}/lib/libmuduo_base.a"
            INTERFACE_INCLUDE_DIRECTORIES "${_pkg_root}/include"
    )
endif()

if(NOT TARGET muduo::http)
    add_library(muduo::http STATIC IMPORTED)

    set_target_properties(muduo::http PROPERTIES
            IMPORTED_LOCATION "${_pkg_root}/lib/libmuduo_http.a"
            INTERFACE_INCLUDE_DIRECTORIES "${_pkg_root}/include"
    )
endif()

if(NOT TARGET muduo::inspect)
    add_library(muduo::inspect STATIC IMPORTED)

    set_target_properties(muduo::inspect PROPERTIES
            IMPORTED_LOCATION "${_pkg_root}/lib/libmuduo_inspect.a"
            INTERFACE_INCLUDE_DIRECTORIES "${_pkg_root}/include"
    )
endif()

if(NOT TARGET muduo::net)
    add_library(muduo::net STATIC IMPORTED)

    set_target_properties(muduo::net PROPERTIES
            IMPORTED_LOCATION "${_pkg_root}/lib/libmuduo_net.a"
            INTERFACE_INCLUDE_DIRECTORIES "${_pkg_root}/include"
    )
endif()

unset(_pkg_root)