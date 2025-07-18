/*
    File handles context-sensitive functionality
    As of now, the only functionality handled is the "__func_name__" keyword
*/

#pragma once

void set_func_name(char *name);
char *func_name();