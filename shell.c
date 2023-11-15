#include "shell.h"
/*
 *
 */

int main(void) {
    char command[120];

    while (true) {
        display_prompt();
        read_command(command, sizeof(command));
        exe_cmd(command);
    }





    

    return 0;
}

