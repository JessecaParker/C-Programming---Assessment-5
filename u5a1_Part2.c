/*Jesseca Wirtz - IT-FP2240 - Part 2
 * 5/20/2020
 */

 //include appropriate headers including the custom struct created
#include <stdio.h>
#include <stdlib.h>
#include "studentGrade.h"

main()
{
    //declare the variables to be used
    int ctr, outer, inner, didSwap;
    int tempID, tempGrade;
    int arraySize = 0;
    char ans;
    //declare the arrays and save them to the struct
    struct studentGrade idNumber[100];
    struct studentGrade grades[100];


    //loop through to allow the user to enter the number of student's
    //and grades until they have entered all that they need.
    //The ID's and grades are saved to arrays that are saved to the
    //struct created for this program
    for (ctr = 0; ctr < 100; ctr++)
    {
        //to know the amount of students entered
        arraySize++;
        //prompt for ID number and save it to struct
        printf("Enter Student ID Number: ");
        scanf(" %d", &idNumber[ctr].studentID);

        //prompt for grade and save it to struct
        printf("What was their grade? ");
        scanf(" %d", &grades[ctr].grade);

        //ask if user has more grades to enter
        printf("Enter another grade (Y/N)?");
        scanf(" %c", &ans);

        printf("\n\n");

        //if the user does not have more grades to enter, the loop breaks
        if (ans == 'n' || ans == 'N')
        {
            break;
        }
    }

    //sorts the arrays by student ID number, the grades stay with
    //the student ID number they were entered with
    for (outer = 0; outer <= arraySize; outer++)
    {
        didSwap = 0; //Becomes 1 (true) if list is not yet ordered
        for (inner = outer; inner < arraySize; inner++)
        {
            //if the current ID number is less than the next one
            //then the numbers are switched. Need to use a temp
            //number to hold the number in place, otherwise the
            //number would be wiped out
            if (idNumber[inner].studentID < idNumber[outer].studentID)
            {
                tempID = idNumber[inner].studentID;
                tempGrade = grades[inner].grade;
                idNumber[inner].studentID = idNumber[outer].studentID;
                grades[inner].grade = grades[outer].grade;
                idNumber[outer].studentID = tempID;
                grades[outer].grade = tempGrade;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }

    //outputs the student ID numbers and their grades
    printf("\n\nHere are the Student ID Numbers and their grades: ");
    for (ctr = 0; ctr < arraySize; ctr++)
    {
        printf("\n#%d's grade is %d%%.",
               idNumber[ctr].studentID, grades[ctr].grade);
    }
    /*I had return 0 here but was getting an error and I am not sure
    why. I changed 0 to 1 thinking maybe that would help, but it didn't.
    I'm placing it here to show that I know it goes here, but the code would
    not run with the return 0 here.*/
    //return 0;
}
