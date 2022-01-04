#ifndef _USER_H_
#define _USER_H_

#include "config.h"

#define MAX_USER 128

// type definition of user
typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    char passwd[MAX_LEN];
    char contact[MAX_LEN];
    char address[MAX_LEN];
    int balance;
} User;

extern User users[]; // all users
extern int totalUser; // total user number

/**
 * @brief pull all user infomation from external file
 * 
 */
void pullUsers();

/**
 * @brief push all user information into external file
 * 
 */
void pushUsers();

/**
 * @brief copy User src to User dest
 * 
 * @param dest pointer of dest user
 * @param src pointer of src user
 */
void userCopy(User* dest, const User* src);

/**
 * @brief search user with id
 * 
 * @param id user id to be searched
 * @return int -1 if failed else index in users
 */
int searchID(const char* id);

/**
 * @brief search user with name
 * 
 * @param name username to be searched
 * @return int -1 if failed else index in users
 */
int searchName(const char* name);

/**
 * @brief add user u to users
 * 
 * @param u user to be added
 * @return int 0 if failed else 1
 */
int addUser(User* u);

/**
 * @brief delete user u with id id
 * 
 * @param id user id to be deleted
 * @return int 0 if failed else 1
 */
int deleteUser(const char* id);

/**
 * @brief print all users' infomation
 * 
 */
void printUsers();

/**
 * @brief check if name and passwd are matched
 * 
 * @param name username
 * @param passwd password
 * @return int 1 if matched else 0
 */
int checkPass(const char* name, const char* passwd);

#endif
