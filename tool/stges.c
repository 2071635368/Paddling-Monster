/*
	完成时间: 2020.4.25 / 12:05
	作者:MX_PMUP

	作用: 统计输入路径的文件中每个字符出现的次数(适用于UTF-8编码)

	使用：
		    生成的可执行文件 路径
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define ASCII 127
# define TOWCODE 223
# define CNCODE 239
# define WCODE 247
# define CHARIN 191

typedef struct cnlist{
	char cr[10];
	int weight;
	struct cnlist* pnext;
}CNS;

int juge(FILE*, char*, char*);
int traverse_list(CNS*);
void sort(CNS*, int, int, int);
void meger(CNS*, int, int);
void meger_sort(CNS*);

void screen(FILE* in, CNS* cns){
	char buff;
	int time = 0;
	int size = 0;

	buff = fgetc(in);
	while(!feof(in)){
		CNS* cmt = cns;

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
	meger_sort(&cns);
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
	if((int)*buff <= ASCII){
		*tmp = *buff;
		*buff = fgetc(in);
		time ++;
		return time;
	}
	else{
		if(((int)*buff) > ASCII && ((int)*buff) <= TOWCODE){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 2;
		}
		else if(((int)*buff) > TOWCODE && ((int)*buff) <= CNCODE){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 3;
		}
		else if(((int)*buff) > CNCODE && ((int)*buff) <= WCODE){
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			j = 4;
		}
		else{
			perror("Error: ");
			exit(-1);
		}
		while(((int)*buff) <= CHARIN && j != 1){	
			tmp[i] = *buff;
			*buff = fgetc(in);
			i ++;
			time ++;
			j --;
		}
	}
	return time;
}

void meger_sort(CNS* cns){
	int len = 0;
	CNS* cnt = cns;
	while(cnt != NULL){
		cnt = cnt->pnext;
		len ++;
	}
	meger(cns, 0, len-1);
}

void meger(CNS* cns, int low, int len){
	if(low >= len){
		return;
	}
	int mid = (low + len) / 2;
	meger(cns, low, mid);
	mid ++;
	meger(cns, mid, len);
	sort(cns, low, mid, len);
}

void sort(CNS* cns, int low, int mid, int len){
	CNS* tlow = cns;
	CNS* tmid = cns;
	CNS* tlen = cns;
	for(int i = 0; i < low; i ++){
		tlow = tlow->pnext;
	}
	for(int i = 0; i < mid; i ++){
		tmid = tmid->pnext;
	}
	for(int i = 0; i < len; i ++){
		if(tlen->pnext != NULL){
			tlen = tlen->pnext;
		}
	}
	
	int ls = mid - low;
	int rs = len - mid + 1;
	CNS* lcns = (CNS*)malloc(sizeof(CNS) * ls);
	CNS* rcns = (CNS*)malloc(sizeof(CNS) * rs);

	int i = 0;
	CNS* tmp = tlow;
	while(tmp != tmid){
		strcpy(lcns[i].cr, tmp->cr);
		lcns[i].weight = tmp->weight;
		tmp = tmp->pnext;
		i ++;
	}

	i = 0;
	tmp = tmid;
	while(tmp != tlen){
		strcpy(rcns[i].cr, tmp->cr);
		rcns[i].weight = tmp->weight;
		tmp = tmp->pnext;
		i ++;
	}
	if(tmp == tlen){
		strcpy(rcns[i].cr, tmp->cr);
		rcns[i].weight = tmp->weight;
	}
	
	i = 0;
	tmp = tlow;
	int j = 0, k = 0;
	while(j < ls && k < rs && tmp->pnext != NULL){
		if(lcns[j].weight < rcns[k].weight || lcns[j].weight == rcns[k].weight){
			strcpy(tmp->cr, lcns[j].cr);
			tmp->weight = lcns[j].weight;
			tmp = tmp->pnext;
			j ++;
		}
		else{
			strcpy(tmp->cr, rcns[k].cr);
			tmp->weight = rcns[k].weight;
			tmp = tmp->pnext;
			k ++;
		}
	}

	while(j < ls || k < rs && tmp->pnext != NULL){
		if(j < ls){
			strcpy(tmp->cr, lcns[j].cr);
			tmp->weight = lcns[j].weight;
			tmp = tmp->pnext;
			j ++;
		}
		else{
			strcpy(tmp->cr, rcns[k].cr);
			tmp->weight = rcns[k].weight;
			tmp = tmp->pnext;
			k ++;
		}
	}
	
	free(lcns);
	free(rcns);
}

int traverse_list(CNS* cns){
	CNS* cnt = cns;
	int i = 0;
	while(cnt != NULL){
		printf("字符> %s的权值为: ", cnt->cr);
		printf("%d\n", cnt->weight);
		cnt = cnt->pnext;
		i ++;
	}
	printf("\nPs: Carriage return is the real carriage return !\n");
	return i;
}

