/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkImageConverterCommandFactory.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_ImageConverterCommandFactory_h_
#define _itk_ImageConverterCommandFactory_h_

#include "itkObjectFactoryBase.h"

namespace itk
{
  
  class ImageConverterCommandFactory : public ObjectFactoryBase
  {
    
  public:
    typedef ImageConverterCommandFactory Self;
    typedef ObjectFactoryBase        Superclass;
    typedef SmartPointer<Self>       Pointer;
    typedef SmartPointer<const Self> ConstPointer;
    
    /** Class methods used to interface with the registered factories. */
    virtual const char* GetITKSourceVersion(void) const;
    virtual const char* GetDescription(void) const;
    
    /** Method for class instantiation. */
    itkFactorylessNewMacro(Self);
    static ImageConverterCommandFactory* FactoryNew() { return new ImageConverterCommandFactory;}
    
    /** Run-time type information (and related methods). */
    itkTypeMacro(ImageConverterCommandFactory, ObjectFactoryBase);
    
    /** Register one factory of this type  */
    static void RegisterOneFactory(void)
    {
      ImageConverterCommandFactory::Pointer CSFFactory = ImageConverterCommandFactory::New();
      ObjectFactoryBase::RegisterFactory( CSFFactory );
    }
    
		
  protected:
    ImageConverterCommandFactory();
    ~ImageConverterCommandFactory();
    
  private:
    ImageConverterCommandFactory(const Self&);
    void operator=(const Self&);
    
  };
  
}

#endif
