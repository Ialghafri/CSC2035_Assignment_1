/*
 * Replace the following string of 0s with your student number
 * 210288315
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job.h"

/* 
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, unsigned int priority, 
    const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, priority, label);
}

/* 
 * TODO: you must implement this function
 */
job_t* job_copy(job_t* src, job_t* dst) {
    if (src == NULL)    {
        return NULL;
    }  if (src == dst ) {
        return src;
    }  if (dst == NULL) {
        job_t* new_job = job_new( src->pid, src->id, src->priority, src->label ); 
        return new_job;
    }  else  {
        dst == src;
        return dst;
    }

    return NULL; 
}

/* 
 * TODO: you must implement this function
 */
void job_init(job_t* job) {
    if ( job != NULL ) {
        job->pid = 0;
        job->id = 0;
        job->priority = 0;
        strcpy(job->label, PAD_STRING);
    }   
    
    return;
     
}

/* 
 * TODO: you must implement this function
 */
bool job_is_equal(job_t* j1, job_t* j2) {

if ( j1 == NULL && j2 == NULL ) {

    return true;
}

else if ( (j1 == NULL && j2 != NULL) || (j1 != NULL && j2 == NULL) ) {

    return false;

}    
if ( j1->pid == j2->pid && j1->id == j2->id && j1->priority == j2->priority && strcmp(j1->label, j2->label ) == 0) {

    return true;
}
else { 

    return false;
} 
}


/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job
 *      labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, unsigned int priority,
    const char* label) {
    return job;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see malloc and calloc system library functions for dynamic allocation, 
 *      and the documentation in job.h for when to do dynamic allocation
 */
char* job_to_str(job_t* job, char* str) {
    return NULL;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see the hint for job_to_str
 */
job_t* str_to_job(char* str, job_t* job) {
    return NULL;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    return;
}