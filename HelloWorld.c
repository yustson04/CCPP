#include <string.h>
#include <stdio.h>
#include "kisystem.h"

void main()
{
    char currentTime[100];\
    char fileName[200]="C:/Users/ks/Documents/CCPP_0/ReportCSV/";
    int iReturn;
    testPrint();

    strcpy(currentTime,LocalTime());
    printf("Current Time is %s\n",currentTime);

    iReturn=CreateReport(fileName,currentTime);
    //    iReturn = CreateReport();
}