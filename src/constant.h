#ifndef _H_CONSTANT
#define _H_CONSTANT

/* == Inlcudes == */
#include "my_types.h"
#include "init/params.h"
#include "err/err.h"

/* == Var Globales == */
#ifdef DEBUG
    #include "time.h"
    extern time_t debug_start_timer, debug_end_timer;
    #define START_TIMER debug_start_timer=clock()
    #define STOP_TIMER debug_end_timer=clock()
    #define GET_TIMER_VALUE ((debug_end_timer-debug_start_timer)/(double)CLOCKS_PER_SEC)
#endif
extern Params *p;
extern suint diff_stderr_show_help;


#endif