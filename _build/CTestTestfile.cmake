# CMake generated Testfile for 
# Source directory: /home/kali/workspace/lab05
# Build directory: /home/kali/workspace/lab05/_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check "/home/kali/workspace/lab05/_build/check")
set_tests_properties(check PROPERTIES  _BACKTRACE_TRIPLES "/home/kali/workspace/lab05/CMakeLists.txt;14;add_test;/home/kali/workspace/lab05/CMakeLists.txt;0;")
subdirs("_build/third-party/gtest")
