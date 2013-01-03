/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkSyntheticTensorFieldGeneratorCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkSyntheticTensorFieldGeneratorCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkSyntheticTensorFieldGeneratorCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  SyntheticTensorFieldGeneratorCommandFactory::SyntheticTensorFieldGeneratorCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkSyntheticTensorFieldGeneratorCommand",
			   "Generate a synthetic crossing or circle tensor field",
			   1,
			   CreateObjectFunction<SyntheticTensorFieldGeneratorCommand>::New());
  }
  
  SyntheticTensorFieldGeneratorCommandFactory::~SyntheticTensorFieldGeneratorCommandFactory()
  {
  }
  
  const char* 
  SyntheticTensorFieldGeneratorCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  SyntheticTensorFieldGeneratorCommandFactory::GetDescription(void) const
  {
    return "Generate a synthetic crossing or circle tensor field";
  }
  
} // end namespace itk
