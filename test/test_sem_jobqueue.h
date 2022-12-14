/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_sem_jobqueue.h - structures and function declarations for unit tests
 * of sem_jobqueue functions.
 * 
 */  
#ifndef _TEST_SEM_JOBQUEUE_H
#define _TEST_SEM_JOBQUEUE_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit/munit.h"

MunitResult test_semjq_dequeue_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_enqueue_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_is_empty_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_is_full_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_peek_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_size_null(const MunitParameter params[], 
    void* fixture);
MunitResult test_semjq_space_null(const MunitParameter params[], 
    void* fixture);
    
/* two-process tests */
MunitResult test_sem_jobqueue_2proc_ndequeue(const MunitParameter params[],
    void* fixture);

MunitResult test_sem_jobqueue_delete(const MunitParameter params[],
    void* fixture);

void* test_setup(const MunitParameter params[], void* user_data);
void test_tear_down(void* fixture);

static MunitTest tests[] = {
    { "/test_semjq_dequeue_null", test_semjq_dequeue_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_enqueue_null", test_semjq_enqueue_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_is_empty_null", test_semjq_is_empty_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_is_full_null", test_semjq_is_full_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_peek_null", test_semjq_peek_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_size_null", test_semjq_size_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_semjq_space_null", test_semjq_space_null, test_setup,
        test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },

    { "/test_sem_jobqueue_2proc_ndequeue", test_sem_jobqueue_2proc_ndequeue,
        NULL, NULL, MUNIT_TEST_OPTION_NONE,  NULL },
        
    { "/test_sem_jobqueue_delete", test_sem_jobqueue_delete,
        NULL, NULL, MUNIT_TEST_OPTION_NONE,  NULL },
        
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

static const MunitSuite suite = {
    "/test_sem_jobqueue", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    




#endif