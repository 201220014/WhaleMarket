#ifndef _GOOD_H_
#define _GOOD_H_

#include "config.h"

// good state
typedef enum {SELLING, SOLD, BANNED} State;

// type definition of good
typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char date[MAX_LEN];
    char description[MAX_LEN];
} Good;

/**
 * @brief pull all good infomation from external file
 * 
 */
void pullGoods();

/**
 * @brief push all good information into external file
 * 
 */
void pushGoods();

/**
 * @brief Get the Good object
 * 
 * @param idex index
 * @return User* pointer to result good
 */
Good* getGood(int idex);

/**
 * @brief search good with id
 * 
 * @param id good id to be searched
 * @return int -1 if failed else index in goods
 */
int searchGoodID(const char* id);

/**
 * @brief add Good g to goods
 * 
 * @param u good to be added
 * @return int 0 if failed else 1
 */
int addGood(Good* g);

/**
 * @brief delete good u with id id
 * 
 * @param id good id to be deleted
 * @param who who does the deletion
 * @return int 0 if failed else 1
 */
int deleteGood(const char* id, const char* who);

/**
 * @brief print all goods' information
 * 
 */
void printGoods();

/**
 * @brief print search results for buyer
 * 
 * @param name good name to be searched
 */
void searchGoodName4Buyer(const char* name);

/**
 * @brief print search results for administrator
 * 
 * @param name good name to be searched
 */
void searchGoodName4Admin(const char* name);

/**
 * @brief good information
 * 
 * @param i good index
 */
void goodInfo(int i);

/**
 * @brief print goods with seller id
 * 
 * @param id seller id
 */
void printGoods4Seller(const char* id);

/**
 * @brief print avaliable goods
 * 
 * @param id buyer id
 */
void printGoods4Buyer(const char* id);

#endif
