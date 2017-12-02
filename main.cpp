 /*
    Glenn Ahearne
    06/11/17
    Exercise 7
    Coordinate Conversions
  */

    /**Preprocessive Directives*/
#include <iostream>
#include <cmath>


using namespace std;

    /**main function*/
int main()
{
        /**Character userChoice*/
    char userChoice;

        /**local functions*/
    void cart2pol(void);
    void pol2cart(void);

    char menu(void);

        /**Read out title*/
    cout<< "\n\t\tCoordinate Conversion\n\n";


        /**Do while loop to prompt user to pick a case from switch case statement and call the function declared within it*/
    do

    {
        userChoice = menu();


        switch (userChoice)

        {

            case 'p': cart2pol();
                      break;

            case 'c': pol2cart();
                      break;

            case 'q': cout << "\n\n\t\t Goodbye!"<< "\n" <<endl;
                      break;

            default : cout<<"\n\n\t\t Please Try Again!\t\t"<<endl;
                      break;


        }

    }
        /**Keep looping while userchoice is not equal to Q*/
    while (userChoice != 'q');

    return 0;

}

    /**Cartesian to polar function*/
void cart2pol(void)
{

    /**Variable Declarations*/
    double x, y, mag, angle;
    double *mag_ptr, *angle_ptr;

    /**Cartesian to polar calculation function declared locally*/
    void cart2polCalculation(double, double, double *, double *);

    /**assigning Pointer to address of variable*/
    mag_ptr = &mag;
    angle_ptr = &angle;

    /**Prompt user to read in values for x and y*/
    cout <<" \n\nEnter Cartesian Value for X: ";
    cin >> x;
    cout <<" \n\nEnter Cartesian Value for Y: ";
    cin >> y;

    /**Passing values to cartesian to polar function*/
    cart2polCalculation(x, y, mag_ptr, angle_ptr);

    /**Read out Polar form*/
    cout <<"\n\t\t Result in Polar Form is : " << mag << " < " << angle << "\n\n"<< endl;

    return;
}

    /**Cartesian to polar calculation function*/
void cart2polCalculation(double xVal, double yVal, double *mptr, double *aptr)
{
        /**carrying out calculation for magnitude and angle*/
    *mptr = sqrt(pow(xVal,2) + pow(yVal,2));

    *aptr = atan2(yVal, xVal) / M_PI * 180.0;
}

    /**polar to cartesian function*/
void pol2cart(void)
{
        /**variable declarations*/
    double x, y, r, ang;
    double *x_ptr, *y_ptr;

        /**polar to cartesian calculation function declared locally*/
    void pol2cartCalculation(double, double, double *, double *);

        /**assigning pointer to address of x and y*/
    x_ptr = &x;
    y_ptr = &y;

        /**prompting user to enter values for Magnitude and Angle*/
    cout <<"\n\nEnter Value for Magnitude : ";
    cin >> r;
    cout <<"\n\nEnter Value for Angle : ";
    cin >> ang;

        /**Calling polar to cartesian function and passing variables*/
    pol2cartCalculation(r, ang, x_ptr, y_ptr);

        /**Read out result in cartesian form to user*/
    cout <<"\n\t\t Result in Cartesian Form is : " << x << " + " << y << "j" << "\n\n"<< endl;

    return;
}

    /**Polar to Cartesian calculation function*/
void pol2cartCalculation(double r,double ang, double *x_ptr, double *y_ptr)
{
        /**calculating value for x and y pointers*/
   *x_ptr = r * cos(ang / 180.0 * M_PI);

   *y_ptr = r * sin(ang / 180.0 * M_PI);
}

    /**Choice menu for user to choose which calculation they want to do*/
char menu(void)
{
        /**variable declaration of type char*/
    char choice;

            /**read out options to users*/
    cout<<  "\t\tChoose One of the Following Options:\n\n"<<
    "\t\tPress p for Cartesian to Polar Conversion\n"<<
    "\t\tPress c for Polar to Cartesian Conversion\n"<<
    "\t\tPress q to Quit!"<< endl;

            /**read out result to user*/
    cout<<  "\n\t\tValue Entered is : ";

            /**read in choice of type character*/
    cin >>  choice;

    return choice;

}
