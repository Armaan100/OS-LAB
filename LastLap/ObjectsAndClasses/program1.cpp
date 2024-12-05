#include<iostream>
using namespace std;

/*
Write the class definition for a Date class that contains three private integer data members:
month, day, and year. Create a static member to hold a slash. Create two public member
functions, setDate() and showDate(). You will use the static slash in the showDate() function.
The setDate()function accepts three integer arguments and passes them on to three private
functions, setMonth(), setDay(), and setYear(). If a month is greater than 12, then set it to 12.
If a day is greater than 31, then set it to 31. Write a main()function that instantiates several
objects of the Date class and tests the member functions.
*/

class Date{
    private:
    int day, month, year;

    static char slash;

    void setMonth(int m){
        month = (m>12)?12:(m<1?1:m);
    }

    bool isLeapYear(int y) const {
        if(y%100 == 0 && y%400 == 0)
            return true;
        if(y%4 == 0)
            return true;
        return false;
    }

    //getMaxDays
    int getMaxDaysInMonth(int m, int y) const{
        switch(m){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;

            case 4: case 6: case 9: case 11:
            return 30;

            case 2:
                return isLeapYear(y) ? 29: 28;
            
            default:
                return 31;
        }
    }

    //set day
    void setDay(int d){
        int maxDays = getMaxDaysInMonth(month, year);

        day = (d>maxDays)? maxDays: (d<1? 1: d);
    }

    //set year
    void setYear(int y){
        year = y;
    }

    public:
    //setDate
    void setDate(int m, int d, int y){
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    void showDate() const {
        cout << month << slash << day << slash << year << endl;
    }

    //increase day
    void increaseDay(){
        int maxDays = getMaxDaysInMonth(day, month);
        
        day++;

        if(day>maxDays){
            month++;
            day = 1;
        }

        if(month>12){
            month = 1;
            year++;
        }
    }
};


char Date::slash = '/';

int main() {
 // Test the Date class
 Date date1, date2, date3, date4, date5;
 // Set and display dates
 date1.setDate(2, 29, 2024); // Leap year
 date1.showDate(); // Expected: 2/29/2024
 date2.setDate(2, 29, 2023); // Non-leap year
 date2.showDate(); // Expected: 2/28/2023
 date3.setDate(4, 31, 2023); // Invalid day for April
 date3.showDate(); // Expected: 4/30/2023
 date4.setDate(12, 15, 2100); // Valid date
 date4.showDate(); // Expected: 12/15/2100
 
 date5.setDate(11, 30, 2024);
 date5.increaseDay();
 date5.showDate();
 return 0;
}