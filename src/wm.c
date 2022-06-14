#include <config.h>
#include <wm.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int execute_binary(char* command){
    char* argv[100];
    int argc = 0;
    argv[argc] = strtok(command, " ");
    while (argv[argc]){
        argc++;
        argv[argc] = strtok(0, " ");
    }
    int status;
    if(fork() == 0){
        execvp(command, argv);
    } else {
        wait(&status);
    }
    return status;
}


void init_desktops(const desktop_t* desktop_all, int mode){
    char* temp = malloc(sizeof(char)*100);
    strcpy(temp, "bspc monitor -d ");
    int i = 0;

    while(desktop_all[i].name){
        strcat(temp, desktop_all[i].name);
        i++;
    }
    if (mode == DEBUG)
        printf("Desktops configuration...\n%s\n\n", temp);
    else {
        printf("Setting desktops...\n");
        execute_binary(temp);
    }
    free(temp);
}

void init_config(const config_t* config_all, int mode){
    int i = 0;
    if(mode == DEBUG) {
        printf("WM Configurations...\n");
        while(config_all[i].name){
            printf("bspc config %s %s\n", config_all[i].name, config_all[i].value);
            i++;
        }
    } else {
        printf("Setting WM Configurations...\n");
        while(config_all[i].name){
            char* buffer = malloc(sizeof(char)*100);
            sprintf(buffer, "bspc config %s %s\n", config_all[i].name, config_all[i].value);
            printf("bspc config %s %s\n", config_all[i].name, config_all[i].value);
            //execute_binary(buffer);
            system(buffer);
            free(buffer);
            i++;
        }
    }
    printf("\n");
}

void init_window_rules(const window_rule_t* window_rule_all, int mode){
    int i = 0;
    if (mode == DEBUG){
        printf("Window Rules...\n");
        while (window_rule_all[i].name){
            printf("bspc rule -a %s desktop=%s state=%s follow=%s\n", 
                    window_rule_all[i].name, window_rule_all[i].desktop, 
                    window_rule_all[i].state, window_rule_all[i].follow);
                    i++;
        }
    } else {
        printf("Setting Window Rules...\n");
        while(window_rule_all[i].name){
            char* buffer = malloc(sizeof(char)*100);
            sprintf(buffer, "bspc rule -a %s desktop=%s state=%s follow=%s\n", 
                    window_rule_all[i].name, window_rule_all[i].desktop, 
                    window_rule_all[i].state, window_rule_all[i].follow);
            execute_binary(buffer);
            free(buffer);
            i++;
        }
    }
}

void init_autostart_script(const char* autostart_script, int mode){
    if (mode == DEBUG)
        printf("\nAutostart script...\n%s\n\n", autostart_script);
    else{
        printf("\nRunning Autostart script...\n%s\n\n", autostart_script);
        execute_binary((char*)autostart_script);
    }
}

void init_bar_script(const char* bar_script, int mode){
    if (mode == DEBUG)
        printf("\nBar script...\n%s\n\n", bar_script);
    else{
        printf("\nRunning Bar script...\n%s\n\n", bar_script);
        execute_binary((char*)bar_script);
    }
}

void init_bspwm(int mode){
    if (mode == DEBUG)
        printf("Generating Configuration...\n\n");

    init_desktops(desktops, mode);
    init_config(configs, mode);
    init_window_rules(window_rules, mode);
    init_autostart_script(autostart_script, mode);
    init_bar_script(bar_script, mode);
}