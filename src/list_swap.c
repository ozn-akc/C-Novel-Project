#include "headers/list_swap.h"


void swap_close(novel *a, novel *b){
    novel *temp_pre = a->pre;

    a->post = b->post;
    a->pre = b;
    a->pre->post = b;
    a->post->pre = a;

    b->pre = temp_pre;
    b->post = a;
    b->post->pre = b;
    b->pre->post = b;
}

void swap_first_last(novel *a, novel *b){
    novel *temp_pre = a->pre, *temp_post = a->post;

    a->post->pre = b;

    b->pre->post = a;

    a->pre = b->pre;
    a->post = b->post;

    b->pre = temp_pre;
    b->post = temp_post;
}

void swap_first_rando(novel *a, novel *b){
    novel *temp_pre = a->pre, *temp_post = a->post;

    a->post->pre = b;

    b->post->pre = a;
    b->pre->post = a;

    a->pre = b->pre;
    a->post = b->post;

    b->pre = temp_pre;
    b->post = temp_post;
}

void swap_last_rando(novel *a, novel *b){
    novel *temp_pre = a->pre, *temp_post = a->post;

    a->pre->post = b;

    b->post->pre = a;
    b->pre->post = a;

    a->pre = b->pre;
    a->post = b->post;

    b->pre = temp_pre;
    b->post = temp_post;
}

void swap_first_second(novel *a, novel *b){
    a->post = b->post;
    a->pre = b;
    a->pre->post = a;
    a->post->pre = a;

    b->pre = 0;
    b->post = a;
    b->post->pre = b;
}

void swap_last_snd_to_last(novel *a, novel *b){
    a->post = b;
    a->pre = b->pre;
    a->pre->post = a;
    a->post->pre = a;

    b->post = 0;
    b->pre = a;
    b->pre->post = b;
}

void swap_random(novel *a, novel *b){
    novel *temp_pre = a->pre, *temp_post = a->post;

    a->pre->post = b;
    a->post->pre = b;

    b->post->pre = a;
    b->pre->post = a;

    a->pre = b->pre;
    a->post = b->post;

    b->pre = temp_pre;
    b->post = temp_post;
}

void swap_items(novel *first, novel *second, novel_field *f){
    if(!first->pre && first->post){
        if(!second->post && second->pre){
            swap_first_last(first, second);
        }
        else if(first->post == second) {
            swap_first_second(first, second);
        }else{
            swap_first_rando(first, second);
        }
        f->start= second;
    } else if(!first->post && first->pre){
        if(!second->pre && second->post){
            swap_first_last(second, first);
            f->start= second;
        } else if(second->post == first){
            swap_last_snd_to_last(first, second);
        }else {
            swap_last_rando(first, second);
        }
    }else {
        if(!second->pre && second->post){
            swap_first_rando(second, first);
            f->start= first;
        }else if(!second->post && second->pre && first->post == second){
            swap_last_snd_to_last(second, first);
        }else if(!second->post && second->pre){
            swap_last_rando(second, first);
        }else if(first->post == second){
            swap_close(first, second);
        }
        else{
            swap_random(first, second);
        }
    }

}
