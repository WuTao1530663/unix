/*************************************************************************
	> File Name: cp1.c
	> Created Time: 2016年12月18日 星期日 16时22分43秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFFSIZE 4096
#define COPYMODE
int main(int argc,char *args){
	int in_fd,out_fd,n_chars;
	char buff[BUFFSIZE];
	
	if(argc != 3){
		fprintf(stderr,"usage:%s source destination\n",*args);
		exit(1);		
	}
	if((in_fd = open(args[1],O_RDONLY)) == -1)
		oops("Cannot open",args[1]);
	if((out_fd = create(args[2],COPYMODE)) == -1)
		oops("Cannot create",args[2]);
	while((n_chars = read(in_fd,buf,BUFFSIZE)) > 0){
		if(write(out_fd,buf,n_chars) != n_chars)
			oops("Write error to",args[2]);
	}
	if(n_chars == -1)
		oops("Read error from",args[1]);

	if((close(in_fd)==-1)||(close(out_fd) == -1))
		oops("close error","");



}
