include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CXXTEST_INCLUDE_DIR})

set(TEST_LIBRARIES cmi ${PROTOBUF_LIBRARIES} util rtos WS2_32.lib Winmm.lib)

#CXXTEST_ADD_TEST(test_connection test_connection.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_connection.hpp)
#target_link_libraries(test_connection cmi ${PROTOBUF_LIBRARIES})

CXXTEST_ADD_TEST(test_notestack test_notestack.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_notestack.hpp)
target_link_libraries(test_notestack ${TEST_LIBRARIES})

CXXTEST_ADD_TEST(test_serialisation test_serialisation.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_serialisation.hpp)
target_link_libraries(test_serialisation ${TEST_LIBRARIES})

CXXTEST_ADD_TEST(test_observablestate test_observablestate.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_observablestate.hpp)
target_link_libraries(test_observablestate ${TEST_LIBRARIES})

CXXTEST_ADD_TEST(test_abstractcashunit test_abstractcashunit.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_abstractcashunit.hpp)
target_link_libraries(test_abstractcashunit ${TEST_LIBRARIES})

CXXTEST_ADD_TEST(test_systeminterfacemockup test_systeminterfacemockup.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test_systeminterfacemockup.hpp)
target_link_libraries(test_systeminterfacemockup ${TEST_LIBRARIES})
