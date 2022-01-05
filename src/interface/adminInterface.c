#include "interface/interface.h"

#include <stdio.h>

static void allUsers() {
    printUsers();
    successMessage();
}

static void allGoods() {
    printGoods();
    successMessage();
}

static void banUser() {
    char id[MAX_LEN];
    printf("Please input User ID to be baned: ");
    scanf("%s", id);
    if (deleteUser(id)) successMessage();
    else failureMessage();
}

static void banGood() {
    char id[MAX_LEN];
    printf("Please input Good ID to be baned: ");
    scanf("%s", id);
    if (deleteGood(id)) successMessage();
    else failureMessage();
}

static HANDLER handler[] = {allGoods, inv, inv, allUsers, banUser, banGood};
make_interface(A, DMIN)
