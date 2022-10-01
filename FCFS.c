/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Input
{
     char pname[10];
      int bt,at,ct,tbt;
} tab[5];

struct Sequence
{
     int start,end;
      char pname[10];
} seq[100],seq1[20];

int finish,time,n,k,prev;

void getinput()
{
    int i;
     printf("\n Enter number of processes:");
     scanf("%d",&n);
     for (i=0;i<n;i++)
     {
          printf("Process name");
          scanf("%s",tab[i].pname);
          printf("Burst time");
          scanf("%d",&tab[i].bt);
          printf("Arrival time");
          scanf("%d",&tab[i].at);
          tab[i].tbt=tab[i].bt;
     }
}

void printinput()
{
    int i;
     printf("\n\n\nProcess\tBT\tAT");
     for (i=0;i<n;i++)
     {
         printf("\n%s\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at);
     }
     
void bubble()
{
    struct Input t;
    int i,j;
    for(i=1;i<n;i++)
       for(j=0;j<n-i;j++)
          if (tab[j].at>tab[j+1].at)
       {
           t=tab[j];
           tab[j]=tab[j+1];
           tab[j+1]=t;
       }
}

void printoutput()
{
    int i;
     float AvgTAT=0,AvgWT=0;
     printf("\n ********Final Table********");
     printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT");
     for(i=0;i<n;i++)
     {
          printf("\n\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].pname, tab[i].at,tab[i].bt,tab[i].ct,tab[i].ct-tab[i].at,tab[i].ct-tab[i].at-tab[i].bt);
          AvgTAT+=tab[i].ct-tab[i].at;
          AvgWT+=tab[i].ct-tab[i].at-tab[i].bt;
    }
    
     AvgTAT/=n;
     AvgWT/=n;
     printf("\n\nAverage TAT=%f",AvgTAT);
     printf("\n\nAverage WT= %f",AvgWT);
}

int arrived(int t)
{
    int i;
    for(i=0;i<n;i++)
       if(tab[i].at<=t && tab[i].tbt!=0)
            return 1;
        return 0;
}
 
void processinput()
{
    int i=0,j;
    finish=k=0;
    time=tab[0].at;
    while(finish!=n)
    {
        if(arrived(time))
        {
            if(tab[i].tbt!=0)
            {
                for(j=0;j<tab[i].bt;j++)
                {
                    time++;
                    tab[i].tbt--;
                    printinput();
                    seq[k].start=prev;
                    seq[k].end=time;
                    strcpy(seq[k++].pname,tab[i].pname);
                    prev=time;
                    tab[i].ct=time;
                    if(tab[i].tbt==0)
                    {
                        finish++;
                        break;
                    }
                    
                }
            }
        }
        else
        {
            time++;
            seq[k].start=prev;
            seq[k].end=time;
            strcpy(seq[k++].pname,"*");
            prev=time;
        }
        if(time<tab[(i+1)%n].at)\
        {
            i=0;
        }
        else
             i=(i+1)%n;
    }
}

void gnattchart()
{
    int i,j=1;
    seq1[0]=seq[0];
    printf("\n ********GnattChart********");
    for(i=1;i<k;i++)
    {
        if(strcmp(seq1[j-1].pname,seq[i].pname)==0)
           seq1[j-1].end=seq[i].end;
        else
            seq[j++]=seq[i];
    }
    for(i=0;i<j;i++)
    printf("\n\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
}

void main()
{
    int i;
    getinput();
    printf("\n Entered data: ");
    printinput();
    bubble();
    printf("\n\n Data after sorting according to arrival time: ");
    printinput();
    processinput();
    printoutput();
    gnattchart();
         for(i=0;i<n;i++)
         {
             tab[i].tbt=tab[i].bt=rand()%10+1;
             tab[i].at=tab[i].ct+2;
             
         }
         processinput();
         printoutput();
         gnattchart();
         
}

 
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
}
