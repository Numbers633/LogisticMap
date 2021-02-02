#include <iostream>
#include "Source.h"

int main()
{
    //Initialize input values
    double rValue = 0;
    double xValue = 0;
    double xValue2 = 0;

    double numPreIterations = 0;
    double maxCycleLength = 0;
    double searchQuality = 300;

    //Original input

    std::cout << "Logistic map finder" << std::endl;
    std::cout << "Used for generating cycles." << std::endl;
    
    while (true)
    {
        //Recieve user input
        std::cout << std::endl << std::endl << "R: ";
        std::cin >> rValue;
        std::cout << std::endl << "X: ";
        std::cin >> xValue;
        std::cout << std::endl << std::endl << std::endl << "Please enter the number of iterations to do before looking: ";
        std::cin >> numPreIterations;
        std::cout << "Please enter the maximum cycle length: ";
        std::cin >> maxCycleLength;
        std::cout << std::endl << "Search Quality (resolution): ";
        std::cin >> searchQuality;

        // xValue2

        if (xValue > 0.5)
        {
            xValue2 = (1 - xValue) * 2;
        }
        else
        {
            xValue2 = (1 - xValue) * 0.5;
        }

        bool useXValue2 = true;

        if (xValue > 1 || xValue < 0)
        {
            // IERR 1
            //
            // xValue is not in the limits and will blow up.

            std::cout << "WARNING IERR1: X CANNOT BE LESS THAN 0 OR GREATER THAT 1!" << std::endl;

            continue;
        }
        else if (rValue > 4 || rValue < -2)
        {
            // IERR 2
            //
            // rValue is outside limits.  Please adjust R.

            std::cout << "FATAL ERROR IERR2: THE XVALUE BLEW UP TO INFINITY!!!  See error message below:" << std::endl;
            std::cout << "1: The description warned you that X cannot be in this range" << std::endl;
            
            if (rValue > 4)
            {
                std::cout << "2: The equation blew up to negative infinity." << std::endl;
            }
            else if (rValue < -2)
            {
                std::cout << "2: The equation blew up to infinity." << std::endl;
            }

            std::cout << "3: R = " << rValue << std::endl;

            continue;
        }
        else  if (xValue2 > 1 || xValue2 < 0)
        {
            // IERR3
            //
            // Warning: Internal variable xValue2 (to reduce noise) is outside limits.  The quality of the cycles is lower.

            std::cout << "WARNING IERR3: An internal X value is outside the limits.  See error message below:" << std::endl;
            std::cout << "1: xValue: " << xValue << std::endl;
            std::cout << "2: xValue2: " << xValue2 << std::endl;
            std::cout << "3: The program will be a little less reliable.  The search quality needs to be increased." << std::endl;

            useXValue2 = false;
        }

        // Initiallize
        double iMax = numPreIterations + maxCycleLength;
        int i = 0;
        double repeatValue = xValue;
        double repeatValue2 = xValue2;
        bool cycleFound = false;
        int cycleLength = 0;
        int numSearches = 0;
        double currentXValue = xValue;
        int j = i;

        for (i = 0; i < iMax; i++)
        {
            if (cycleFound == true)
            {
                break;
            }

            // Check for the cycle
            j = i;

            if (j == numPreIterations)
            {
                cycleFound = false;
                cycleLength = 0;
                repeatValue = xValue;

                if (useXValue2 == true)
                {
                    repeatValue2 = xValue2;
                }
            }
            else if (j > numPreIterations)
            {
                cycleFound = false;
                cycleLength++;

                if (xValue == repeatValue)
                {
                    if (useXValue2 == false || xValue2 == repeatValue2)
                    {
                        std::cout << "Found the cycle.  Length: " << cycleLength << std::endl;
                        cycleFound = true;
                    }
                }
            }

            i = j;

            // Iterate the equation rx(1-x)
            double oldXValue = xValue;
            double oldXValue2 = xValue2;
            xValue = rValue * oldXValue * (1 - oldXValue);
            xValue = rValue * oldXValue * (1 - oldXValue);
        }

        // Determine if CycleFound = true

        if(cycleFound == false)
        {
            std::cout << std::endl << "Failed to find a cycle.  It is possible that it might actually be chaos or a bifurcation point.  Try adjusting R." << std::endl;
        }

        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
    }

    return 0;
}