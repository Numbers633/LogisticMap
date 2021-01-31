#include <iostream>
#include "Source.h"
#include <stdlib.h>

using namespace std;

int main()
{
    double rValue = 0;
    double xValue = 0;
    int numCycles = 2;
    bool isReady = true;

    //Original input

    cout << "Logistic map finder" << endl;
    cout << "Please input a starting value for R: ";
    cin >> rValue;
    cout << endl << "You input a value for R, now input a starting value for X: ";
    cin >> xValue;

    //Calculate

    if (xValue < 0 || xValue > 1)
    {
        xValue = 0.5;
        cout << "The input value for X is wrong.  X has been set to 0.5." << endl;

        bool isReady = false;
    }

    if (rValue > 4 || rValue < -2)
    {
        rValue = 3.822;
        cout << "R is outside of the limits.  It is now 3.889." << endl;

        bool isReady = false;
    }
    else if (rValue == 3)
    {
        cout << "3 is a bifurcation point and therfore the program will detect a false unstable cycle.  Choose a different value of R for the program to work: ";
        cin >> rValue;
    }

    if (isReady = false)
    {
        cout << "There are errors in the values.  The value is automatically set to the described values." << endl;
    }

    cout << endl << "The number of cycles to be found is needed.  Enter 0 to close this application." << endl;
    cout << "Please enter the number: ";
    cin >> numCycles;

    if (numCycles >= 0)
    {
        //
        // The cycles are now ready to be calculated.  First, the info will be output.
        // TODO: Iterate the equation rx(1-x) 4000 times to kill any initial values outside.
        //

        cout << "Calculating conditions." << endl;
        cout << "The R value is set to " << rValue << ".  The X value is " << xValue << "." << endl;;

        int i = 0;
        int numIterations = 0;
        int cycleLength = 0;
        int numPastCycles = 0;

        double original_Value = 0;
        double in2XValue = 0;
        bool cycleFound = false;

        for (i = 0, i < 4000, i++;;)
        {
            numIterations++;
            i++;

            if (numIterations == 10000)
            {
                double newXValue = xValue;

                in2XValue = xValue * 3000000;
                in2XValue = floor(in2XValue);


                original_Value = in2XValue;
            }
            else if (numIterations > 10000)
            {
                double newXValue = xValue;

                double inXValue = xValue * 3000000;
                inXValue = floor(inXValue);

                if (inXValue == original_Value)
                {
                    cycleLength = numIterations - 10000;

                    if (cycleFound == false)
                    {
                        cout << "When R = " << rValue << ", X is " << cycleLength << "-periodic." << endl;
                    }

                    cycleFound = true;
                }

                xValue = newXValue;
            }

            if (cycleFound == false)
            {
                double oldXValue = xValue;
                xValue = oldXValue * rValue * (1 - oldXValue);
                cout << numIterations << ": " << xValue << endl;
            }
        }

        cout << "A cycle has been found." << endl;
        return 0;
    }
    else if (numCycles = -1)
    {
        int numPixelsY = 60;

        cout << endl << "You have entered -1 for the number of cycles, so enter the pixels: ";
        cin >> numPixelsY;

        int i = 0;
        double pixelNumD = 0;
        double pixelNum = 0;

        for (i = 0, i < 4000, i++;;)
        {
            double oldXValue = xValue;
            xValue = oldXValue * rValue * (1 - oldXValue);
            
            pixelNumD = numPixelsY * xValue;
            pixelNum = floor(pixelNumD);
            cout << pixelNum << endl;
        }
    }
    else if (numCycles = -2)
    {
        double rValueMinimum = -2;
        double rValueMaximum = 4;

        cout << endl << "Random R value.  Please enter the minimum value: ";
        cin >> rValueMinimum;
        cout << "Random R value.  Please enter the maximum value: ";
        cin >> rValueMaximum;

        double rValue0 = rand();
        double rValueRange = rValueMaximum - rValueMinimum;
        double rValue1 = rValue0 * rValueRange;
        rValue = rValue1 + rValueMinimum;

        cout << endl << "The chosen R value is " << rValue << endl;

        int i = 0;

        for (i = 0, i < 4000, i++;;)
        {
            double oldXValue = xValue;
            xValue = oldXValue * rValue * (1 - oldXValue);
            cout << xValue << endl;
        }
    }
    else
    {
        cout << "You have enter 0 for the number of cycles.  The application will close soon." << endl;
    }
}