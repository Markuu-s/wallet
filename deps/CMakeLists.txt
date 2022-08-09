add_subdirectory(boost)
add_subdirectory(json-rpc)

if (TESTING)
    add_subdirectory(googletest)
endif()
