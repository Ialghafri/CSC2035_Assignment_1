/******** DO NOT EDIT THIS FILE ********/
#include "test_jobqueue_common.h"
#include "test_pri_jobqueue.h"

int main(int argc, char** argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

MunitResult test_pri_jobqueue_dummy(const MunitParameter params[], 
    void* fixture) {
    return test_jq_dummy();
}
