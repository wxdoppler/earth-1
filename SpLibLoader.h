// $Id$

#ifndef _splibloader_h_
#define _splibloader_h_

#include <list>
#include <dlfcn.h>

// Handles the loading and releasing of dynamic libraries

class SpLibLoader
{
	public:
		SpLibLoader() { };
		~SpLibLoader() { };
		void load(char *fileName);
		void releaseAll();
	private:
		list<void *> handles;	
};

#endif