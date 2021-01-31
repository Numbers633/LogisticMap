#include <iostream>
#include "Source.h"

using namespace std;

int main()
{
    //Initialize input values
    double rValue = 0;
    double xValue = 0;
    int numCycles = 2;
    bool isReady = true;

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

            cycleLength1++;
            cycleLength++;
            cycleLength2++;

            if (i == numPreIterations && numSearches == 0)
            {
                repeatValue = floor(xValue * searchQuality);
                numSearches++;
                cycleLength1 = 1;
            }
            else if (numSearches > 0)
            {
                if (xValue = repeatValue)
                {
                    cycleFound = true;

                    currentXValue = floor(xValue * searchQuality);

                    cycleLength = cycleLength1 + 1;

                    if (cycleLength1 != cycleLength)
                    {
                        cycleLength1 = cycleLength;
                    }

                    cout << endl << "Cycle found.  Length: " << cycleLength << "." << endl;

                    break;
                }

                
                cycleLength = cycleLength1;
            }

            //Bugfix: The code cannot stop
            numPreIterations = numPreIterations2;
            i = j;

            // Iterate the equation rx(1-x)
            double oldXValue = xValue;
            xValue = rValue * oldXValue * (1 - oldXValue);
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