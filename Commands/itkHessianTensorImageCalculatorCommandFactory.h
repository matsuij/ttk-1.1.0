/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkHessianTensorImageCalculatorCommandFactory.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_HessianTensorImageCalculatorCommandFactory_h_
#define _itk_HessianTensorImageCalculatorCommandFactory_h_

#include "itkObjectFactoryBase.h"

namespace itk
{
  
  class HessianTensorImageCalculatorCommandFactory : public ObjectFactoryBase
  {
    
  public:
    typedef HessianTensorImageCalculatorCommandFactory Self;
    typedef ObjectFactoryBase        Superclass;
    typedef SmartPointer<Self>       Pointer;
    typedef SmartPointer<const Self> ConstPointer;
    
    /** Class methods used to interface with the registered factories. */
    virtual const char* GetITKSourceVersion(void) const;
    virtual const char* GetDescription(void) const;
    
    /** Method for class instantiation. */
    itkFactorylessNewMacro(Self);
    static HessianTensorImageCalculatorCommandFactory* FactoryNew() { return new HessianTensorImageCalculatorCommandFactory;}
    
    /** Run-time type information (and related methods). */
    itkTypeMacro(HessianTensorImageCalculatorCommandFactory, ObjectFactoryBase);
    
    /** Register one factory of this type  */
    static void RegisterOneFactory(void)
    {
      HessianTensorImageCalculatorCommandFactory::Pointer CSFFactory = HessianTensorImageCalculatorCommandFactory::New();
      ObjectFactoryBase::RegisterFactory( CSFFactory );
    }
    
		
  protected:
    HessianTensorImageCalculatorCommandFactory();
    ~HessianTensorImageCalculatorCommandFactory();
    
  private:
    HessianTensorImageCalculatorCommandFactory(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
