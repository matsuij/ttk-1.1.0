/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Common/itkTensorTransform.txx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itkTensorTransform_txx
#define _itkTensorTransform_txx

#include "itkTensorTransform.h"

namespace itk
{


/**
 * Constructor
 */
template < class TScalarType,
           unsigned int NInputDimensions,
           unsigned int NOutputDimensions >
TensorTransform< TScalarType,NInputDimensions,NOutputDimensions>
::TensorTransform():
  m_Parameters(1),
  m_FixedParameters(1),
  m_Jacobian(NOutputDimensions,1)
{
  itkWarningMacro(<< "Using default transform constructor.  Should specify NOutputDims and NParameters as args to constructor.");
}



/**
 * Constructor
 */
template < class TScalarType,
           unsigned int NInputDimensions,
           unsigned int NOutputDimensions >
TensorTransform< TScalarType,NInputDimensions,NOutputDimensions>
::TensorTransform(unsigned int dimension,unsigned int numberOfParameters):
  m_Parameters(numberOfParameters),
  m_FixedParameters(numberOfParameters),
  m_Jacobian(dimension,numberOfParameters)
{
}


/**
 * GenerateName
 */
template < class TScalarType,
           unsigned int NInputDimensions,
           unsigned int NOutputDimensions >
std::string TensorTransform< TScalarType,NInputDimensions,NOutputDimensions>
::GetTransformTypeAsString () const
{
  OStringStream n;
  n << GetNameOfClass();
  n << "_";
  if ( typeid ( TScalarType ) == typeid ( float ) )
    {
    n << "float";
    }
  else if ( typeid ( TScalarType ) == typeid ( double ) )
    {
      n << "double";
    }
  else
    {
      n << "other";
    }
  n << "_" << InputSpaceDimension << "_" << OutputSpaceDimension;
  return n.str();
}


} // end namespace itk


#endif

