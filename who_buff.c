#include<time.h>
#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//#define SHOWHOST
int utmp_open(char*,int);
struct utmp* utmp_next();
int utmp_reload();
void utmp_close();
void show_info(struct utmp *);
int main(){
	
	struct utmp *utbufp;	
	if((utmp_open(UTMP_FILE,O_RDONLY))== -1){
		perror(UTMP_FILE);
		exit(1);
	}

	while((utbufp = utmp_next())!= ((struct utmp *)NULL)){
		show_info(utbufp);
	}
	utmp_close();
	return 0;
		
}

void
	show_info(struct utmp *utbufp){
	    void show_time(long);	
		printf("%-8.8s",utbufp->ut_name);
		printf(" ");
		printf("%-8.8s",utbufp->ut_line);
		printf(" ");
		show_time(utbufp->ut_time);
		printf(" ");
	#ifdef SHOWHOST
		printf("(%s)",utbufp->ut_host);
	#endif
		printf("\n");
	}

void
	show_time(long timeval){
		char *cp;
		cp = ctime(&timeval);
		printf("%-12.12s",cp + 4);
	}
