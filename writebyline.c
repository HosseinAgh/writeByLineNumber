#include <stdio.h>
#include <ctype.h>
int main(int argc,char* argv[]){

	if(argc != 3)
		printf("‌writebyline.‌exe <in file> <out file>");

	FILE* fpr = fopen(argv[1],"r");
	if(fpr == NULL){
		printf("faild to open file %s",argv[1]);
		return 0;
	}

	FILE* fpw = fopen(argv[2],"w");
	if(fpw == NULL){
		printf("faild to create file %s",argv[2]);
		fclose(fpr);
		return 0;
	}

	char buff[1000];
	char buf[1000];
	int index = 0;
	while(!feof(fpr)){
		if(NULL == fgets(buff,sizeof(buff)/sizeof(buff[0]),fpr))
			break;
		sprintf(buf,"[%d]-%s",index,buff);
		printf("[%d]-%s",index,buff);
		index++;
		fputs(buf,fpw);
	}
	fclose(fpr);
	fclose(fpw);

}
