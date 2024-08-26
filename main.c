
/* Section : Includes */

#include "main.h"

void main(void)
{
    uint8 enter = WRONG;
    uint8 triels = 0 ;

    COLOR();
    wel_come();

    while(triels<TRIELS)
    {
        enter = login();
        if(CORRECT == enter)
        {
            gotoxy(19,37);
            printf("Entered Successful :)");
            Sleep(1000);
            CLEAR_CONSOLE();
            break;
        }
        else
        {
            gotoxy(19,37);
            printf("Wrong UserName or Password !!");
            Sleep(1200);
            CLEAR_CONSOLE();
        }
        triels++;
    }

    if(triels >= TRIELS)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t SYSTEM OUT \n\n\n\n\n\n\n\n\n\n");
        exit(0);
    }
    else {/* Nothing */}

    while(1)
    {
        menu();
    }
}
