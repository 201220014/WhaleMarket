#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "tools/hint.h"
#include "menu/menu.h"
#include "user/user.h"
#include "good/good.h"

// invalid prompt
void inv();

// current User
extern int curUser;

typedef void (*HANDLER)(void);

/* An interface gets user input with corresponding menu and handles it. */

/**
 * @brief 
 * | 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |
 */
void MAIN_Interface();

/**
 * @brief 
 * | 1.Buyer | 2.Seller | 3.Infomation | 4.Back |
 */
void USER_Interface();

/**
 * @brief 
 * | 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |
 */
void ADMIN_Interface();

/**
 * @brief 
 * | 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Infomation | 6.Back |
 */
void BUYER_Interface();

/**
 * @brief 
 * | 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
 */
void SELLER_Interface();


// below are some helper macros that simplify codes

#define make_interface(T, YPE)\
void T##YPE##_Interface() {\
    int op = menu(T##YPE);\
    while (op != optionNum[T##YPE]) {\
        loadingMessage();\
        handler[op - 1]();\
        op = menu(T##YPE);\
    }\
    loadingMessage();\
    successMessage();\
}

#define get_username_passwd\
    char username[MAX_LEN];\
    char passwd[MAX_LEN];\
    printf ("Username: ");\
    scanf("%s", username);\
    printf ("Password: ");\
    scanf("%s", passwd);

#define make_login(T, YPE, cond)\
static void T##YPE##_Login() {\
    get_username_passwd\
    if (cond) {\
        successMessage();\
        T##YPE##_Interface();\
        return ;\
    }\
    failureMessage();\
}

#endif
