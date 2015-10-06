#include <iostream>
#include <string.h>
#include "Framework.h"
#include "Consts.h"
#include <string>

int main(int argc, char* argv[]){

	/*
 *	read problem id
 *	Load id based .so
 *		Instantiate Solution object
 *		Instantiate Test Case Iterator
 *		Test Case : { Input Object, Max Time, Max memory, Reference Output Object}
 *
 *	Instantiate Invoker & Verifier
 *
 *	create timed thread ; Thr func { Use Invoker to call Solution function, and use verifier to return result, write to a file}
 *	main thread : do timed sleep, kill thread if required, gather result and return by writing result to file.
 *
 *
 *	Input & output object : Int, String, (Array Of Int/String/array & int size), ListNode, TreeNode - Can Invoker and Verifier be COMMON ?
 *
 *	For verifier, write templatized Compare functions for each known object types
 *
 *
 *
 * 	*/
	unsigned int prlen = strlen(argv[0]);
	unsigned int dvlen = strlen(argv[1]);
	if(argc != 2 || prlen == 0 || dvlen == 0 || prlen > MAX_CMD_ARG_LENGTH || dvlen > MAX_CMD_ARG_LENGTH){
		std::cout << "Ensure that problem_id and developer_id are passed as command line arguments and are maximum 16 characters long.\n";
		return 1;
	}

	std::string problem_id(argv[0]);
	std::string developer_id(argv[1]);

	Framework frmk;
	frmk.test(problem_id, developer_id);

	return 0;
}

