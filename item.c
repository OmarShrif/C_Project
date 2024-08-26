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
static void list(FILE *new_data,uint8 x, uint8 y);

void add_item(void)
{
    gotoxy(26,10);
    printf("Press Enter to continue ...");
    gotoxy(26,37);
    while(getch() != ENTER);
}

void delete_item(void)
{
    gotoxy(26,10);
    printf("Press Enter to continue ...");
    gotoxy(26,37);
    while(getch() != ENTER);
}

void edit_item(void)
{
    gotoxy(26,10);
    printf("Press Enter to continue ...");
    gotoxy(26,37);
    while(getch() != ENTER);
}

void search_item(void)
{

    gotoxy(26,10);
    printf("Press Enter to continue ...");
    while(getch() != ENTER);
}

void items_list(void)
{
    uint8 x = 7;
    uint8 y = 15;
    uint16 number_of_items = 0;
    fpos_t pos = 0;
    new_data = fopen(_new,"r");

    while((fscanf(new_data,"%s %i %i %s %i",&(item.productname),&(item.price),&(item.Qnt),&(item.productcomp),&(item.productid))) != EOF)
    {
        number_of_items++;
    }
    pos = 0;
    fsetpos(new_data,&pos);
    if(number_of_items == 0)
    {
        gotoxy(x,y);
        printf("List is empty !!");
        fclose(new_data);
        gotoxy(26,15);
        printf("Press Enter to continue ...");
        while(getch() != ENTER);
    }
    else if(number_of_items <=15)
    {
        list(new_data,x,y);
        fclose(new_data);
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
            fgetpos(new_data,&(poses[counter]));
            list(new_data,x,y);
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
                fclose(new_data);
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
                    fsetpos(new_data,&(poses[counter]));
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

void list(FILE *new_data,uint8 x, uint8 y)
{
    uint8 counter = 0;
    system("cls");
    frame();
    gotoxy(x,y);
    printf("Product");
    gotoxy(x,y+20);
    printf("Price");
    gotoxy(x,y+40);
    printf("Quantity");
    gotoxy(x,y+60);
    printf("Company");
    gotoxy(x,y+80);
    printf("Id");
    for(counter = 0 ; counter<15 ; counter++)
    {
        if((fscanf(new_data,"%s %i %i %s %i",&(item.productname),&(item.price),&(item.Qnt),&(item.productcomp),&(item.productid))) != EOF)
        {
            x++;
            gotoxy(x,y);
            printf("%s",item.productname);
            gotoxy(x,y+20);
            printf("%i",item.price);
            gotoxy(x,y+40);
            printf("%i",item.Qnt);
            gotoxy(x,y+60);
            printf("%s",item.productcomp);
            gotoxy(x,y+80);
            printf("%i",item.productid);
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
