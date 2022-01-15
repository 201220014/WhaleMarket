#ifndef _INFO_H_
#define _INFO_H_

/**
 * @brief Get the Date
 * 
 * @param dest string to store the date
 */
void getDate(char* dest);

/**
 * @brief generate an ID
 * 
 * @param dest string to store the ID
 * @param type ID type
 */
void genID(char* dest, char type);

// helper macro for print
#define print_header \
    printf("%s\n", divide);\
    printf("%s\n", header);\
    printf("%s\n", divide);

#define print_divide \
    printf("%s\n", divide);

#endif
