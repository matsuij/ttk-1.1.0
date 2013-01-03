/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkDWIBrainMaskExtractorCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkDWIBrainMaskExtractorCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkDWIBrainMaskExtractorCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  DWIBrainMaskExtractorCommandFactory::DWIBrainMaskExtractorCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkDWIBrainMaskExtractorCommand",
			   "Extract a brain mask from a DWI",
			   1,
			   CreateObjectFunction<DWIBrainMaskExtractorCommand>::New());
  }
  
  DWIBrainMaskExtractorCommandFactory::~DWIBrainMaskExtractorCommandFactory()
  {
  }
  
  const char* 
  DWIBrainMaskExtractorCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  DWIBrainMaskExtractorCommandFactory::GetDescription(void) const
  {
    return "Extract a brain mask from a DWI";
  }
  
} // end namespace itk
