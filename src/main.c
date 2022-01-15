#include "interface/interface.h"
#include "tools/hint.h"

int main() {
    pullUsers();
    pullGoods();
    pullOrders();

    welcomeMessage();
    MAIN_Interface();
    exitingMessage();
    
    pushUsers();
    pushGoods();
    pushOrders();
    return 0;
}
