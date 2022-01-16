#include "interface/interface.h"

#include <stdio.h>
#include <stdlib.h>

static void info() {
    userInfo(curUser);
    successMessage();
}

static void topUp() {
    char buffer[MAX_LEN];
    printf("Please input the amount of money: ");
    scanf("%s", buffer);
    check_double
    User* u = getUser(curUser);
    u->balance += m;
    successMessage();
}

static HANDLER handler[] = {info, MODIFY_Interface, topUp};
make_interface(I, NFO)
