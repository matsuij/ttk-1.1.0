/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkNormalizeTensorsCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkNormalizeTensorsCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkNormalizeTensorsCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  NormalizeTensorsCommandFactory::NormalizeTensorsCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkNormalizeTensorsCommand",
			   "Divide tensors by the largest eigenvalue of the field",
			   1,
			   CreateObjectFunction<NormalizeTensorsCommand>::New());
  }
  
  NormalizeTensorsCommandFactory::~NormalizeTensorsCommandFactory()
  {
  }
  
  const char* 
  NormalizeTensorsCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  NormalizeTensorsCommandFactory::GetDescription(void) const
  {
    return "Divide tensors by the largest eigenvalue of the field";
  }
  
} // end namespace itk
