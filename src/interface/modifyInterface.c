#include "interface/interface.h"

#include <stdio.h>
#include <string.h>

static void modify_passwd() {
    char buffer[MAX_LEN];
    printf("Please input current password: ");
    scanf("%s", buffer);
    User* u = getUser(curUser);
    if (strcmp(u->passwd, buffer)) fail
    printf("Please input new password: ");
    scanf("%s", buffer);
    strcpy(u->passwd, buffer);
    successMessage();
}

make_modify(contact, U, ser)
make_modify(address, U, ser)

static HANDLER handler[] = {modify_passwd, modify_contact, modify_address};
make_interface(M, ODIFY)
