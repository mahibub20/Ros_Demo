#!/bin/sh
#. /opt/ros/kinetic/setup.sh
mkdir test_results
mkdir test_results/coverage
mkdir test_results/gtest
mkdir test_results/cppcheck
mkdir test_results/cpplint
echo 'Building Application'
#catkin_make install
echo 'Executing UTs'
#catkin_make run_tests >> test_results/gtest/Unit_testResult.txt
echo 'Code Coverage'
gcovr -r . -e ".*\.h" --exclude=".*test.cc" --exclude=".*_node.cc" --html -o test_results/coverage/coverage.html --html-details
gcovr -r . --exclude=".*test.cc" --exclude=".*_node.cc" --xml-pretty > test_results/coverage/cov.xml
gcovr -r . --exclude=".*test.cc" --exclude=".*_node.cc" --xml > test_results/coverage/cov_small.xml
echo "Doxygen Results"
doxygen dox_config.conf
echo 'Guidelines Report'
cd src
cpplint --counting=detailed     $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/build\/" ) >> ../test_results/cpplint/Guidelines_detail.txt 2>&1
cpplint --counting=detailed     $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/build\/" ) 2>&1 |     grep -e "Category" -e "Total error" >> ../test_results/cpplint/Guidelines_summary.txt
echo 'cppcheck'
cd ..
cppcheck --xml --xml-version=2 --enable=all . 2> test_results/cppcheck/cppcheck.xml
echo 'Copying gtest XMLs'
cp build/test_results/ros_arithmetic/gtest-ros_arithmetic_test.xml test_results/gtest/gtest-ros_arithmetic_test.xml
cp build/test_results/ros_number_generator/gtest-ros_number_generator_test.xml test_results/gtest/gtest-ros_number_generator_test.xml
echo 'DONE'
