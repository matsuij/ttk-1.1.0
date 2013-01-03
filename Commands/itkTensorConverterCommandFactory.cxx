/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorConverterCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkTensorConverterCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkTensorConverterCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  TensorConverterCommandFactory::TensorConverterCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkTensorConverterCommand",
			   "Convert a tensor image into another format",
			   1,
			   CreateObjectFunction<TensorConverterCommand>::New());
  }
  
  TensorConverterCommandFactory::~TensorConverterCommandFactory()
  {
  }
  
  const char* 
  TensorConverterCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  TensorConverterCommandFactory::GetDescription(void) const
  {
    return "Convert a tensor image into another format";
  }
  
} // end namespace itk
