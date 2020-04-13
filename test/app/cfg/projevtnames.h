/** @file
 *	@brief	Project-specific event enumerations for simulated events.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Jan 20, 2018
 *	@author kbecker
 */

#ifndef UT_PROJEVTNAMES_H_
#define UT_PROJEVTNAMES_H_

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================
#define UT_PROJEVTNAMES_H__REVSTRING "$Revision: 0123 $"

/** Project-specific list of events.
 * 	This list must be contained inside the enumeration; the name of the enumeration tag is
 * 	significant, and it is highly recommended the 1st enum (value of 0) should be reserved for No
 * 	Event.
 *
 * 	Note that while an event is tightly coupled to an event handler in the vast majority of cases,
 * 	still, for maximum flexibility and ease of maintenance, we make this association in "member"
 * 	functions and in supplementary tables, rather than in foundational-level structs.
 */
enum eProjectEvents {
	evNoEvent,				/**< reserved value, used for initialization */
	evNotInit,              /**< By CWSW convention, 1 is always "component not initialized" */
	evAlreadyInit,			/**< BY CWSW convention, 2 is "already initialized" */
	evButtonPressed,		/**< debounced press event */
	evButtonCommit,
	evButtonReleased,
	evUpdateUi,
	evTerminateRequested,
	kNumProjectEvents
};


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================


extern void EventHandler__evNotInit				(tEventPayload EventData);
extern void EventHandler__evTerminateRequested	(tEventPayload EventData);
extern void EventHandler__evButtonCommit 		(tEventPayload EventData);
extern void EventHandler__evButtonPressed		(tEventPayload EventData);
extern void EventHandler__evButtonReleased		(tEventPayload EventData);

#ifdef	__cplusplus
}
#endif

#endif /* UT_PROJEVTNAMES_H_ */
