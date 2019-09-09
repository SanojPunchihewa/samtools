# Get all the directories with needed .hpp files
include_directories ("${PROJECT_SOURCE_DIR}/src")

# Create the executable
add_executable(samtool_example samtool_example.c)

# Link the required libraries
target_link_libraries(samtool_example samtoolshared)