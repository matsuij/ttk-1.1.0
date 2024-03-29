/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Common/itkDenseFiniteDifferenceImageFilter2.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkDenseFiniteDifferenceImageFilter2.h,v $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkDenseFiniteDifferenceImageFilter2_h_
#define __itkDenseFiniteDifferenceImageFilter2_h_

#include "itkFiniteDifferenceImageFilter.h"
#include "itkMultiThreader.h"

namespace itk {

/**
 * \class DenseFiniteDifferenceImageFilter2
 *
 * This filter implements a layer of the finite difference solver hierarchy that
 * performs ``dense'' iteration, ie. iteration over all pixels in the input and
 * output at each change calculation and update step. Dense iteration is in
 * contrast to a ``sparse'' iteration over a subset of the pixels.  See
 * documenation for FiniteDifferenceImageFilter for an overview of the
 * iterative finite difference algorithm:
 *
 * \par
 * \f$u_{\mathbf{i}}^{n+1}=u^n_{\mathbf{i}}+\Delta u^n_{\mathbf{i}}\Delta t\f$ 
 *
 * \par
 * The generic code for performing iterations and updates at each time
 * step is inherited from the parent class.  This class defines an update
 * buffer for \f$ \Delta \f$ and the methods CalculateChange() and
 * ApplyUpdate(). These methods are designed to automatically thread their
 * execution.  \f$ \Delta \f$ is defined as an image of identical size and type 
 * as the output image.
 *
 * \par
 * As we descend through each layer in the hierarchy, we know more and more
 * about the specific application of our filter.  At this level, we
 * have committed to iteration over each pixel in an image. We take advantage
 * of that knowledge to multithread the iteration and update methods. 
 *  
 * \par Inputs and Outputs
 * This is an image to image filter.  The specific types of the images are not
 * fixed at this level in the hierarchy.
 *
 * \par How to use this class
 * This filter is only one layer in a branch the finite difference solver
 * hierarchy.  It does not define the function used in the CalculateChange() and
 * it does not define the stopping criteria (Halt method).  To use this class,
 * subclass it to a specific instance that supplies a function and Halt()
 * method.
 * 
 * \ingroup TensorToolKit
 * \sa FiniteDifferenceImageFilter */
template <class TInputImage, class TOutputImage>
class ITK_EXPORT DenseFiniteDifferenceImageFilter2  
  : public FiniteDifferenceImageFilter<TInputImage, TOutputImage>
{
public:
  /** Standard class typedefs */
  typedef DenseFiniteDifferenceImageFilter2 Self;
  typedef FiniteDifferenceImageFilter<TInputImage, TOutputImage> Superclass;
  typedef SmartPointer<Self>  Pointer;
  typedef SmartPointer<const Self>  ConstPointer;
  
  /** Run-time type information (and related methods) */
  itkTypeMacro(DenseFiniteDifferenceImageFilter2, ImageToImageFilter );
  
  /** Convenient typedefs */
  typedef typename Superclass::InputImageType  InputImageType;
  typedef typename Superclass::OutputImageType OutputImageType;
  typedef typename Superclass::FiniteDifferenceFunctionType
   FiniteDifferenceFunctionType;
  
  /** Dimensionality of input and output data is assumed to be the same.
   * It is inherited from the superclass. */
  itkStaticConstMacro(ImageDimension, unsigned int,Superclass::ImageDimension);

  /** The pixel type of the output image will be used in computations.
   * Inherited from the superclass. */
  typedef typename Superclass::PixelType PixelType;

  /** The value type of a time step.  Inherited from the superclass. */
  typedef typename Superclass::TimeStepType TimeStepType;

  /** The container type for the update buffer. */
  typedef OutputImageType UpdateBufferType;
  
protected:
  DenseFiniteDifferenceImageFilter2()
    { m_UpdateBuffer = UpdateBufferType::New(); }
  ~DenseFiniteDifferenceImageFilter2() {}
  void PrintSelf(std::ostream& os, Indent indent) const;

  /** A simple method to copy the data from the input to the output.  ( Supports
   * "read-only" image adaptors in the case where the input image type converts
   * to a different output image type. )  */
  virtual void CopyInputToOutput();

  /** This method applies changes from the m_UpdateBuffer to the output using
   * the ThreadedAPplyUpdate() method and a multithreading mechanism.  "dt" is
   * the time step to use for the update of each pixel. */
  virtual void ApplyUpdate(TimeStepType dt);

  /** Method to allow subclasses to get direct access to the update
   * buffer */
  virtual UpdateBufferType* GetUpdateBuffer()
    { return m_UpdateBuffer; }
  
private:
  DenseFiniteDifferenceImageFilter2(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  /** Structure for passing information into static callback methods.  Used in
   * the subclasses' threading mechanisms. */
  struct DenseFDThreadStruct
  {
    DenseFiniteDifferenceImageFilter2 *Filter;
    TimeStepType TimeStep;
    TimeStepType *TimeStepList;
    bool *ValidTimeStepList;
  };
  
  /** The type of region used for multithreading */
  typedef typename UpdateBufferType::RegionType ThreadRegionType;

  /** This method allocates storage in m_UpdateBuffer.  It is called from
   * Superclass::GenerateData(). */
  virtual void AllocateUpdateBuffer();
  
  /** This callback method uses ImageSource::SplitRequestedRegion to acquire an
   * output region that it passes to ThreadedApplyUpdate for processing. */
  static ITK_THREAD_RETURN_TYPE ApplyUpdateThreaderCallback( void *arg );
  
  /** This method populates an update buffer with changes for each pixel in the
   * output using the ThreadedCalculateChange() method and a multithreading
   * mechanism. Returns value is a time step to be used for the update. */
  virtual TimeStepType CalculateChange();

  /** This callback method uses SplitUpdateContainer to acquire a region
   * which it then passes to ThreadedCalculateChange for processing. */
  static ITK_THREAD_RETURN_TYPE CalculateChangeThreaderCallback( void *arg );
  
  /** Split the UpdateBuffer into "num" pieces, returning region "i" as
   * "splitRegion". This method is called "num" times to return non-overlapping
   * regions. The method returns the number of pieces that the UpdateBuffer
   * can be split into by the routine. i.e. return value is less than or equal
   * to "num".
   * \sa ImageSource */
  //  virtual
  //  int SplitUpdateContainer(int i, int num, ThreadRegionType& splitRegion);

  /**  Does the actual work of updating the output from the UpdateContainer over
   *  an output region supplied by the multithreading mechanism.
   *  \sa ApplyUpdate
   *  \sa ApplyUpdateThreaderCallback */ 
  virtual
  void ThreadedApplyUpdate(TimeStepType dt,
                           const ThreadRegionType &regionToProcess,
                           int threadId);
  // FOR ALL: iterator(output, splitRegion), iterator(update, splitRegion)

  /** Does the actual work of calculating change over a region supplied by
   * the multithreading mechanism.
   * \sa CalculateChange
   * \sa CalculateChangeThreaderCallback */
  virtual
  TimeStepType ThreadedCalculateChange(const ThreadRegionType &regionToProcess,
                                       int threadId);
  // FOR ALL : iterator(input, splitRegion), iterator(update, splitRegion)

  /** The buffer that holds the updates for an iteration of the algorithm. */
  typename UpdateBufferType::Pointer m_UpdateBuffer;
};
  

}// end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkDenseFiniteDifferenceImageFilter2.txx"
#endif

#endif
