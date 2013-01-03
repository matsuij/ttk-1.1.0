/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorNormalizedGaussianInterpolationCommand.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorNormalizedGaussianInterpolationCommand_h_
#define _itk_TensorNormalizedGaussianInterpolationCommand_h_

#include "itkCommandObjectBase.h"

namespace itk {

  class TensorNormalizedGaussianInterpolationCommand : public CommandObjectBase
  {
    
  public:
		
    typedef TensorNormalizedGaussianInterpolationCommand Self;
    typedef CommandObjectBase Superclass;
    typedef SmartPointer <Self> Pointer;
    typedef SmartPointer <const Self> ConstPointer;
    
    itkTypeMacro(TensorNormalizedGaussianInterpolationCommand, CommandObjectBase);
    itkNewMacro(Self);
    
    const char *GetCommandName(void)
    { return "normalized_gaussian_interpolation"; }
    
    int Execute(int nargs, const char *args[]);
    
  protected:
    TensorNormalizedGaussianInterpolationCommand();
    ~TensorNormalizedGaussianInterpolationCommand();
    
  private:
    TensorNormalizedGaussianInterpolationCommand(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
