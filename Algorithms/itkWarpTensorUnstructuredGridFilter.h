/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkWarpTensorUnstructuredGridFilter.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkWarpTensorUnstructuredGridFilter_h
#define __itkWarpTensorUnstructuredGridFilter_h

#include "itkProcessObject.h"
#include "itkVectorLinearInterpolateImageFunction.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkTensorLinearInterpolateImageFunction.h"
#include "itkWarpJacobianFilter.h"
#include "itkPoint.h"
#include "itkFixedArray.h"
#include "itkTensor.h"

#include <vector>

namespace itk
{

template <
  class TDeformationField
  >
class ITK_EXPORT WarpTensorUnstructuredGridFilter :
    public ProcessObject
{
public:
  /** Standard class typedefs. */
  typedef WarpTensorUnstructuredGridFilter      Self;
  typedef ProcessObject Superclass;
  typedef SmartPointer<Self>         Pointer;
  typedef SmartPointer<const Self>   ConstPointer;

  enum ReorientationType { FS, PPD };

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods) */
  itkTypeMacro( WarpTensorUnstructuredGridFilter, ProcessObject );

  /** Typedef to describe the region type. */
  typedef typename TDeformationField::RegionType RegionType;

  /** Inherit some types from the superclass. */
  typedef TDeformationField                           DeformationFieldType;
  typedef typename DeformationFieldType::Pointer      DeformationFieldPointer;
  typedef typename DeformationFieldType::ConstPointer DeformationFieldConstPointer;
  typedef typename DeformationFieldType::SpacingType  SpacingType;
  typedef typename DeformationFieldType::IndexType    IndexType;


  
  /** Determine the image dimension. */
  itkStaticConstMacro(DeformationFieldDimension, unsigned int,
                      TDeformationField::ImageDimension );

  itkStaticConstMacro(VectorDimension, unsigned int,
	  TDeformationField::PixelType::Dimension);

  typedef Matrix<double, DeformationFieldDimension, VectorDimension> JacobianType;
  typedef Image<JacobianType, DeformationFieldDimension>             JacobianImageType;
  typedef typename JacobianImageType::Pointer             JacobianPointer;
  typedef WarpJacobianFilter<TDeformationField, JacobianImageType>  JacobianFilterType;

  /** Interpolator typedef support. */
  typedef VectorLinearInterpolateImageFunction<DeformationFieldType,double>   DeformationInterpolatorType;
  typedef typename DeformationInterpolatorType::Pointer   DeformationInterpolatorPointer;
/*   typedef LinearInterpolateImageFunction<JacobianImageType,double>   JacobianInterpolatorType; */
/*   typedef typename JacobianInterpolatorType::Pointer   JacobianInterpolatorPointer; */
  
  itkGetObjectMacro(Jacobian, JacobianImageType);

  /** Deformation field typedef support. */
  typedef typename DeformationFieldType::PixelType DeformationType;
  typedef typename DeformationFieldType::PointType PointType;

  typedef Tensor<double, VectorDimension> TensorType;
  typedef TensorType PixelType;
  typedef std::vector<TensorType> TensorArrayType;
  typedef std::vector<PointType> PointArrayType;

  /** Interpolator typedef support. */
  typedef double CoordRepType;

  /** Type for representing the direction of the output image */
  typedef typename DeformationFieldType::DirectionType     DirectionType;

  itkGetObjectMacro (DeformationField, DeformationFieldType);
  itkSetObjectMacro (DeformationField, DeformationFieldType);
  itkGetObjectMacro (InverseDeformationField, DeformationFieldType);
  itkSetObjectMacro (InverseDeformationField, DeformationFieldType);  

  /** Set the edge padding value */
  itkSetMacro( EdgePaddingValue, PixelType );

  /** Get the edge padding value */
  itkGetMacro( EdgePaddingValue, PixelType );
  
    /** Set the type of tensor reorientation */
  itkSetMacro( ReorientationStrategy, ReorientationType );

  /** Get the edge padding value */
  itkGetMacro( ReorientationStrategy, ReorientationType );

  /** WarpTensorUnstructuredGridFilter produces an image which is a different
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


  virtual void SetPoints (PointArrayType arg)
  { m_Points = arg; }
  virtual void SetTensors (TensorArrayType arg)
  { m_Tensors = arg; }

  PointArrayType GetOutputPoints (void)
  { return m_OutputPoints; }
  TensorArrayType GetOutputTensors (void)
  { return m_OutputTensors; }

protected:
  WarpTensorUnstructuredGridFilter();
  ~WarpTensorUnstructuredGridFilter() {};
  void PrintSelf(std::ostream& os, Indent indent) const;

  /** WarpTensorUnstructuredGridFilter is implemented as a filter.
   * As such, it needs to provide and implementation for 
   * GenerateData(). */
  void GenerateData();

private:
  WarpTensorUnstructuredGridFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  PixelType                  m_EdgePaddingValue;

  typename JacobianImageType::Pointer m_Jacobian;
  
  ReorientationType m_ReorientationStrategy;

  DeformationInterpolatorPointer m_InverseDeformationInterpolator;
/*   JacobianInterpolatorPointer m_JacobianInterpolator; */
  
  PointArrayType m_Points;
  PointArrayType m_OutputPoints;
  TensorArrayType m_Tensors;
  TensorArrayType m_OutputTensors;

  DeformationFieldPointer m_DeformationField;
  DeformationFieldPointer m_InverseDeformationField;
  
  
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkWarpTensorUnstructuredGridFilter.txx"
#endif

#endif
