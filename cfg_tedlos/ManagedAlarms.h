/** @file
 *	@brief	Project-specific configuration to specify which alarms will be managed by TEDLOS.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Apr 14, 2020
 *	@author Kevin L. Becker
 */

#ifndef MANAGEDALARMS_H
#define MANAGEDALARMS_H

#ifdef	__cplusplus
extern "C" {
#endif

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_swtimer.h"

// ----	Module Headers --------------------------
#include "stoplite.h"				/* StopLite_tmr_SME */
#include "cwsw_bsp_buttons.h"		/* Btn_tmr_ButtonRead */


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

extern tCwswSwAlarm	Os_tmr_10ms;
extern tCwswSwAlarm	Os_tmr_1000ms;


/**	List of alarms managed by the OS timer tic task.
 *
 * 	All alarms listed here, must be of type `tCwswSwAlarm`.
 *	The order in which alarm names are listed here, is the order in which they will be processed.
 *	This allows a manner of assigning priority, by placing more important alarms higher in the list.
 *	PLEASE RESPECT RMS SCHEDULING (fastest repetition rate == highest priority).
 *	Single-shot alarms should (generally) be at the end of the list.
 *
 *	Reminder: This list is not a "closed" list, meaning that this list is not all-inclusive of all
 *	alarms to be found in the system. This list only identifies the alarms that are managed by the
 *	default timer tic callback.
 */
#define ListOfManagedAlarms	\
	/* **** DO NOT EDIT THIS DEFINITION ABOVE THIS LINE **** */	\
	  &Os_tmr_10ms			\
	, &Btn_tmr_ButtonRead	\
	, &StopLite_tmr_SME		\
	, &Os_tmr_1000ms		\
	/* **** DO NOT EDIT THIS DEFINITION BELOW THIS LINE **** */	\
	/* end of list */


#ifdef	__cplusplus
}
#endif

#endif /* MANAGEDALARMS_H */
