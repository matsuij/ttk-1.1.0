/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorsToVTKUnstructuredGridCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkTensorsToVTKUnstructuredGridCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkTensorsToVTKUnstructuredGridCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  TensorsToVTKUnstructuredGridCommandFactory::TensorsToVTKUnstructuredGridCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkTensorsToVTKUnstructuredGridCommand",
			   "Convert tensor images into a vtk unstructured grid",
			   1,
			   CreateObjectFunction<TensorsToVTKUnstructuredGridCommand>::New());
  }
  
  TensorsToVTKUnstructuredGridCommandFactory::~TensorsToVTKUnstructuredGridCommandFactory()
  {
  }
  
  const char* 
  TensorsToVTKUnstructuredGridCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  TensorsToVTKUnstructuredGridCommandFactory::GetDescription(void) const
  {
    return "Convert tensor images into a vtk unstructured grid";
  }
  
} // end namespace itk
