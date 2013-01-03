/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkLogDomainDemonsTensorRegistrationCommandFactory.h $
  Language:  C++
  Date:      $Date: 2010-07-08 15:02:10 +0200 (Thu, 08 Jul 2010) $
  Version:   $Revision: 89 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_LogDomainDemonsTensorRegistrationCommandFactory_h_
#define _itk_LogDomainDemonsTensorRegistrationCommandFactory_h_

#include "itkObjectFactoryBase.h"

namespace itk
{
  
  class LogDomainDemonsTensorRegistrationCommandFactory : public ObjectFactoryBase
  {
    
  public:
    typedef LogDomainDemonsTensorRegistrationCommandFactory Self;
    typedef ObjectFactoryBase        Superclass;
    typedef SmartPointer<Self>       Pointer;
    typedef SmartPointer<const Self> ConstPointer;
    
    /** Class methods used to interface with the registered factories. */
    virtual const char* GetITKSourceVersion(void) const;
    virtual const char* GetDescription(void) const;
    
    /** Method for class instantiation. */
    itkFactorylessNewMacro(Self);
    static LogDomainDemonsTensorRegistrationCommandFactory* FactoryNew() { return new LogDomainDemonsTensorRegistrationCommandFactory;}
    
    /** Run-time type information (and related methods). */
    itkTypeMacro(LogDomainDemonsTensorRegistrationCommandFactory, ObjectFactoryBase);
    
    /** Register one factory of this type  */
    static void RegisterOneFactory(void)
    {
      LogDomainDemonsTensorRegistrationCommandFactory::Pointer CSFFactory = LogDomainDemonsTensorRegistrationCommandFactory::New();
      ObjectFactoryBase::RegisterFactory( CSFFactory );
    }
    
		
  protected:
    LogDomainDemonsTensorRegistrationCommandFactory();
    ~LogDomainDemonsTensorRegistrationCommandFactory();
    
  private:
    LogDomainDemonsTensorRegistrationCommandFactory(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
