/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkTensorToScalarFunction.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_TensorToScalarFunction_h_
#define _itk_TensorToScalarFunction_h_

#include <itkLightObject.h>

namespace itk
{

  template < class TInputPixelType, class TOutputPixelType >
    class ITK_EXPORT TensorToScalarFunction : public LightObject
  {
    
  public:
    
    typedef TensorToScalarFunction Self;
    typedef LightObject Superclass;

    typedef SmartPointer<Self>        Pointer;
    typedef SmartPointer<const Self>  ConstPointer;

    itkTypeMacro (TensorToScalarFunction, LightObject);

    typedef TInputPixelType   InputPixelType;
    typedef TOutputPixelType  OutputPixelType;
    
    virtual OutputPixelType ComputeScalar (const  InputPixelType&) const = 0;
        
    
  protected:
    TensorToScalarFunction(){};
    ~TensorToScalarFunction(){};

    void PrintSelf(std::ostream& os, Indent indent) const
    {
      Superclass::PrintSelf(os, indent);
    }
    
    
    
  private:
    TensorToScalarFunction (const Self&);
    void operator=(const Self&);
        
    
  };   
  
  
} // end of namespace


#endif
