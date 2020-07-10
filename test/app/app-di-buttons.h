/** @file app-di-buttons.h
 *	@brief	One-sentence short description of file.
 *
 *	Description:
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jul 10, 2020
 *	Author: kevin
 */

#ifndef APP_APP_DI_BUTTONS_H_
#define APP_APP_DI_BUTTONS_H_

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------
#include "cwsw_evqueue_ex.h"

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


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

// ---- Discrete Functions -------------------------------------------------- {
extern uint16_t buttons__Init(void);

extern void AppButtonPress(tEvQ_Event ev, uint32_t extra);
extern void AppButtonCommit(tEvQ_Event ev, uint32_t extra);
extern void AppButtonStuck(tEvQ_Event ev, uint32_t extra);
extern void AppButtonUnstuck(tEvQ_Event ev, uint32_t extra);

// ---- /Discrete Functions ------------------------------------------------- }

// ---- Targets for Get/Set APIs -------------------------------------------- {
// ---- /Targets for Get/Set APIs ------------------------------------------- }


#ifdef	__cplusplus
}
#endif

#endif /* APP_APP_DI_BUTTONS_H_ */
