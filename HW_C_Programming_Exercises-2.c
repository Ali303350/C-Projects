
#define _SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{

     int userSelection=0;

    while (userSelection != 3)
    {
        printf("What do you like to do?\n");
        printf("1 – Exercise 1\n");
        printf("2 – Exercise 2\n");
        printf("3 - Exit\n");
        scanf("%d",&userSelection);
        if(userSelection == 1)
        {
               // Exercise "1"

             int minCols, maxCols, minRows, maxRows;
            printf("Enter range of the Rows:\n");
            scanf("%d%d", &minCols, &maxCols);
            printf("Enter range of the columns:\n");
            scanf("%d%d", &minRows, &maxRows);

            printf("Your Table is:\n");
            printf("\t\t");
            if (minRows < maxRows && (maxRows - minRows <= 10 && maxRows - minRows > 0) && minCols < maxCols && (maxCols - minCols <= 10 && maxCols - minCols > 0)
            && minRows <= 99 && maxRows <= 99 && minCols <= 99 && maxCols <= 99)
            {
                    for (int j = minRows; j <= maxRows; j++)
                    {
                        printf("%d\t", j);
                    }
                    printf("\n");
                    printf("----------------");
                    for (int j = minRows; j <= maxRows; j++)
                    {
                         printf("--------");
                    }
                    printf("\n");
                    for (int i = minCols; i <= maxCols; i++)
                    {
                        printf("%d", i);
                        printf("\t|\t");
                    for (int j = minRows; j <= maxRows; j++)
                    {

                        printf("%d\t", i * j);
                    }
                        printf("\n");
                    }
            }
            else
                printf("You must enter a correct range\n");
                //End of Exercise "1"

        }
               //Exercise 2
         if(userSelection == 2)
        {
                int num,x,counterN=0;
                srand(time(NULL));
                x = rand()%100+1;

                char again = 'y';


                while(again == 'y')
                {
                    x = rand()%100+1;
                    for(int i = 0; i<10;i++)
                   {
                        printf("please,enter your number from 1 to 100:\n");
                        scanf("%d",&num);
                        counterN++;

                            if (num > x)
                            {
                                printf("Your number is too big\n");
                            }
                            else if (num < x)
                            {
                                printf("Your number is too small\n");
                            }
                            else
                            {
                                printf("Congratulation! Your result is:%d trails\n",counterN);
                                break;
                            }
                    }
                              counterN=0;

                            if(counterN == 10)
                            {
                                printf("Sorry,your trails in this game are over! But you can begin new game.\n");
                            }
                                printf("Do you want play again? (y/n)\n");
                                scanf("%s",&again);
                                if(again == 'n')
                                {
                                    printf("Thanks for playing!\n");
                                    break;
                                }
                                else if (again != 'y' && again != 'n')
                                {
                                    printf("Error input. Please enter 'y' or 'n' .\n");
                                }

                }
                //End of Exercise "2"
        }
                            if(userSelection == 3)
                            {
                                printf("Thanks for playing, Bye!\n");
                            }

    }
return 0;

}
