/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkResampleTensorImage2Command.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_ResampleTensorImage2Command_h_
#define _itk_ResampleTensorImage2Command_h_

#include "itkCommandObjectBase.h"

namespace itk {

  class ResampleTensorImage2Command : public CommandObjectBase
  {
    
  public:
		
    typedef ResampleTensorImage2Command Self;
    typedef CommandObjectBase Superclass;
    typedef SmartPointer <Self> Pointer;
    typedef SmartPointer <const Self> ConstPointer;
    
    itkTypeMacro(ResampleTensorImage2Command, CommandObjectBase);
    itkNewMacro(Self);
    
    const char *GetCommandName(void)
    { return "resample2"; }
    
    int Execute(int nargs, const char *args[]);
    
  protected:
    ResampleTensorImage2Command();
    ~ResampleTensorImage2Command();
    
  private:
    ResampleTensorImage2Command(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
