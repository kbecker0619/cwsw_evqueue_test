/** @file cwsw_swtimer.h
 *
 *	Description:
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Feb 21, 2020
 *	Author: KBECKE35
 */

#ifndef CWSW_SWTIMER_H
#define CWSW_SWTIMER_H

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_lib.h"		/* kErr_Lib_NoError */
#include "cwsw_clock.h"		/* tCwswClockTics */

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

enum eErrorCodes_SwTmr {
	kErr_SwTmr_NoError = kErr_Lib_NoError,
	kErr_SwTmr_NotInitialized,
	kErr_SwTmr_BadParm,			//!< Bad Parameter; e.g., NULL pointer-to-event.
};

/**	Enabled/disabled states for CWSW SW Timers.
 */
enum eSwTimerState {
	kSwTimerDisabled,
	kSwTimerEnabled,
	kSwTimerPaused
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

typedef enum eErrorCodes_SwTmr tErrorCodes_SwTmr;

/**	Enabled/disabled states for CWSW SW Timers.
 */
typedef enum eSwTimerState tSwTimerState;

/**	CWSW SW Timer.
 */
typedef struct sSwTimer {
	tCwswClockTics		tm;			/**< Current # of tics left before expiration.
									 * @note We want this to be the 1st field, on the thinking that
									 * this will result in correct operation if an object of this
									 * type is passed to the clock services APIs.
									 */
	tCwswClockTics		reloadtm;	/**< For repetitive alarms, the # of tics to rearm the timer with. */
	ptEvQ_QueueCtrlEx	pEvQX;		/**< Event Queue for this timer. */
	int16_t				evid;		/**< Event, if any, to post when timer expires.
									 * This is a generic container so any event class can be used; 0 for no event.
									 */
	tSwTimerState		tmrstate;	/**< Current timer state. */
} tCwswSwAlarm, *ptCwswSwAlarm;


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

// ---- Discrete Functions -------------------------------------------------- {

extern tErrorCodes_SwTmr Cwsw_SwAlarm__Init(
	// timer-related parameters
	ptCwswSwAlarm		pAlarm,		//!< SW Alarm reference.
	tCwswClockTics		armtm, 		//!< Initial timeout value.
	tCwswClockTics		tm_rearm, 	//!< Rearm / reload time
	// timer-maturation parameters
	ptEvQ_QueueCtrlEx	pEvqCtrl,	//!< Which event queue do we post an event to?
	int16_t 			evid);
extern void Cwsw_SwAlarm__SetState(ptCwswSwAlarm pAlarm, tSwTimerState newstate);
extern void Cwsw_SwAlarm__ManageTimer(ptCwswSwAlarm pAlarm);

// ---- /Discrete Functions ------------------------------------------------- }

// ---- Targets for Get/Set APIs -------------------------------------------- {

/** "Chapter Designator" for Get/Set API.
 *	Intentionally unused symbol, designed to get you to the correct starting
 *	point, when you want to find macros for the Get/Set API; simply highlight
 *	the Module argument in your IDE (e.g, Eclipse, NetBeans, etc.), and select
 *	Go To Definition.
 */
enum { Cwsw_SwAlarm };	/* Component ID for Event Queue */


// ---- /Targets for Get/Set APIs ------------------------------------------- }


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_SWTIMER_H */
