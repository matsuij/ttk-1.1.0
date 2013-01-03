/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorToScalarCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkTensorToScalarCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkTensorToScalarCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  TensorToScalarCommandFactory::TensorToScalarCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkTensorToScalarCommand",
			   "Extract scalars (such as FA) from tensors",
			   1,
			   CreateObjectFunction<TensorToScalarCommand>::New());
  }
  
  TensorToScalarCommandFactory::~TensorToScalarCommandFactory()
  {
  }
  
  const char* 
  TensorToScalarCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  TensorToScalarCommandFactory::GetDescription(void) const
  {
    return "Extract scalars (such as FA) from tensors";
  }
  
} // end namespace itk
