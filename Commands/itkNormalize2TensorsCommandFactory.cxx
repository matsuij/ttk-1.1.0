/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkNormalize2TensorsCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkNormalize2TensorsCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkNormalize2TensorsCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  Normalize2TensorsCommandFactory::Normalize2TensorsCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkNormalize2TensorsCommand",
			   "Divide each tensor by its largest eigenvalue",
			   1,
			   CreateObjectFunction<Normalize2TensorsCommand>::New());
  }
  
  Normalize2TensorsCommandFactory::~Normalize2TensorsCommandFactory()
  {
  }
  
  const char* 
  Normalize2TensorsCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  Normalize2TensorsCommandFactory::GetDescription(void) const
  {
    return "Divide each tensor by its largest eigenvalue";
  }
  
} // end namespace itk
