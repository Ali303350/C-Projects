
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int num1,num2,num3,userNum,resetValue;

    printf("Enter a 3 digits number\n");
    scanf("%d",&userNum);
        if (userNum >= 100 && userNum <= 999){
              resetValue = userNum % 7;


              num1 = userNum % 10;
              userNum = userNum / 10;
              num2 = userNum % 10;
              num3 = userNum / 10;

            if( (resetValue == 0 && (num1 == 7 || num2 == 7 || num3 == 7 )) || (num1 + num2 + num3) == 7 ){
                printf("BOOM\n");
            } else {
                printf("NO BOOM\n");
            }
        } else {
            printf("your must enter a 3 digits number\n");
        }

    return 0;
}




int main(){

    int hour , min , sec,userSecs , totalMins , totalSecs , totalHours , userTotalSec, days, flightTime, flag = 0;


    printf("ENTER START TIME (Hour ,min ,Sec)\n");
    scanf("%d%d%d", &hour, &min, &sec);

    if (sec >= 0 && sec < 60 && min >= 0 && min < 60 && hour >= 0 && hour < 24){
        userTotalSec = (hour *3600) + (min * 60) + sec;

        printf("Enter flight time in Seconds:\n");
        scanf("%d", &userSecs);

        flightTime = userSecs + userTotalSec;
        if(userSecs > 0){
            totalMins = flightTime / 60;
            totalSecs = flightTime % 60;

            if(totalMins >= 60){
                totalHours = totalMins / 60;
                totalMins = totalMins % 60;
            }else{
                totalHours = 0;
            }
        printf("The landing will take place at ");

    int saveTotalHours = totalHours;

    if (totalHours != 0 || totalHours == 1 || totalHours != 1){
        if(totalHours >= 24){
             totalHours = totalHours % 24;
        }
            if (totalHours != 0 && totalHours == 1)
            {
               printf("%d hour ",totalHours);
            }if (totalHours != 0 && totalHours != 1){
              printf("%d hours ",totalHours);
            }

    }
    if ( totalMins == 0 || totalMins != 0 || totalMins == 1 || totalMins != 1){
        if(totalMins == 0 ){
            flag++;
        }
        if (totalMins != 0 && totalMins == 1)
        {
           printf("%d minute ",totalMins);
        }
        if (totalMins != 0 && totalMins != 1){
          printf("%d minutes ",totalMins);
        }
    }

    if ( totalSecs == 0 || totalSecs != 0 || totalSecs == 1 || totalSecs != 1){
         if(totalSecs == 0 ){
            flag++;
        }
        if (totalSecs != 0 && totalSecs == 1)
        {
           printf("%d second",totalSecs);
        }if (totalSecs != 0 && totalSecs != 1){
          printf("%d seconds",totalSecs);
        }
    }

    if(flag == 2){
        printf(" exactly");
    }

      if(saveTotalHours >= 24){
            days = saveTotalHours / 24;
            saveTotalHours = saveTotalHours % 24;
            if(days == 1){
                printf(" (+%d day)\n",days);
            }else{
                 printf(" (+%d days)\n",days);
            }

        }

        } else {
            printf("Your flight time can't be zero!\n");
        }
    } else
        {
        printf("You have entered a wrong values!\n");
        }

    return 0;
}
