#include "xmulti_filter.h"

XMulti_filter_Config XMulti_filter_ConfigTable[] __attribute__ ((section (".drvcfg_sec"))) = {

	{
		"xlnx,multi-filter-1.0", /* compatible */
		0x40000000 /* reg */
	},
	 {
		 NULL
	}
};