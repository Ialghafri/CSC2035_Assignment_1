/******** DO NOT EDIT THIS FILE ********/
#include "procs4tests.h"
#include "stdlib.h"

static proc_t* _new_test_proc(pid_t pid, char* name) {
    work_ms_t w = {0, 0};
    proctype_t type = pid % 2 ? BWAIT_PROD_PROC : BWAIT_CONS_PROC;
    
    return proc_new(type, name, pid, 1, false, 0, 0, w, w);
}

proc_t* new_test_proc(pid_t pid) {
    return _new_test_proc(pid, "test_proc");
}

proc_t* new_init_proc() {
    proc_t* proc = _new_test_proc(0, "proc_in");    // BWAIT_CONS_PROC if id = 0
    proc->is_init = true;
    
    return proc; 
}

proc_t* new_noninit_proc() {
    return _new_test_proc(1, "proc_ni");           // BWAIT_PROD_PROC if id = 1
}

test_procs_t* new_test_procs() {
    test_procs_t* tp = (test_procs_t*) malloc(sizeof(test_procs_t));
    
    tp->pin = new_init_proc();
    tp->pni = new_noninit_proc();

    return tp;
}

void delete_test_procs(test_procs_t* tp) {
    proc_delete(tp->pin);
    proc_delete(tp->pni);
    free(tp);
}