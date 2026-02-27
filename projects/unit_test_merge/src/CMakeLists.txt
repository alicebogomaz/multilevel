target_sources(${MERGE_LIB}
    PRIVATE
        sortings.cpp
    PUBLIC
        sortings.hpp
)

target_include_directories(${MERGE_LIB} PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

