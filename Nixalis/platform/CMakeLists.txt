#[Set Properties]
set(SUBDIRECTORIES
        #[Names of subdirectories]
        Linux
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