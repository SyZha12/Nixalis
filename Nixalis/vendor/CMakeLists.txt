##############################################################################
#                             ADD SUBDIRECTORIES                             #
##############################################################################
#[Set directories and search for CMakeLists.txt files to execute]
set(DIRECTORIES
        spdlog
)
foreach(DIR ${DIRECTORIES})
    add_subdirectory(${DIR})
endforeach()

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include
)