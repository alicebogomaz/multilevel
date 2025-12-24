target_sources(merge PRIVATE
    sortings.cpp
    sortings.hpp
    io.cpp
    io.hpp
)

target_include_directories(merge PRIVATE
    "${PROJECT_SOURCE_DIR}/sorting"
)
