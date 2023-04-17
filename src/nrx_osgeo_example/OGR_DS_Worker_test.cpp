#include "pch.h"
#include "OGR_DS_Worker_test.h"



OGR_DS_Worker_test::OGR_DS_Worker_test(const char* file_path, const char* provider)
{
	OGRRegisterAll();

	GDALDriver* ogr_driver = GetGDALDriverManager()->GetDriverByName(provider);
	GDALDataset* ds = NULL;
	unsigned int openFlags = GA_ReadOnly | GDAL_OF_VECTOR;
	ds = static_cast<GDALDataset*>(GDALOpenEx(file_path, openFlags, NULL, NULL, NULL));
	if (ds == nullptr)
	{
		//make an exception
	}
	else {
		int layers_count = ds->GetLayerCount();
		for (int Layer_counter = 0; Layer_counter < layers_count; Layer_counter++)
		{
			OGRLayer* layer = ds->GetLayer(Layer_counter);

			CA2W ca2w(layer->GetName());
			std::wstring wide = ca2w;

			this->layer_names.push_back(wide);
		}
	}

}