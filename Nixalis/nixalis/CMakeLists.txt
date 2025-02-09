#[Set Properties]
set(SUBDIRECTORIES
    #[Names of subdirectories]
        Core
)
set(FILES
    #[Names of source files]
)
set(RELATIVE_PATH
    #[Relative path for include]
)

#[Execute Properties]
#============================
foreach(DIR ${SUBDIRECTORIES})
    add_subdirectory(${DIR})
endforeach()
#=============================
if(FILES)
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
endif()

##############################################################################
#                             ADD MACROS EXPORT                              #
##############################################################################
#[Library Export - For programmes to use the library functions; use this code to generate]
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)


















#[Library Export - For programmes to use the library functions; use this code to generate]
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)