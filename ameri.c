#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **str1_ptr, char **str2_ptr)
{
   char *temp = *str1_ptr;
   *str1_ptr = *str2_ptr;
   *str2_ptr = temp;
}
struct studentsInfo
{
    char idNumber[20];
    char firstname[20];
    char lastname[20];
    char score[5];
};
int main()
{
    char password[100];
    char inputpass[100];
    FILE * passwordfile;
    passwordfile = fopen("pass.txt","r");
    int b = 0;
    char currentCharacter;
    while((currentCharacter = fgetc(passwordfile)) != EOF)
    {
        password[b] = currentCharacter;
        b++;
    }
    fclose(passwordfile);
    int comparee = 5;
    while(comparee != 0)
    {
        printf("please enter the password\n");
        scanf("%s",&inputpass);
        comparee = strcmp(password,inputpass);
        if(comparee != 0)
        {
            printf("wrong password.you cannot get in\n");
        }
        else
        {
            break;
        }
    }
    system("cls");
    int repeatChoice = 1;
    while(repeatChoice == 1)
    {
        system("cls");
        int menuchoice;
        printf("1- Enter Info of New Students\n2- Delete a student\n3- Sort Students Info\n4- Search Students\n5- Change Password\n6- Logout\n\n");
        scanf("%d",&menuchoice);
        if(menuchoice == 1)
        {
            FILE * firstnamespointer;
            FILE * lastnamespointer;
            FILE * idNumberpointer;
            FILE * scorepointer;
            firstnamespointer = fopen("firstname.txt","a");
            lastnamespointer = fopen("lastname.txt","a");
            idNumberpointer = fopen("idNumber.txt","a");
            scorepointer = fopen("score.txt","a");
            int quant;
            char endl[] = "\n";
            printf("please enter the quantity of new students\n");
            scanf("%d",&quant);
            struct studentsInfo  Info[quant];
            for(int i = 0;i < quant;i++)
            {
                printf("enter student %d id number\n",i+1);
                scanf("%s",&Info[i].idNumber);
                printf("enter student %d first name\n",i+1);
                scanf("%s",&Info[i].firstname);
                printf("enter student %d last name\n",i+1);
                scanf("%s",&Info[i].lastname);
                printf("enter student %d score\n",i+1);
                scanf("%s",&Info[i].score);
            }
            for(int i = 0;i < quant;i++)
            {
                fputs(Info[i].firstname,firstnamespointer);
                fputs(endl,firstnamespointer);
                fputs(Info[i].lastname,lastnamespointer);
                fputs(endl,lastnamespointer);
                fputs(Info[i].idNumber,idNumberpointer);
                fputs(endl,idNumberpointer);
                fputs(Info[i].score,scorepointer);
                fputs(endl,scorepointer);
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
        }
        //---------------------------------------------------
        else if(menuchoice == 2)
        {
            char * allfirstNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allfirstNameData[i] = (char*) malloc(100);
            }
            char * alllastNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                alllastNameData[i] = (char*) malloc(100);
            }
            char * allidData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allidData[i] = (char*) malloc(100);
            }
            char * allscoreData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allscoreData[i] = (char*) malloc(100);
            }
            int i = 0;
            int j = 0;
            int k = 0;
            int l = 0;
            char inputID[1][20];
            FILE * firstnamespointer;
            FILE * lastnamespointer;
            FILE * idNumberpointer;
            FILE * scorepointer;
            firstnamespointer = fopen("firstname.txt","r");
            lastnamespointer = fopen("lastname.txt","r");
            idNumberpointer = fopen("idNumber.txt","r");
            scorepointer = fopen("score.txt","r");
            int string1 = 0;
            while((currentCharacter = fgetc(firstnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string1++;
                    i = 0;
                    continue;
                }
                allfirstNameData[string1][i] = currentCharacter;
                i++;
            }
            int string2 = 0;
            while((currentCharacter = fgetc(lastnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string2++;
                    j = 0;
                    continue;
                }
                alllastNameData[string2][j] = currentCharacter;
                j++;
            }
            int string3 = 0;
            while((currentCharacter = fgetc(idNumberpointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string3++;
                    k = 0;
                    continue;
                }
                allidData[string3][k] = currentCharacter;
                k++;
            }
            int string4 = 0;
            while((currentCharacter = fgetc(scorepointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string4++;
                    l = 0;
                    continue;
                }
                allscoreData[string4][l] = currentCharacter;
                l++;
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
            //-------------------------------------------------------------
            printf("enter the id number of the student which you want to delete\n");
            scanf("%s",&inputID[0]);
            int compare;
            for(int m = 0;m < string3;m++)
            {
                compare = strcmp(inputID[0],allidData[0]);
                if(compare == 0)
                {
                    for(int n = m;n < string1;n++)
                    {
                        allfirstNameData[n] = allfirstNameData[n+1];
                    }
                    for(int n = m-1;n < string2;n++)
                    {
                        alllastNameData[n] = alllastNameData[n+1];
                    }
                    for(int n = m-1;n < string3;n++)
                    {
                        allidData[n] = allidData[n+1];
                    }
                    for(int n = m-1;n < string4;n++)
                    {
                        allscoreData[n] = allscoreData[n+1];
                    }
                    break;
                }
            }
            //----------------------------writing on the file
            char endl[] = "\n";
            firstnamespointer = fopen("firstname.txt","w");
            lastnamespointer = fopen("lastname.txt","w");
            idNumberpointer = fopen("idNumber.txt","w");
            scorepointer = fopen("score.txt","w");
            for(int i = 0;i < string1 - 1;i++)
            {
                fputs(allfirstNameData[i],firstnamespointer);
                fputs(endl,firstnamespointer);
                fputs(alllastNameData[i],lastnamespointer);
                fputs(endl,lastnamespointer);
                fputs(allidData[i],idNumberpointer);
                fputs(endl,idNumberpointer);
                fputs(allscoreData[i],scorepointer);
                fputs(endl,scorepointer);
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
        }
        //---------------------------------------------------
        else if(menuchoice == 3)
        {
            char * allfirstNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allfirstNameData[i] = (char*) malloc(100);
            }
            char * alllastNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                alllastNameData[i] = (char*) malloc(100);
            }
            char * allidData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allidData[i] = (char*) malloc(100);
            }
            char * allscoreData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allscoreData[i] = (char*) malloc(100);
            }
            int i = 0;
            int j = 0;
            int k = 0;
            int l = 0;
            FILE * firstnamespointer;
            FILE * lastnamespointer;
            FILE * idNumberpointer;
            FILE * scorepointer;
            firstnamespointer = fopen("firstname.txt","r");
            lastnamespointer = fopen("lastname.txt","r");
            idNumberpointer = fopen("idNumber.txt","r");
            scorepointer = fopen("score.txt","r");
            int string1 = 0;
            while((currentCharacter = fgetc(firstnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string1++;
                    i = 0;
                    continue;
                }
                allfirstNameData[string1][i] = currentCharacter;
                i++;
            }
            int string2 = 0;
            while((currentCharacter = fgetc(lastnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string2++;
                    j = 0;
                    continue;
                }
                alllastNameData[string2][j] = currentCharacter;
                j++;
            }
            int string3 = 0;
            while((currentCharacter = fgetc(idNumberpointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string3++;
                    k = 0;
                    continue;
                }
                allidData[string3][k] = currentCharacter;
                k++;
            }
            int string4 = 0;
            while((currentCharacter = fgetc(scorepointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string4++;
                    l = 0;
                    continue;
                }
                allscoreData[string4][l] = currentCharacter;
                l++;
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
            //-----------------------------------now sorting out
            for(int i = 0;i < string1;i++)
            {
                for(int j = i;j < string1;j++)
                {
                    int compare = strcmp(allscoreData[j],allscoreData[j+1]);
                    if(compare == -1)
                    {
                        swap(&allscoreData[j],&allscoreData[j+1]);
                        swap(&allfirstNameData[j],&allfirstNameData[j+1]);
                        swap(&alllastNameData[j],&alllastNameData[j+1]);
                        swap(&allidData[j],&allidData[j+1]);
                    }
                }
            }
            //--------------------------------------------------------------- sort by first names for equal ones
            for(int i = 0;i < string1;i++)
            {
                for(int j = i;j < string1;j++)
                {
                    int compare = strcmp(allfirstNameData[j],allfirstNameData[j+1]);
                    if(compare == -1)
                    {
                        swap(&allscoreData[j],&allscoreData[j+1]);
                        swap(&allfirstNameData[j],&allfirstNameData[j+1]);
                        swap(&alllastNameData[j],&alllastNameData[j+1]);
                        swap(&allidData[j],&allidData[j+1]);
                    }
                }
            }
            //---------------------------------------------------------------------------sort by last names for equal ones
            for(int i = 0;i < string1;i++)
            {
                for(int j = i;j < string1;j++)
                {
                    int compare = strcmp(alllastNameData[j],alllastNameData[j+1]);
                    if(compare == -1)
                    {
                        swap(&allscoreData[j],&allscoreData[j+1]);
                        swap(&allfirstNameData[j],&allfirstNameData[j+1]);
                        swap(&alllastNameData[j],&alllastNameData[j+1]);
                        swap(&allidData[j],&allidData[j+1]);
                    }
                }
            }
            //---------------------------------------------------------printing the sorted data
            for(int i = 0; i < string1;i++)
            {
                printf("student %d information\n",i+1);
                printf("id: %s\n",allidData[i]);
                printf("first name: %s\n",allfirstNameData[i]);
                printf("last name: %s\n",alllastNameData[i]);
                printf("score: %s\n-----------\n",allscoreData[i]);
            }
            //-----------------------------------------------writing the sorted data into the files
            char endl[] = "\n";
            firstnamespointer = fopen("firstname.txt","w");
            lastnamespointer = fopen("lastname.txt","w");
            idNumberpointer = fopen("idNumber.txt","w");
            scorepointer = fopen("score.txt","w");
            for(int i = 0;i < string1;i++)
            {
                fputs(allfirstNameData[i],firstnamespointer);
                fputs(endl,firstnamespointer);
                fputs(alllastNameData[i],lastnamespointer);
                fputs(endl,lastnamespointer);
                fputs(allidData[i],idNumberpointer);
                fputs(endl,idNumberpointer);
                fputs(allscoreData[i],scorepointer);
                fputs(endl,scorepointer);
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
            //----------------------------
            printf("all your data is now completely sorted out and saved\n");
        }
        //------------------------------------------------------------------+
        else if(menuchoice == 4)
        {
            char * allfirstNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allfirstNameData[i] = (char*) malloc(100);
            }
            char * alllastNameData[1000];
            for(int i = 0;i < 1000;i++)
            {
                alllastNameData[i] = (char*) malloc(100);
            }
            char * allidData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allidData[i] = (char*) malloc(100);
            }
            char * allscoreData[1000];
            for(int i = 0;i < 1000;i++)
            {
                allscoreData[i] = (char*) malloc(100);
            }
            int i = 0;
            int j = 0;
            int k = 0;
            int l = 0;
            FILE * firstnamespointer;
            FILE * lastnamespointer;
            FILE * idNumberpointer;
            FILE * scorepointer;
            firstnamespointer = fopen("firstname.txt","r");
            lastnamespointer = fopen("lastname.txt","r");
            idNumberpointer = fopen("idNumber.txt","r");
            scorepointer = fopen("score.txt","r");
            int string1 = 0;
            while((currentCharacter = fgetc(firstnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string1++;
                    i = 0;
                    continue;
                }
                allfirstNameData[string1][i] = currentCharacter;
                i++;
            }
            int string2 = 0;
            while((currentCharacter = fgetc(lastnamespointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string2++;
                    j = 0;
                    continue;
                }
                alllastNameData[string2][j] = currentCharacter;
                j++;
            }
            int string3 = 0;
            while((currentCharacter = fgetc(idNumberpointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string3++;
                    k = 0;
                    continue;
                }
                allidData[string3][k] = currentCharacter;
                k++;
            }
            int string4 = 0;
            while((currentCharacter = fgetc(scorepointer)) != EOF)
            {
                if(currentCharacter == '\n')
                {
                    string4++;
                    l = 0;
                    continue;
                }
                allscoreData[string4][l] = currentCharacter;
                l++;
            }
            fclose(firstnamespointer);
            fclose(lastnamespointer);
            fclose(idNumberpointer);
            fclose(scorepointer);
            //----------------------------------data is ready now we search
            printf("choose the type of search(by id: 1 / by score: 2\n");
            int searchchoice;
            char idsearch[100];
            scanf("%d",&searchchoice);
            if(searchchoice == 1)
            {
                printf("enter the id\n");
                scanf("%s",&idsearch);
                for(int i = 0;i < string1;i++)
                {
                    int compare = strcmp(allidData[i],idsearch);
                    if(compare == 0)
                    {
                        printf("id: %s\n",allidData[i]);
                        printf("first name: %s\n",allfirstNameData[i]);
                        printf("last name: %s\n",alllastNameData[i]);
                        printf("score: %s\n",allscoreData[i]);
                    }
                }
            }
            else if(searchchoice == 2)
            {
                printf("enter the score\n");
                scanf("%s",&idsearch);
                for(int i = 0;i < string1;i++)
                {
                    int compare = strcmp(allscoreData[i],idsearch);
                    if(compare == 0)
                    {
                        printf("id: %s\n",allidData[i]);
                        printf("first name: %s\n",allfirstNameData[i]);
                        printf("last name: %s\n",alllastNameData[i]);
                        printf("score: %s\n",allscoreData[i]);
                    }
                }
            }
        }
        //----------------------------------------------------------
        else if(menuchoice == 5)
        {
            printf("type in the new password\n");
            scanf("%s",&password);
            FILE * passwordfile;
            passwordfile = fopen("pass.txt","w");
            fputs(password,passwordfile);
            printf("now password is set to %s\n",password);
            fclose(passwordfile);
        }
        else if(menuchoice == 6)
        {
            return 0;
        }
        printf("do you wnat the program to start again?(yes:1 / no:0)\n");
        scanf("%d",&repeatChoice);
    }
    return 0;
}