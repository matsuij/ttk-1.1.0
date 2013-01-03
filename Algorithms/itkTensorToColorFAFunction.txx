/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkTensorToColorFAFunction.txx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorToColorFAFunction_txx_
#define _itk_TensorToColorFAFunction_txx_

#include "itkTensorToColorFAFunction.h"
#include "vnl/vnl_trace.h"


namespace itk
{

  template<class TInputPixelType, class TOutputPixelType>
  typename TensorToColorFAFunction<TInputPixelType, TOutputPixelType>::OutputPixelType
  TensorToColorFAFunction<TInputPixelType, TOutputPixelType>
  ::ComputeScalar (const InputPixelType &T) const
  {    
    typedef typename InputPixelType::ValueType ValueType;
    vnl_matrix<ValueType> M = T.GetVnlMatrix();

    ValueType t = vnl_trace(M);
    ValueType t2 = vnl_trace(M*M);
    
    ValueType tmp = (t*t)/(3.0*t2);
    
    if(tmp>1.0)
      tmp = 1.0;

    ValueType fa = static_cast<ValueType>( sqrt ( 1.5* ( 1.0  - tmp  )) );

    // get the major eigenvector:
    typedef typename InputPixelType::VectorType VectorType;
    VectorType vec = T.GetEigenvector (2);
    
    typedef typename OutputPixelType::ComponentType ComponentType;

    double r = fabs (vec[0])*255.0;
    double g = fabs (vec[1])*255.0;
    double b = fabs (vec[2])*255.0;
    double a = 2.0*255.0*fa;
    
    ComponentType R = static_cast<ComponentType>( (r>255.0)?255.0:r );
    ComponentType G = static_cast<ComponentType>( (g>255.0)?255.0:g );
    ComponentType B = static_cast<ComponentType>( (b>255.0)?255.0:b );
    ComponentType A = static_cast<ComponentType>( (a>255.0)?255.0:a );

    OutputPixelType output;
    output.SetRed (R);
    output.SetGreen (G);
    output.SetBlue (B);
    output.SetAlpha (A);

    return output;
    
  }
  
  
} // end of namespace


#endif
