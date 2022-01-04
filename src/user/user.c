#include "user/user.h"
#include "tools/info.h"
#include <stdio.h>
#include <string.h>

User users[MAX_USER];
int totalUser = 0;

static const char* filePath = "src/data/user.txt";
const char* header = "";

void pullUsers() {
    totalUser = 0;
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        while (fscanf(pf, "%s%s%s%s%s%d", users[totalUser].id, \
users[totalUser].name, users[totalUser].passwd, users[totalUser].contact, \
users[totalUser].address, &(users[totalUser].balance)) != EOF) totalUser++;
        fclose(pf);
    }
}

void pushUsers() {
    FILE* pf = fopen(filePath, "w");
    for (int i = 0; i < totalUser; i++)
        fprintf(pf, "%s %s %s %s %s %d\n", users[i].id, users[i].name, users[i].passwd, \
users[i].contact, users[i].address, users[i].balance);
    fclose(pf);
}

void userCopy(User* dest, const User* src) {
    strcpy(dest->id, src->id);
    strcpy(dest->name, src->name);
    strcpy(dest->passwd, src->passwd);
    strcpy(dest->contact, src->contact);
    strcpy(dest->address, src->address);
    dest->balance = src->balance;
}

void printUsers() {
    for (int i = 0; i < totalUser; i++)
        printf("%s %s %s %s %s %d\n", users[i].id, users[i].name, users[i].passwd, \
users[i].contact, users[i].address, users[i].balance);
}

int searchName(const char* name) {
    for (int i = 0; i < totalUser; i++)
        if (strcmp(users[i].name, name) == 0) return i;
    return -1;
}

int addUser(User* u) {
    if (searchName(u->name) != -1) return 0;
    genID(u->id, 'U');
    userCopy(&users[totalUser++], u);
    return 1;
}

int searchID(const char* id) {
    for (int i = 0; i < totalUser; i++)
        if (strcmp(users[i].id, id) == 0) return i;
    return -1;
}

int deleteUser(const char* id) {
    int idx = searchID(id);
    if (idx == -1) return 0;
    for (int j = idx; j < totalUser - 1; j++) userCopy(&users[j], &users[j+1]);
    totalUser--;
    return 1;
}

int checkPass(const char* name, const char* passwd) {
    int idx = searchName(name);
    if (idx == -1) return 0;
    return strcmp(users[idx].passwd, passwd) == 0;
}
