// $Id$

#ifndef _spiffimage_h_
#define _spiffimage_h_

#include "SpImage.h"
#include "SpImageDim.h"

class SpIFFImageFormat: public SpImageFormat
{
	public:
		virtual string formatString() { return "IFF"; };
		virtual SpImage* constructImage();
		virtual bool recognise(unsigned char *buf);
		virtual int sizeToRecognise() { return 12; };
};

class SpIFFImage : public SpImage
{
	public:
		SpIFFImage() : headerRead(false), validHeader(false) { };
		~SpIFFImage() { };
		SpImageDim dim();
		bool valid();
		string formatString() { return format.formatString(); };
		SpImage* clone() { return format.constructImage(); };
		bool recognise(unsigned char *buf) { return format.recognise(buf); };
		int sizeToRecognise() { return format.sizeToRecognise(); };
	private:
		unsigned int h, w;
		bool headerRead;
		bool validHeader;
		void readHeader();
		SpIFFImageFormat format;
};

#endif
