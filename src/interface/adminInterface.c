#include "interface/interface.h"

#include <stdio.h>

make_all(U, ser)
make_all(G, ood)

make_ban(U, ser, "User", NULL)
make_ban(G, ood, "Good", NULL)

static HANDLER handler[] = {allGoods, inv, inv, allUsers, banUser, banGood};
make_interface(A, DMIN)
