#include <iostream>

// SRP : Single Responsibility Principle
class Date
{
    // Date could be wrong value
    int year;
    int month;
    int day;
    static int days[12]; // initial ... outside
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    // getter
    int get_year() const { return year; }
    int get_month() const { return month; }

    int get_day() const { return day; }
    void set_day(int d) { day = d; }
    
    // other useful member function 
    // => const member function
    Date after_days(int n) const
    {
   
        Date temp(year, month, day + n); //  wrong

        return temp;
    }

    int dayofweek() const
    {
        // 
        return 0;
    }
    static int dayofweek(int y, int m, int d) { return 0; }

}; 
int Date::days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int main()
{
    Date d1(2021, 10, 10);
    Date d2 = d1.after_days(100);

    // 2024/12/25  WHAT dayofweek?
    // Method 1. create object and call member function
    Date d3(2024, 12, 25);
    int n1 = d3.dayofweek();
    // Method 2. allow argument
    int n2 = Date::dayofweek(2024, 12, 25);

    // What is tomorrow?
    // => "Certain Date" is needed
    // => non-static member function
    // Date d4 = d1.tomorrow();
}