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
    double m = atof(buffer);
    while (1) {
        if (m > 0) break;
        illegalMessage();
        printf("Please try again: ");
        scanf("%s", buffer);
        m = atof(buffer);
    }
    User* u = getUser(curUser);
    u->balance += m;
    successMessage();
}

static HANDLER handler[] = {info, MODIFY_Interface, topUp};
make_interface(I, NFO)
