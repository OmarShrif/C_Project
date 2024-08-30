/*
 * File:   item.c
 * Author: Omar Shrif Mohamed
 * https://www.linkedin.com/in/omar-shrif-982413213/
 * Created on 08, 17, 2024, 07:24 PM
 */

/* Section : Includes */

#include "item.h"

/* Section : Global variables Definations */

NewItem item = {0};
FILE *new_data = NULL;
FILE *current_data = NULL;

/* Section : Functions Definations */
static void list(FILE *_data,uint8 x,uint8 y,void (*fram)(void));

uint8 add_item(void (*fram)(void))
{
    uint8 x = 8;
    uint8 y = 15;
    uint8 one = 1;
    uint8 name[18] = {0};
    uint8 code[10] = {0};
    uint8 found = NOT_FOUND;
    fpos_t pos = 0;
    current_data = fopen(_current,"a+");

    while((fscanf(current_data,"%s %i %i %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
    {
        if(1 == one)
        {
            one++;
            gotoxy(x,y);
            printf("Enter item name : ");
            gets(name);
            while(!strlen(name))
            {
                gotoxy(x,33);
                gets(name);
            }
        }
        if(strcmp(name,item.name) == 0)
        {
            gotoxy(x+1,y);
            printf("item name already exists !!");
            found = FOUND;
            fclose(current_data);
            gotoxy(26,15);
            printf("Press Enter to continue ...");
            while(getch() != ENTER);
            break;
        }
    }
    if(1 == one)
    {
        gotoxy(x,y);
        printf("Enter item name : ");
        gets(item.name);
        while(!strlen(item.name))
        {
            gotoxy(x,33);
            gets(item.name);
        }
        gotoxy(x+1,y);
        printf("Enter item code : ");
        gets(item.code);
        while(!strlen(item.code))
        {
            gotoxy(x+1,31);
            gets(item.code);
        }
        gotoxy(x+2,y);
        printf("Enter company name : ");
        gets(item.company);
        while(!strlen(item.company))
        {
            gotoxy(x+2,36);
            gets(item.company);
        }
        gotoxy(x+3,y);
        printf("Enter item price : $");
        gets(item.price);
        while(!strlen(item.price))
        {
            gotoxy(x+3,35);
            gets(item.price);
        }
        gotoxy(x+4,y);
        printf("Enter item quantity : ");
        gets(item.quantity);
        while(!strlen(item.quantity))
        {
            gotoxy(x+4,37);
            gets(item.quantity);
        }
        fprintf(current_data,"%s %s %s %s %s\n",item.name,item.price,item.quantity,item.company,item.code);
        fclose(current_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else
    {
        one = 1;
        pos = 0;
        fsetpos(current_data,&pos);
        while((fscanf(current_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
        {
            if(1 == one)
            {
                one++;
                gotoxy(x+1,y);
                printf("Enter item code : ");
                gets(code);
                while(!strlen(code))
                {
                    gotoxy(x+1,31);
                    gets(code);
                }
            }
            if(strcmp(code,item.code) == 0)
            {
                gotoxy(x+2,y);
                printf("item code already exists !!");
                found = FOUND;
                fclose(current_data);
                gotoxy(26,15);
                printf("Press Enter to continue ...");
                while(getch() != ENTER);
                break;
            }
        }
        if(NOT_FOUND == found)
        {
            strcpy(item.name,name);
            strcpy(item.code,code);
            gotoxy(x+2,y);
            printf("Enter company name : ");
            gets(item.company);
            while(!strlen(item.company))
            {
                gotoxy(x+2,36);
                gets(item.company);
            }
            gotoxy(x+3,y);
            printf("Enter item price : $");
            gets(item.price);
            while(!strlen(item.price))
            {
                gotoxy(x+3,35);
                gets(item.price);
            }
            gotoxy(x+4,y);
            printf("Enter item quantity : ");
            gets(item.quantity);
            while(!strlen(item.quantity))
            {
                gotoxy(x+4,37);
                gets(item.quantity);
            }
            fprintf(current_data,"%s %s %s %s %s\n",item.name,item.price,item.quantity,item.company,item.code);
            fclose(current_data);
            gotoxy(26,15);
            printf("Press Enter to continue ...");
            while(getch() != ENTER);
        }
    }
    return found;
}

void delete_item(void (*fram)(void))
{
    uint8 x = 7;
    uint8 y = 15;
    uint8 one = 1;
    uint8 search[18] = {0};
    uint8 found = NOT_FOUND;
    current_data = fopen(_current,"r");
    new_data = fopen(_new,"w");

    while((fscanf(current_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
    {
        if(1 == one)
        {
            one++;
            gotoxy(x,y);
            printf("Enter item name or code : ");
            gets(search);
            while(!strlen(search))
            {
                gotoxy(x,39);
                gets(search);
            }
        }
        if((strcmp(search,item.name) == 0) || (strcmp(search,item.code) == 0))
        {
            found = FOUND;
        }
        else
        {
            fprintf(new_data,"%s %s %s %s %s\n",item.name,item.price,item.quantity,item.company,item.code);
        }
    }
    if(1 == one)
    {
        gotoxy(x,y);
        printf("List is empty !!");
        fclose(new_data);
        fclose(current_data);
        remove(_new);
        rename(_new,_current);
        Sleep(20);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(NOT_FOUND == found)
    {
        CLEAR_CONSOLE();
        fram();
        gotoxy(x,y);
        printf("Item not found :(");
        fclose(new_data);
        fclose(current_data);
        remove(_current);
        rename(_new,_current);
        Sleep(20);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(FOUND == found)
    {
        CLEAR_CONSOLE();
        fram();
        gotoxy(x,y);
        printf("Item is deleted :)");
        fclose(new_data);
        fclose(current_data);
        remove(_current);
        rename(_new,_current);
        Sleep(20);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
}

void edit_item(void (*fram)(void))
{
    uint8 x = 7;
    uint8 y = 15;
    uint8 one = 1;
    uint8 search[18] = {0};
    uint8 found = NOT_FOUND;
    NewItem edit = {0};
    current_data = fopen(_current,"r");
    new_data = fopen(_new,"w");

    while((fscanf(current_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
    {
        if(1 == one)
        {
            one++;
            gotoxy(x,y);
            printf("Enter item name or code : ");
            gets(search);
            while(!strlen(search))
            {
                gotoxy(x,39);
                gets(search);
            }
        }
        if((strcmp(search,item.name) == 0) || (strcmp(search,item.code) == 0))
        {
            found = FOUND;
            edit = item;
        }
        else
        {
            fprintf(new_data,"%s %s %s %s %s\n",item.name,item.price,item.quantity,item.company,item.code);
        }
    }
    if(1 == one)
    {
        gotoxy(x,y);
        printf("List is empty !!");
        fclose(new_data);
        fclose(current_data);
        remove(_new);
        Sleep(50);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(NOT_FOUND == found)
    {
        CLEAR_CONSOLE();
        fram();
        gotoxy(x,y);
        printf("Item not found :(");
        fclose(new_data);
        fclose(current_data);
        remove(_current);
        rename(_new,_current);
        Sleep(50);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(FOUND == found)
    {
        CLEAR_CONSOLE();
        fram();
        gotoxy(x,y);
        printf("\xB2\xB2 New data \xB2\xB2");
        fclose(new_data);
        fclose(current_data);
        remove(_current);
        rename(_new,_current);
        Sleep(50);
        if(add_item(fram) == FOUND)
        {
            current_data = fopen(_current,"a+");
            fprintf(current_data,"%s %s %s %s %s\n",edit.name,edit.price,edit.quantity,edit.company,edit.code);
            fclose(current_data);
        }
    }
}

void search_item(void (*fram)(void))
{
    uint8 x = 7;
    uint8 y = 15;
    uint8 one = 1;
    uint8 search[18] = {0};
    uint8 found = NOT_FOUND;
    current_data = fopen(_current,"r");

    while((fscanf(current_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
    {
        if(1 == one)
        {
            one++;
            gotoxy(x,y);
            printf("Enter item name or code : ");
            gets(search);
            while(!strlen(search))
            {
                gotoxy(x,39);
                gets(search);
            }
        }
        if((strcmp(search,item.name) == 0) || (strcmp(search,item.code) == 0))
        {
            CLEAR_CONSOLE();
            fram();
            gotoxy(x,y);
            printf("Item Name : %s",item.name);
            gotoxy(x+1,y);
            printf("Item Price : $%s",item.price);
            gotoxy(x+2,y);
            printf("Item Quantity : %s",item.quantity);
            gotoxy(x+3,y);
            printf("Item Company : %s",item.company);
            gotoxy(x+4,y);
            printf("Item Id : %s",item.code);
            gotoxy(26,15);
            printf("Press Enter to continue ...");
            while(getch() != ENTER);
            found = FOUND;
            break;
        }
    }
    if(1 == one)
    {
        gotoxy(x,y);
        printf("List is empty !!");
        fclose(current_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(NOT_FOUND == found)
    {
        CLEAR_CONSOLE();
        fram();
        gotoxy(x,y);
        printf("Item not found :(");
        fclose(current_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
}

void items_list(void (*fram)(void))
{
    uint8 x = 7;
    uint8 y = 15;
    uint16 number_of_items = 0;
    fpos_t pos = 0;
    current_data = fopen(_current,"r");

    while((fscanf(current_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
    {
        number_of_items++;
    }
    pos = 0;
    fsetpos(current_data,&pos);
    if(number_of_items == 0)
    {
        gotoxy(x,y);
        printf("List is empty !!");
        fclose(current_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(number_of_items <=15)
    {
        list(current_data,x,y,fram);
        fclose(current_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else
    {
        uint8 counter = 0;
        fpos_t * poses = NULL;
        uint8 layers = number_of_items/15;
        if(number_of_items%15)
        {
            layers+=1;
        }
        poses = (fpos_t *)calloc(layers,sizeof(fpos_t));
        for(counter = 0 ; counter < layers ; counter++)
        {
            x = 7;
            y = 15;
            uint8 chooies = 0;
            fgetpos(current_data,&(poses[counter]));
            list(current_data,x,y,fram);
again:
            gotoxy(26,15);
            printf("Main Menu <Enter>          Previous <4>          Next <6> :");
            chooies = getch();
            while((chooies != ENTER) && (chooies != '4') && (chooies != '6'))
            {
                chooies = getch();
            }
            if(chooies == ENTER)
            {
                fclose(current_data);
                break;
            }
            else if(chooies == '4')
            {
                if(counter == 0)
                {
                    goto again;
                }
                else
                {
                    counter--;
                    fsetpos(current_data,&(poses[counter]));
                    counter--;
                }
            }
            else if(chooies == '6')
            {
                if(counter == layers-1)
                {
                    goto again;
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

void list(FILE *_data,uint8 x,uint8 y,void (*fram)(void))
{
    uint8 counter = 0;
    CLEAR_CONSOLE();
    fram();
    gotoxy(x,y);
    printf("Item");
    gotoxy(x,y+20);
    printf("Price ($)");
    gotoxy(x,y+40);
    printf("Quantity");
    gotoxy(x,y+60);
    printf("Company");
    gotoxy(x,y+80);
    printf("Code");
    for(counter = 0 ; counter<15 ; counter++)
    {
        if((fscanf(_data,"%s %s %s %s %s",&(item.name),&(item.price),&(item.quantity),&(item.company),&(item.code))) != EOF)
        {
            x++;
            gotoxy(x,y);
            printf("%s",item.name);
            gotoxy(x,y+20);
            printf("%s",item.price);
            gotoxy(x,y+40);
            printf("%s",item.quantity);
            gotoxy(x,y+60);
            printf("%s",item.company);
            gotoxy(x,y+80);
            printf("%s",item.code);
        }
        else
        {
            break;
        }
    }
}

void gotoxy(uint8 y, uint8 x)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
