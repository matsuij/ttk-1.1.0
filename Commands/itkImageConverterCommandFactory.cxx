/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkImageConverterCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkImageConverterCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkImageConverterCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  ImageConverterCommandFactory::ImageConverterCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkImageConverterCommand",
			   "Convert an image file into another format",
			   1,
			   CreateObjectFunction<ImageConverterCommand>::New());
  }
  
  ImageConverterCommandFactory::~ImageConverterCommandFactory()
  {
  }
  
  const char* 
  ImageConverterCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  ImageConverterCommandFactory::GetDescription(void) const
  {
    return "Convert an image file into another format";
  }
  
} // end namespace itk
