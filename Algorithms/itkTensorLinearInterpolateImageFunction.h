/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkTensorLinearInterpolateImageFunction.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkTensorLinearInterpolateImageFunction_h
#define __itkTensorLinearInterpolateImageFunction_h

#include "itkInterpolateImageFunction.h"

namespace itk
{
  
  template <class TInputImage, class TCoordRep = float>
    class ITK_EXPORT TensorLinearInterpolateImageFunction : 
    public InterpolateImageFunction<TInputImage,TCoordRep> 
    {
      
    public:
    /** Standard class typedefs. */
    typedef TensorLinearInterpolateImageFunction Self;
    typedef InterpolateImageFunction<TInputImage,TCoordRep> Superclass;
    typedef SmartPointer<Self>        Pointer;
    typedef SmartPointer<const Self>  ConstPointer;
  
    /** Run-time type information (and related methods). */
    itkTypeMacro(TensorLinearInterpolateImageFunction, InterpolateImageFunction);

    /** Method for creation through the object factory. */
    itkNewMacro(Self);  
    
    /** OutputType typedef support. */
    typedef typename Superclass::OutputType OutputType;

    /** OutputType typedef support. */
    typedef typename OutputType::ValueType ScalarType;
    
    /** InputImageType typedef support. */
    typedef typename Superclass::InputImageType InputImageType;
    
    /** RealType typedef support. */
    typedef typename Superclass::RealType RealType;
    
    /** Dimension underlying input image. */
    itkStaticConstMacro(ImageDimension, unsigned int,Superclass::ImageDimension);
    
    /** Index typedef support. */
    typedef typename Superclass::IndexType IndexType;
    
    /** ContinuousIndex typedef support. */
    typedef typename Superclass::ContinuousIndexType ContinuousIndexType;
    
    /** Evaluate the function at a ContinuousIndex position
     *
     * Returns the linearly interpolated image intensity at a 
     * specified point position. No bounds checking is done.
     * The point is assume to lie within the image buffer.
     *
     * ImageFunction::IsInsideBuffer() can be used to check bounds before
     * calling the method. */
    virtual OutputType EvaluateAtContinuousIndex( const ContinuousIndexType & index ) const;

    /**
       Normalize the interpolation (default: OFF). Normalization is used when the sum of
       weights in less than one. Without normalization, a Log-Eucldiean interpolation
       will behave like we were interpolating with a null log-tensor, which is an identity
       tensor in the real space, which can be problematic.
       On the contrary, normalization forces the resulting tensor to be of the size of its
       neighbors, thus always creating new values on the image boundary, which can be also
       problematic. Depending on the siutation, one would prefer to normalize or not the
       interpolation.
     */
    itkSetMacro (Normalize, int);
    itkGetMacro (Normalize, int);
    itkBooleanMacro (Normalize);
    
    protected:
    TensorLinearInterpolateImageFunction();
    ~TensorLinearInterpolateImageFunction(){};
    void PrintSelf(std::ostream& os, Indent indent) const;
    
    private:
    TensorLinearInterpolateImageFunction( const Self& ); //purposely not implemented
    void operator=( const Self& ); //purposely not implemented
    
    /** Number of neighbors used in the interpolation */
    static const unsigned long  m_Neighbors;

    int m_Normalize;
    
    };
  
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTensorLinearInterpolateImageFunction.txx"
#endif

#endif
