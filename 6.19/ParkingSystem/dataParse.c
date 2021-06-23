#include"dataParse.h"

void getDate(const char *date, int *pmouth, int *pday, int *pyear){
	const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
                                 "Sep", "Oct", "Nov", "Dec"};
	char mouth[4];
	memset(mouth, 0, 4); 
	strncpy(mouth, date, 3); 
	for(int i=0; i<12; i++){
	    if(!strcmp(mouth, months[i])){
		*pmouth = i+1;
		break;
		}   
	}
	*pday = *pyear = 0;
    for(int i=0; i<2; i++){
		*pday = date[4+i] - '0' + *pday*10;
	 }   
	 for(int i=0; i<4; i++){
		*pyear = date[7+i] - '0' + *pyear*10;
	}   
}

void getTime(const char *time, int *phour, int *pminute){
    *phour = *pminute = 0;
	for(int i=0; i<2; i++){
		*phour = time[i] - '0' + *phour*10;
	}   
	for(int i=0; i<2; i++){
		*pminute = time[i+3] - '0' + *pminute*10;
	}   
}

