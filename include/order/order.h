#ifndef _ORDER_H_
#define _ORDER_H_

#include "config.h"

// type definition of order
typedef struct {
    char id[MAX_LEN];
    char good_id[MAX_LEN];
    double price;
    char date[MAX_LEN];
    char seller_id[MAX_LEN];
    char buyer_id[MAX_LEN];
} Order;

/**
 * @brief pull all order infomation from external file
 * 
 */
void pullOrders();

/**
 * @brief push all order information into external file
 * 
 */
void pushOrders();

/**
 * @brief add Order o to orderss
 * 
 * @param o order to be added
 * @return int 0 if failed else 1
 */
int addOrder(Order* o);

/**
 * @brief print all orders' information
 * 
 */
void printOrders();

/**
 * @brief print orders with seller id
 * 
 * @param id seller id
 */
void printOrders4Seller(const char* id);

/**
 * @brief print orders with buyer id
 * 
 * @param id buyer id
 */
void printOrders4Buyer(const char* id);

#endif
