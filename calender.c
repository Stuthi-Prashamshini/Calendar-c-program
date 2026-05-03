#include<stdio.h>
#include<stdlib.h>

// Function to calculate the weekday of Jan 1st of given year
int get_1st_weekday(int year)
{
    int d;
    // Formula to calculate starting day (0 = Sunday, 1 = Monday, etc.)
    d= (((year-1)*365) + ((year-1)/4) - ((year-1)/100) +((year)/400)+1) %7;
    return d;
}

int main()
{
    system("color 3F");// Changes console color (Windows only)
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    printf("\n enter your desired year :");
    scanf("%d",&year);

    char *months[] ={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[] ={31,28,31,30,31,30,31,31,30,31,30,31};

    // Check for leap year and update February days
    if(year%4==0 && year%100!=0 || year%400==0)
    {
        monthDays[1] = 29;
    }

    // Get starting weekday of the year
    startingDay = get_1st_weekday(year);

    // Loop through all 12 months
    for(month=0;month<12;month++)
    {
        daysInMonth = monthDays[month];
        // Print month header
        printf("\n\n-------------------------%s-------------------------\n\n",months[month]);

        // Print days of the week
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print spaces before first day
        for(weekDay=0;weekDay<startingDay;weekDay++)
            printf("     ");

        // Print all days of the month
        for(day=1;day<=daysInMonth;day++)
        {
            printf("%5d",day);

            // Move to next line after Saturday
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }

            // Update starting day for next month
            startingDay= weekDay;
        }

    }

}
