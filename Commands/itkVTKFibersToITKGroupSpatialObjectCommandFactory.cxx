/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkVTKFibersToITKGroupSpatialObjectCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkVTKFibersToITKGroupSpatialObjectCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkVTKFibersToITKGroupSpatialObjectCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  VTKFibersToITKGroupSpatialObjectCommandFactory::VTKFibersToITKGroupSpatialObjectCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkVTKFibersToITKGroupSpatialObjectCommand",
			   "Convert a vtkPolyData fiber representation to an ITK GroupSpatialObject file",
			   1,
			   CreateObjectFunction<VTKFibersToITKGroupSpatialObjectCommand>::New());
  }
  
  VTKFibersToITKGroupSpatialObjectCommandFactory::~VTKFibersToITKGroupSpatialObjectCommandFactory()
  {
  }
  
  const char* 
  VTKFibersToITKGroupSpatialObjectCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  VTKFibersToITKGroupSpatialObjectCommandFactory::GetDescription(void) const
  {
    return "Convert a vtkPolyData fiber representation to an ITK GroupSpatialObject file";
  }
  
} // end namespace itk
