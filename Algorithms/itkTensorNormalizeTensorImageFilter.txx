/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkTensorNormalizeTensorImageFilter.txx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorNormalizeTensorImageFilter_txx_
#define _itk_TensorNormalizeTensorImageFilter_txx_

#include "itkTensorNormalizeTensorImageFilter.h"

#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>


namespace itk
{

  template <class TTensorInput, class TTensorOutput>
  void
  TensorNormalizeTensorImageFilter<TTensorInput, TTensorOutput>
  ::ThreadedGenerateData (const OutputRegionType& outputRegion, int threadId)
  {
    
    typedef ImageRegionIterator<OutputImageType>       OutputIteratorType;
    typedef ImageRegionConstIterator<InputImageType>  InputIteratorType;
    
    InputIteratorType itIn(this->GetInput(), outputRegion);
    OutputIteratorType itOut(this->GetOutput(), outputRegion);
    
    while(!itOut.IsAtEnd() )
    {
      InputPixelType T = itIn.Get();	
      if( !T.IsZero() )
      {
	T /= m_NormalizationFactor;
      }

      itOut.Set (T);
      ++itOut;
      ++itIn;
    }
    
  }
  
} // end of namespace


#endif
