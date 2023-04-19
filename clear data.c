#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    int i;
    char carr[2],storage[8][20],storage1[8][50],storage2[8][50];

for (i=0;i<8;i++){
    char fbusno[20] = {"data/tno"};
    char fseatname[20]={"data/Namelist"};
    char fbuseat[20] ={"data/Seatno"};
    itoa(i+1,carr,10);
    strcat(fbusno,carr);
    strcat(fbusno,".txt");
    strcpy(storage[i],fbusno);

    strcat(fbuseat,carr);
    strcat(fbuseat,".txt");
    strcpy(storage1[i],fbuseat);

    strcat(fseatname,carr);
    strcat(fseatname,".txt");
    strcpy(storage2[i],fseatname);
}


    i = 0;
    char c, ch[30][100];

    FILE *fp1, *fp2;

    FILE *fp3;


    for (i=0;i<8;i++){
    fp1 = fopen(storage2[i], "w");
    if (fp1 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    //fprintf(fp1, "%s%c", name[n], '\0');



    fp2 = fopen(storage1[i], "w+");
    if (fp2 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    //fprintf(fp2, "%d%c", n, ' ');



    fp3 = fopen(storage[i], "w");
    if (fp3 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    fprintf(fp3,"%d%c",0,'\0');
}
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);


            system("CLS");
        printf("\n\n\n===================================== BUS RESERVATION RESET SYSTEM =====================================\n\n");
        printf("\t\t\t\t\t ==> Everything was reset;\n\n");
        printf("=========================================================================================================\n\n");
        getchar();
}
