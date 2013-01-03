/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkDemonsTensorRegistrationCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-07-08 15:02:10 +0200 (Thu, 08 Jul 2010) $
  Version:   $Revision: 89 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkDemonsTensorRegistrationCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkDemonsTensorRegistrationCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  DemonsTensorRegistrationCommandFactory::DemonsTensorRegistrationCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkDemonsTensorRegistrationCommand",
			   "non-linear diffeomorphic tensor registration using the demons",
			   1,
			   CreateObjectFunction<DemonsTensorRegistrationCommand>::New());
  }
  
  DemonsTensorRegistrationCommandFactory::~DemonsTensorRegistrationCommandFactory()
  {
  }
  
  const char* 
  DemonsTensorRegistrationCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  DemonsTensorRegistrationCommandFactory::GetDescription(void) const
  {
    return "Non-linear diffeomorphic tensor registration using the demons";
  }
  
} // end namespace itk
