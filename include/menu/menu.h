#ifndef _MENU_H_
#define _MENU_H_

// types of menu
typedef enum {MAIN, ADMIN, USER, BUYER, SELLER, INFO, MODIFY, GOOD} Menu;

// the number of option for different menus
extern const int optionNum[];

/**
 * @brief a menu is what gives some prompt and gets a user input 
 * 
 * @param type menu type
 * @return int user input
 */
int menu(Menu type);

#endif
