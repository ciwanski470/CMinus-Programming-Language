/*
    Implementation of "parser_context.h"
*/

char *curr_func;

void set_func_name(char *name) {
    curr_func = name;
}

void func_ended() {
    curr_func = 0;
}

char *func_name() {
    if (curr_func == 0) {
        printf("Error: __func_name__ used outside of function definition\n");
        return "";
    }
    return curr_func;
}