target_sources(sort PRIVATE
    sortings.cpp
    sortings.hpp
    io.cpp
    io.hpp
)

target_include_directories(sort PRIVATE
    "${PROJECT_SOURCE_DIR}/sorting"
)
