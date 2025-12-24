target_sources(merge_sort_lib
    PRIVATE
        sortings.cpp
    PUBLIC
        sortings.hpp
)

target_include_directories(merge_sort_lib PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

