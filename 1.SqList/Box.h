#ifndef BOX_H
#define BOX_H

#include <iostream>

#include <string.h>
#include "Status.h"

#define BOX_NAME_MAX_SIZE 20

typedef struct Box
{
    int no;
    char name[BOX_NAME_MAX_SIZE];
} Box;

Box *CreateBox(int no, const char *name);
Status InitBox(Box *box, int no, const char *name);
Status DestroyBox(Box *box);

Box *CreateBox(int no, const char *name)
{
    Box *box = new Box;
    InitBox(box, no, name);
    return box;
}

Status InitBox(Box *box, int no, const char *name)
{
    if (box == nullptr) {
        return ERROR;
    }
    box -> no = no;
    if (name != nullptr){
        strncpy(box -> name, name, BOX_NAME_MAX_SIZE - 1);
        box -> name[BOX_NAME_MAX_SIZE - 1] = '\0';
    } else {
        box -> name[0] = '\0';
    }
 
    return OK;
}

Status DestroyBox(Box *box)
{
    if (box == nullptr) {
        return ERROR;
    }
    delete box;
    return OK;
}

#endif