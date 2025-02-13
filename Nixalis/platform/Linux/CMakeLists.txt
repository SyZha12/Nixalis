#[Set Properties]
set(SUBDIRECTORIES
        #[Names of subdirectories]
)
set(SOURCE_FILES
        #[Names of source files]
        LinuxWindow.cpp
        CACHE INTERNAL "Source files"
)
set(HEADER_FILES
        #[Names of header files]
        LinuxWindow.h
        CACHE INTERNAL "Header files"
)
set(RELATIVE_PATH
        #[Relative path for include]
        Nixalis/platform
)

#[Execute Properties]
#============================
foreach(DIR ${SUBDIRECTORIES})
    add_subdirectory(${DIR})
endforeach()
#=============================
set(FILES ${SOURCE_FILES} ${HEADER_FILES} )
if(FILES)
    target_sources(${PROJECT_NAME} PRIVATE ${FILES})
    install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_BINARY_DIR}/Build/lib)
    install(FILES ${HEADER_FILES} DESTINATION ${PROJECT_BINARY_DIR}/Build/include/${RELATIVE_PATH})
endif()