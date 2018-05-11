#include "dynamicbutton.h"

dynamicButton::dynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   /* Assigning a button number which will be further work with buttons
                         * */

}

dynamicButton::~dynamicButton()
{

}

/* Method to return the value of the button numbers
 * */
int dynamicButton::getID()
{
    return buttonID;
}

/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
int dynamicButton::ResID = 0;
