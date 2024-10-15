
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 10 // Q "3"
#define M 6 // Q "3"
#define R 20 // Q "2"

//functions for Q "1"-
int symmetric(char str[]);

//functions for Q "2"-
void SPECIAL_NUMBER(int arr[],int *numIndex, int *numCount);

//functions for Q "3"-
typedef struct
{
    char NameOfTheDog[15];
    char ColourOfTheDog[10];
    int IdOwnerOfTheDog;
    int DateOfTheVaccination;
    int SizeOfDog;//(1-small 2-medium 3-large)

}Dog;

typedef struct
{
   char NameOfTheOwner[20];
   int IdOwnerOfTheDog;
   int PhoneNumber;

}Person;

int NumbersOfBigDogsWithNoVac(Dog dogs_arr[]);
void NamesAndIdOfTheOwnersThatDogsNoVac(Person persons_arr[],Dog dogs_arr[]);
void NamesAndPhoneNumbersForDogsWithOldVaccination(Person persons_arr[],Dog dogs_arr[]);
void NamesOfTheOwnersThatOwnMoreThanOneDog(Person persons_arr[],Dog dogs_arr[]);
void TheMostColorusOnDogs(Dog dogs_arr[]);
void findTheDogsForPerson(Person persons_arr[],Dog dogs_arr[], int id);
void findPersonByDogColor(Person persons_arr[],Dog dogs_arr[], char color[]);

//functions for Q "4"-
int Check (int A[3]);
int Decoder (int A[3]);
int Mux(int I[4],int S[2]);


int main()
{
    int UserSelection;
    while(UserSelection != 5)
    {
        printf("What is your choice:\n");
        printf("1 – Exercise 1\n");
        printf("2 – Exercise 2\n");
        printf("3 - Exercise 3\n");
        printf("4 - Exercise 4\n");
        printf("5 - Exit\n");
        scanf("%d",&UserSelection);

        if(UserSelection == 1)//start of Q "1"
        {
            char str[100];
            printf("Enter a string of characters: ");
            getchar();
            gets(str);
            int symmetricCount = symmetric(str);
            printf("There are %d symmetric words in the sentence\n", symmetricCount);
        }
        if(UserSelection == 2)//start of Q "2"
        {
            int arr[R],numIndex, numCount;
            printf("Please start by filling numbers from 1 till 20\n");
            for(int i =0; i< R; i++)
            {
              printf("Enter the %d number:\n",i+1);
              scanf("%d",&arr[i]);
            }
            SPECIAL_NUMBER(arr,&numIndex,&numCount);
            printf("The count of digits: %d\n",numCount);
            printf("The index of the number: %d\n",numIndex);

        }
        if(UserSelection == 3)//start of Q "3"
        {
            Dog dogs_arr[N]=
            {
                {"dog1", "white", 1111, 150617, 1},
                {"dog2", "black", 2222, 999999, 1},
                {"dog3", "gray",  3333, 200620, 2},
                {"dog4", "white", 6666, 111214, 1},
                {"dog5", "white", 5555, 150121, 1},
                {"dog6", "black", 6666, 999999, 1},
                {"dog7", "white", 2222, 300120, 2},
                {"dog8", "white", 6666, 150615, 1},
                {"dog9", "gray" , 9999, 999999, 1},
                {"dog10","white", 1111, 220521, 3}
            };

            Person persons_arr[M]=
            {
                {"Man1", 2222, 636591},
                {"Man2", 3333, 698674},
                {"Man3", 5555, 8635672},
                {"Man4", 6666, 5466654},
                {"Man5", 9999, 8612340},
                {"Man6", 1111, 5368879}
            };

            printf("1)Number of large dogs with no vaccination: %d\n",NumbersOfBigDogsWithNoVac(dogs_arr));//function"1"
            printf("\n");
            printf("2)Name and Id of the Owners of the dogs have not been vaccinated:\n");
            NamesAndIdOfTheOwnersThatDogsNoVac(persons_arr,dogs_arr);//function"2"
            printf("3)Id and PhoneNumber of the Owners of the dogs have been vaccinated before 2018:\n");
            NamesAndPhoneNumbersForDogsWithOldVaccination(persons_arr,dogs_arr);//function "3"
            printf("4)Names of the owners that have more than one dogs:\n");
            NamesOfTheOwnersThatOwnMoreThanOneDog(persons_arr,dogs_arr);//function "4"
            printf("5)The most colour of dogs:\n");
            TheMostColorusOnDogs(dogs_arr);//function "5"
            //function "6"
            int id;
            printf("Enter the ID:\n");
            scanf("%d",&id);
            findTheDogsForPerson(persons_arr,dogs_arr,id);
            //function "7"
            printf("Enter a color:\n");
            char color[10];
            scanf("%s", color);
            findPersonByDogColor(persons_arr,dogs_arr,color);

        }
        if(UserSelection == 4)//start of Q "4"
        {
                    char again = 'y';
            int A[3],I[4] = {0,0,0,0},S[2] = {0,0};
            int d=0;
            while(again == 'y')
            {
                printf("Enter a 3 Binary numbers:\n");
                for(int i = 0; i < 3; i++)
                {
                    scanf("%d",&A[i]);
                }
                int result = Check(A);
                if(result == 1)
                {
                    d = Decoder(A);
                    if(d < 4)
                    {
                        I[d] = 1;
                    }
                    else if (d > 6)
                    {
                       S[d-6] = 1;
                    }
                     int Y = Mux(I,S);
                     printf("The result is: %d\n",Y);
                }
                printf("Do you want to get answer to another 3 inputs (y/n)? \n");
                scanf("%s", &again);

                if(again == 'n')
                {
                    printf("Thanks!\n");
                    break;
                }
                else if (again != 'y' && again != 'n')
                {
                    printf("Error input. Please enter 'y' or 'n' .\n");
                }

            }
        }
        else if(UserSelection == 5)//Exit
        {
            printf("Thanks for you Time\n");
        }

    }

    return 0;
}

    int symmetric(char str[]) //function "1" - Question "1"
    {
        int count = 0, wordCount = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] != ' ')
            {
                wordCount++;
                char word[100] = "";
                int j = i, k = 0;
                while (j < strlen(str) && str[j] != ' ')
                {
                    word[k] = str[j];
                    k++; j++;
                }
                i = j;
                int isSymmetric = 1;
                for (int k = 0; k < strlen(word)/2; k++)
                {
                    if (word[k] != word[strlen(word)-1-k])
                    {
                        isSymmetric = 0;
                        break;
                    }
                }
                if (isSymmetric) {
                    count++;
                    printf("\nWord:%s\nLength of the word is: %ld\nplace in the line is:%d\n",word, strlen(word), wordCount);
                }
            }
        }
        return count;
    }

    void SPECIAL_NUMBER(int arr[],int *numIndex, int *numCount)//function "1" - Question "2"
    {
      int count = 0, save, counter = 0,index;
      for(int i = 0; i< R; i++){
        save = arr[i];
        while(save != 0){// find the length of the array
          save = save/10;
          count++;
        }

        if(arr[i] % 2 == 0 && count > 1)
        {

          int tempArr[count],save2;
          save2 = arr[i];
          for(int j = 0; j< count; j++)
          {// save the number into temp array
            tempArr[j] = save2%10;
            save2 = save2/10;
          }

          for(int k = 0; k < count/2; k++)
          {
            if(tempArr[k] == tempArr[count-k-1])
            {
              counter++;//1
            }
          }

          if(counter == count/2)
          {//the count is the number of digits for the wanted number
            *numIndex = i+1; // the number index
            *numCount = count;
          }

          count = 0,counter = 0;
        }
        else
        {
          count = 0;
        }

      }
    }

    int NumbersOfBigDogsWithNoVac(Dog dogs_arr[])//function "1" - Question "3"
    {
        int count=0;
        for(int i = 0; i < N; i++)
        {
            if(dogs_arr[i].SizeOfDog == 3 && dogs_arr[i].DateOfTheVaccination == 999999)
            {
                count++;
            }
        }
         return count;
    }

    void NamesAndIdOfTheOwnersThatDogsNoVac(Person persons_arr[],Dog dogs_arr[])//function "2" - Question "3"
    {
        int k=0;
        int tempArr[N];
            for(int i = 0; i < N; i++)
            {
                if(dogs_arr[i].DateOfTheVaccination == 999999)
                {
                    tempArr[k] = dogs_arr[i].IdOwnerOfTheDog;
                    k++;
                }
            }

            for(int j = 0; j < M; j++)
            {
                for(int m = 0; m < k; m++)
                {
                    if(persons_arr[j].IdOwnerOfTheDog == tempArr[m])
                    {
                        printf("- %s  -ID: %d\n",persons_arr[j].NameOfTheOwner,persons_arr[j].IdOwnerOfTheDog);
                    }
                }
            }
                printf("\n");
    }

    void NamesAndPhoneNumbersForDogsWithOldVaccination(Person persons_arr[],Dog dogs_arr[])//function "3" - Question "3"
    {
        int first=0,second=0,save=0,year=0,k=0,tempArr[N];
      for(int i =0; i < N; i++)
      {
          if(dogs_arr[i].DateOfTheVaccination != 999999)
          {
             save = dogs_arr[i].DateOfTheVaccination;
             first = save % 10;
             save = save / 10;
             second = (save % 10) * 10;
             year = first + second;

                if(year < 18)
                {
                    tempArr[k] = dogs_arr[i].IdOwnerOfTheDog;
                    k++;
                }
          }
      }
      for(int j = 0; j < M; j++)
            {
                for(int m = 0; m < k; m++)
                {
                    if(persons_arr[j].IdOwnerOfTheDog == tempArr[m])
                    {
                        printf("- %s  -phone number: %d\n",persons_arr[j].NameOfTheOwner,persons_arr[j].PhoneNumber);
                    }
                }
            }
                   printf("\n");
    }

    void NamesOfTheOwnersThatOwnMoreThanOneDog(Person persons_arr[],Dog dogs_arr[])//function "4" - Question "3"
    {
        int tempArr[N],found_id=0;

        for(int i = 0; i <= N; i++)
        {
            found_id = dogs_arr[i].IdOwnerOfTheDog;

            for(int j = i+1; j < N; j++)
            {
               if(dogs_arr[j].IdOwnerOfTheDog == found_id)
               {
                   for(int k = 0; k < M; k++)
                   {
                       if(persons_arr[k].IdOwnerOfTheDog == found_id)
                       {
                            printf("- %s\n",persons_arr[k].NameOfTheOwner);
                       }
                   }
               }
            }
        }
        printf("\n");
    }

     void TheMostColorusOnDogs(Dog dogs_arr[])//function "5" - Question "3"
     {
         int max=0,count=0, index = 0, countLetters =0, flag =0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k< N; k++){
                    if(dogs_arr[i].ColourOfTheDog[k] != dogs_arr[j].ColourOfTheDog[k]){
                      flag = 1;
                    }
                }
                if(flag == 0){
                  count++;
                }
                flag = 0;

            }
            if(count > max)
            {
                max = count;
                index = i;
            }
            count = 0;
        }
        printf("%s \n",dogs_arr[index].ColourOfTheDog);

     }


    void findTheDogsForPerson(Person persons_arr[],Dog dogs_arr[], int id)//function "6" - Question "3"
    {
        int count = 0;
        for(int i = 0; i < M; i++)
        {
             if(persons_arr[i].IdOwnerOfTheDog == id)
             {
               printf("\n6)The person ID: %s\n", persons_arr[i].NameOfTheOwner);
             }
        }

        for(int i = 0; i < N; i++)
        {
             if(dogs_arr[i].IdOwnerOfTheDog == id)
             {
               count++;
               printf("The color: %s, ",dogs_arr[i].ColourOfTheDog);
               if(dogs_arr[i].SizeOfDog == 1){
                 printf("The size of the dog is: small\n");
               }else if(dogs_arr[i].SizeOfDog == 2){
                 printf("The size of the dog is: medium\n");
               }else{
                 printf("The size of the dog is: large\n");
               }
             }
        }
           if(count == 0)
           {
             printf("There are no dogs related to this owner id\n");
           }

    }

    void findPersonByDogColor(Person persons_arr[],Dog dogs_arr[], char color[])//function "7" - Question "3"
    {
           int flag = 0, count = 0, save = 0;//count- The count owners that have the same dog color
           for(int i = 0; i < N; i++)
           {
                for(int j = 0; j < strlen(color); j++)
                {
                    if(dogs_arr[i].ColourOfTheDog[j] != color[j])
                    {
                        flag = 1;
                    }
                }

             if(flag == 0)
                {
                    count++;
                }
             flag = 0;
           }

           if(count == 0)
           {
             printf("no such color!\n");
           }
           else
           {
                printf("The count owners that have the same dog color is: %d\n", count);
           }

    }

    int Check (int A[])//function "1" - Question "4"
    {
        for(int i = 0; i < 3; i++)
        {
            if(A[i] != 0 && A[i] != 1)
            {
                printf("Input %d is incorrect,It should be (0 or 1)\n",i);
                return 0;
            }
        }
        return 1;
    }

    int Decoder(int A[])// function "2" - Question "4"
    {
        int index = A[2]*4 + A[1]*2 + A[0];
        return index; //index is output of the decoder
    }

    int Mux(int I[], int S[])// function "3" - Question "4"
    {
        if(S[0] == 0 && S[1] == 0) return I[0];
        if(S[0] == 0 && S[1] == 1) return I[1];
        if(S[0] == 1 && S[1] == 0) return I[2];
        if(S[0] == 1 && S[1] == 1) return I[3];
        else{return 0;}
    }
