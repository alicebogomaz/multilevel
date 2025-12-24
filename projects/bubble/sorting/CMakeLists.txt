target_sources(bubble PRIVATE
    sortings.cpp
    sortings.hpp
    io.cpp
    io.hpp
)

target_include_directories(bubble PRIVATE
    "${PROJECT_SOURCE_DIR}/sorting"
)
