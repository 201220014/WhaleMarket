#include "interface/interface.h"

#include <stdio.h>

static void myGoods() {
    printGoods4Buyer();
    successMessage();
}

static void buy() {
    char buffer[MAX_LEN];
    printf("Please input Good id to buy: ");
    scanf("%s", buffer);
    int idx = searchGoodID(buffer);
    if (idx == -1) fail
    Good* g = getGood(idx);
    User* u = getUser(curUser);
    if (g->state != SELLING) fail
    if (g->price > u->balance) fail
    u->balance -= g->price;
    g->state = SOLD;
    topUp(g->seller_id, g->price);
    successMessage();
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

static void search() {
    char buffer[MAX_LEN];
    printf("Please input Good Name to search: ");
    scanf("%s", buffer);
    loadingMessage();
    searchGoodName(buffer);
    successMessage();
}

static HANDLER handler[] = {myGoods, buy, search, inv, info};
make_interface(B, UYER)
