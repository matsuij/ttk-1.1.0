/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkResampleTensorImageCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkResampleTensorImageCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkResampleTensorImageCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  ResampleTensorImageCommandFactory::ResampleTensorImageCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkResampleTensorImageCommand",
			   "Resample tensors w.r.t. a linear matrix and a reference image",
			   1,
			   CreateObjectFunction<ResampleTensorImageCommand>::New());
  }
  
  ResampleTensorImageCommandFactory::~ResampleTensorImageCommandFactory()
  {
  }
  
  const char* 
  ResampleTensorImageCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  ResampleTensorImageCommandFactory::GetDescription(void) const
  {
    return "Resample tensors w.r.t. a linear matrix and a reference image";
  }
  
} // end namespace itk
