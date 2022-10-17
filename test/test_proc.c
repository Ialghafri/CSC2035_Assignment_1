/******** DO NOT EDIT THIS FILE ********/
#include <stdio.h>
#include <unistd.h>
#include "test_proc.h"
#include "../proc.h"

int main(int argc, char** argv) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

MunitResult test_proc_new(const MunitParameter params[], 
    void* fixture) {        
    static const char* proctype_label[] = { 
        "bwait_cons",
        "bwait_prod", 
        "sem_cons", 
        "sem_prod"
    };

    pid_t pid = getpid();
    work_ms_t w1 = { 1, 2 };
    work_ms_t w2 = { 3, 4 };

    proc_t* p = proc_new(BWAIT_CONS_PROC, "test1", pid, 100, true, 10, 20,
                 w1, w2);
    assert_int(p->type, ==, BWAIT_CONS_PROC);
    munit_assert_string_equal(p->name, "test1");
    assert_int(p->id, ==, pid);
    assert_int(p->jobs, ==, 100);
    assert_true(p->is_init);
    assert_int(p->delay_start, ==, 10);
    assert_int(p->delay_exit, ==, 20);
    assert_int(p->crit_work.min, ==, 1);
    assert_int(p->crit_work.max, ==, 2);
    assert_int(p->noncrit_work.min, ==, 3);
    assert_int(p->noncrit_work.max, ==, 4);
    
    proc_delete(p);    
    
    w1.min += 2;
    w1.max += 2;
    w2.min += 2;
    w2.max += 2;
    p = proc_new(BWAIT_PROD_PROC, NULL, pid, 200, false, 20, 30, w1, w2);
    assert_int(p->type, ==, BWAIT_PROD_PROC);
    munit_assert_string_equal(p->type_label, proctype_label[p->type]);
    munit_assert_string_equal(p->name, "none");
    assert_int(p->id, ==, pid);
    assert_int(p->jobs, ==, 200);
    assert_false(p->is_init);
    assert_int(p->delay_start, ==, 20);
    assert_int(p->delay_exit, ==, 30);
    assert_int(p->crit_work.min, ==, 3);
    assert_int(p->crit_work.max, ==, 4);
    assert_int(p->noncrit_work.min, ==, 5);
    assert_int(p->noncrit_work.max, ==, 6);
    
    proc_delete(p);    

    w1.min += 3;
    w1.max += 3;
    w2.min += 3;
    w2.max += 3;
    p = proc_new(SEM_CONS_PROC, "", pid, 300, true, 30, 30, w1, w2);
    assert_int(p->type, ==, SEM_CONS_PROC);
    munit_assert_string_equal(p->type_label, proctype_label[p->type]);
    munit_assert_string_equal(p->name, "none");
    assert_int(p->id, ==, pid);
    assert_int(p->jobs, ==, 300);
    assert_true(p->is_init);
    assert_int(p->delay_start, ==, 30);
    assert_int(p->delay_exit, ==, 30);
    assert_int(p->crit_work.min, ==, 6);
    assert_int(p->crit_work.max, ==, 7);
    assert_int(p->noncrit_work.min, ==, 8);
    assert_int(p->noncrit_work.max, ==, 9);
    
    proc_delete(p);    

    w1.min += 4;
    w1.max += 5;
    w2.min += 6;
    w2.max += 7;
    p = proc_new(SEM_CONS_PROC, "test4", pid, 400, false, 40, 50, w1, w2);
    assert_int(p->type, ==, SEM_CONS_PROC);
    munit_assert_string_equal(p->type_label, proctype_label[p->type]);
    munit_assert_string_equal(p->name, "test4");
    assert_int(p->id, ==, pid);
    assert_int(p->jobs, ==, 400);
    assert_false(p->is_init);
    assert_int(p->delay_start, ==, 40);
    assert_int(p->delay_exit, ==, 50);
    assert_int(p->crit_work.min, ==, 10);
    assert_int(p->crit_work.max, ==, 12);
    assert_int(p->noncrit_work.min, ==, 14);
    assert_int(p->noncrit_work.max, ==, 16);
    
    proc_delete(p);        

    return MUNIT_OK;
}   

MunitResult test_proc_new_null(const MunitParameter params[], 
    void* fixture) {
    
    pid_t pid = getpid();
    work_ms_t w1 = { 1, 2 };
    work_ms_t w2 = { 3, 4 };

    proc_t* p = proc_new(BWAIT_CONS_PROC - 1, "test", pid, 100, true, 10, 20,
        w1, w2);
    assert_null(p);
    
    p = proc_new(SEM_PROD_PROC + 1, "test", pid, 100, true, 10, 20, w1, w2);
    assert_null(p);
    
    p = proc_new(SEM_PROD_PROC, "test", pid, 0, true, 10, 20, w1, w2);
    assert_null(p);
    
    return MUNIT_OK;
}       
