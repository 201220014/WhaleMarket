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
    check_double
    g->price = m;
    printf("Description: ");
    scanf("%s", g->description);
    strcpy(g->seller_id, seller->id);
    if (addGood(g)) successMessage();
    else failureMessage();
    free(g);
}

static void modify() {
    printf("Please input the good ID to modify: ");
    char buffer[MAX_LEN];
    scanf("%s", buffer);
    curGood = searchGoodID(buffer);
    if (curGood == -1) fail
    User* u = getUser(curUser);
    Good* g = getGood(curGood);
    if (strcmp(u->id, g->seller_id) == 0 && g->state == SELLING) 
        GOOD_Interface();
    else failureMessage();
}

make_my(Goods, S, eller)
make_my(Orders, S, eller)

make_ban(G, ood, "Good", getUser(curUser)->id);

static HANDLER handler[] = {sell, myGoods, modify, banGood, myOrders};
make_interface(S, ELLER)
