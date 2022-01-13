#include "interface/interface.h"

int curUser = -1;

static HANDLER handler[] = {BUYER_Interface, SELLER_Interface, INFO_Interface};
make_interface(U, SER)
