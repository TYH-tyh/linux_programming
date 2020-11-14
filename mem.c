#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct PACKED{
    int total;
    int free;
    int buffer;
    int cached;
    int used;
}MEM_OCCUPY;

void get_memoccupy(MEM_OCCUPY *mem){
    char buf[BUF_SIZE];
    char name[BUF_SIZE];
    FILE *fp;
    int len;

    //open file /proc/meminfo
    if((fp = fopen("/proc/meminfo", "r")) == NULL){
        printf("error!");
    }

    while(fgets(buf, BUF_SIZE, fp) != NULL){
        len = strlen(buf);
        buf[len - 1] = '\0';
        if(sscanf(buf, "%s", name) == 1){
            if(!strcmp(name, "MemTotal:")){
                sscanf(buf, "%*s%d", &(mem->total));
            }
            if(!strcmp(name, "MemFree:")){
                sscanf(buf, "%*s%d", &(mem->free));
            }
            if(!strcmp(name, "Buffers:")){
                sscanf(buf, "%*s%d", &(mem->buffer));
            }
            if(!strcmp(name, "Cached:")){
                sscanf(buf, "%*s%d", &(mem->cached));
            }
        }
        mem->used = mem->total - mem->free - mem->buffer - mem->cached;
       
    }
}

int main(){
    MEM_OCCUPY mem;

    get_memoccupy(&mem);

    printf("total:%d\n", mem.total);
    printf("used:%d\n", mem.used);
    printf("free:%d\n", mem.free);

    return 0;
}

