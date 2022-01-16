#include "interface/interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void buy() {
    char buffer[MAX_LEN];
    printf("Please input Good id to buy: ");
    scanf("%s", buffer);
    int idx = searchGoodID(buffer);
    if (idx == -1) fail

    Good* g = getGood(idx);
    User* u = getUser(curUser); // buyer

    if (g->state != SELLING) fail
    if (g->price > u->balance) fail
    
    u->balance -= g->price;
    g->state = SOLD;
    userTopUp(g->seller_id, g->price);

    // generate an order
    Order* o = (Order*)malloc(sizeof(Order));
    strcpy(o->good_id, g->id);
    strcpy(o->seller_id, g->seller_id);
    strcpy(o->buyer_id, u->id);
    o->price = g->price;

    if (addOrder(o)) successMessage();
    else failureMessage();
    free(o);
}

static void info() {
    char buffer[MAX_LEN];
    printf("Please input Good ID for more information: ");
    scanf("%s", buffer);
    int idx = searchGoodID(buffer);
    if (idx == -1) fail
    loadingMessage();
    goodInfo(idx);
    successMessage();
}

make_search(Buyer)

make_my(Goods, B, uyer)
make_my(Orders, B, uyer)

static HANDLER handler[] = {myGoods, buy, search, myOrders, info};
make_interface(B, UYER)
