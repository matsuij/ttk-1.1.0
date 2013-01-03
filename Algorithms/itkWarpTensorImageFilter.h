/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkWarpTensorImageFilter.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkWarpTensorImageFilter_h
#define __itkWarpTensorImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkInterpolateImageFunction.h"
#include "itkTensorLinearInterpolateImageFunction.h"
#include "itkWarpJacobianFilter.h"
#include "itkPoint.h"
#include "itkFixedArray.h"

enum ReorientationType { FS, PPD };

namespace itk
{

template <
  class TInputImage,
  class TOutputImage,
  class TDeformationField
  >
class ITK_EXPORT WarpTensorImageFilter :
    public ImageToImageFilter<TInputImage, TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef WarpTensorImageFilter      Self;
  typedef ImageToImageFilter<TInputImage,TOutputImage> Superclass;
  typedef SmartPointer<Self>         Pointer;
  typedef SmartPointer<const Self>   ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods) */
  itkTypeMacro( WarpTensorImageFilter, ImageToImageFilter );

  /** Typedef to describe the output image region type. */
  typedef typename TOutputImage::RegionType OutputImageRegionType;

  /** Inherit some types from the superclass. */
  typedef typename Superclass::InputImageType        InputImageType;
  typedef typename Superclass::InputImagePointer     InputImagePointer;
  typedef typename Superclass::OutputImageType       OutputImageType;
  typedef typename Superclass::OutputImagePointer    OutputImagePointer;
  typedef typename Superclass::InputImageConstPointer InputImageConstPointer;
  typedef typename OutputImageType::IndexType        IndexType;
  typedef typename OutputImageType::SizeType         SizeType;
  typedef typename OutputImageType::PixelType        PixelType;
  typedef typename OutputImageType::SpacingType      SpacingType;

  /** Determine the image dimension. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TOutputImage::ImageDimension );
  itkStaticConstMacro(InputImageDimension, unsigned int,
                      TInputImage::ImageDimension );
  itkStaticConstMacro(DeformationFieldDimension, unsigned int,
                      TDeformationField::ImageDimension );

  itkStaticConstMacro(VectorDimension, unsigned int,
	  TDeformationField::PixelType::Dimension);

  typedef Matrix<double, ImageDimension, VectorDimension> JacobianType;
  typedef Image<JacobianType, ImageDimension>             JacobianImageType;
  typedef typename JacobianImageType::Pointer             JacobianPointer;
  typedef WarpJacobianFilter<TDeformationField, JacobianImageType>  JacobianFilterType;

  itkGetObjectMacro(Jacobian, JacobianImageType);

  /** Deformation field typedef support. */
  typedef TDeformationField    DeformationFieldType;
  typedef typename DeformationFieldType::Pointer  DeformationFieldPointer;
  typedef typename DeformationFieldType::PixelType DeformationType;

  /** Interpolator typedef support. */
  typedef double CoordRepType;
  typedef InterpolateImageFunction<InputImageType,CoordRepType>   InterpolatorType;
  typedef typename InterpolatorType::Pointer   InterpolatorPointer;
  typedef TensorLinearInterpolateImageFunction<InputImageType,CoordRepType>
  DefaultInterpolatorType;

  /** Point type */
  typedef Point<CoordRepType,itkGetStaticConstMacro(ImageDimension)> PointType;
  /** Type for representing the direction of the output image */
  typedef typename TOutputImage::DirectionType     DirectionType;

  /** Set the deformation field. */
  void SetDeformationField( const DeformationFieldType * field );

  /** Get a pointer the deformation field. */
  DeformationFieldType * GetDeformationField(void);

  /** Set the interpolator function. */
  itkSetObjectMacro( Interpolator, InterpolatorType );

  /** Get a pointer to the interpolator function. */
  itkGetObjectMacro( Interpolator, InterpolatorType );

  /** Set the output image spacing. */
  itkSetMacro(OutputSpacing, SpacingType);
  virtual void SetOutputSpacing( const double* values);

  /** Get the output image spacing. */
  itkGetConstReferenceMacro(OutputSpacing, SpacingType);

  /** Set the output image origin. */
  itkSetMacro(OutputOrigin, PointType);
  virtual void SetOutputOrigin( const double* values);

  /** Get the output image origin. */
  itkGetConstReferenceMacro(OutputOrigin, PointType);

  /** Set the edge padding value */
  itkSetMacro( EdgePaddingValue, PixelType );

  /** Get the edge padding value */
  itkGetMacro( EdgePaddingValue, PixelType );
  
    /** Set the type of tensor reorientation */
  itkSetMacro( ReorientationStrategy, ReorientationType );

  /** Get the edge padding value */
  itkGetMacro( ReorientationStrategy, ReorientationType );

  /** WarpTensorImageFilter produces an image which is a different
   * size than its input image. As such, it needs to provide an
   * implemenation for GenerateOutputInformation() which set
   * the output information according the OutputSpacing, OutputOrigin
   * and the deformation field's LargestPossibleRegion. */
  virtual void GenerateOutputInformation();

  /** It is difficult to compute in advance the input image region
   * required to compute the requested output region. Thus the safest
   * thing to do is to request for the whole input image.
   *
   * For the deformation field, the input requested region
   * set to be the same as that of the output requested region. */
  virtual void GenerateInputRequestedRegion();

  /** This method is used to set the state of the filter before 
   * multi-threading. */
  virtual void BeforeThreadedGenerateData();

  /** This method is used to set the state of the filter after 
   * multi-threading. */
  virtual void AfterThreadedGenerateData();

  /** Set/Get the direction (orientation) of the output image */
  itkSetMacro(OutputDirection, DirectionType );
  itkGetConstReferenceMacro(OutputDirection, DirectionType );

protected:
  WarpTensorImageFilter();
  ~WarpTensorImageFilter() {};
  void PrintSelf(std::ostream& os, Indent indent) const;

  /** WarpTensorImageFilter is implemented as a multi-threaded filter.
   * As such, it needs to provide and implementation for 
   * ThreadedGenerateData(). */
  void ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,
                            int threadId );

private:
  WarpTensorImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  PixelType                  m_EdgePaddingValue;
  SpacingType                m_OutputSpacing;
  PointType                  m_OutputOrigin;

  InterpolatorPointer        m_Interpolator;

  typename JacobianImageType::Pointer m_Jacobian;
  
  ReorientationType m_ReorientationStrategy;

  DirectionType m_OutputDirection;
  
  
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkWarpTensorImageFilter.txx"
#endif

#endif
