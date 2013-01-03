/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkTensorToVolumeFunction.txx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorToVolumeFunction_txx_
#define _itk_TensorToVolumeFunction_txx_

#include "itkTensorToVolumeFunction.h"

namespace itk
{


  template <class TInputPixelType, class TOutputPixelType>
  typename TensorToVolumeFunction<TInputPixelType,TOutputPixelType>::OutputPixelType
  TensorToVolumeFunction<TInputPixelType,TOutputPixelType>
  ::ComputeScalar (const InputPixelType & T) const
  {

    OutputPixelType vol = 1.0;
    for( unsigned int i=0; i< InputPixelType::Dimension; i++)
      vol *= T.GetEigenvalue (i);

    return vol;
  }
  


}// end of namespace



#endif
