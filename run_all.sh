if [ -d "test_results" ]; then
    echo "folder test_results exist"
else
    mkdir test_results
fi
echo '-Building Application-'
catkin_make install
echo "-Doxygen Results-"
doxygen dox_config.conf
echo '-Guidelines Report-'
cd src
cpplint *.cc >>../test_results/Guidelines_Report.txt
echo '-Guidelines Summary-'
cpplint --counting=detailed     $( find . -name \*.h -or -name \*.cc | grep -vE "^\.\/build\/" ) 2>&1 |     grep -e "Category" -e "Total error" >>../test_results/Guidelines_summary.txt
cd ..





