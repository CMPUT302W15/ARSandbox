/***********************************************************************
FrameFilter - Class to filter streams of depth frames arriving from a
depth camera, with code to detect unstable values in each pixel, and
fill holes resulting from invalid samples.
Copyright (c) 2012-2013 Oliver Kreylos

This file is part of the Augmented Reality Sandbox (SARndbox).

The Augmented Reality Sandbox is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The Augmented Reality Sandbox is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with the Augmented Reality Sandbox; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
***********************************************************************/

#ifndef FRAMEFILTER_INCLUDED
#define FRAMEFILTER_INCLUDED

#include <Threads/Thread.h>
#include <Threads/MutexCond.h>
#include <Kinect/FrameBuffer.h>
#include <Kinect/FrameSource.h>

/* Forward declarations: */
namespace Misc {
template <class ParameterParam>
class FunctionCall;
}
namespace Geometry {
template <class ScalarParam,int dimensionParam>
class Plane;
template <class ScalarParam,int dimensionParam>
class ProjectiveTransformation;
}

class FrameFilter
	{
	/* Embedded classes: */
	public:
	typedef unsigned short RawDepth; // Data type for raw depth values
	typedef float FilteredDepth; // Data type for filtered depth values
	typedef Misc::FunctionCall<const Kinect::FrameBuffer&> OutputFrameFunction; // Type for functions called when a new output frame is ready
	typedef Geometry::Plane<double,3> Plane;
	typedef Geometry::ProjectiveTransformation<double,3> PTransform;
	typedef Kinect::FrameSource::DepthCorrection::PixelCorrection PixelDepthCorrection; // Type for per-pixel depth correction factors
	
	/* Elements: */
	private:
	unsigned int size[2]; // Width and height of processed frames
	PixelDepthCorrection* pixelDepthCorrection; // Buffer of per-pixel depth correction coefficients
	Threads::MutexCond inputCond; // Condition variable to signal arrival of a new input frame
	Kinect::FrameBuffer inputFrame; // The most recent input frame
	unsigned int inputFrameVersion; // Version number of input frame
	volatile bool runFilterThread; // Flag to keep the background filtering thread running
	Threads::Thread filterThread; // The background filtering thread
	float minPlane[4]; // Plane equation of the lower bound of valid depth values in depth image space
	float maxPlane[4]; // Plane equation of the upper bound of valid depth values in depth image space
	int numAveragingSlots; // Number of slots in each pixel's averaging buffer
	RawDepth* averagingBuffer; // Buffer to calculate running averages of each pixel's depth value
	int averagingSlotIndex; // Index of averaging slot in which to store the next frame's depth values
	unsigned int* statBuffer; // Buffer retaining the running means and variances of each pixel's depth value
	unsigned int minNumSamples; // Minimum number of valid samples needed to consider a pixel stable
	unsigned int maxVariance; // Maximum variance to consider a pixel stable
	bool retainValids; // Flag whether to retain previous stable values if a new pixel in instable, or reset to a default value
	float instableValue; // Value to assign to instable pixels if retainValids is false
	bool spatialFilter; // Flag whether to apply a spatial filter to time-averaged depth values
	float* validBuffer; // Buffer holding the most recent stable depth value for each pixel
	Kinect::FrameBuffer outputFrame; // The most recently filtered output frame
	OutputFrameFunction* outputFrameFunction; // Function called when a new output frame is ready
	
	/* Private methods: */
	void* filterThreadMethod(void); // Method for the background filtering thread
	
	/* Constructors and destructors: */
	public:
	FrameFilter(const unsigned int sSize[2],int sNumAveragingSlots,const PTransform& depthProjection,const Plane& basePlane); // Creates a filter for frames of the given size and the given running average length
	~FrameFilter(void); // Destroys the frame filter
	
	/* Methods: */
	void setDepthCorrection(const Kinect::FrameSource::DepthCorrection& newDepthCorrection); // Sets the frame filter's per-pixel depth correction coefficients
	void setValidDepthInterval(unsigned int newMinDepth,unsigned int newMaxDepth); // Sets the interval of depth values considered by the depth image filter
	void setValidElevationInterval(const PTransform& depthProjection,const Plane& basePlane,double newMinElevation,double newMaxElevation); // Sets the interval of elevations relative to the given base plane considered by the depth image filter
	void setStableParameters(unsigned int newMinNumSamples,unsigned int newMaxVariance); // Sets the statistical properties to consider a pixel stable
	void setRetainValids(bool newRetainValids); // Sets whether the filter retains previous stable values for instable pixels
	void setInstableValue(float newInstableValue); // Sets the depth value to assign to instable pixels
	void setSpatialFilter(bool newSpatialFilter); // Sets the spatial filtering flag
	void setOutputFrameFunction(OutputFrameFunction* newOutputFrameFunction); // Sets the output function; adopts given functor object
	void receiveRawFrame(const Kinect::FrameBuffer& newFrame); // Called to receive a new raw depth frame
	};

#endif
