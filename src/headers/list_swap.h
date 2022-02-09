#ifndef NOVEL_PROJECT_LIST_SWAP_H
#define NOVEL_PROJECT_LIST_SWAP_H

#include "novel_list.h"

void swap_items(novel *first, novel *second, novel_field*);
void swap_first_last(novel *a, novel *b);
void swap_first_rando(novel *a, novel *b);
void swap_close(novel *a, novel *b);
void swap_last_rando(novel *a, novel *b);
void swap_first_second(novel *a, novel *b);
void swap_last_snd_to_last(novel *a, novel *b);

#endif //NOVEL_PROJECT_LIST_SWAP_H
