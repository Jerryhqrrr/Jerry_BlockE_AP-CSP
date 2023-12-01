#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
int *readFile(string fileName, int size, int size2);  //pointer to return and int array
int linearSearch(int array[], int guess, int size);  //linear search
int binarySearch(int array[],int choice){
    int star=0,mid, end=SIZE2-1;
    mid=(star+end)/2;
    while(star<=end){
        if(choice>array[mid])
            star=mid+1;
        if(choice<array[mid])
            end=mid-1;
        if(choice==array[mid]){
            return mid;
        }
        mid=(star+end)/2;
    }
    return 0;
}
int *bubbleSort(int array[]){
for(int i=0; i < SIZE2; i++){
        for(int j=0; j <SIZE2-1;j++){
            if(array[j]>array[j+1]){
                int b= array[j];
                array[j] = array[j+1];
                array[j+1] = b;
            }
        }

}
return array;
}
int *selectSort(int array[]){
    int c;
    for(int i=0;i<SIZE2;i++){
        int b = i;
        for(int j = i;j<SIZE2;j++){
            if(array[j]<array[b]){
                b=j;
            }
        }
        c=array[i];
        array[i] = array[b];
        array[b]=c;
}
return array;
}
void printArray(int array[], int size){
    for(int i=0;i<size ;i++)
        printf("%i \n",array[i]);
}


void writeFile(int array[], int size)
{
    string name = get_string("Enter the name of File: name.txt");
    FILE *f = fopen(name, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%d\n", array[i]);
    }
    fclose(f);
}
void menu(){
    printf("===============================\n");
    printf("*            Menu             *\n");
    printf("*     1)Read File             *\n");
    printf("*     2)Sort an Array         *\n");
    printf("*     3)Find an Index         *\n");
    printf("*     4)Write a File          *\n");
    printf("*     5)Exit                  *\n");
    printf("===============================\n");
}


int main(void){
    bool exit = false;
    int *array = NULL;
    int size;
    do{
        size = get_int("What do you want as the size of your array: 5000,10000, or 50000");
     } while (size !=5000||size!=10000||size!=50000);

    do
    {
        menu();
        int option = get_int("Which operation do you want to do?");

        switch (option)
        {
            case 1://Read File
                string filename;
                filename = get_string("Enter the name of the file: ");
                array = readFile(filename, SIZE2, 5);
                size = SIZE2;
                break;
            case 2://Sort an Array
                int sortOption = get_int("Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n");
                if (sortOption == 1)
                {
                    array = bubbleSort(array);
                    for(int i=0;i<size;i++){
                        print("%i,\n"array[i]);
                    }
                }
                else if (sortOption == 2)
                {
                    array = selectSort(array);
                    for(int i=0;i<size;i++)
                        print("%i,\n"array[i]);
                }
                break;

            case 3: // Find an Index
    if (array == NULL)
    {
        printf("Please read a file first.\n");
        break;
    }

    array = bubbleSort(array); // Sort the array before searching

    int searchOption = get_int("Choose search algorithm:\n1. Linear Search\n2. Binary Search\n");
    int guess = get_int("Enter the number to find: ");
    int index;

    switch (searchOption)
    {
        case 1: // Linear Search
            index = linearSearch(array, guess, size);
            break;

        case 2: // Binary Search
            index = binarySearch(array, guess);
            break;

        default:
            printf("Invalid search option.\n");
            break;
    }

    if (index != -1)
    {
        printf("Number found at index %d.\n", index);
    }
    else
    {
        printf("Number not found in the array.\n");
    }
    break;

            case 4://Write a File
                if (array == NULL)
                {
                    printf("Please read a file first.\n");
                    break;
                }

                writeFile(array, size);
                break;

            case 5: // Exit
                exit = true;
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }

    } while (!exit);

    return 0;
}

        // string fileName=get_string("Enter File name ");
        // FILE* file=(fopen(fileName, "r"));
        // if(!file)
        // {
        // printf("\n Unable to open : %s ", fileName);
        // return -1;
        // }
        // fclose(file);
        // int *array;
        // array=readFile(fileName, 10000, 5);   // call of the function
        // int guess=get_int("give me a number in between ");
        // int indx = linearSearch(array, guess, SIZE2);//call linear search
        // printf("the index is %i \n", indx);
        // int *sorted = selectSort(array);//call selectionsort function
        // printArray(sorted, SIZE2);//print array function
    }
int *readFile(string fileName, int size, int size2 )
    {

    FILE* file=(fopen(fileName, "r"));

    char line[size2]; //how many characers per line
    char options[size][size2];//array to put all the numbers from the file

    int  static numbers[size];  // file to be returned

    for (int i=0; i <size; i++)
    {
        fscanf(file, "%s", options[i]);
        // printf("%s \n", options[i]);
        numbers[i]= atoi(options[i]);
    }
    fclose(file);
   return numbers;
}
int linearSearch(int array[],int guess,int size )
{
    for(int i=0; i < size; i++)
    {
        if (array[i]== guess)
        {
            return i;
        }
    }
    return -1;
}
