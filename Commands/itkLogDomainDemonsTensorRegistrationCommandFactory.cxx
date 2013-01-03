/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkLogDomainDemonsTensorRegistrationCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-07-08 15:02:10 +0200 (Thu, 08 Jul 2010) $
  Version:   $Revision: 89 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkLogDomainDemonsTensorRegistrationCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkLogDomainDemonsTensorRegistrationCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  LogDomainDemonsTensorRegistrationCommandFactory::LogDomainDemonsTensorRegistrationCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkLogDomainDemonsTensorRegistrationCommand",
			   "non-linear, log-domain and symmetric diffeomorphic tensor registration using the demons",
			   1,
			   CreateObjectFunction<LogDomainDemonsTensorRegistrationCommand>::New());
  }
  
  LogDomainDemonsTensorRegistrationCommandFactory::~LogDomainDemonsTensorRegistrationCommandFactory()
  {
  }
  
  const char* 
  LogDomainDemonsTensorRegistrationCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  LogDomainDemonsTensorRegistrationCommandFactory::GetDescription(void) const
  {
    return "Non-linear, log-domain and symmetric diffeomorphic tensor registration using the demons";
  }
  
} // end namespace itk
