#pragma once
#include "pch.h"

class OGR_DS_Worker_test
{
public:
	OGR_DS_Worker_test(const char* file_path, const char* provider);
	std::vector<std::wstring> layer_names;
};

