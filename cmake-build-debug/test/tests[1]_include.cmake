if(EXISTS "/Users/valeriomartino/Desktop/LAB_INF/cmake-build-debug/test/tests[1]_tests.cmake")
  include("/Users/valeriomartino/Desktop/LAB_INF/cmake-build-debug/test/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()
