/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorAnisotropicFilteringCommand.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorAnisotropicFilteringCommand_h_
#define _itk_TensorAnisotropicFilteringCommand_h_

#include "itkCommandObjectBase.h"

namespace itk {

  class TensorAnisotropicFilteringCommand : public CommandObjectBase
  {
    
  public:
		
    typedef TensorAnisotropicFilteringCommand Self;
    typedef CommandObjectBase Superclass;
    typedef SmartPointer <Self> Pointer;
    typedef SmartPointer <const Self> ConstPointer;
    
    itkTypeMacro(TensorAnisotropicFilteringCommand, CommandObjectBase);
    itkNewMacro(Self);
    
    const char *GetCommandName(void)
    { return "anisotropic_filter"; }
    
    int Execute(int nargs, const char *args[]);
    
  protected:
    TensorAnisotropicFilteringCommand();
    ~TensorAnisotropicFilteringCommand();
    
  private:
    TensorAnisotropicFilteringCommand(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
