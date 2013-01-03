/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkAverageStdCalculatorCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkAverageStdCalculatorCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkAverageStdCalculatorCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  AverageStdCalculatorCommandFactory::AverageStdCalculatorCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkAverageStdCalculatorCommand",
			   "Calculate the average and covariance matrix of a set of images",
			   1,
			   CreateObjectFunction<AverageStdCalculatorCommand>::New());
  }
  
  AverageStdCalculatorCommandFactory::~AverageStdCalculatorCommandFactory()
  {
  }
  
  const char* 
  AverageStdCalculatorCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  AverageStdCalculatorCommandFactory::GetDescription(void) const
  {
    return "Calculate the average and covariance matrix of a set of images";
  }
  
} // end namespace itk
