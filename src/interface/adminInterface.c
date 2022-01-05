#include "interface/interface.h"

static void allUsers() {
    printUsers();
    successMessage();
}

static void allGoods() {
    printGoods();
    successMessage();
}

static HANDLER handler[] = {allGoods, inv, inv, allUsers, inv, inv, inv};
make_interface(A, DMIN)
