/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Common/itkAffineTensorTransform.txx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkAffineTensorTransform_txx
#define __itkAffineTensorTransform_txx

#include "itkNumericTraits.h"
#include "itkAffineTensorTransform.h"
#include "vnl/algo/vnl_matrix_inverse.h"


namespace itk
{

/** Constructor with default arguments */
template<class TScalarType, unsigned int NDimensions>
AffineTensorTransform<TScalarType, NDimensions>::
AffineTensorTransform(): Superclass(SpaceDimension,ParametersDimension)
{
}


/** Constructor with default arguments */
template<class TScalarType, unsigned int NDimensions>
AffineTensorTransform<TScalarType, NDimensions>::
AffineTensorTransform( unsigned int outputSpaceDimension, 
                 unsigned int parametersDimension   ):
  Superclass(outputSpaceDimension,parametersDimension)
{
}


/** Constructor with explicit arguments */
template<class TScalarType, unsigned int NDimensions>
AffineTensorTransform<TScalarType, NDimensions>::
AffineTensorTransform(const MatrixType & matrix,
               const OutputVectorType & offset):
  Superclass(matrix, offset)
{
}


/**  Destructor */
template<class TScalarType, unsigned int NDimensions>
AffineTensorTransform<TScalarType, NDimensions>::
~AffineTensorTransform()
{
  return;
}


/** Print self */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>::
PrintSelf(std::ostream &os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);
}


/** Compose with a translation */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>::
Translate(const OutputVectorType &trans, bool pre)
{
  OutputVectorType newTranslation = this->GetTranslation();
  if (pre) 
    {
    newTranslation += this->GetMatrix() * trans;
    }
  else 
    {
    newTranslation += trans;
    }
  this->SetVarTranslation(newTranslation);
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with isotropic scaling */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Scale(const TScalarType &factor, bool pre) 
{
  if (pre) 
    {
    MatrixType newMatrix = this->GetMatrix();
    newMatrix *= factor;
    this->SetVarMatrix(newMatrix);
    }
  else 
    {
    MatrixType newMatrix = this->GetMatrix();
    newMatrix *= factor;
    this->SetVarMatrix(newMatrix);

    OutputVectorType newTranslation = this->GetTranslation();
    newTranslation *= factor;
    this->SetVarTranslation(newTranslation);
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with anisotropic scaling */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Scale(const OutputVectorType &factor, bool pre) 
{
  MatrixType trans;
  unsigned int i, j;

  for (i = 0; i < NDimensions; i++) 
    {
    for (j = 0; j < NDimensions; j++) 
      {
      trans[i][j] = 0.0;
      }
    trans[i][i] = factor[i];
    }
  if (pre) 
    {
    this->SetVarMatrix( this->GetMatrix() * trans );
    }
  else 
    {
    this->SetVarMatrix( trans * this->GetMatrix() );
    this->SetVarTranslation( trans * this->GetTranslation() );
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with elementary rotation */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Rotate(int axis1, int axis2, TScalarType angle, bool pre) 
{
  MatrixType trans;
  unsigned int i, j;

  for (i = 0; i < NDimensions; i++) 
    {
    for (j = 0; j < NDimensions; j++) 
      {
      trans[i][j] = 0.0;
      }
    trans[i][i] = 1.0;
    }
  trans[axis1][axis1] =  vcl_cos(angle);
  trans[axis1][axis2] =  vcl_sin(angle);
  trans[axis2][axis1] = -sin(angle);
  trans[axis2][axis2] =  vcl_cos(angle);
  if (pre) 
    {
    this->SetVarMatrix( this->GetMatrix() * trans );
    }
  else 
    {
    this->SetVarMatrix( trans * this->GetMatrix() );
    this->SetVarTranslation( trans * this->GetTranslation() );
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with 2D rotation
 * \todo Find a way to generate a compile-time error
 * is this is used with NDimensions != 2. */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Rotate2D(TScalarType angle, bool pre)
{
  MatrixType trans;

  trans[0][0] =  vcl_cos(angle);
  trans[0][1] = -sin(angle);
  trans[1][0] = vcl_sin(angle);
  trans[1][1] =  vcl_cos(angle);
  if (pre) 
    {
    this->SetVarMatrix( this->GetMatrix() * trans );
    }
  else 
    {
    this->SetVarMatrix( trans * this->GetMatrix() );
    this->SetVarTranslation( trans * this->GetTranslation() );
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with 3D rotation
 *  \todo Find a way to generate a compile-time error
 *  is this is used with NDimensions != 3. */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Rotate3D(const OutputVectorType &axis, TScalarType angle, bool pre)
{
  MatrixType trans;
  ScalarType r, x1, x2, x3;
  ScalarType q0, q1, q2, q3;

  // Convert the axis to a unit vector
  r = vcl_sqrt(axis[0]*axis[0] + axis[1]*axis[1] + axis[2]*axis[2]);
  x1 = axis[0] / r;
  x2 = axis[1] / r;
  x3 = axis[2] / r;

  // Compute quaternion elements
  q0 = vcl_cos(angle/2.0);
  q1 = x1 * vcl_sin(angle/2.0);
  q2 = x2 * vcl_sin(angle/2.0);
  q3 = x3 * vcl_sin(angle/2.0);

  // Compute elements of the rotation matrix
  trans[0][0] = q0*q0 + q1*q1 - q2*q2 - q3*q3;
  trans[0][1] = 2.0*(q1*q2 - q0*q3);
  trans[0][2] = 2.0*(q1*q3 + q0*q2);
  trans[1][0] = 2.0*(q1*q2 + q0*q3);
  trans[1][1] = q0*q0 + q2*q2 - q1*q1 - q3*q3;
  trans[1][2] = 2.0*(q2*q3 - q0*q1);
  trans[2][0] = 2.0*(q1*q3 - q0*q2);
  trans[2][1] = 2.0*(q2*q3 + q0*q1);
  trans[2][2] = q0*q0 + q3*q3 - q1*q1 - q2*q2;

  // Compose rotation matrix with the existing matrix
  if (pre) 
    {
    this->SetVarMatrix( this->GetMatrix() * trans );
    }
  else 
    {
    this->SetVarMatrix( trans * this->GetMatrix() );
    this->SetVarTranslation( trans * this->GetTranslation() );
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compose with elementary rotation */
template<class TScalarType, unsigned int NDimensions>
void
AffineTensorTransform<TScalarType, NDimensions>
::Shear(int axis1, int axis2, TScalarType coef, bool pre)
{
  MatrixType trans;
  unsigned int i, j;

  for (i = 0; i < NDimensions; i++) 
    {
    for (j = 0; j < NDimensions; j++) 
      {
      trans[i][j] = 0.0;
      }
    trans[i][i] = 1.0;
    }
  trans[axis1][axis2] =  coef;
  if (pre) 
    {
    this->SetVarMatrix( this->GetMatrix() * trans );
    }
  else 
    {
    this->SetVarMatrix( trans * this->GetMatrix() );
    this->SetVarTranslation( trans * this->GetTranslation() );
    }
  this->ComputeMatrixParameters();
  this->ComputeRigidPartOfTransform();
  this->ComputeOffset();
  this->Modified();
  return;
}


/** Compute a distance between two affine transforms */
template<class TScalarType, unsigned int NDimensions>
typename AffineTensorTransform<TScalarType, NDimensions>::ScalarType
AffineTensorTransform<TScalarType, NDimensions>
::Metric(const Self * other) const
{
  ScalarType result = 0.0, term;

  for (unsigned int i = 0; i < NDimensions; i++) 
    {
    for (unsigned int j = 0; j < NDimensions; j++) 
      {
      term = this->GetMatrix()[i][j] - other->GetMatrix()[i][j];
      result += term * term;
      }
    term = this->GetOffset()[i] - other->GetOffset()[i];
    result += term * term;
    }
  return vcl_sqrt(result);
}


/** Compute a distance between self and the identity transform */
template<class TScalarType, unsigned int NDimensions>
typename AffineTensorTransform<TScalarType, NDimensions>::ScalarType
AffineTensorTransform<TScalarType, NDimensions>
::Metric(void) const
{
  ScalarType result = 0.0, term;

  for (unsigned int i = 0; i < NDimensions; i++) 
    {
    for (unsigned int j = 0; j < NDimensions; j++) 
      {
      if (i == j)
        {
        term = this->GetMatrix()[i][j] - 1.0;
        }
      else
        {
        term = this->GetMatrix()[i][j];
        }
      result += term * term;
      }
    term = this->GetOffset()[i];
    result += term * term;
    }

  return vcl_sqrt(result);
}


} // namespace

#endif
