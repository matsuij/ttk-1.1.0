/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkWarpTensorImageCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkWarpTensorImageCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkWarpTensorImageCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  WarpTensorImageCommandFactory::WarpTensorImageCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkWarpTensorImageCommand",
			   "warp a tensor image",
			   1,
			   CreateObjectFunction<WarpTensorImageCommand>::New());
  }
  
  WarpTensorImageCommandFactory::~WarpTensorImageCommandFactory()
  {
  }
  
  const char* 
  WarpTensorImageCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  WarpTensorImageCommandFactory::GetDescription(void) const
  {
    return "Warp a tensor image given a deformation field";
  }
  
} // end namespace itk
