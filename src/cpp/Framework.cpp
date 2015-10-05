#include <iostream>
#include <string>
#include "DL_Loader.h"
#include "interfaces/DeveloperBase.h"
#include "Framework.h"

void Framework::test(const std::string& problem_id, const std::string& developer_id){

	DL_Loader dll;

	std::string lib_path = "../developers/";
	lib_path += problem_id;
	lib_path += "/";
	lib_path += developer_id;
	
	std::string solution_lib = "/libSolution.so";

	std::string func_name = "create";

	void* ret_func_ptr = NULL;

	DL_Status dls = dll.load_library(lib_path + solution_lib, func_name, ret_func_ptr);

	if(dls == DL_SUCCESS){
		DeveloperBase* (*create) ();
		*(void**) (&create) = ret_func_ptr;
		DeveloperBase* db = create();
		
	}
	else{
		std::cout << "Error loading Solution library\n";
		return;
	}

	dll.unload_library();
}
