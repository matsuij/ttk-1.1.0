/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkRBFRotationMatrixExtrapolationCommandFactory.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkRBFRotationMatrixExtrapolationCommandFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkRBFRotationMatrixExtrapolationCommand.h"
#include "itkVersion.h"

namespace itk
{
  
  RBFRotationMatrixExtrapolationCommandFactory::RBFRotationMatrixExtrapolationCommandFactory()
  {
    this->RegisterOverride("itkCommandObjectBase",
			   "itkRBFRotationMatrixExtrapolationCommand",
			   "Extrapolate a set of rotation matrices using radial basis functions (RBF)",
			   1,
			   CreateObjectFunction<RBFRotationMatrixExtrapolationCommand>::New());
  }
  
  RBFRotationMatrixExtrapolationCommandFactory::~RBFRotationMatrixExtrapolationCommandFactory()
  {
  }
  
  const char* 
  RBFRotationMatrixExtrapolationCommandFactory::GetITKSourceVersion(void) const
  {
    return ITK_SOURCE_VERSION;
  }
  
  const char* 
  RBFRotationMatrixExtrapolationCommandFactory::GetDescription(void) const
  {
    return "Extrapolate a set of rotation matrices using radial basis functions (RBF)";
  }
  
} // end namespace itk
