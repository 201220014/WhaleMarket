#include "interface/interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv() { 
    invalidMessage(); 
    failureMessage();
}

make_login(U, SER, checkPass(username, passwd, &curUser))
make_login(A, DMIN, strcmp(username, ADMIN_NAME) == 0 && strcmp(passwd, ADMIN_PASS) == 0)

static void USER_SignUp() {
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

static HANDLER handler[] = {USER_Login, USER_SignUp, ADMIN_Login};
make_interface(M, AIN)
