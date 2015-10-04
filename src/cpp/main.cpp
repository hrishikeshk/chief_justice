#include "Framework.h"

int main(){

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

	Framework frmk;

	return 0;
}

