#include "interface/interface.h"

static void allUsers() {
    printUsers();
    successMessage();
}

static HANDLER handler[] = {inv, inv, inv, allUsers, inv, inv, inv};
make_interface(A, DMIN)
