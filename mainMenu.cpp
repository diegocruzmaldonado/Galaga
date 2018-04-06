#include <stdio.h>

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "Galaga" << endl;
    cout << "1. PLAY" << endl;
    cout << "2. CREDITS" << endl;
    
    char userChoice;
    cin.get(userChoice);
    
    while (userChoice != '1' && userChoice != '2')
    {
        cin >> userChoice;
    }
    if (userChoice == '1')
    {
        cout << setw (24) << "READY" << endl;
        
        cout << endl;
        
        cout << left << "playership" << setw(30) << right << "lives" << endl;
    }
    if (userChoice == '2')
    {
        cout << setw(16) << "Created By" << endl;
        cout << endl;
        cout << "Joy, Emily, Diego, & Rocio" << endl;
    }
    
    cout << endl;
    
    return 0;
}
