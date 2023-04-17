#include "pch.h"
#include <ogr_api.h>
#include <ogr_core.h>
#include <ogr_feature.h>
#include <ogrsf_frmts.h>
#include <gdal_priv.h>

#include "osgeo_net_wrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections;

namespace osgeonetwrapper {
	OGR_DS_Worker_test::OGR_DS_Worker_test(String^ file_path, String^ provider)
	{
		OGRRegisterAll();

		auto driver_name = (char*)(void*)Marshal::StringToHGlobalAnsi(provider);
		auto file_path_converted = (char*)(void*)Marshal::StringToHGlobalAnsi(file_path);

		GDALDriver* ogr_driver = GetGDALDriverManager()->GetDriverByName(driver_name);
		GDALDataset* ds = NULL;
		unsigned int openFlags = GA_ReadOnly | GDAL_OF_VECTOR;
		ds = static_cast<GDALDataset*>(GDALOpenEx(file_path_converted, openFlags, NULL, NULL, NULL));
		if (ds == nullptr)
		{
			//make an exception
		}
		else {
			int layers_count = ds->GetLayerCount();
			this->layer_names = gcnew array<String^>(layers_count);
			for (int Layer_counter = 0; Layer_counter < layers_count; Layer_counter++)
			{
				OGRLayer* layer = ds->GetLayer(Layer_counter);
				this->layer_names[Layer_counter] = gcnew String(layer->GetName());
			}
		}
		
	}
}

