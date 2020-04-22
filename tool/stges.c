/*
	统计输入路径的文件中每个字符出现的次数
	使用：
		    生成的可执行文件 路径
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define ascll 127
# define towcode 223
# define cncode 239
# define wcode 247
# define charin 191

typedef struct cnlist{
	char cr[10];
	int weight;
	struct cnlist* pnext;
}CNS;

int juge(FILE*, char*, char*);
void traverse_list(CNS*);

void screen(FILE* in, CNS* cns){
	char buff;
	int time = 0;
	int size = 0;

	CNS* cmt = NULL;
	fseek(in, 0, SEEK_END);
	size = ftell(in);
	rewind(in);

	buff = fgetc(in);
	while(!feof(in)){
		cmt = cns;

		char tmp[10] = "0";
		juge(in, &buff, tmp);
		
		if(cmt->weight == 0 && cmt->pnext == NULL){
			strcpy(cmt->cr, tmp);
			cmt->weight ++;
			continue;
		}

		while(cmt != NULL){
			if(strcmp(cmt->cr, tmp) == 0){
				cmt->weight ++;
				break;
			}
			else if((!feof(in)) && cmt->pnext == NULL){
				cmt->pnext = (CNS*)malloc(sizeof(CNS));
				cmt->pnext->weight = 0;
				cmt->pnext->pnext = NULL;
				strcpy(cmt->pnext->cr, tmp);
				cmt->pnext->weight ++;
				break;
			}
			else{
				cmt = cmt->pnext;
			}
		}
	}
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("Error ::stges has only one parameter (address)");
		exit(-1);
	}

	FILE* in;
	if((in = fopen(argv[1], "r")) == NULL){
		perror("Error :");
		return 0;
	}
	CNS cns = {{0}, 0, NULL};
	screen(in, &cns);
	traverse_list(&cns);
	
	fclose(in);
	return 0;
}

int juge(FILE* in, char* buff, char* tmp){
	if(*buff == EOF){
		return EOF;
	}
	int i = 0;
	int time = 0;
	int j = 0;
	if((int)*buff <= ascll){
		*tmp = *buff;
		*buff = fgetc(in);
		time ++;
		return time;
	}
	else{
		if(((int)*buff) > ascll && ((int)*buff) <= towcode){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 2;
		}
		else if(((int)*buff) > ascll && ((int)*buff) <= cncode){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 3;
		}
		else if(((int)*buff) > ascll && ((int)*buff) <= wcode){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 4;
		}
		else{
			perror("Error: ");
			exit(-1);
		}
		while(((int)*buff) <= charin && j != 1){	
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			time ++;
			j --;
		}
	}
	return time;
}

void traverse_list(CNS* cns){
	CNS* cnt = cns;
	while(cnt != NULL){
		printf("字符> %s的权值为: ", cnt->cr);
		printf("%d\n", cnt->weight);
		cnt = cnt->pnext;
	}
}
