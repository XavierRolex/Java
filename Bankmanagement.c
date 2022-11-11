#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

void welcome();
void login();
void menu();
void newAcc();
void edit();
void userInfo();
void del();

struct Dates
{
    int date, month, year;
};

struct StudentInfo
{
    char name[25];
    char fName[25];
    char mName[25];
    char stdID[15];
    char conInfo[15];
    float amm;
    float deposit;
    float withdraw;
    struct Dates DOB;
    struct Dates create;
    struct Dates depo;
    struct Dates withd;

}std;

int main()
{
    welcome();
    login();
    menu();

    return 0;
}

void welcome()
{
    system("COLOR 30");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t==================================================================");
    printf("\n\t\t\t\t\t\t\t\t**********************************");
    printf("\n\n\t\t\t\t\t\t\t\t\t     WELCOME");
    printf("\n\n\t\t\t\t\t\t\t\t\t       TO");
    printf("\n\n\t\t\t\t\t\t\t\t      NORTH SOUTH UNIVERSITY");
    printf("\n\n\t\t\t\t\t\t\t\t          STUDENT BANKING\n\n");
    printf("\t\t\t\t\t\t\t\t**********************************");
    printf("\n\t\t\t\t\t\t==================================================================");
    printf("\n\n\n\n\t\t\t\t\t\tPress a key to continue. . . . .");

    getch();
}

void login()
{
    char user[25], pass[15];
    char trueUser[25]="Group5";
    char truePass[15]="@MrToad504";
    int hint=0;

    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t===========================  ADMIN LOGIN  =========================");

        if(hint==1)
        {
            printf("\n\n\n\t\t\t\t\t\tUsername & Password Hint: Team Frogs");
        }

        printf("\n\n\n\t\t\t\t\t\tUsername: ");
        gets(user);

        printf("\t\t\t\t\t\tPassword: ");
        gets(pass);

        if(strcmp(user, trueUser)==0 && strcmp(pass, truePass)==0)
        {
            printf("\n\t\t\t\t\t\tYou have successfully logged in. Press Enter to Continue.");
            getch();
            break;
        }
        else
        {
            printf("\n\t\t\t\t\t\tInvalid Username or Password. Press Enter to Try Again.");
            hint=1;
            getch();
        }
    }

}

void menu()
{
    int choice;

    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t=============================  MENU  =============================");

        printf("\n\n\n\t\t\t\t\t\t1. Create new Account.");
        printf("\n\t\t\t\t\t\t2. Check details of an existing Account.");
        printf("\n\t\t\t\t\t\t3. Edit an existing Account.");
        printf("\n\t\t\t\t\t\t4. Delete an existing Account.");
        printf("\n\t\t\t\t\t\t5. Exit.");

        printf("\n\n\t\t\t\t\t\tEnter your Choice(1-5): ");
        scanf("%d", &choice);

        if(choice==1)
        {
            newAcc();
        }
        else if(choice==2)
        {
            userInfo();
        }
        else if(choice==3)
        {
            edit();
        }
        else if(choice==4)
        {
            del();
        }
        else if(choice==5)
        {
            exit(0);
        }
        else
        {
            menu();
        }
    }
}


void newAcc()
{
    FILE *file;

    file = fopen("banking.txt", "a");

    int num, i;

    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t=======================  ACCOUNT CREATION  =======================");

    printf("\n\n\n\t\t\t\t\t\tEnter The Number of New Accounts: ");
    scanf("%d", &num);

    if(file==NULL)
    {
        printf("\t\t\t\t\t\tSorry File does not exist");
    }
    else
    {
        for(i=0; i<num; i++)
        {
            printf("\n\n\t\t\t\t\t\tNB: WHILE WRITING NAMES USE UNDERSCORES INSTEAD OF SPACES.\n\n");
            printf("\n\t\t\t\t\t\tFor Student %d,\n", i+1);
            fflush(stdin);
            printf("\t\t\t\t\t\t\tEnter Full Name: ");
            gets(std.name);
            printf("\t\t\t\t\t\t\tEnter Father's Name: ");
            gets(std.fName);
            printf("\t\t\t\t\t\t\tEnter Mother's Name: ");
            gets(std.mName);
            printf("\t\t\t\t\t\t\tEnter Date of Birth: ");
            scanf("%d/%d/%d", &std.DOB.date, &std.DOB.month, &std.DOB.year);
            fflush(stdin);
            printf("\t\t\t\t\t\t\tEnter Student ID: ");
            gets(std.stdID);
            printf("\t\t\t\t\t\t\tEnter Contact Info: ");
            gets(std.conInfo);
            printf("\t\t\t\t\t\t\tEnter Date of Account Creation: ");
            scanf("%d/%d/%d", &std.create.date, &std.create.month, &std.create.year);
            printf("\t\t\t\t\t\t\tEnter the amount of Deposit: ");
            scanf("%f", &std.deposit);

            fprintf(file, "\n%25s%25s%25s\t%2d/%2d/%4d\t%13s%15s\t\t%2d/%2d/%4d\t\t%.2f", std.name, std.fName, std.mName, std.DOB.date, std.DOB.month, std.DOB.year, std.stdID, std.conInfo, std.create.date, std.create.month, std.create.year, std.deposit);

            if(i==num-1)
            {
                printf("\n\n\t\t\t\t\t\tAccount Created Successfully.");
                printf("\n\t\t\t\t\t\tPress Enter to return to Menu.");
                getch();
            }
            else
            {
                printf("\n\n\t\t\t\t\t\tAccount Created Successfully.");
            }

        }

    }

    fclose(file);
}
void edit()
{
    FILE *bfile, *afile;

    bfile = fopen("banking.txt","r");
    afile = fopen("temporary.txt","w");

    char tempID[30];

    int edt=0, tryagain, edChoice, edtMore;

    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t=========================  ACCOUNT EDIT  =========================");

    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\tEnter the Student ID of the Account Holder: ");
    gets(tempID);

    while (fscanf(bfile, "%s %s %s %d/%d/%d %s %s %d/%d/%d %f", &std.name, &std.fName, &std.mName, &std.DOB.date, &std.DOB.month, &std.DOB.year, &std.stdID, &std.conInfo, &std.create.date, &std.create.month, &std.create.year, &std.deposit)!=EOF)
    {
        if(strcmp(tempID, std.stdID)==0)
        {
            printf("\n\n\t\t\t\t\t\tNAME OF THE ACCOUNT HOLDER: %s", std.name);

            printf("\n\n\t\t\t\t\t\tWould you Like to Edit: ");
            printf("\n\n\t\t\t\t\t\t(1) Student's Name.");
            printf("\n\t\t\t\t\t\t(2) Father's Name.");
            printf("\n\t\t\t\t\t\t(3) Mother's Name.");
            printf("\n\t\t\t\t\t\t(4) Date of Birth.");
            printf("\n\t\t\t\t\t\t(5) Contact Info.");
            printf("\n\t\t\t\t\t\t(6) Deposit.");
            printf("\n\n\t\t\t\t\t\tEnter your Choice(1-6): ");
            scanf("%d", &edChoice);

            fflush(stdin);

            if(edChoice==1)
            {
                printf("\n\n\t\t\t\t\t\tEnter Full Name: ");
                gets(std.name);
            }
            else if(edChoice==2)
            {
                printf("\n\n\t\t\t\t\t\tEnter Father's Name: ");
                gets(std.fName);
            }
            else if(edChoice==3)
            {
                printf("\n\n\t\t\t\t\t\tEnter Mother's Name: ");
                gets(std.mName);
            }
            else if(edChoice==4)
            {
                printf("\n\n\t\t\t\t\t\tEnter Date of Birth: ");
                scanf("%d/%d/%d", &std.DOB.date, &std.DOB.month, &std.DOB.year);
            }
            else if(edChoice==5)
            {
                printf("\n\n\t\t\t\t\t\tEnter Contact Info: ");
                gets(std.conInfo);
            }
            else if(edChoice==6)
            {
                printf("\n\n\t\t\t\t\t\tEnter the amount of Deposit: ");
                scanf("%f", &std.deposit);
            }

            fprintf(afile, "\n%25s%25s%25s\t%2d/%2d/%4d\t%13s%15s\t\t%2d/%2d/%4d\t\t%.2f", std.name, std.fName, std.mName, std.DOB.date, std.DOB.month, std.DOB.year, std.stdID, std.conInfo, std.create.date, std.create.month, std.create.year, std.deposit);

            edt=1;

        }
        else
        {
            fprintf(afile, "\n%25s%25s%25s\t%2d/%2d/%4d\t%13s%15s\t\t%2d/%2d/%4d\t\t%.2f", std.name, std.fName, std.mName, std.DOB.date, std.DOB.month, std.DOB.year, std.stdID, std.conInfo, std.create.date, std.create.month, std.create.year, std.deposit);
        }
    }
    fclose(bfile);
    fclose(afile);
    remove("banking.txt");
    rename("temporary.txt","banking.txt");

    if(edt==0)
    {
        printf("\n\t\t\t\t\t\tRecord not found!!");

        printf("\n\n\t\t\t\t\t\tEnter 1 to Try Again and any other number to Return to the Main Menu: ");
        scanf("%d", &tryagain);

        if (tryagain==1)
        {
            edit();
        }

        else
        {
            menu();
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\tRecord Edited Successfully.\n");

        printf("\n\t\t\t\t\t\tEnter 1 to edit more and any other number to Return to the Main Menu: ");
        scanf("%d", &edtMore);

        if (edtMore==1)
        {
            edit();
        }

        else
        {
            menu();
        }

    }
}
void userInfo()
{
    FILE *file;

    file = fopen("banking.txt","r");

    char tempID[30];

    int nFound=0, tryagain, usMore;

    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t=========================  ACCOUNT INFO  =========================");

    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\tEnter the Student ID of the Account Holder: ");
    gets(tempID);

    while (fscanf(file, "%s %s %s %d/%d/%d %s %s %d/%d/%d %f", &std.name, &std.fName, &std.mName, &std.DOB.date, &std.DOB.month, &std.DOB.year, &std.stdID, &std.conInfo, &std.create.date, &std.create.month, &std.create.year, &std.deposit)!=EOF)
    {
        if(strcmp(tempID, std.stdID)==0)
        {
            printf("\n\n\t\t\t\t\t\tRecord Found!\n");

            printf("\n\t\t\t\t\t\tName: %s", std.name);
            printf("\n\t\t\t\t\t\tFather's Name: %s", std.fName);
            printf("\n\t\t\t\t\t\tMother's Name: %s", std.mName);
            printf("\n\t\t\t\t\t\tDate of Birth: %d/%d/%d", std.DOB.date, std.DOB.month, std.DOB.year);
            printf("\n\t\t\t\t\t\tStudent ID: %s", std.stdID);
            printf("\n\t\t\t\t\t\tContact Info: %s", std.conInfo);
            printf("\n\t\t\t\t\t\tAccount Created: %d/%d/%d", std.create.date, std.create.month, std.create.year);
            printf("\n\t\t\t\t\t\tAmmount Stored: %.2f", std.deposit);

            nFound=1;
        }
        else
        {

        }
    }
    fclose(file);

    if(nFound==0)
    {
        printf("\n\t\t\t\t\t\tRecord not found!!");

        printf("\n\n\t\t\t\t\t\tEnter 1 to Try Again and any other number to Return to the Main Menu: ");
        scanf("%d", &tryagain);

        if (tryagain==1)
        {
            userInfo();
        }

        else
        {
            menu();
        }
    }
    else
    {

        printf("\n\n\t\t\t\t\t\tEnter 1 to check more and any other number to Return to the Main Menu: ");
        scanf("%d", &usMore);

        if (usMore==1)
        {
            userInfo();
        }

        else
        {
            menu();
        }
    }
}
void del()
{
    FILE *bfile, *afile;

    bfile = fopen("banking.txt","r");
    afile = fopen("temporary.txt","w");

    char tempID[30], amSure;

    int delt=0, tryagain, dltMore;

    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t========================  ACCOUNT DELETE  ========================");

    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\tEnter the Student ID of the Account Holder: ");
    gets(tempID);

    
    while (fscanf(bfile, "%s %s %s %d/%d/%d %s %s %d/%d/%d %f", &std.name, &std.fName, &std.mName, &std.DOB.date, &std.DOB.month, &std.DOB.year, &std.stdID, &std.conInfo, &std.create.date, &std.create.month, &std.create.year, &std.deposit)!=EOF)
    {
        if(strcmp(tempID, std.stdID)==0)
        {
            printf("\n\n\t\t\t\t\t\tNAME OF ACCOUNT HOLDER: %s", std.name);
            printf("\n\n\t\t\t\t\t\tAre you Sure you'd like to DELETE this account (Y/N): ");
            scanf("%c", &amSure);

            if(amSure=='Y')
            {
                break;
            }
            else if(amSure=='N')
            {
                fclose(bfile);
                fclose(afile);
                remove("temporary.txt");
                printf("\n\n\t\t\t\t\t\tPress Enter to Return to the Main Menu.");
                getch();
                menu();
            }
        }
    }
    

    while (fscanf(bfile, "%s %s %s %d/%d/%d %s %s %d/%d/%d %f", &std.name, &std.fName, &std.mName, &std.DOB.date, &std.DOB.month, &std.DOB.year, &std.stdID, &std.conInfo, &std.create.date, &std.create.month, &std.create.year, &std.deposit)!=EOF)
    {
        if(strcmp(tempID, std.stdID)==0)
        {
            printf("\n\n\t\t\t\t\t\tNAME OF ACCOUNT HOLDER: %s", std.name);
            printf("\n\n\t\t\t\t\t\tPress Any Key to Delete.");
            getch();

            printf("\n\n\t\t\t\t\t\tRecord deleted successfully!\n");
            delt=1;
        }
        else
        {
            fprintf(afile,"\n%25s%25s%25s\t%2d/%2d/%4d\t%13s%15s\t\t%2d/%2d/%4d\t\t%.2f", std.name, std.fName, std.mName, std.DOB.date, std.DOB.month, std.DOB.year, std.stdID, std.conInfo, std.create.date, std.create.month, std.create.year, std.deposit);
        }
    }
    fclose(bfile);
    fclose(afile);
    remove("banking.txt");
    rename("temporary.txt","banking.txt");

    if(delt==0)
    {
        printf("\n\t\t\t\t\t\tRecord not found!!");

        printf("\n\n\t\t\t\t\t\tEnter 1 to Try Again and any other number to Return to the Main Menu: ");
        scanf("%d", &tryagain);

        if (tryagain==1)
        {
            del();
        }

        else
        {
            menu();
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\tEnter 1 to check more and any other number to Return to the Main Menu: ");
        scanf("%d", &dltMore);

        if (dltMore==1)
        {
            del();
        }

        else
        {
            menu();
        }
    }
}