#ifndef _INTERFACE_H_
#define _INTERFACE_H_

typedef void (*HANDLER)(void);

/**
 * @brief get user input with mainMenu and handle it
 * 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit
 */
void MAIN_Interface();

#define makeInterface(T, YPE)\
void T##YPE##_Interface() {\
    int op = menu(T##YPE);\
    while (op != optionNum[T##YPE]) {\
        loadingMessage();\
        handler[op - 1]();\
        op = menu(T##YPE);\
    }\
    loadingMessage();\
}

#endif
