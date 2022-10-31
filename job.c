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
        dst -> pid = src -> pid;
        dst -> id = src -> id;
        dst -> priority = src -> priority;
        strcpy ( dst -> label , src -> label);
        
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

    char storeLabel[MAX_NAME_SIZE];

if ( job == NULL ) {

        return NULL; 

    }
else {

    job->id = id;
    job->pid = pid;
    job->priority = priority;

    if ( label == NULL ) {

        snprintf( storeLabel, MAX_NAME_SIZE, "%s", PAD_STRING );

        storeLabel[ MAX_NAME_SIZE - 1 ] = "\0";

        snprintf( job->label, MAX_NAME_SIZE, "%s",storeLabel );

        return job;



    }

    else {

        snprintf( storeLabel, MAX_NAME_SIZE, "%s%s", label,PAD_STRING );

        storeLabel[ MAX_NAME_SIZE - 1 ] = "\0";

        snprintf( job->label, MAX_NAME_SIZE, "%s",storeLabel );

        return job;


    }

}

}    

/*
 * TODO: you must implement this function.
 * Hint:
 * - see malloc and calloc system library functions for dynamic allocation, 
 *      and the documentation in job.h for when to do dynamic allocation
 */
char* job_to_str(job_t* job, char* str) {

    if (strnlen(job->label, MAX_NAME_SIZE) != MAX_NAME_SIZE - 1 ){ return NULL;
     }

    if ( job == NULL ) {
    return NULL;
    }

    else {


        if (str != NULL) {

            snprintf( str, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job->id, job->priority, job->label);

            return str;

        }

        else {
        char* pdac;
        pdac = (char*) malloc(sizeof(JOB_STR_SIZE) );

        snprintf( pdac, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job-> id, job->priority, job-> label);
        return pdac;
        }
        

    } 

   return NULL;

}


/*
 * TODO: you must implement this function.
 * Hint:
 * - see the hint for job_to_str
 */
job_t* str_to_job(char* str, job_t* job) {

    if ( str == NULL || sscanf( str, JOB_STR_FMT )) {

        return NULL;

    }

    int pid;
    int id;
    int priority;
    char label[MAX_NAME_SIZE];
    char compare_str[JOB_STR_SIZE];

    if ( job == NULL ) {
        job_t* nullNew;
        nullNew = (job_t*) malloc(JOB_STR_SIZE * sizeof(job_t) );
        job_init(nullNew);
        
        sscanf(str, JOB_STR_FMT, &pid, &id, &priority, label);
        snprintf( compare_str, JOB_STR_SIZE, JOB_STR_FMT, pid, id, priority, label );
        if (strncmp(str, compare_str, JOB_STR_SIZE) != 0) {
            return NULL;
        }

        job_set(nullNew, pid, id, priority, label);
        job_copy(nullNew, job);


    }

    else {
        sscanf(str, JOB_STR_FMT, &job->pid, &job->id, &job->priority, job->label);
        snprintf( compare_str, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job->id, job->priority, job->label );


        if (strnlen(job->label, MAX_NAME_SIZE - 1) != MAX_NAME_SIZE - 1) {
            return NULL;
        }        
        if (strncmp(str, compare_str, JOB_STR_SIZE) !=0) {return NULL;
        }
    }



    return job;

}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    
    free (job);

    return;
}