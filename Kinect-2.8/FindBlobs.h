/***********************************************************************
FindBlobs - Helper function to extract all eight-connected blobs of
pixels from a frame whose pixel values match a given value up to a given
tolerance.
Copyright (c) 2010-2011 Oliver Kreylos

This file is part of the Kinect 3D Video Capture Project (Kinect).

The Kinect 3D Video Capture Project is free software; you can
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

The Kinect 3D Video Capture Project is distributed in the hope that it
will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with the Kinect 3D Video Capture Project; if not, write to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA
***********************************************************************/

#ifndef FINDBLOBS_INCLUDED
#define FINDBLOBS_INCLUDED

#include <vector>
#include <Kinect/FrameBuffer.h>

template <class PixelParam>
class BlobProperty // Class to accumulate additional pixel properties along with blobs
	{
	/* Embedded classes: */
	public:
	typedef PixelParam Pixel; // Underlying pixel type
	
	/* Methods: */
	void addPixel(int x,int y,const PixelParam& pixelValue) // Adds a pixel to the property accumulator
		{
		}
	void merge(const BlobProperty& other) // Merges two blob property accumulators when their respecive blobs are merged
		{
		}
	};

template <class PixelParam>
struct Blob // Structure for extracted blobs
	{
	/* Embedded classes: */
	public:
	typedef PixelParam Pixel; // Underlying pixel type
	
	/* Elements: */
	public:
	double x,y; // Position of blob's centroid
	int min[2],max[2]; // Bounding box of blob
	BlobProperty<Pixel> blobProperty; // Additional accumulated blob property
	};

template <class PixelParam>
class PixelComparer // Class to compare pixel values
	{
	/* Embedded classes: */
	public:
	typedef PixelParam Pixel; // Underlying pixel type
	
	/* Methods: */
	bool operator()(const Pixel& pixel) const // Compares the given pixel and returns true if the pixels are similar
		{
		return false;
		}
	};

template <class PixelParam>
std::vector<Blob<PixelParam> > findBlobs(const Kinect::FrameBuffer& frame,const PixelComparer<PixelParam>& comparer); // Extracts all connected blobs from the given frame whose pixel values match the given pixel comparer

#ifndef FINDBLOBS_IMPLEMENTATION
#include "FindBlobs.icpp"
#endif

#endif
