cmake_minimum_required(VERSION 3.0.0)
project(redblack VERSION 0.1.0)

option(ENABLE_CLASSROOM_TESTING "Enable testing" ON)

configure_file(${PROJECT_SOURCE_DIR}/config.h.in
               ${PROJECT_SOURCE_DIR}/librb/config.h)

include(CTest)
enable_testing()
include_directories(librb)
add_subdirectory(librb)
add_subdirectory(tests)

# define a function to simplify adding tests

add_test(NAME TestInsert COMMAND  ${PROJECT_SOURCE_DIR}/build/tests/test1 out1.txt)
add_test(NAME CompareTestInsertOutput COMMAND cmake -E compare_files out1.txt ${PROJECT_SOURCE_DIR}/tests/expected/test1.out)

add_test(NAME TestRemove COMMAND  ${PROJECT_SOURCE_DIR}/build/tests/test2 out2.txt)
add_test(NAME CompareTestRemoveOutput COMMAND cmake -E compare_files out2.txt ${PROJECT_SOURCE_DIR}/tests/expected/test2.out)

add_test(NAME TestInsertRemove COMMAND  ${PROJECT_SOURCE_DIR}/build/tests/test3 out3.txt)
add_test(NAME CompareTestInsertRemoveOutput COMMAND cmake -E compare_files out3.txt ${PROJECT_SOURCE_DIR}/tests/expected/test3.out)




