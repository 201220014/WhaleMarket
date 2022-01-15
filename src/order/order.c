#include "order/order.h"
#include "tools/info.h"
#include <stdio.h>
#include <string.h>

static Order orders[MAX_ORDER]; // all orders
static int totalOrder = 0;

static const char* filePath = "src/data/order.txt";
static const char* header = "|ID         |Good       |Price      |Date       |Seller     |Buyer      |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

void pullOrders() {
    totalOrder = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(pf, "%s%s%lf%s%s%s", orders[totalOrder].id, \
orders[totalOrder].good_id, &orders[totalOrder].price, orders[totalOrder].date, \
orders[totalOrder].seller_id, orders[totalOrder].buyer_id) != EOF) totalOrder++;
        fclose(pf);
    }
}

void pushOrders() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalOrder; i++)
        fprintf(pf, "%s %s %.1f %s %s %s\n", orders[i].id, \
orders[i].good_id, orders[i].price, orders[i].date, \
orders[i].seller_id, orders[i].buyer_id);
    fclose(pf);
}

int addOrder(Order* o) {
    if (totalOrder == MAX_ORDER) return 0;
    genID(o->id, 'O');
    getDate(o->date);
    orders[totalOrder++] = *o;
    return 1;
}

static void printOrder(int i) {
    printf("|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n", orders[i].id, \
orders[i].good_id, orders[i].price, orders[i].date, \
orders[i].seller_id, orders[i].buyer_id);
}

void printOrders() {
    print_header
    for (int i = 0; i < totalOrder; i++) {
        printOrder(i);
        print_divide
    }
}

void printOrders4Seller(const char* id) {
    print_header
    for (int i = 0; i < totalOrder; i++)
        if (strcmp(orders[i].seller_id, id) == 0) {
            printOrder(i);
            print_divide
        }
}

void printOrders4Buyer(const char* id) {
    print_header
    for (int i = 0; i < totalOrder; i++)
        if (strcmp(orders[i].buyer_id, id) == 0) {
            printOrder(i);
            print_divide
        }
}
