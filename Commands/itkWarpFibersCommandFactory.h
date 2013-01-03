/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkWarpFibersCommandFactory.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_WarpFibersCommandFactory_h_
#define _itk_WarpFibersCommandFactory_h_

#include "itkObjectFactoryBase.h"

namespace itk
{
  
  class WarpFibersCommandFactory : public ObjectFactoryBase
  {
    
  public:
    typedef WarpFibersCommandFactory Self;
    typedef ObjectFactoryBase        Superclass;
    typedef SmartPointer<Self>       Pointer;
    typedef SmartPointer<const Self> ConstPointer;
    
    /** Class methods used to interface with the registered factories. */
    virtual const char* GetITKSourceVersion(void) const;
    virtual const char* GetDescription(void) const;
    
    /** Method for class instantiation. */
    itkFactorylessNewMacro(Self);
    static WarpFibersCommandFactory* FactoryNew() { return new WarpFibersCommandFactory;}
    
    /** Run-time type information (and related methods). */
    itkTypeMacro(WarpFibersCommandFactory, ObjectFactoryBase);
    
    /** Register one factory of this type  */
    static void RegisterOneFactory(void)
    {
      WarpFibersCommandFactory::Pointer CSFFactory = WarpFibersCommandFactory::New();
      ObjectFactoryBase::RegisterFactory( CSFFactory );
    }
    
		
  protected:
    WarpFibersCommandFactory();
    ~WarpFibersCommandFactory();
    
  private:
    WarpFibersCommandFactory(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
