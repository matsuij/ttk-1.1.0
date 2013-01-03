/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkNPTRemoverCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkNPTRemoverCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkNPTRemoverCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  NPTRemoverCommandFactory::NPTRemoverCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkNPTRemoverCommand",
			   "remove any Non-Postive Tensors (NPT)",
			   1,
			   CreateObjectFunction<NPTRemoverCommand>::New());
  }
  
  NPTRemoverCommandFactory::~NPTRemoverCommandFactory()
  {
  }
  
  const char* 
  NPTRemoverCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  NPTRemoverCommandFactory::GetDescription(void) const
  {
    return "Removes any non-postive tensors";
  }
  
} // end namespace itk
