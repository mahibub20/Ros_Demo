#!/bin/sh
. /opt/ros/melodic/setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/x86_64-linux-gnu/
mkdir test_results
mkdir test_results/coverage
mkdir test_results/gtest
mkdir test_results/cppcheck
mkdir test_results/cpplint
echo '############################# S T E P 1 : BUILD APPLICATION     ######################################################n'

echo 'Building Application'
catkin_make install

echo '############################# S T E P 2 : UNIT TESTS     ######################################################n'

echo 'Executing UTs'
catkin_make run_tests >> test_results/gtest/Unit_testResult.txt
echo '############################# S T E P 3 : CODE COVERAGE TESTS     ######################################################n'

echo 'Code Coverage'
gcovr -r . -e ".*\.h" --exclude=".*test.cc" --exclude=".*_node.cc" --html -o test_results/coverage/coverage.html --html-details
gcovr -r . --exclude=".*test.cc" --exclude=".*_node.cc" --xml-pretty > test_results/coverage/cov.xml
gcovr -r . --exclude=".*test.cc" --exclude=".*_node.cc" --xml > test_results/coverage/cov_small.xml
gcovr --branches -r . --html --html-details -o gcovr-report.html
echo '############################# S T E P 4 : DOXYGEN DOCU GENERATION    ######################################################n'

echo "Doxygen Results"
doxygen dox_config.conf
echo '############################# S T E P 5 : CPP GUIDELINES CHECKER    ######################################################n'

echo 'Guidelines Report'
cd src
cpplint --counting=detailed     $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/build\/" ) >> ../test_results/cpplint/Guidelines_detail.txt 2>&1
cpplint --counting=detailed     $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/build\/" ) 2>&1 |     grep -e "Category" -e "Total error" >> ../test_results/cpplint/Guidelines_summary.txt
echo '############################# S T E P 6 : CPP QUALITY CHECKER    ######################################################n'

echo 'cppcheck'
cd ..
cppcheck --xml --xml-version=2 --enable=all . 2> test_results/cppcheck/cppcheck.xml
echo 'Copying gtest XMLs'
echo '############################# S T E P 7 : REPORT GENERATION    ######################################################n'

cp build/test_results/ros_arithmetic/gtest-ros_arithmetic_test.xml test_results/gtest/gtest-ros_arithmetic_test.xml
cp build/test_results/ros_number_generator/gtest-ros_number_generator_test.xml test_results/gtest/gtest-ros_number_generator_test.xml
echo 'DONE'

echo '############################# COMPLETED    ######################################################n'

