// $Id$

#ifndef _spimage_h_
#define _spimage_h_

#include <list>

#include "SpFile.h"
#include "SpImageDim.h"

class SpImage : public SpFile
{
	public:
		static SpImage* construct(const string &path);
		static void registerPlugins();
		static void deRegisterPlugins();
		virtual SpImageDim dim() = 0;
		virtual string formatString() = 0;
		virtual bool valid() = 0;
		virtual bool recognise(unsigned char *buf) = 0;
		virtual int sizeToRecognise() = 0;
		virtual SpImage* clone() = 0;
	protected:
		unsigned char  readChar() const;
		unsigned short readShort(const int &endian) const;
		unsigned long  readLong(const int &endian) const;
	private:
		static list<SpImage *> plugins;
};

#endif
