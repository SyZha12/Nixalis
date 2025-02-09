add_executable(Sandbox
        Sandbox.cpp
)

target_link_libraries(Sandbox PRIVATE
        NIXALIS::NIXALIS
)

install(TARGETS Sandbox DESTINATION ${PROJECT_BINARY_DIR}/Build/bin)