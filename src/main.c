#include "interface/interface.h"
#include "tools/hint.h"
#include "user/user.h"

int main() {
    pullUsers();
    pullGoods();
    welcomeMessage();
    MAIN_Interface();
    exitingMessage();
    pushUsers();
    pushGoods();
    return 0;
}
