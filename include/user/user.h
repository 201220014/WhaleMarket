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
 * @brief Get the User object
 * 
 * @param idex index
 * @return User* pointer to result user
 */
User* getUser(int idex);

/**
 * @brief print detailed information
 * 
 * @param i user index
 */
void userInfo(int i);

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
 * @param who who does the deletion
 * @return int 0 if failed else 1
 */
int deleteUser(const char* id, const char* who);

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

/**
 * @brief top up money 
 * 
 * @param id user id
 * @param m money
 * @return int 0 if failed else 1
 */
int userTopUp(const char* id, double m);

#endif
