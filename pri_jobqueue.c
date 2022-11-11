/*
 * Replace the following string of 0s with your student number
 * 210288315
 */
#include <stdlib.h>
#include <stdbool.h>
#include "pri_jobqueue.h"

/* 
 * TODO: you must implement this function that allocates a job queue and 
 * initialise it.
 * Hint:
 * - see job_new in job.c
 */
pri_jobqueue_t* pri_jobqueue_new( int buf_size, int size, job_t jobs) {   // double check
    
    pri_jobqueue_t* newJobQueue  = (pri_jobqueue_t*) malloc(sizeof(pri_jobqueue_t)); //malloc(sizeof(pri_jobqueue_t)); <-- malloc(JOB_BUFFER_SIZE)
    pri_jobqueue_init( newJobQueue );
    return newJobQueue;
}

/*   
 * TODO: you must implement this function.
 */
void pri_jobqueue_init(pri_jobqueue_t* pjq) {   // double check
    pjq->buf_size = JOB_BUFFER_SIZE; 
    pjq->size = 0;

    for (int i=0; i < pjq->buf_size; i++ ) {
        job_init(&pjq->jobs[i]);

    }

    

    return;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 *      - if a queue is not empty, and the highest priority job is not in the 
 *      last used slot on the queue, dequeueing a job will result in the 
 *      jobs on the queue having to be re-arranged
 *      - remember that the job returned by this function is a copy of the job
 *      that was on the queue
 */
job_t* pri_jobqueue_dequeue(pri_jobqueue_t* pjq, job_t* dst) {
    if (pjq == NULL || !pjq->size || pjq->jobs[pjq->size - 1].pid < 0  
        || !pjq->jobs[pjq->size - 1].priority)
        return NULL;

    if ( dst != NULL ) {

        *dst = pjq->jobs[pjq->size - 1]; 
        job_init(&pjq->jobs[pjq->size - 1]);
        pjq->size--;
        return dst;
        

    }

    else {
        
        job_t* newPointer = (job_t*)malloc(sizeof(job_t));
        *newPointer = pjq->jobs[pjq->size - 1];
        job_init(&pjq->jobs[pjq->size - 1]);
        pjq->size--;
        return newPointer;

    }



    }






/* 
 * TODO: you must implement this function.
 * Hints:
 * - if a queue is not full, and if you decide to store the jobs in 
 *      priority order on the queue, enqueuing a job will result in the jobs 
 *      on the queue having to be re-arranged. However, it is not essential to
 *      store jobs in priority order (it simplifies implementation of dequeue
 *      at the expense of extra work in enqueue). It is your choice how 
 *      you implement dequeue (and enqueue) to ensure that jobs are dequeued
 *      by highest priority job first (see pri_jobqueue.h)
 * - remember that the job passed to this function is copied to the 
 *      queue
 */
void pri_jobqueue_enqueue(pri_jobqueue_t* pjq, job_t* job) {

if ( pjq == NULL || job == NULL ) {

    return;
} 

if (pjq->size == pjq->buf_size || !job->priority) 
        return;

    int top = pjq->size;
    
    for (int i = 0; i < pjq->size; i++) {
        if (pjq->jobs[i].priority <= job->priority) {
            top = i;
            break;
        }
    }
        
    for (int i = pjq->size - 1; i > top - 1; i--)
        pjq->jobs[i + 1] = pjq->jobs[i];

    pjq->jobs[top].pid = job->pid;
    pjq->jobs[top].id = job->id;
    pjq->jobs[top].priority = job->priority; 
    
    pjq->size++;
    
    return;


}



//     if ( pjq->size == pjq->buf_size || !job->priority ) {
//         return;

//     }

//     int top = pjq->size;
    
//     int i = 0;

//     if ( i < pjq->size, i++) {
//         if (pjq->jobs[i].priority <= job->priority) {
//             top = i;
//             return;
//         }
//     }
        
//     i = pjq->size - 1;
//     if ( i > top - 1, i--)
//         pjq->jobs[i + 1] = pjq->jobs[i];

//     pjq->jobs[top].pid = job->pid;
//     pjq->jobs[top].id = job->id;
//     pjq->jobs[top].priority = job->priority; 
    
//     pjq->size++;


//     //if ( pjq == NULL ) {


//     return;

// }
   


/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_empty(pri_jobqueue_t* pjq) {
    
    if ( pjq == NULL || pjq->size == 0 ) {

        //pjq->size = 0;
        //pjq->jobs = 0;
        //pjq->buf_size = 0;

    return true;

    }

    

    else   
    return false; 

    


}

/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_full(pri_jobqueue_t* pjq) {
    
    if ( pjq == NULL ) {
    return true;
    }

    if ( pjq->size == pjq->buf_size )
    return true;


    else  return false; 
}

/* 
 * TODO: you must implement this function.
 * Hints:
 *      - remember that the job returned by this function is a copy of the 
 *      highest priority job on the queue.
 *      - both pri_jobqueue_peek and pri_jobqueue_dequeue require copying of 
 *      the highest priority job on the queue
 */
job_t* pri_jobqueue_peek(pri_jobqueue_t* pjq, job_t* dst) {


if (!pjq->size || pjq->jobs[pjq->size - 1].pid < 0  
        || !pjq->jobs[pjq->size - 1].priority){
        return NULL;
        }

if ( dst == NULL) {

    job_t* newJob = ((job_t*)malloc(sizeof(job_t)));
    *newJob = pjq->jobs[pjq->size - 1];
    return newJob;

}
*dst = pjq->jobs[pjq->size - 1];    
return dst;

}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_size(pri_jobqueue_t* pjq) {

if ( pjq == NULL ) {
    return 0;


}

if ( pjq != NULL ) {
    return pjq->size;

}
//int size = pri_jobqueue_size(pjq);      // get the queue's size
//printf("%d\n", size);

//if ( size(pjq) != NULL ) {

//int size(pjq) = ">=0";

//}

}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_space(pri_jobqueue_t* pjq) {
    
    if ( pjq == NULL ) {
        return 0;

    }

    int spaceAvailable = pjq->buf_size - pjq->size;

    return spaceAvailable;
    
    // if ( pjq != NULL )  {
    //     return pjq->buf_size;

    // }
    
    // return 0;
}

 
/* 
 * TODO: you must implement this function.
 *  Hint:
 *      - see pri_jobqeue_new
 */
void pri_jobqueue_delete(pri_jobqueue_t* pjq) {

    if ( pjq != NULL ) {

        free(pjq);
    }

    else
    
    return;
}
