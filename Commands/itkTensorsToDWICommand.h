/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkTensorsToDWICommand.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorsToDWICommand_h_
#define _itk_TensorsToDWICommand_h_

#include "itkCommandObjectBase.h"

namespace itk {

  class TensorsToDWICommand : public CommandObjectBase
  {
    
  public:
		
    typedef TensorsToDWICommand Self;
    typedef CommandObjectBase Superclass;
    typedef SmartPointer <Self> Pointer;
    typedef SmartPointer <const Self> ConstPointer;
    
    itkTypeMacro(TensorsToDWICommand, CommandObjectBase);
    itkNewMacro(Self);
    
    const char *GetCommandName(void)
    { return "tensors_to_dwis"; }
    
    int Execute(int nargs, const char *args[]);
    
  protected:
    TensorsToDWICommand();
    ~TensorsToDWICommand();
    
  private:
    TensorsToDWICommand(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
