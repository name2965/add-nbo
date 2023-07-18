#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t func(char * file_name);

int main(int argc,char* argv[]){
	if(argc != 3){
		printf("[X] input add-nbo <file1> <file2>\n");
		return -1;
	}
	uint32_t var1,var2;
	var1 = func(argv[1]);
	var2 = func(argv[2]);
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",var1,var1,var2,var2,var1+var2,var1+var2);
	return 0;
}

uint32_t func(char* file_name){
	FILE* fp;
        if((fp = fopen(file_name,"rb")) == NULL){
                printf("[X] open error\n");
                return -2;
        }
	uint32_t buffer[2];
	uint32_t ret;
        fread(buffer,sizeof(uint32_t),1,fp);
	ret = ntohl(buffer[0]);
        fclose(fp);
	return ret;
}
