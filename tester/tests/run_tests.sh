# ANSI Colors
RED="\033[31;1m"
GREEN="\033[32;1m"
RST="\033[0m"

ECHO_FLAG="-e"

LOGS="logs"
DIFFS="diffs"

CXX="clang++"
CXXFLAGS="-Wall -Werror -Wextra -std=c++98 -I$FT_CONTAINERS -I."

TEST_DIR="tests"

# Print success
test_success() {
    echo $ECHO_FLAG $1:$GREEN OK! $RST
}

# Print failure
test_fail() {
    echo $ECHO_FLAG $1:$RED KO! $RST
}

# Print red text
print_err() {
    echo $ECHO_FLAG $RED$1$RST
}

do_test() {
    LOG_FT="$LOGS/$1/$2"__ft.log
    LOG_STD="$LOGS/$1/$2"__std.log

    if $CXX $CXXFLAGS -DNAMESPACE=ft -DSFINAE=ft $3 track/memory_tracker.cpp track/leak_checker.cpp; then
        if ! ./a.out > $LOG_FT; then
            test_fail "$1 $2"
            return
        fi
    else
        print_err "error compiling $3"
        test_fail "$1 $2"
        return
    fi

    if ! $CXX $CXXFLAGS -DNAMESPACE=std -DSFINAE=fake_std $3 track/memory_tracker.cpp track/leak_checker.cpp; then
        print_err "warning: std test failed to compile"
    fi
    ./a.out > $LOG_STD

    DIFF_FILE="$DIFFS/$1/$2".diff
    diff -u $LOG_FT $LOG_STD > $DIFF_FILE
    RESULT=$(cat $DIFF_FILE)

    if [[ ${#RESULT} > 0 ]] ; then
        test_fail "$1 $2"
        print_err "Check $DIFF_FILE for $2 diffs with std"
    else
        test_success "$1 $2"
        rm -f $DIFF_FILE
    fi
}

check_dir() {
    if [[ ! -d "tests/$1" ]]; then
        print_err "test directory '$1' does not exist"
        return 1
    fi

    return 0
}

test_container() {
    if ! check_dir $1; then
        return
    fi

    TESTS=$(find "$TEST_DIR/$1" -type f -name '*.cpp' | sort)

    if [[ ${#TESTS} == 0 ]] ; then
        return
    fi

    mkdir -p $LOGS/$1 $DIFFS/$1

    for test in $TESTS; do
        TEST_NAME=$(basename -- $test)
        TEST_NAME=${TEST_NAME%.*}

        do_test $1 $TEST_NAME $test
    done

    rm -f a.out
}

run_container_tests() {
    rm -rf $LOGS $DIFFS
    mkdir -p $LOGS $DIFFS

    CONTAINERS="vector map stack set"

    if [ $# -ne 0 ]; then
        CONTAINERS=$@;
    fi

    for c in $CONTAINERS; do
        test_container $c
    done
}