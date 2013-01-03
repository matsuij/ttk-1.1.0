/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorFlipCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkTensorFlipCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkTensorFlipCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  TensorFlipCommandFactory::TensorFlipCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkTensorFlipCommand",
			   "flip tensors w.r.t. a given axis",
			   1,
			   CreateObjectFunction<TensorFlipCommand>::New());
  }
  
  TensorFlipCommandFactory::~TensorFlipCommandFactory()
  {
  }
  
  const char* 
  TensorFlipCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  TensorFlipCommandFactory::GetDescription(void) const
  {
    return "Flip tensors w.r.t. a given axis";
  }
  
} // end namespace itk
