#!/bin/bash

touch infile; touch outfile1; touch outfile2
test(){
	$CMD1 < infile | $CMD2 > outfile1
	./pipex infile "$CMD1" "$CMD2" outfile2
	if diff outfile1 outfile2 > /dev/null; then
		echo "$1: success"
	else
		echo "$1: failed"
		diff outfile1 outfile2
	fi
}

test_invalid_args() {
    local testname="$1" 
    ./pipex "$@" 2> errlog
    local actual_status=$?
    local testname="$1"

    if [ "$actual_status" -ne 1 ]; then
        echo "$testname: failed (exit $actual_status, expected 1)"
        return
    fi

    if grep -iq "error\|usage\|arguments" errlog; then
        echo "$testname: success"
    else
        echo "$testname: failed (message not found)"
        echo "--- stderr ---"
        cat errlog
    fi
}


# general test
echo "-----general test-----"
# test1 cat | cat
CMD1="cat"; CMD2="cat"
echo "hello world" > infile
test test1

# test2 ls -al | cat
CMD1="ls -a"; CMD2="cat"
test test2

# test3 grep hello | wc -c
CMD1="grep hello"; CMD2="wc -c"
echo -e "hello world\nbye world" > infile
test test3

# test4 tr a-z A-Z | cat
CMD1="tr a-z A-Z"; CMD2="cat"
echo "hello pipex" > infile
test test4

# test5 head -n 1 | wc -w
CMD1="head -n 1"; CMD2="wc -w"
echo -e "a b c d\nx y z" > infile
test test5

# test6 sort | uniq
CMD1="sort"; CMD2="uniq"
echo -e "banana\napple\nbanana\ncherry" > infile
test test6

# validation test
echo "validation test"
test_invalid_args test_no_args
test_invalid_args test_few_args1 file1
test_invalid_args test_few_args2 file1 "ls"
test_invalid_args test_few_args3 file1 "ls" "wc"
