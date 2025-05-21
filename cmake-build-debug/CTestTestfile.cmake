# CMake generated Testfile for 
# Source directory: C:/Users/Franc/CLionProjects/Actividad Integradora 1
# Build directory: C:/Users/Franc/CLionProjects/Actividad Integradora 1/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_palindrome]=] "C:/Users/Franc/CLionProjects/Actividad Integradora 1/cmake-build-debug/test_palindrome.exe")
set_tests_properties([=[test_palindrome]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;47;add_test;C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;51;add_test_executable;C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;0;")
add_test([=[test_utils]=] "C:/Users/Franc/CLionProjects/Actividad Integradora 1/cmake-build-debug/test_utils.exe")
set_tests_properties([=[test_utils]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;47;add_test;C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;52;add_test_executable;C:/Users/Franc/CLionProjects/Actividad Integradora 1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
