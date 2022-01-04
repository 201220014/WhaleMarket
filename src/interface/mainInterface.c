#include "interface/interface.h"
#include "tools/hint.h"
#include "menu/menu.h"
#include "user/user.h"

#include <stdio.h>
#include <stdlib.h>

HANDLER handler[] = { };

void mainInterface() {
    int op = menu(MAIN);
    while (op != 4) {
        loadingMessage();
        handler[op - 1]();
        op = menu(MAIN);
    }
    loadingMessage();
}

void userLogin() {
    char username[MAX_LEN];
    char passwd[MAX_LEN];
    printf ("Username: ");
    scanf("%s", username);
    printf ("Password: ");
    scanf("%s", passwd);
    if (checkPass(username, passwd)) {
        successMessage();
        loadingMessage();
        // TODO: user interface
        return ;
    }

}

void userSignUp() {
    User* u = (User*)malloc(sizeof(User));
    printf("Please input your username: ");
    scanf("%s", u->name);
    printf("Please input your password: ");
    scanf("%s", u->passwd);
    printf("Please input your phone number: ");
    scanf("%s", u->contact);
    printf("Please input your address: ");
    scanf("%s", u->address);
    u->balance = 0;
    if (addUser(u)) successMessage();
    else failureMessage();
    free(u);
}

void adminLogin() {

}

