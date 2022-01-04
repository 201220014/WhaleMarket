#include "interface/interface.h"

#include <stdio.h>

static void asBuyer() {
    successMessage();
    BUYER_Interface();
}

static void asSeller() {
    successMessage();
    SELLER_Interface();
}

static HANDLER handler[] = {asBuyer, asSeller, inv, inv};
make_interface(U, SER)
