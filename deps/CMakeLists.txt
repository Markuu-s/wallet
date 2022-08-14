add_subdirectory(boost)
add_subdirectory(nlohmann-json)

if (TESTING)
    add_subdirectory(googletest)
endif()
