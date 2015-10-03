#define BOOST_TEST_MODULE test_suite1
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "Test_Utils.h"
#include "DL_Loader.h"

using namespace boost::unit_test;

void simple_dl_test(){

	DL_Loader dl_loader;
	std::string path = "libsimpledl.so";
	std::string func_name = "func_success";
	void* ret_func_ptr = NULL;

	bool (*func_success) (bool);

	BOOST_REQUIRE(dl_loader.load_library(path, func_name, ret_func_ptr) == DL_SUCCESS);
	BOOST_REQUIRE(ret_func_ptr != NULL);

	*(void**) (&func_success) = ret_func_ptr;

	BOOST_REQUIRE(func_success(true) == true);
	BOOST_REQUIRE(func_success(false) == false);
	
	dl_loader.unload_library();
}

BOOST_AUTO_TEST_SUITE ( test_suite1 )

BOOST_AUTO_TEST_CASE( dl_load_func_call ){

	std::cout << "Running Test # " << "1\n";
        simple_dl_test();
        std::cout << " ... done\n";

}

BOOST_AUTO_TEST_SUITE_END()

