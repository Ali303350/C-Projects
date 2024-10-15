
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 8
#define M 3
#define ROWS 4
#define COLS 6
#define K 8
void PRINT_ARRAY();
int PRINT_SUM();
int CHECK_ASCENDING_ORDER();
int CHECK_EQUAL_PAIRS();
void Print_Table();
void Sums_by_days();
void Best_day();
float Sum_of_the_week();

int main()
{
    int UserSelection;
    while(UserSelection != 4)
    {
        printf("What do you like to do?\n");
        printf("1 – Exercise 1\n");
        printf("2 – Exercise 2\n");
        printf("3 - Exercise 3\n");
        printf("4 - Exit\n");
        scanf("%d",&UserSelection);
        if(UserSelection == 1)
        {
            int arr[N][M];//Question "1"
            for(int i = 0; i < N; i++)
            {
                int num = i;
                for(int j = M-1; j >= 0; j--)
                {
                    arr[i][j] = num % 2;
                    num = num / 2;
                }
                printf("\n");
            }

              for(int i  = 0; i < N; i++)
              {
                for(int j = 0; j < M; j++)
                {
                    printf("%d\t",arr[i][j]);
                }
                printf("\n");
              }
        }
        if(UserSelection == 2)
        {   int arr[K];//Question "2"
            int i,option=0,n,m;
              printf("Enter numbers:\n");
              for (i=0 ; i < K; i++)
              scanf("%d",&arr[i]);

            while(option != 5)
            {
                printf("what is your option:\n");
                printf("1-Print the array.\n2-Print sum of elements from index n till index m.\n3-Check,are the elements in ascending order?\n");
                printf("4-check,is the array filled with two identical sequential data.\n5-Exit from program.\n");
                scanf("%d",&option);
                if (option == 1)
                {
                    PRINT_ARRAY(arr);
                }
                if (option == 2)
                {
                    printf("Enter a range numbers:\n");
                    scanf("%d%d",&n,&m);
                        printf("your sum is: %d\n",PRINT_SUM(arr,m,n));
                }
                if(option == 3)
                {
                    int result = CHECK_ASCENDING_ORDER(arr);
                    if (result == 1)
                        printf("True\n");
                    else
                        printf("False\n");
                }
                if(option == 4)
                {
                    int result = CHECK_EQUAL_PAIRS(arr);
                    if (result == 1)
                        printf("True\n");
                    else
                        printf("False\n");
                }
                else if(option == 5)
                {
                    printf("Thanks for playing!!\n");
                }
            }
        }

        if(UserSelection == 3)
        {
            int i,j,Choise,week;//Question "3"
            float Result=0;
            float arr[ROWS][COLS]={{2304.56 , 698.00 , 1873.60 , 970.00 , 2009.10 , 897.43},
                                  {980.30 , 1102.55 , 1003.75 , 2024.00 , 596.95 , 1564.25},
                                  {1324.70 , 93.50 , 873.10 , 1680.75 , 2104.65 , 993.45},
                                  {1707.00 , 234.55 , 2855.60 , 3001.58 , 987.75 , 2100.99}};
            // float arr[ROWS][COLS];
            //  for (int i=0 ; i < ROWS; i++)
            //  {
            //  printf("Enter numbers:\n");

            //     for(int j=0; j < COLS; j++)
            //         scanf("%f",&arr[i][j]);
            while(Choise != 5)
            {
                printf("\nPlease Choose what do you want to do:\n");
                printf("1- Print table\n2- Show sales by days\n3- Best day\n4- Chose a week (1-4) to see sum of the sales\n5- Exit from program\n");
                scanf("%d",&Choise);

                if(Choise == 1)
                {
                    Print_Table(arr);
                }
                if(Choise == 2)
                {
                    Sums_by_days(arr);
                }
                if(Choise == 3)
                {
                    Best_day(arr);
                }
                if(Choise == 4)
                {

                    printf("Choose a week from (1-4)\n");
                    scanf("%d",&week);
                    Result =  Sum_of_the_week(arr,week);

                }
                else if (Choise == 5)
                {
                    printf("Thanks for playing.\n");
                }
            }
        }

        else if(UserSelection == 4)
        {
            printf("Thanks for playing CYA.\n");
        }
    }
        return 0;
}

     void PRINT_ARRAY(int arr[])// function "1" -for Question "2"      (Start functions of Question "2")
            {

                for(int i = 0; i < K; i++)
                {
                    printf("%d\t",arr[i]);
                }
                printf("\n");
            }

            int PRINT_SUM(int arr[],int m,int n)// function "2" -for Question "2"
            {
                int sum=0;
                for (int i = n-1 ; i < m; i++)
                {
                    sum = sum + arr[i];
                }
                return sum;
            }

            int CHECK_ASCENDING_ORDER(int arr[])//function "3" -for Question "2"
            {
                    for(int i = 0; i < K; i++)
                    {
                        if (!(arr[i] < arr[i+1]))
                        {
                            return 0;
                        }
                    }
                return 1;
            }

            int CHECK_EQUAL_PAIRS(int arr[])//function "4" -for Question "2"  (End functions of Question "2")
            {

                for(int i = 0 ; i < K ; i++)
                {
                        if ((arr[i] == arr[i+1]))
                        {
                            return 1;
                        }
                }
                return 0;
            }

    void Print_Table(float arr[ROWS][COLS])//function "1"- Question "3"         (Start functions of Question "3")
    {
        int i,j;

        printf("\tSunday\t   \tMonday\t   \tTuesday\t   \tWednesday       Thursday        Friday\n");
        printf("\t------\t   \t------\t   \t-------\t   \t---------       --------        ------\n");

        for(i = 0; i < ROWS; i++)
        {
            printf("\n");
            printf("Week%d|",i+1);
            printf("\t");
            for(j = 0; j < COLS; j++)
            {
                printf("%.2f\t\t", arr[i][j]);
            }
        }
    }

    void Sums_by_days(float arr[ROWS][COLS])//function "2"- Question "3"
    {

            float temp[ROWS];
            float sum= 0;
          for(int i=0 ;i < COLS;i++)
          {
              for(int j=0 ;j < ROWS;j++)
              {
                 sum = sum + arr[j][i];
              }
              temp[i] = sum;
              sum = 0;
          }
            printf("\tSunday\t   \tMonday\t   \tTuesday\t   \tWednesday       Thursday        Friday\n");
            printf("\t------\t   \t------\t   \t-------\t   \t---------       --------        ------\n");
          for(int i = 0;i<COLS; i++)
          {
              printf("\t");
              printf("%.2f\t", temp[i]);
          }
    }


    void Best_day(float arr[ROWS][COLS])//function "3"- Question "3"
    {
        float temp[ROWS];
        float sum= 0;

          for(int i=0 ;i < COLS;i++)
          {
              for(int j=0 ;j < ROWS;j++)
              {
                 sum = sum + arr[j][i];
              }
              temp[i] = sum;
              sum = 0;
          }

          float max=0;
          int day=0;
          for(int i = 0 ;i < COLS ; i++)
            {
                if (temp[i] > max)
                {
                   max = temp[i];
                   day = i;
                }
            }
            switch(day)
            {
             case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            }
    }

    float Sum_of_the_week(float arr[ROWS][COLS], int week)//function "4"- Question "3"   (End functions of Question "3")
    {
           float temp[ROWS];
            float sum= 0;
          for(int i=0 ;i < ROWS;i++)
          {
              for(int j=0 ;j < COLS;j++)
              {
                 sum = sum + arr[i][j];
              }
              temp[i] = sum;
              sum = 0;
          }
          switch(week)
          {
             case 1:
                printf("Total sales on Week1:%.2f\n",temp[0]);
                break;
            case 2:
                printf("Total sales on Week2:%.2f\n",temp[1]);
                break;
            case 3:
                printf("Total sales on Week3:%.2f\n",temp[2]);
                break;
            case 4:
                printf("Total sales on Week4:%.2f\n",temp[3]);
                break;
          }

    }
