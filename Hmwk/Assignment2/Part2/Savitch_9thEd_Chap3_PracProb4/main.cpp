/* 
 * File:   main.cpp
 * Author: Tati
 * Created on January 14, 2015, 11:49 PM
 * 
 * Homework:
 * Horoscope Signs of the same element are most compatible. There are 4 
 * elements in astrology, and 3 Signs in each: 
 * - Fire  (Aries, Leo, Sagittarius), 
 * - eArTH (Taurus, Virgo, Capricorn), 
 * - Air   (gemini, Libra, Aquarius), 
 * - WATer (Cancer, Scorpio, Pisces).
 * 
 * According to some astrologers, you are most comfortable with your own 
 * sign and the other two signs in your element. For example, Aries would be 
 * most comfortable with other Aries and the two other Fire signs, Leo and 
 * Sagittarius.
 * 
 * Modify your program from Practice Program 3 to also display the name of 
 * the signs that will be compatible for the birthday.
 */

#include <iostream>
using namespace std;

short month, // the month entered by user
      day;   // the day entered by user

void getMonth()
{
    // continues until input is correct
    while (true)
    {
        // Get month from user
        cout << "Month of Birth: ";
        cin  >> month;
        
        // check if month exists
        if (month < 1 || month > 12)
        {
            cout << "Month does not exist" << endl;
            continue;
        }
        else
            break;
    }
}

void getDay()
{
    while (true)
    {
        // Get day from user
        cout << "Day of Birth: ";
        cin  >> day;
    
        // Check for correct day per month
        switch (month)
        {
            case 1: 
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else
                    break;
            }
            case 2:
            {
                if (day < 1 || day > 29)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 3:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 4:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 5:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 6:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 7:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 8:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 9:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 10:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 11:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 12:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            default:
                break;
        }
        break;
    }
}

void getBirthday()
{
    getMonth();
    getDay();
}

short calcAdj(string s, short n)
{
    string sign; // user's sign
    short adj; // check if day of birth is only 
               // one or two days away from an adjacent sign
    adj  = n - day;
    if (adj == 2 || adj == 1)
    {
        cout << "Your birthday is on a cusp!" << endl;
        cout << s << ": You will be lucky today."  << endl;
    }
    return adj;
}

string getSign()
{
    string sign; // user's sign

    // Get user's horoscope sign
    switch (month)
    {
        case 1:
        {
            if (day <= 19)
            {
                sign = "Capricorn";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 19);
            }
            if (day >= 20)
            {
                sign = "Aquarius";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 20);
            }
            break;
        }       
        case 2:
        {
            if (day <= 18)
            {
                sign = "Aquarius";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 18);
            }
            if (day >= 19)
            {
                sign = "Pisces";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 19);
            }
            break;
        }
        case 3:
        {
            if (day <= 20)
            {
                sign = "Aries";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 20);
            }
            if (day >= 21)
            {
                sign = "Pisces";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 21);
            }
            break;
        }
        case 4:
        {
            if (day <= 19)
            {
                sign = "Aries";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 19);
            }
            if (day >= 20)
            {
                sign = "Taurus";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 20);
            }
            break;
        }
        case 5:
        {
            if (day <= 20)
            {
                sign = "Taurus";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 20);
            }
            if (day >= 21)
            {
                sign = "Gemini";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 21);
            }
            break;
        }
        case 6:
        {
            if (day <= 21)
            {
                sign = "Gemini";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 21);
            }
            if (day >= 22)
            {
                sign = "Cancer";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            break;
        }
        case 7:
        {
            if (day <= 22)
            {
                sign = "Cancer";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            if (day >= 23)
            {
                sign = "Leo";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 23);
            }
            break;
        }
        case 8:
        {
            if (day <= 22)
            {
                sign = "Leo";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            if (day >= 23)
            {
                sign = "Virgo";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 23);
            }
            break;
        }
        case 9:
        {
            if (day <= 22)
            {
                sign = "Virgo";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            if (day >= 23)
            {
                sign = "Libra";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 23);
            }
            break;
        }
        case 10:
        {
            if (day <= 22)
            {
                sign = "Libra";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            if (day >= 23)
            {
                sign = "Scorpio";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 23);
            }
            break;
        }
        case 11:
        {
            if (day <= 21)
            {
                sign = "Scorpio";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 21);
            }
            if (day >= 22)
            {
                sign = "Sagittarius";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            break;
        }
        case 12:
        {
            if (day <= 21)
            {
                sign = "Sagittarius";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 21);
            }
            if (day >= 22)
            {
                sign = "Capricorn";
                cout << "Your sign is " << sign << endl;
                calcAdj(sign, 22);
            }
            break;
        }      
    }
    return sign;
}

void getCompatibleSigns(string sign)
{
    // FIRE
    if (sign == "Aries" 
            || sign == "Leo" 
                || sign == "Sagittarius")
    {
        cout << "Signs compatible with yours are:"<< endl;
        cout << "Aries, Leo, Sagittarius";
    }
    // EARTH
    else if (sign == "Taurus"
            || sign == "Virgo"
                || sign == "Capricorn")
    {
        cout << "Signs compatible with yours are:"<< endl;
        cout << "Taurus, Virgo, Capricorn";
    }
    // AIR
    else if (sign == "Gemini" 
            || sign == "Libra" 
                || sign == "Aquarius")
    {
        cout << "Signs compatible with yours are:"<< endl;
        cout << "Gemini, Libra, Aquarius";
    }
    // WATER
    else if (sign == "Cancer" || sign == "Scorpio")
    {
        cout << "Signs compatible with yours are:"<< endl;
        cout << "Cancer, Scorpio, Pisces";
    }
    else
    {
        cout << "Signs compatible with yours are:"<< endl;
        cout << "Cancer, Scorpio, Pisces";
    }
    cout << endl;
}

bool repeat()
{
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? ";
    cin  >> input;
    
    while (true)
    {
        // Check if input is valid
        if (input == "yes")
            return true;
        else if (input == "no")
            return false;
        else
        {
            cout << "What was that? yes or no? ";
            cin  >> input;
        } 
    }  
}

int main(int argc, char** argv) 
{
    while (true)
    {
        // gets the user's birth day and 
        // checks if month and day are correct
        getBirthday();
        cout << endl;
        
        // Get user's sign and horoscope
        string sign = getSign();
        cout << endl;
        // Get user's compatible signs
        getCompatibleSigns(sign);
        cout << endl;
        
        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
        {
            cout << endl;
            continue;
        }
        else
            break; 
    }
  
    return 0;
}

