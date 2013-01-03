/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkWarpFibersCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkWarpFibersCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkWarpFibersCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  WarpFibersCommandFactory::WarpFibersCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkWarpFibersCommand",
			   "Warp fibers w.r.t. a linear matrix or a deformation field",
			   1,
			   CreateObjectFunction<WarpFibersCommand>::New());
  }
  
  WarpFibersCommandFactory::~WarpFibersCommandFactory()
  {
  }
  
  const char* 
  WarpFibersCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  WarpFibersCommandFactory::GetDescription(void) const
  {
    return "Warp fibers w.r.t. a linear matrix or a deformation field";
  }
  
} // end namespace itk
