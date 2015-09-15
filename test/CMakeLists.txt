include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CXXTEST_INCLUDE_DIR})

set(TEST_LIBRARIES ${wxWidgets_LIBRARIES} libwxunivDiff)

CXXTEST_ADD_TEST(test_cmdline test_cmdline.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_cmdline.hpp)
target_link_libraries(test_cmdline ${TEST_LIBRARIES})
