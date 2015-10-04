#ifndef DL_LOADER
#define DL_LOADER

#include <string>

enum DL_Status {DL_SUCCESS, DL_WRONG_PATH, DL_UNKNOWN_FUNC};

class DL_Loader{

	void* handle;

public:
	DL_Status load_library(const std::string& path_name, const std::string& func_name, void*& func );

	void unload_library();

 	DL_Status get_sym(const std::string& func_name, void*& func);
};

#endif

