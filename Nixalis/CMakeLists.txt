##############################################################################
#                            NIXALIS DIRECTORY                               #
##############################################################################
#[Set Properties for the library]
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

#[${PROJECT_NAME} == Nixalis]
#[Users can target_link_libraries to NIXALIS::NIXALIS alias to link to this library]
add_library(${PROJECT_NAME} "")
add_library(NIXALIS::NIXALIS ALIAS ${PROJECT_NAME})

##############################################################################
#                             ADD SUBDIRECTORIES                             #
##############################################################################
#[Set directories and search for CMakeLists.txt files to execute]
set(DIRECTORIES
        nixalis
        vendor
)
foreach(DIR ${DIRECTORIES})
    add_subdirectory(${DIR})
endforeach()

#[Current source directory - Nixalis]
#[Every include needs to start with <nixalis/...>]
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})