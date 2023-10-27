
#include "r_cg_macrodriver.h"
#include "customTypedef.h"
#include "r_cg_userdefine.h"
#include "InputSense.h"



#define IGN_PIN_SENSE_TIME          5u     /* Ignition ON/OFF time sense in ms */
#define HR_RESET_SENSE_TIME			1000u	/* He reset ON/OFF time sense in ms */




/*********************************************************************//**
 *
 * Get bGet Hour Reset Input Pins Status
 *
 *
 * @param      None    
 *
 * @return     Bool
 *************************************************************************/
bool bGetHourResetInputPinsStatus(void)
{
	static bool status = FALSE;
	static u16 InputOnTimeStamp = 0u;
	static u16 InputOffTimeStamp = 0u;			
	
	if(HOUR_RESET_INPUT_PIN == HIGH )
	{
		status = FALSE;
		InputOnTimeStamp = u16GetClockTicks();
	}
	else if(HOUR_RESET_INPUT_PIN == LOW )
	{
		if( u16GetClockTicks() - InputOnTimeStamp >= HR_RESET_SENSE_TIME)
		{
			status = TRUE;
		}
		else
		{
			/*NA*/
		}
		InputOffTimeStamp = u16GetClockTicks() ;
	}
	else
	{
		/*NA*/
	}
		
	return status;	
  
}






