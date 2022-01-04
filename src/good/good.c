#include "good/good.h"
#include "tools/info.h"
#include <stdio.h>
#include <string.h>

Good goods[MAX_GOOD];
int totalGood = 0;

const char* stateName[] = {"Selling", "Sold", "Banned"};

static const char* filePath = "src/data/good.txt";
const char* header = "";

void pullGoods() {
    totalGood = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(pf, "%s%s%lf%s%u%s", goods[totalGood].id, \
goods[totalGood].name, &goods[totalGood].price, goods[totalGood].seller_id, \
&goods[totalGood].state, goods[totalGood].description) != EOF) totalGood++;
        fclose(pf);
    }
}

void pushGoods() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalGood; i++)
        fprintf(pf, "%s %s %lf %s %u %s\n", goods[i].id, goods[i].name, goods[i].price, \
goods[i].seller_id, goods[i].state, goods[i].description);
    fclose(pf);
}

void goodCopy(Good* dest, const Good* src) {
    strcpy(dest->id, src->id);
    strcpy(dest->name, src->name);
    dest->price = src->price;
    strcpy(dest->seller_id, src->seller_id);
    dest->state = src->state;
    strcpy(dest->description, src->description);
}

Good* getGood(int idx) { return goods + idx; }

void printGood(int i) {
    printf("%s %s %lf %s %d\n", goods[i].id, goods[i].name, goods[i].price, \
goods[i].seller_id, goods[i].state);
}

void printGoods() {
    for (int i = 0; i < totalGood; i++) 
        printGood(i);
}

int searchGoodName(const char* name) {
    for (int i = 0; i < totalGood; i++)
        if (strcmp(goods[i].name, name) == 0) return i;
    return -1;
}

int addGood(Good* g) {
    genID(g->id, 'G');
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
