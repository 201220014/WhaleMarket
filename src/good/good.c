#include "good/good.h"
#include "tools/info.h"
#include <stdio.h>
#include <string.h>

Good goods[MAX_GOOD];
int totalGood = 0;

const char* stateName[] = {"Selling", "Sold", "Banned"};

static const char* filePath = "src/data/good.txt";
static const char* header = "|ID         |Name       |Price      |Date       |Seller     |State      |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

void pullGoods() {
    totalGood = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(pf, "%s%s%lf%s%u%s%s", goods[totalGood].id, \
goods[totalGood].name, &goods[totalGood].price, goods[totalGood].seller_id, \
&goods[totalGood].state, goods[totalGood].date, goods[totalGood].description) != EOF) totalGood++;
        fclose(pf);
    }
}

void pushGoods() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalGood; i++)
        fprintf(pf, "%s %s %.1f %s %u %s %s\n", goods[i].id, goods[i].name, goods[i].price, \
goods[i].seller_id, goods[i].state, goods[i].date, goods[i].description);
    fclose(pf);
}

void goodCopy(Good* dest, const Good* src) {
    strcpy(dest->id, src->id);
    strcpy(dest->name, src->name);
    dest->price = src->price;
    strcpy(dest->seller_id, src->seller_id);
    dest->state = src->state;
    strcpy(dest->date, src->date);
    strcpy(dest->description, src->description);
}

void goodInfo(int i) {
    printf("ID: %s\n", goods[i].id);
    printf("Name: %s\n", goods[i].name);
    printf("Date: %s\n", goods[i].date);
    printf("Price: %.1f \n", goods[i].price);
    printf("Seller: %s \n", goods[i].seller_id);
    printf("State: %s \n", stateName[goods[i].state]);
}

void printGood(int i) {
    printf("|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n", goods[i].id, goods[i].name, goods[i].price, \
goods[i].date, goods[i].seller_id, stateName[goods[i].state]);
}

void printGoods() {
    print_header
    for (int i = 0; i < totalGood; i++) {
        printGood(i);
        printf("%s\n", divide);
    }
}

int addGood(Good* g) {
    if (totalGood == MAX_GOOD) return 0;
    genID(g->id, 'G');
    getDate(g->date);
    g->state = SELLING;
    goodCopy(&goods[totalGood++], g);
    return 1;
}

int searchGoodID(const char* id) {
    for (int i = 0; i < totalGood; i++)
        if (strcmp(goods[i].id, id) == 0) return i;
    return -1;
}

int deleteGood(const char* id) {
    int idx = searchGoodID(id);
    if (idx == -1) return 0;
    for (int j = idx; j < totalGood - 1; j++) goodCopy(&goods[j], &goods[j+1]);
    totalGood--;
    return 1;
}
