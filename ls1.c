/*************************************************************************
	> File Name: ls1.c
	> Created Time: 2016年12月19日 星期一 12时49分06秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

void do_ls(char*);

int main(int agrc,char **agrv){
	if(agrc == 1)
		do_ls(".");
	else
		while(--agrc){
			printf("%s:\n",*++agrv);
			do_ls(agrv[agrc]);
		}
}
void do_ls(char *dirname){
	DIR *dir_ptr;
	struct dirent *direntp;
	if((dir_ptr = opendir(dirname)) == NULL)
		fprintf(stderr,"lsl:cannot open %s\n",dirname);
	else
	{
		while((direntp = readdir(dir_ptr)) != NULL)
			printf("%s\n",direntp->d_name);
		closedir(dir_ptr);
	}
}
