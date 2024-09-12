/*
 * File:   system.c
 * Author: Omar Shrif Mohamed
 * https://www.linkedin.com/in/omar-shrif-982413213/
 * Created on 08, 17, 2024, 07:10 PM
 */

#include "system.h"

void _time(uint8 *t)
{
    uint8 t2[25] = {0};
    uint8 t3[12] = {0};
    uint8 t4[9] = {0};
    time_t t1;
    time(&t1);
    strcpy(t2,ctime(&t1));
    strncpy(t3,&t2[4],7);
    strncpy(&t3[7],&t2[20],4);
    strncpy(t4,&t2[11],8);
    strcpy(t,t4);
    memset(&t[8],' ',3);
    strcpy(&t[11],t3);
}

void frame(void)
{
    uint8 t[22] = {0};
    printf("\n\t----------------------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t----------------------------------------------------------------------------------------------------\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t|                                                                                                  |\n");
    printf("\t----------------------------------------------------------------------------------------------------\n");

    _time(t);
    gotoxy(3,45);
    printf("%s",t);
}

void wel_come(void)
{
    frame();
    gotoxy(10,40);
    printf("WELCOME TO STOCK MANAGEMENT SYSTEM");
    gotoxy(14,49);
    printf("CAIRO - EGYPT");
    gotoxy(18,30);
    printf("https://www.linkedin.com/in/omar-shrif-982413213");
    gotoxy(26,10);
    printf("Press Enter to continue ...");
    gotoxy(26,37);
    while(getch() != ENTER);
    CLEAR_CONSOLE();
}

uint8 login(void)
{
    frame();
    uint8 enter = WRONG;
    uint8 user[USERNAME_LENGTH+1] = {0};
    uint8 pass[PASSWORD_LENGTH+1] = {0};
    sint8 counter = 0;
    uint8 temp = 0;
    gotoxy(13,37);
    printf("UserName :");
    gotoxy(15,37);
    printf("Password :");
    gotoxy(13,48);
    gets(user);
    while(!strlen(user))
    {
        gotoxy(13,48);
        gets(user);
    }
    while(counter == 0)
    {
        gotoxy(15,48);
        temp = getch();
        while(temp != ENTER)
        {
            if(counter<PASSWORD_LENGTH)
            {
                pass[counter] = temp;
            }
            printf("*");
            counter++;
            temp = getch();
        }
    }

    if((counter == PASSWORD_LENGTH) && (strcmp(USERNAME,user) == 0) && (strcmp(PASSWORD,pass) == 0))
    {
        enter = CORRECT;
    }
    else
    {
        enter = WRONG;
    }

    return enter;
}

void menu(void)
{
    CLEAR_CONSOLE();
    frame();
    uint8 selection = 0;
    gotoxy(10,30);
    printf("MAIN MENU :");
    gotoxy(12,30);
    printf("Add item                               <1>");
    gotoxy(13,30);
    printf("Delete item                            <2>");
    gotoxy(14,30);
    printf("Edit item                              <3>");
    gotoxy(15,30);
    printf("Search item                            <4>");
    gotoxy(16,30);
    printf("Items List                             <5>");
    gotoxy(17,30);
    printf("Exit                                   <6>");
    gotoxy(19,30);
    printf("Selection >> ");
    selection = getch();
    while(selection < '1' || selection > '6')
    {
        selection = getch();
    }
    selection -= 48;
    printf("%i",selection);
    gotoxy(19,44);
    CLEAR_CONSOLE();
    frame();
    switch (selection)
    {
    case 1 :
    {
        add_item(frame);
        break;
    }
    case 2 :
    {
        delete_item(frame);
        break;
    }
    case 3 :
    {
        edit_item(frame);
        break;
    }
    case 4 :
    {
        search_item(frame);
        break;
    }
    case 5 :
    {
        items_list(frame);
        break;
    }
    case 6 :
    {
        gotoxy(19,44);
        CLEAR_CONSOLE();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t SYSTEM OUT \n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(0);
    }
    default :
    {
        break;
    }
    }
}
