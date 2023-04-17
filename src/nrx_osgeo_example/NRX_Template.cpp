//project
#include "pch.h"
#include "framework.h"
#include "NRX_Template.h"
#include "OGR_DS_Worker_test.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void ogr_test()
{
	const char* gj_path = "C:\\bicycles.geojson";
	OGR_DS_Worker_test* ogr_data = new OGR_DS_Worker_test(gj_path, "GeoJSON");
	for (auto layer_name : ogr_data->layer_names)
	{
		acutPrintf(layer_name.c_str());
	}
}
