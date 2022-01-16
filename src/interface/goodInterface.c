#include "interface/interface.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int curGood = -1;

static int checkModifiable() {
    User* u = getUser(curUser);
    Good* g = getGood(curGood);
    return strcmp(u->id, g->seller_id) == 0 && g->state == SELLING;
}

make_modify(name, G, ood)
make_modify(description, G, ood)

static void modify_price() {
    if (!checkModifiable) fail
    char buffer[MAX_LEN];
    printf("Please input new price: ");
    scanf("%s", buffer);
    check_double
    Good* x = getGood(curGood);
    x->price = m;
    successMessage();
}

static HANDLER handler[] = {modify_name, modify_price, modify_description};
make_interface(G, OOD)
