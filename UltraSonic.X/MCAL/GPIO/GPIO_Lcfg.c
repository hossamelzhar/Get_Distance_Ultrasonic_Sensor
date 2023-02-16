#include "GPIO_Lcfg.h"

const PinStatus_type PinsStatus[TOTAL_PINS]=
{
	OUTPUT,   	/* Port A Pin 0 */
	OUTPUT,  	 /* Port A Pin 1 */
	OUTPUT,  	 /* Port A Pin 2 */
	OUTPUT,	   	/* Port A Pin 3 */
	OUTPUT,  	 /* Port A Pin 4 */
	OUTPUT,  	 /* Port A Pin 5 */
	FLOATING,   	/* Port A Pin 6 */
	FLOATING,  	 /* Port A Pin 7 */
	FLOATING,  	 /* Port B Pin 0   / */
	FLOATING,  	 /* Port B Pin 1   /*/
	FLOATING,		 /* Port B Pin 2 / INT2*/
	FLOATING,		 /* Port B Pin 3   /*/
	FLOATING,		 /* Port B Pin 4 */
	FLOATING,		 /* Port B Pin 5 */
	FLOATING,		 /* Port B Pin 6 */
	FLOATING,		 /* Port B Pin 7 */
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	FLOATING,		 /* Port C Pin 4 */
	FLOATING,		 /* Port C Pin 5 */
	FLOATING,		 /* Port C Pin 6 */
	FLOATING,		 /* Port C Pin 7 */
	FLOATING,		 /* Port D Pin 0 */
	FLOATING,		 /* Port D Pin 1 */
	FLOATING,      /* Port D Pin 2 / INT0 */
	FLOATING,    /* Port D Pin 3 / INT1 */
	OUTPUT,		 /* Port D Pin 4 */
	OUTPUT,		 /* Port D Pin 5 */
	INPUT,		 /* Port D Pin 6 /   ICP*/
	FLOATING		 /* Port D Pin 7 */
};
