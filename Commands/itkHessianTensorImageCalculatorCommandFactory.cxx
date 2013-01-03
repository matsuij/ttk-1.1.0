/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkHessianTensorImageCalculatorCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkHessianTensorImageCalculatorCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkHessianTensorImageCalculatorCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  HessianTensorImageCalculatorCommandFactory::HessianTensorImageCalculatorCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkHessianTensorImageCalculatorCommand",
			   "Extract the largest eigenvalue of the Hessian of a tensor field",
			   1,
			   CreateObjectFunction<HessianTensorImageCalculatorCommand>::New());
  }
  
  HessianTensorImageCalculatorCommandFactory::~HessianTensorImageCalculatorCommandFactory()
  {
  }
  
  const char* 
  HessianTensorImageCalculatorCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  HessianTensorImageCalculatorCommandFactory::GetDescription(void) const
  {
    return "Extract the largest eigenvalue of the Hessian of a tensor field";
  }
  
} // end namespace itk
