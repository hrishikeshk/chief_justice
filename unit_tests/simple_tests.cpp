#define BOOST_TEST_MODULE test_suite1
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "Test_Utils.h"
#include "DL_Loader.h"
#include "interfaces/DeveloperBase.h"

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

void simple_dl_fail_test(){
	DL_Loader dl_loader;
	std::string path = "libwrongdl.so";
	std::string func_name = "func_success";
	void* ret_func_ptr = NULL;

	BOOST_REQUIRE(dl_loader.load_library(path, func_name, ret_func_ptr) == DL_WRONG_PATH);
}

void simple_dl_fail_test2(){
	DL_Loader dl_loader;
	std::string path = "libsimpledl.so";
	std::string func_name = "func_fail";
	void* ret_func_ptr = NULL;

	BOOST_REQUIRE(dl_loader.load_library(path, func_name, ret_func_ptr) == DL_UNKNOWN_FUNC);
}

void solution_dl_test(){

	DL_Loader dl_loader;
	std::string path = "libSolution.so";
	std::string func_name = "create";
	void* ret_func_ptr = NULL;

	DeveloperBase* (*create) ();
	void (*destroy) (DeveloperBase*);

	BOOST_REQUIRE(dl_loader.load_library(path, func_name, ret_func_ptr) == DL_SUCCESS);
	BOOST_REQUIRE(ret_func_ptr != NULL);

	*(void**) (&create) = ret_func_ptr;

	DeveloperBase* db = create();
	
	BOOST_REQUIRE(db->invoke(true) == true);
	BOOST_REQUIRE(db->invoke(false) == false);

	func_name = "destroy";
	void* des_func_ptr = NULL;
	BOOST_REQUIRE(dl_loader.get_sym(func_name, des_func_ptr) == DL_SUCCESS);

	*(void**) (&destroy) = des_func_ptr;

	destroy(db);

	dl_loader.unload_library();
}

BOOST_AUTO_TEST_SUITE ( test_suite1 )

BOOST_AUTO_TEST_CASE( dl_load_func_call ){
	std::cout << "Running Test # " << "1\n";
        simple_dl_test();
        std::cout << " ... done\n";
}

BOOST_AUTO_TEST_CASE( dl_load_fail1 ){
	std::cout << "Running Test # " << "2\n";
        simple_dl_fail_test();
        std::cout << " ... done\n";
}

BOOST_AUTO_TEST_CASE( dl_load_fail2 ){
	std::cout << "Running Test # " << "3\n";
        simple_dl_fail_test2();
        std::cout << " ... done\n";
}

BOOST_AUTO_TEST_CASE( solution_dl_func ){
	std::cout << "Running Test # " << "4\n";
        solution_dl_test();
        std::cout << " ... done\n";
}

BOOST_AUTO_TEST_SUITE_END()

