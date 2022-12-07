/*Jesseca Wirtz - IT-FP2240 - Part 1
 * 5/20/2020
 */

 //include appropriate headers and call the struct
 #include <stdio.h>
 #include <string.h>
 #include "date.h"

 //prototype of the custom function
 struct date addSeven(struct date originalDate);

 main()
 {
     //declare two sets of numbers to use struct date
    struct date originalDate, newDate;

    //prompt to enter the date
    printf("Enter a date (mm/dd/yyyy): ");
    scanf(" %d/%d/%d", &originalDate.month, &originalDate.day,
          &originalDate.year);

    //calling the function
    newDate = addSeven(originalDate);

    //printing the original date
    printf("\n\nThe original date was: %d/%d/%d.", originalDate.month,
           originalDate.day, originalDate.year);
    //printing the new date
    printf("\nThe new date is: %d/%d/%d.\n", newDate.month, newDate.day,
           newDate.year);

    return 0;
 }

 /*************************************************************************/
 //the custom function used to add 7 days to the date
 struct date addSeven(struct date originalDate)
 {
     //adds 7 to the day
     originalDate.day += 7;

     //If the month is one of the numbers entered
     if ((originalDate.month == 1 || //January
          originalDate.month == 3 || //March
          originalDate.month == 5 || //May
          originalDate.month == 7 || //July
          originalDate.month == 8 || //August
          originalDate.month == 10 || //October
          originalDate.month == 12) //December
         //and the day is greater than 31
         && originalDate.day > 31)
     {
         //then the day subtracts 31 to get the new date
         originalDate.day -= 31;
         //and the month adds one to it
         originalDate.month +=1;
     }
     //otherwise if the month is one of these numbers entered
     else if ((originalDate.month == 4 || //April
               originalDate.month == 6 || //June
               originalDate.month == 9 || //September
               originalDate.month == 11) //November
              //and the day is more than 30
              && originalDate.day > 30)
     {
         //then the day subtracts 30 to get the new day
         originalDate.day -= 30;
         //and the month adds 1 to get the new month
         originalDate.month += 1;
     }
     else
     {
         //if the year is divisible by 4, then it is a leap year
         //if it is a leap year and the day is more than 29
         if (originalDate.year % 4 == 0 && originalDate.day > 29)
         {
             //then the day subtracts 29 to get the new day
             originalDate.day -= 29;
             //and adds 1 to the month to get the new month
             originalDate.month += 1;
         }
         //if the year is not a leap year and the day is equal to
         //greater than 28
         else if (originalDate.day > 28)
         {
             //then the day subtracts 28 to get the new day
             originalDate.day -= 28;
             //and the month adds 1 to get the new month
             originalDate.month += 1;
         }
     }
     //If the month is equal to greater than 12
     if (originalDate.month > 12)
     {
         //then the month is equal to 1 and the year adds 1 to get
         //the new year
         originalDate.month = 1; originalDate.year += 1;
     }
     //it is returned to main
     return originalDate;
 }
