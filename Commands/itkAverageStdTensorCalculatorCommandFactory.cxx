/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkAverageStdTensorCalculatorCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkAverageStdTensorCalculatorCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkAverageStdTensorCalculatorCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  AverageStdTensorCalculatorCommandFactory::AverageStdTensorCalculatorCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkAverageStdTensorCalculatorCommand",
			   "Calculate the average and covariance matrix of a set of tensor fields",
			   1,
			   CreateObjectFunction<AverageStdTensorCalculatorCommand>::New());
  }
  
  AverageStdTensorCalculatorCommandFactory::~AverageStdTensorCalculatorCommandFactory()
  {
  }
  
  const char* 
  AverageStdTensorCalculatorCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  AverageStdTensorCalculatorCommandFactory::GetDescription(void) const
  {
    return "Calculate the average and covariance matrix of a set of tensor fields";
  }
  
} // end namespace itk
