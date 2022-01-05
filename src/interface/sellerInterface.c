#include "interface/interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sell() {
    User* seller = getUser(curUser);
    Good* g = (Good*)malloc(sizeof(Good));
    printf("Please input the information of your product ...\n");
    printf("Name: ");
    scanf("%s", g->name);
    printf("Price: ");
    char buffer[MAX_LEN];
    scanf("%s", buffer);
    g->price = atof(buffer);
    while (g->price <= 0) {
        illegalMessage();
        printf("Please Try Again: ");
        scanf("%s", buffer);
        g->price = atof(buffer);
    }
    printf("Description: ");
    scanf("%s", g->description);
    strcpy(g->seller_id, seller->id);
    if (addGood(g)) successMessage();
    else failureMessage();
    free(g);
}

static void myGoods() {
    printGoods4Seller(getUser(curUser)->id);
    successMessage();
}

make_ban(G, ood, "Good", getUser(curUser)->id);

static HANDLER handler[] = {sell, myGoods, inv/*Modify*/, banGood, inv/*Order*/};
make_interface(S, ELLER)
