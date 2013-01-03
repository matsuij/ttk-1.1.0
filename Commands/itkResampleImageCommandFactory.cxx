/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkResampleImageCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkResampleImageCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkResampleImageCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  ResampleImageCommandFactory::ResampleImageCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkResampleImageCommand",
			   "Resample an image given a linear transform and a reference image",
			   1,
			   CreateObjectFunction<ResampleImageCommand>::New());
  }
  
  ResampleImageCommandFactory::~ResampleImageCommandFactory()
  {
  }
  
  const char* 
  ResampleImageCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  ResampleImageCommandFactory::GetDescription(void) const
  {
    return "Resample an image given a linear transform and a reference image";
  }
  
} // end namespace itk
