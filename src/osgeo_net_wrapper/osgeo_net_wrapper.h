#pragma once

using namespace System;

namespace osgeonetwrapper {
	public ref class OGR_DS_Worker_test {
	public:
		array<String^>^ layer_names;
		OGR_DS_Worker_test(String^ file_path, String^ provider);
	};


}
