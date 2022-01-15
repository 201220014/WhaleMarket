#include "interface/interface.h"

#include <stdio.h>

make_all(U, ser)
make_all(G, ood)
make_all(O, rder)

make_ban(U, ser, "User", NULL)
make_ban(G, ood, "Good", NULL)

make_search(Admin)

static HANDLER handler[] = {allGoods, search, allOrders, allUsers, banUser, banGood};
make_interface(A, DMIN)
