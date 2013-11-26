#include "init.h"

#ifdef DEBUG
    #include "time.h"
    time_t debug_start_timer, debug_end_timer;
#endif

void init_diff(int argc, char** argv, File files[]) {

    /* Analyse des paramètres */
    #ifdef DEBUG
        START_TIMER;
        printf("Start of the options analysing...\n");
    #endif

    initialize_params();

	atexit(free_params_glob); // Ajout à la liste

    make_params(argc, argv);

    #ifdef DEBUG
        STOP_TIMER;
        printf("... options analysing completed (%.4fs) \n--------------\n", GET_TIMER_VALUE);

        if(p->d_show_options) {
            print_params(p);
            if(p->d_interactive_mode) {
                printf("Press enter to continue...\n");
                getchar();
            }
        }
    #endif

    /* Analyse des chemins */
    files[0].path = malloc(sizeof(char)*(strlen(p->pathLeft)+1));
    strcpy(files[0].path, p->pathLeft);
    files[1].path = malloc(sizeof(char)*(strlen(p->pathRight)+1));
    strcpy(files[1].path, p->pathRight);

    /* Labels */
    if(p->label_1) {
        files[0].label = malloc(sizeof(char)*(strlen(p->label_1)+1));
        strcpy(files[0].label, p->label_1);
    } else {
        files[0].label = files[0].path;
    }

    if(p->label_2) {
        files[1].label = malloc(sizeof(char)*(strlen(p->label_2)+1));
        strcpy(files[1].label, p->label_2);
    } else {
        files[1].label = files[1].path;
    }

    files[0].i = NULL;
    files[1].i = NULL;

    set_paths(files);
}