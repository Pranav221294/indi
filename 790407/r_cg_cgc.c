/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cgc.c
* Version      : Applilet3 for RL78/D1A V2.04.03.01 [15 Nov 2019]
* Device(s)    : R5F10CGB
* Tool-Chain   : CA78K0R
* Description  : This file implements device driver for CGC module.
* Creation Date: 16/5/2022
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    volatile uint8_t  temp_stab_set;
    volatile uint8_t  temp_stab_wait;

    OSMC = _10_CGC_RTC_CLK_FIL;
    /* Set fMX */
    CMC = _40_CGC_HISYS_OSC | _01_CGC_SYSOSC_OVER10M;
    OSTS = _07_CGC_OSCSTAB_SEL18;
    MSTOP = 0U;
    temp_stab_set = _FF_CGC_OSCSTAB_STA18;

    do
    {
        temp_stab_wait = OSTC;
        temp_stab_wait &= temp_stab_set;
    }
    while (temp_stab_wait != temp_stab_set);

    /* Set fMAIN */
    MCM0 = 1U;

    while (MCS == 0U)
    {
        ;
    }

    MDIV = _00_CGC_FMP_DIV_DEFAULT;
    /* Set fMP to clock through mode */
    SELPLL = 0U;
    /* Set fIH */
    HIOSTOP = 0U;
    /* Set RTC/Interval Timer clock source */
    RTCCL |= _01_CGC_RTC_FIL;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
