/*! **************************
*
* @file: DirectionManager.c
* @author(s): Daniela Becerra, Jes�s Mart�n Barroso
*
//Includes functions to set the direction for rotating the stepper motor
************************** */

/*********************				   Includes					**********************/
#include "GPIO.h"
#include "DirectionManager.h"
#include "MotorStringManager.h"
#include "types.h"

/*********************				   Defines					**********************/

bool direction;

/*********************				   Exported Functions					**********************/
void DirectionManager_Init(void)
{
	  direction = CW;
}

//-------------------------------------------------------------------------------------------------
void DirectionManager_Move(void)
{
  if(direction == CW)
  {
    MotorStringManager_RotateClockwise();
  }
  else
  {
    MotorStringManager_RotateCounterClockwise();
  }
}

void DirectionManager_setDirection(bool dir)
{
	direction = dir;
}

bool DirectionManager_getDirection(void)
{
	return direction;
}
