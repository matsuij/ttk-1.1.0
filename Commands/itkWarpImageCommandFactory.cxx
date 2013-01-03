/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkWarpImageCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkWarpImageCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkWarpImageCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  WarpImageCommandFactory::WarpImageCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkWarpImageCommand",
			   "Warp an image give a deformation field",
			   1,
			   CreateObjectFunction<WarpImageCommand>::New());
  }
  
  WarpImageCommandFactory::~WarpImageCommandFactory()
  {
  }
  
  const char* 
  WarpImageCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  WarpImageCommandFactory::GetDescription(void) const
  {
    return "Warp an image give a deformation field";
  }
  
} // end namespace itk
