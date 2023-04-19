#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void destination(int choice);// To select the selection of passenger
void canclee(char fbusno[],char ofname[],char ofseat[]);
void bstatus();// To how bus status
void booking(int busno);//TO book the seat
void file_init(int busno,int choice);//Initialize file name to read data for bstatus
//void prev_data();//
void isseatfull(char fbusno[],char ofname[],char ofseat[]);// Checks if there is any seat on that bus
void remove_from_file(int n,char ofname[],char ofseat[],char totseats[]);
void reserve_seat(char ofname[],char ofseat[],char totseats[]);// takes input from user to reserve seat
void read_data(char user_name[],char user_no[]);//Reads name and seat no from file
void viewseat(int numb);// displays all the seat of selected bus
void read_or_write(int num1,int choice);//To take booking or showing bustatus
void savetofile(int n,char ofname[],char ofseat[],char totseats[]);//Saves the data to the file
void seat_init();// Initialize name to ------- and
char name[30][100];//To write passengers name
char tempname[30][100];// to store passenger name
int seats[30];// No of sits
int tempseats[30];// to store passenger seat no
int tseats;//to keep track of available seat
int tcount;

int main(){
int num;

do{
        seat_init();
        system("CLS");
        printf("\n\n\n===================================== BUS RESERVATION SYSTEM =====================================\n\n");
        printf("\t\t\t\t\t[1] ==> Select Destination \n\n");
        printf("\t\t\t\t\t[2] ==> Cancel booking\n\n");
        printf("\t\t\t\t\t[3] ==> Buss Status\n\n");
        printf("\t\t\t\t\t[4] ==> Exit\n\n\n");
        printf("==================================================================================================\n\n");
        printf("\t\t Enter your choice: ");
        scanf("%d",&num);
        switch(num){
    case 1:
        destination(0);
        break;
    case 2:
        destination(2);
        break;
    case 3:
        bstatus();
        break;
        }
        getchar();
}
while(num != 4);
system("CLS");
printf("\n\n\n\t------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tThank You For Using Our Services\t\t\t\t\t\t\n");
printf("\t------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t\t\tVisit Againg ^ ^\t\t\t\t\t\t\n\n\n");
return 0;
}


void isseatfull(char fbusno[], char ofname[], char ofseat[])
{
    int i = 0;
    char c;
    char carr[3];

    FILE *bnof;
    bnof = fopen(fbusno, "r+");
    if (bnof == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file. Please check file path and permissions.\n");
        return;
    }

    while ((c = fgetc(bnof)) != EOF)
    {
        carr[i] = c;
        i++;
    }
    tseats = atoi(carr);
    //printf("%d",tseats);
    fclose(bnof);
    if (tseats < 29)
    {
        //writeseat();
        viewseat(225);
        reserve_seat(ofname, ofseat,fbusno);
    }
    else
    {
        system("CLS");
        printf("\n\n\n\t\t==> Seat full\n");
        getchar();
    }
}


void viewseat(int numb)
{
    int num;
    system("CLS");
    char emptname[29][100];
    int i,j = 0,arr[6] = {1,5,9,13,17,21};
    int k = 0,four[6] = {3,7,11,15,19,23};
    for (i = 0;i<29;i++){

            strcpy(emptname[i],"-------");
            seats[i] = i+1;
    }
    for (i = 0;i<29;i++){
        for (j=0;j<29;j++)
        {
         if (i+1 == tempseats[j])
          {
            strcpy(emptname[i],tempname[j]);
          }
          else if (i+1 == numb)
          {
              strcpy(emptname[i],name[numb]);
          }
        }

    }
    j = 0;
    printf("\n\n\n\t===================================== Seats ===============================================\n\n");
    printf("\n\n\t");
    for (i = 0;i<29;i++)
    {
        if (i<10){
            printf("[%d]  %s",seats[i],emptname[i]);
        }
        else{
        printf("[%d] %s",seats[i],emptname[i]);
        }
        if (i == four[k]){
            printf("\n\n\t");
            k++;
        }
        else if (i == arr[j])
        {
            j++;
            printf("\t\t\t");
        }
        else
        {
            printf("\t");
        }

    }
    printf("\n\n\t==================================================================================================\n\n");
}

void reserve_seat(char ofname[],char ofseat[],char totseats[])
{

    int i,j,k=0,temp = 1,check = 0,checker = 0,counter=0;
    char c,input_name[100];
    int tseatno,n;
    do{
    printf("\tTotal ------- seats:: %d\n",(29-tseats));
    printf("\t\tEnter number of Tickets:: ");
    scanf("%d",&tseatno);
    getchar();
    if (tseatno>=30)
    {
                 printf("\n\n\n\t===================================== info ===============================================\n\n");
                 printf("\n\t\tInvalid Seat. Please try again");
                 printf("\n\n\t==================================================================================================\n\n");
    }
    else if ((tseats+tseatno) <= 29)
    {
         for (i = 0;i<tseatno;i++)
        {
        printf("\n\t\tGive seat number for person [%d]:: ",temp);
        scanf("%d",&n);

        getchar();
        for(j=0;j<29;j++)
            {

                if (n == tempseats[j])
                {
                    checker = 0;
                    break;

                    }
                else
                {
                   if (j <28)
                   {

                   }
                   else{
                        checker = 1;
                    break;
                   }
                }

            }
            if (n>=30)
            {
            checker = 0;
            }
            if (checker ==1){
             printf("\n\t\tGive name for person [%d]:: ",temp);

                // Read input name character by character
                while ((c = getchar()) != '\n')
                {
                    input_name[k++] = c;
                }
                input_name[k] = '\0'; // null-terminate the string
                k = 0;
            strcpy(name[n],input_name);
            savetofile(n,ofname,ofseat,totseats);

            viewseat(n);
            read_data(ofname,ofseat);
            temp++;
            tseats++;
            counter++;





            }
            else{
                 printf("\n\n\n\t===================================== info ===============================================\n\n");
                 printf("\n\t\tInvalid Seat. Please try again");
                 printf("\n\n\t==================================================================================================\n\n");
                 i--;
            }
    }
    }
    else
    {
        printf("\n\n\n\t===================================== info ===============================================\n\n");
        printf("\n\t\t\t==> Seat Full\n");
        break;
        printf("\n\n\t==================================================================================================\n\n");
    }
    }

    while(tseatno>=30);
    printf("\n\t===================================== info ===============================================\n\n");
        printf("\n\t\t\t\tTotal cost is:: Rs.%d\n",(1000*counter));
        printf("\n\n\t==================================================================================================\n\n");
}




void savetofile(int n, char ofname[], char ofseat[],char totseats[])
{
    int i = 0, j = 0;
    char c, ch[30][100];

    FILE *fp1, *fp2,*fp3;
    fp1 = fopen(ofname, "a+");
    if (fp1 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    fprintf(fp1, "%s%c", name[n], '\0');
    fclose(fp1);

    fp2 = fopen(ofseat, "a+");
    if (fp2 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    fprintf(fp2, "%d%c", n, ' ');
    fclose(fp2);

    fp3 = fopen(totseats, "w+");
    if (fp3 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    fprintf(fp3,"%d%c",tseats,'\0');
    fclose(fp3);

}


void booking(int busno)
{
    system("CLS");

    file_init(busno,0);



}


void file_init(int busno,int choice){
    char carr[2],fbusno[20] = {"tno"};
    char fseatname[20]={"Namelist"} ,fbuseat[20] ={"Seatno"};

    itoa(busno,carr,10);
    strcat(fbusno,carr);
    strcat(fbusno,".txt");


    strcat(fbuseat,carr);
    strcat(fbuseat,".txt");


    strcat(fseatname,carr);
    strcat(fseatname,".txt");

    read_data(fseatname,fbuseat);
    if (choice == 0)
    {
        isseatfull(fbusno, fseatname, fbuseat);
    }
    else if (choice == 1)
    {

    }
    else if (choice == 2)
    {
        viewseat(225);
        canclee(fbusno, fseatname, fbuseat);

    }

}

void read_or_write(int num1,int choice)
{
    if (choice == 0)
    {
         switch(num1){
case 1:
    booking(num1);
    break;
case 2:
    booking(num1);
    break;
case 3:
    booking(num1);
    break;
case 4:
    booking(num1);
    break;
case 5:
    booking(num1);
    break;
case 6:
    booking(num1);
    break;
case 7:
    booking(num1);
    break;
case 8:
    booking(num1);
    break;
    }
    }
    else if(choice == 1)
    {
    switch(num1){
case 1:
    file_init(num1,choice);
    viewseat(225);
    break;
case 2:
    file_init(num1,choice);

    viewseat(225);
    break;
case 3:
    file_init(num1,choice);

    viewseat(225);
    break;
case 4:
    file_init(num1,choice);

    viewseat(225);
    break;
case 5:
    file_init(num1,choice);

    viewseat(225);
    break;
case 6:
    file_init(num1,choice);

    viewseat(225);
    break;
case 7:
    file_init(num1,choice);

    viewseat(225);
    break;
case 8:
    file_init(num1,choice);

    viewseat(225);
    break;
    }
    getchar();
    }
    else
    {
        switch(num1){
case 1:
    file_init(num1,choice);

    break;
case 2:
    file_init(num1,choice);

    break;
case 3:
    file_init(num1,choice);


    break;
case 4:
    file_init(num1,choice);


    break;
case 5:
    file_init(num1,choice);


    break;
case 6:
    file_init(num1,choice);


    break;
case 7:
    file_init(num1,choice);


    break;
case 8:
    file_init(num1,choice);


    break;
    }

    }


}

void destination(int choice)
{
    int num1;//To take input bus number
    system("CLS");

    printf("\n\n\n\t===================================== Destination ===============================================\n\n\n");
    printf("\t\t\t\t\t[1] ==> Kathmandu to Pokhara\n\n");
    printf("\t\t\t\t\t[2] ==> Kathmandu to Ilam\n\n");
    printf("\t\t\t\t\t[3] ==> Kathmandu to Janakpur\n\n");
    printf("\t\t\t\t\t[4] ==> Kathmandu to Nepalgunj\n\n");
    printf("\t\t\t\t\t[5] ==> Pokhara to Kathmandu\n\n");
    printf("\t\t\t\t\t[6] ==> Ilam to Kathmandu\n\n");
    printf("\t\t\t\t\t[7] ==> Janakpur to Kathmandu\n\n");
    printf("\t\t\t\t\t[8] ==> Nepalgunj to Kathmandu\n\n");
    printf("\t\t\t\t\t[9] ==> Back to main menu\n\n");
    printf("\t==================================================================================================\n\n");
    printf("\t\t Enter your choice:: ");
    scanf("%d",&num1);
    getchar();
    read_or_write(num1,choice);
}


void bstatus()
{
    destination(1);
}

void read_data(char user_name[], char user_no[])
{
    int i = 0, j = 0, n;
    char c, ch[30][100];

    FILE *fp1;
    fp1 = fopen(user_name, "r+");
    if (fp1 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file. Please check file path and permissions.\n");
        return;
    }
    while ((c = fgetc(fp1)) != EOF)
    {
        if (c == '\0')
        {
            ch[i][j] = '\0';
            i++;
            j = 0;
        }
        else
        {
            ch[i][j] = c;
            j++;

        }
    }
    n = i;
    fclose(fp1);
    for (i = 0; i < n; i++)
    {
        strcpy(tempname[i], ch[i]);
    }

    i = 0;
    j = 0;
    char ch2[30][4];
    memset(ch2, 0, sizeof(ch2));
    fp1 = fopen(user_no, "r+");
    if (fp1 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file. Please check file path and permissions.\n");
        return;
    }
    while ((c = fgetc(fp1)) != EOF)
    {
        if (c == ' ')
        {
            ch2[i][j] = '\0';
            i++;
            j = 0;
        }
        else
        {
            ch2[i][j] = c;
            j++;
        }
    }
    tcount = n;
    fclose(fp1);
    for (i = 0; i < n; i++)
    {
        tempseats[i] = atoi(ch2[i]);
    }
}




void seat_init()
{
    int i,j = 0,arr[6] = {1,5,9,13,17,21};
    int k = 0,four[6] = {3,7,11,15,19,23};
    for (i = 0;i<29;i++){
        strcpy(name[i],"-------");
        strcpy(tempname[i],"-------");
    }
    for (i = 0; i<29;i++)
    {
        seats[i] = i+1;
        tempseats[i] = 0;
    }

}

void canclee(char fbusno[],char ofname[],char ofseat[])
{
    int i,j,k=0,temp = 1,check = 0,checker = 0,counter=0;
    char c,input_name[100];
    int tseatno,n;
    do{
    printf("\t\tEnter number of Tickets:: ");
    scanf("%d",&tseatno);
    getchar();
    if (tseatno>=30 || tseatno<=0)
    {
                 printf("\n\n\n\t===================================== info ===============================================\n\n");
                 printf("\n\t\tInvalid Seat. Please try again");
                 printf("\n\n\t==================================================================================================\n\n");
    }
    else if ((tseats+tseatno) <= 29)
    {
         for (i = 0;i<tseatno;i++)
        {
        printf("\n\t\tGive seat number:: ",temp);
        scanf("%d",&n);

        getchar();
        for(j=0;j<29;j++)
            {

                if (n == tempseats[j])
                {
                    checker = 1;
                    break;

                    }
                else
                {
                   if (j <28)
                   {

                   }
                   else{
                        checker = 0;
                    break;
                   }
                }

            }
            if (n>=30 || n<=0)
            {
            checker = 0;
            }
            if (checker == 1){
            strcpy(name[n],"-------");
            remove_from_file(n,ofname,ofseat,fbusno);

            viewseat(n);
            read_data(ofname,ofseat);
            counter++;
            tseats--;

            }
            else{
                 printf("\n\n\n\t===================================== info ===============================================\n\n");
                 printf("\n\t\tInvalid Seat. Please try again");
                 printf("\n\n\t==================================================================================================\n\n");
                 i--;
            }
    }
    }
    else
    {
        printf("\n\n\n\t===================================== info ===============================================\n\n");
        printf("\n\t\t\t==> Seat Full\n");
        break;
        printf("\n\n\t==================================================================================================\n\n");
    }
    }
    while(tseatno>=30);
     while(tseatno>=30);
    printf("\n\t===================================== info ===============================================\n\n");
        printf("\n\t\t\t\tRs.%d is returned. \n",(1000*counter));
        printf("\n\n\t==================================================================================================\n\n");

}

void remove_from_file(int n, char ofname[], char ofseat[],char totseats[])
{
    int i = 0, j = 0;
    int index;
    char c, ch[30][100];

    FILE *fp1, *fp2,*fp3;


    fp2 = fopen(ofseat, "w+");
    if (fp2 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }

    for(i = 0;i<tcount;i++)
    {
        if (tempseats[i]== n)
        {
            index = i;
            tempseats[i] = 0;

        }
    }

    for (i=0;i<tcount;i++)
    {
        if (tempseats[i] != 0)
        {
            fprintf(fp2, "%d%c", tempseats[i], ' ');
        }
    }

    fclose(fp2);

        fp1 = fopen(ofname, "w+");
    if (fp1 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }

    strcpy(tempname[index],"-------");

    for (i=0;i<tcount;i++)
    {
    if (strcmp(tempname[i],"-------") == 1){
    fprintf(fp1, "%s%c", tempname[i], '\0');
    }
    }
    fclose(fp1);

    fp3 = fopen(totseats, "w+");
    if (fp3 == NULL) // Check if file opened successfully
    {
        printf("\n\n\n\t\t==> Error opening file for writing. Please check file path and permissions.\n");
        return;
    }
    fprintf(fp3,"%d%c",tseats,'\0');
    fclose(fp3);

}

