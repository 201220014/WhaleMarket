#include "interface/interface.h"

#include <stdio.h>

int curUser = -1;

static void asBuyer() {
    successMessage();
    BUYER_Interface();
}

static void asSeller() {
    successMessage();
    SELLER_Interface();
}



static HANDLER handler[] = {asBuyer, asSeller, INFO_Interface};
make_interface(U, SER)
