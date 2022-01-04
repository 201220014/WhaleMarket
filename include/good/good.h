#ifndef _GOOD_H_
#define _GOOD_H_

#include "config.h"

#define MAX_GOOD 128

// good state
typedef enum {SELLING, SOLD, BANNED} State;

// type definition of user
typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char description[MAX_LEN];
} Good;

extern Good goods[]; // all goods
extern int totalGood; // total good number

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
 * @brief copy Good src to Good dest
 * 
 * @param dest pointer of dest good
 * @param src pointer of src good
 */
void goodCopy(Good* dest, const Good* src);

/**
 * @brief search good with id
 * 
 * @param id good id to be searched
 * @return int -1 if failed else index in goods
 */
int searchGoodID(const char* id);

/**
 * @brief search good with name
 * 
 * @param name good name to be searched
 * @return int -1 if failed else index in goods
 */
int searchGoodName(const char* name);

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
 * @return int 0 if failed else 1
 */
int deleteGood(const char* id);

/**
 * @brief print all goods' infomation
 * 
 */
void printGoods();

#endif
