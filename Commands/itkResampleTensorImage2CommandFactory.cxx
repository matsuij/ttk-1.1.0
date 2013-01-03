/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkResampleTensorImage2CommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkResampleTensorImage2CommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkResampleTensorImage2Command.h"
#include "itkVersion.h"

namespace itk
{
  
  ResampleTensorImage2CommandFactory::ResampleTensorImage2CommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkResampleTensorImage2Command",
			   "Resample tensors w.r.t. a linear matrix and a domain extent",
			   1,
			   CreateObjectFunction<ResampleTensorImage2Command>::New());
  }
  
  ResampleTensorImage2CommandFactory::~ResampleTensorImage2CommandFactory()
  {
  }
  
  const char* 
  ResampleTensorImage2CommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  ResampleTensorImage2CommandFactory::GetDescription(void) const
  {
    return "Resample tensors w.r.t. a linear matrix and a domain extent";
  }
  
} // end namespace itk
