#include <iostream>
#include "Source.h"

using namespace std;

int main()
{
    //Initialize input values
    double rValue = 0;
    double xValue = 0;
    int numPreIterations = 0;
    double maxCycleLength = 0;
    double searchQuality = 300;

    //Original input

    cout << "Logistic map finder" << endl;
    cout << "Used for generating cycles." << endl;
    
    while (true)
    {
        //Recieve user input
        cout << endl << endl << "R: ";
        cin >> rValue;
        cout << endl << "X: ";
        cin >> xValue;
        cout << endl << endl << endl << "Please enter the number of iterations to do before looking: ";
        cin >> numPreIterations;
        cout << "Please enter the maximum cycle length: ";
        cin >> maxCycleLength;
        cout << endl << "Search Quality: ";
        cin >> searchQuality;

        if (xValue > 1 || xValue < 0)
        {
            cout << "WARNING: X CANNOT BE LESS THAN 0 OR GREATER THAT 1!" << endl;
            continue;
        }

        // Initiallize
        double iMax = numPreIterations + maxCycleLength;
        int i = 0;
        double repeatValue = xValue;
        double numPreIterations2 = numPreIterations;
        bool cycleFound = false;
        int cycleLength = 0;
        int numSearches = 0;
        int cycleLength1 = 0;
        int cycleLength2 = cycleLength;
        double currentXValue = xValue;
        int j = i;

        for (i = 0; i < iMax; i++)
        {
            // Check for the cycle
            j = i;

            if (j == numPreIterations)
            {
                cycleFound = false;
                cycleLength = 0;
                repeatValue = xValue;
                cout << "Started searching" << endl;
            }
            else if (j > numPreIterations)
            {
                cycleFound = false;
                cycleLength++;

                cout << "Searching" << endl;

                if (xValue == repeatValue)
                {
                    std::cout << "Found the cycle.  Length: " << cycleLength << endl;
                    cycleFound = true;
                }
            }

            i = j;

            // Iterate the equation rx(1-x)
            double oldXValue = xValue;
            xValue = rValue * oldXValue * (1 - oldXValue);

            if (cycleFound == true)
            {
                break;
            }
        }

        // Determine if CycleFound = true

        if(cycleFound = false)
        {
            cout << endl << "Failed to find a cycle.  It is possible that it might actually be chaos or a bifurcation point.  Try adjusting R." << endl;
        }

        cout << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl;
    }

    return 0;
}