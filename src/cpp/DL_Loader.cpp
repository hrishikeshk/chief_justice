#include <dlfcn.h>
#include "DL_Loader.h"

DL_Status DL_Loader::load_library(const std::string& path_name, const std::string& func_name, void*& func ){

	handle = dlopen(path_name.c_str(), RTLD_LAZY);
	if(!handle){
		return DL_WRONG_PATH;
	}
	
	dlerror();

	func = dlsym(handle, func_name.c_str() );

	if(dlerror() != NULL){
		return DL_UNKNOWN_FUNC;
	}

	return DL_SUCCESS;
}

void DL_Loader::unload_library(){
	if(handle){
		dlclose(handle);
	}
}
