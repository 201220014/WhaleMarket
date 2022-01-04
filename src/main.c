#include <stdio.h>
#include "interface/interface.h"
#include "tools/hint.h"
#include "user/user.h"

int main() {
    pullUsers();
    welcomeMessage();
    MAIN_Interface();
    exitingMessage();
    pushUsers();
    return 0;
}
