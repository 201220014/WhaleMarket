#include "menu/menu.h"
#include "tools/hint.h"
#include <stdio.h>

// the number of menus
#define MENU_NUM 5

const int optionNum[MENU_NUM] = {4, 7, 4, 6, 6};

// visual propts for different menus
const char* mainMenu = "\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n";

const char* adminMenu = "\
+=========+==========+==========+=========+==========+=======+========+\n\
| 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |\n\
+=========+==========+==========+=========+==========+=======+========+\n";

const char* userMenu = "\
+=========+==========+==============+========+\n\
| 1.Buyer | 2.Seller | 3.Infomation | 4.Back |\n\
+=========+==========+==============+========+\n";

const char* buyerMenu = "\
+========+=========+==========+=======+=========+========+\n\
| 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
+========+=========+==========+=======+=========+========+\n";

const char* sellerMenu = "\
+=========+=======+==========+=========+==============+========+\n\
| 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Infomation | 6.Back |\n\
+=========+=======+==========+=========+==============+========+\n";

/**
 * @brief print visual prompt message
 * 
 * @param type menu type
 */
void promptMessage(Menu type) {
    const char* prompt;
    switch (type) {
        case MAIN:      prompt = mainMenu;      break;
        case ADMIN:     prompt = adminMenu;     break;
        case USER:      prompt = userMenu;      break;
        case BUYER:     prompt = buyerMenu;     break;
        case SELLER:    prompt = sellerMenu;    break;
    }
    printf("%s\nPlease choose operation: ", prompt);
}

int menu(Menu type) {
    promptMessage(type);
    int res;
    scanf("%d", &res);
    while (1) {
        if (res >= 1 && res <= optionNum[type]) break;
        illegalMessage();
        printf("Please try again: ");
        scanf("%d", &res);
    }
    successMessage();
    return res;
}
