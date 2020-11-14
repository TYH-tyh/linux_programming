#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 512

typedef struct PACKED{
	int main_total; 
	int main_free;
	int main_buffer ;
	int main_cached ; 
	int main_used;
}MEM_OCCUPY;

void get_memoccupy(MEM_OCCUPY *mem){
	char buf[BUF_SIZE];
	char name[BUF_SIZE];
	FILE *fp;
	int len;
	
	//open file /proc/meminfo
	if((fp = fopen(" /proc/meminfo", "r")) == NULL){
		printf("error!");
	}
	
	while(fgets(buf, BUF_SIZE, fp) != NULL){
		len = strlen(buf);
		buf[len - 1] = '\0';
		if(sscanf(buf, "%s", name) == 1){
			if( !strcmp(name, "MemTotal:")){
				sscanf(buf, "%*s%d", &(mem->main_total));
			}
			if( !strcmp(name,"MenFree:")){
				len = strlen(buf );
				buf[len-1]='\0';
				if(sscanf(buf, "s%",name) == 1){
					if( !strcmp(name,"MemTotal:")){
						sscanf(buf, "%*s%d", &(mem->main_total));
					}
					if(!strcmp(name, "MenFree:")){
						sscanf(buf, "%*s%d", &(mem->main_free));
					}
					if(!strcmp(name,"Buffers:")){
						sscanf(buf, "%*s%d", &(mem->main_buffer));
					}
					if( !strcmp(name, "Cached:")){
						sscanf(buf, "%*s%d", &(mem->main_cached));
					}
				}
				mem->main_used = mem->main_total - mem->main_free - mem->main_buffer - mem->main_cached;
		}
		
int main(){
	MEM_OCCUPY mem_state;
	
	get_memoccupy(&mem_state);
	
	printf("total:%d\n",mem_state.main_total);
	printf("used:%d\n",mem_state .main_used);
	printf("free:%d\n",mem_state.main_free);
	
	return 0;
}
