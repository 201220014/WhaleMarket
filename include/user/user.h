#ifndef _USER_H_
#define _USER_H_

#include "config.h"

// type definition of user
typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    char passwd[MAX_LEN];
    char contact[MAX_LEN];
    char address[MAX_LEN];
    double balance;
} User;

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
 * @brief Get the User object
 * 
 * @param idex index
 * @return User* pointer to result user
 */
User* getUser(int idex);

/**
 * @brief search user with id
 * 
 * @param id user id to be searched
 * @return int -1 if failed else index in users
 */
int searchUserID(const char* id);

/**
 * @brief search user with name
 * 
 * @param name username to be searched
 * @return int -1 if failed else index in users
 */
int searchUserName(const char* name);

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
 * @param idx index of user if exists else -1
 * @return int 1 if matched else 0
 */
int checkPass(const char* name, const char* passwd, int* idx);

#endif
