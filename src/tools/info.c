#include "tools/info.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static const char* filePath = "src/data/id.txt";

void getDate(char* dest) {
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo = localtime(&rawtime);
    sprintf(dest, "%d-%d-%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
}

void genID(char* dest, char type) {
    int uid = 0, gid = 0, oid = 0; // user, good, order
    FILE* pf = fopen(filePath, "r");
    if (pf) {
        fscanf(pf, "%d%d%d", &uid, &gid, &oid);
        fclose(pf);
    }
    int id = 0;
    switch (type) {
        case 'U': id = uid++; break;
        case 'G': id = gid++; break;
        case 'O': id = oid++; break;
    }
    sprintf(dest, "%c%05d", type, id);
    pf = fopen(filePath, "w");
    fprintf(pf, "%d %d %d\n", uid, gid, oid);
    fclose(pf);
}
