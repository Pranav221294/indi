
#ifndef __HourMeter_H
#define __HourMeter_H

#include "CustomTypedef.h"
#include "r_cg_userdefine.h"


#define MAX_ENGINE_HOUR_VALUE			999999u			/* Max hour data auto recycle to zero */
#define ONE_MINUTE_SECONDS				60u				/* 1 minutes */
#define SIX_MINUTE						6u				/* 6 minutes */
#define ONE_SECOND_COUNTER				3600u			/* 1 second */


typedef struct
{	
	u32		u32FreqPulseCount;
	u8		u8HrMtrSeconds;
	u8		u8EngineHoursMinutes;
	u32		u32EngineHours;							/* Prepare clock data for display 99999 */
	bool 	bHourMeterEnable : 1;
	bool	bUpdateFreqPulseSignal : 1;				/* Set when 1 sec. change */
	bool	bUpdateOneMinuteHourMtr : 1;			/* Set when 1 minute change */
	bool	bUpdateTotalEngineHourMtr : 1;			/* Set when 6 minutes change */

} HOUR_DATA_TYPE;


extern HOUR_DATA_TYPE sHourMeter;


/// @addtogroup HOUR_METER_LIBRARY
/// @{
/// @defgroup HourMeterLib  functions used 
//// 
///   
/// @addtogroup HourMeterLib
/// @{
void _vAddStartUpTime							(void);
void vStart_Hour_Meter							(void);
void UpdateHourMeter							(void);
bool bGetHourMeterEnableStatus					(void);
void vSetHourMeterEnableStatus					(bool Status);
void vSetHoursSecondValue						(u8);
u8 u8GetHoursSecondValue						(void);
void vSetEngineHoursMinutes						(u8 value);	
u8 u8GetEngineHoursMinutes						(void);	
void vSetTotalEngineHoursValue					(u32);
u32 u32GetTotalEngineHours						(void);
void vSetTotalEngineHoursUpdateStatus			(bool status);
bool bGetTotalEngineHoursUpdateStatus			(void);
void vSetHoursSecondsUpdateStatus				(bool status);
bool bGetHoursSecondsUpdateStatus				(void);
void vSetOneMinuteUpdateStatus					(bool status);
bool bGetOneMinuteUpdateStatus					(void);
void vSetFreqPulseUpdateStd						(bool status);
bool bGetFreqPulseUpdateStd						(void);
/// @} // endgroup HourMeterLib

/// @} // endgroup HOUR_METER_LIBRARY


#endif





