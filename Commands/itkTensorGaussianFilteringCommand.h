/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorGaussianFilteringCommand.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorGaussianFilteringCommand_h_
#define _itk_TensorGaussianFilteringCommand_h_

#include "itkCommandObjectBase.h"

namespace itk {

  class TensorGaussianFilteringCommand : public CommandObjectBase
  {
    
  public:
		
    typedef TensorGaussianFilteringCommand Self;
    typedef CommandObjectBase Superclass;
    typedef SmartPointer <Self> Pointer;
    typedef SmartPointer <const Self> ConstPointer;
    
    itkTypeMacro(TensorGaussianFilteringCommand, CommandObjectBase);
    itkNewMacro(Self);
    
    const char *GetCommandName(void)
    { return "gaussian_filter"; }
    
    int Execute(int nargs, const char *args[]);
    
  protected:
    TensorGaussianFilteringCommand();
    ~TensorGaussianFilteringCommand();
    
  private:
    TensorGaussianFilteringCommand(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
