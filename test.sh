#!/bin/bash


# validation test
test_invalid_args() {
    local testname="$1"
	shift 
	touch errlog;
    ./pipex "$@" 2> errlog
    local actual_status=$?

    if [ "$actual_status" -ne 1 ]; then
        echo "$testname: failed (exit $actual_status, expected 1)"
        return
    fi
	if [ -s errlog ]; then
		echo "$testname: success"
	else
		echo "$testname: failed (message not found)"
		echo "--- stderr ---"
		cat errlog
	fi
}
echo "-----validation test-----"
test_invalid_args test_few_args0
test_invalid_args test_few_args1 file1
test_invalid_args test_few_args2 file1 "ls"
test_invalid_args test_few_args3 file1 "ls" "wc"


# general test

test(){
	touch infile; touch outfile1; touch outfile2; touch errlog1; touch errlog2;
	$CMD1 < infile | $CMD2 > outfile1 2> errlog1
	./pipex infile "$CMD1" "$CMD2" outfile2 2> errlog2
	if diff outfile1 outfile2 > /dev/null; then
		echo "$1: success"
	else
		echo "$1: failed"
		diff outfile1 outfile2
	fi
}

echo "-----general test-----"
CMD1="cat"; CMD2="cat"
echo "hello world" > infile
test test1
CMD1="ls -a"; CMD2="cat"
test test2
CMD1="grep hello"; CMD2="wc -c"
echo -e "hello world\nbye world" > infile
test test3
CMD1="tr a-z A-Z"; CMD2="cat"
echo "hello pipex" > infile
test test4
CMD1="head -n 1"; CMD2="wc -w"
echo -e "a b c d\nx y z" > infile
test test5
CMD1="sort"; CMD2="uniq"
echo -e "banana\napple\nbanana\ncherry" > infile
test test6
CMD1="cat"; CMD2="grep 'a b'"
echo -e "a b\nb c\nc a\na b c" > infile
test test7

# error case test
echo "-----error case test-----"
CMD1="no_cmd"; CMD2="cat"
test test1
CMD1="cat"; CMD2="no_cmd" 
test test2
CMD1="   	"; CMD2="cat" # space and tab
test test3
CMD1="cat"; CMD2="   	" # space and tab
test test4
CMD1=""; CMD2="cat"
test test5
CMD1="cat"; CMD2=""
test test6