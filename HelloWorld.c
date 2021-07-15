#include <stdio.h>
#include <time.h>
#include <string.h>
#include<sys/stat.h>

char *LocalTime()
{
    time_t rawTime;
    struct tm *timeinfo;
    static char currentTime[100];
    int year, month, day, hours, minutes, seconds;
    char timeBuffer[10];
    //Ready System Time
    rawTime = time(NULL);
    timeinfo = localtime(&rawTime);

    //Load System Time to Variable
    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
    hours = timeinfo->tm_hour;
    minutes = timeinfo->tm_min;
    seconds = timeinfo->tm_sec;
    sprintf(currentTime, "%d-%02d-%02d-%02d-%02d-%02d", year, month, day, hours, minutes, seconds);

    //   sprintf(timeBuffer, "%s", asctime(timeinfo));
      printf("Curr time is %s\n",currentTime);

    return currentTime;
}
int CreateReport(char ch[50])
{
    FILE *fp;
    int number,iRet;
    int numList[10];
    char buffer[30];
    char cTime[100];
    char fileName[200] = "C:/Users/ks/Documents/CCPP/ReportCSV/";
    sprintf(cTime, "%s", LocalTime());
    //    printf("Curr TIme is %s\n", LocalTime());
    strncat(fileName, cTime, 16);

    //Create Folder If not Exist
    iRet = mkdir(fileName);

    //Append Data On File If exist, If not Exist then create a file.
    strcat(fileName, "/");
    strncat(fileName,cTime,19);
    strcat(fileName,".csv");
    printf("File Name is %s\n", fileName);

    fp = fopen(fileName, "a+"); //Return-Type: FILE*
    if (fp == NULL)
    {
        printf("Error Occured while opening file\n");
        return 1;
    }
    //    number = GetTagWord("INT_0"); //Return-Type: WORD
    for (int i = 0; i < 10; i++)
    {
        numList[i] = i;
        sprintf(buffer, "INT0 %d,", numList[i]);
        fputs(buffer, fp);
    }
    fputs("\n", fp);

    fclose(fp);
    return 0;
}
void main()
{
    int iReturn;
    printf("Hello World\n");
    iReturn = CreateReport();
}