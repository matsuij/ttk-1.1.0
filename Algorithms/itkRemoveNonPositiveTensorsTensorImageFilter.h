/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Algorithms/itkRemoveNonPositiveTensorsTensorImageFilter.h $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itk_RemoveNonPositiveTensorsTensorImageFilter_h_
#define _itk_RemoveNonPositiveTensorsTensorImageFilter_h_

#include "itkImageToImageFilter.h"
#include "itkInPlaceImageFilter.h"
#include "itkConstNeighborhoodIterator.h"

namespace itk
{

  template <class TInputImage, class TOutputImage>
    class ITK_EXPORT RemoveNonPositiveTensorsTensorImageFilter :
  //public ImageToImageFilter<TInputImage, TOutputImage>
  public InPlaceImageFilter<TInputImage, TOutputImage>
  {

  public:

    typedef RemoveNonPositiveTensorsTensorImageFilter     Self;
    typedef ImageToImageFilter<TInputImage, TOutputImage> Superclass;
    typedef SmartPointer<Self>        Pointer;
    typedef SmartPointer< const Self> ConstPointer;

    itkNewMacro (Self);
    itkTypeMacro (RemoveNonPositiveTensorsTensorImageFilter,
                  ImageToImageFilter);
    
    itkStaticConstMacro(ImageDimension, unsigned int,
			TOutputImage::ImageDimension);



    /** Image typedefs */
    typedef typename TOutputImage::PixelType        OutputPixelType;
    typedef typename TInputImage::PixelType         InputPixelType;
    typedef typename InputPixelType::ValueType      ScalarType;

    /** Image typedefs support */
    typedef TInputImage  InputImageType;
    typedef TOutputImage OutputImageType;

    typedef ConstNeighborhoodIterator<TInputImage> ConstNeighborhoodIteratorType;
    typedef typename ConstNeighborhoodIteratorType::RadiusType RadiusType;
        
     /** Superclass typedefs */
    typedef typename Superclass::OutputImageRegionType OutputImageRegionType;

    virtual void GenerateInputRequestedRegion() throw (InvalidRequestedRegionError);

    void SetUseImageSpacingOn()
    { this->SetUseImageSpacing (true); }

    void SetUseImageSpacingOff()
    { this->SetUseImageSpacing (false); }

    itkSetMacro (UseImageSpacing, bool);
    itkGetMacro (UseImageSpacing, bool);

    itkSetMacro (RemovingType, int);
    itkGetMacro (RemovingType, int);
    
  protected:

    RemoveNonPositiveTensorsTensorImageFilter();
    ~RemoveNonPositiveTensorsTensorImageFilter(){};

    void ThreadedGenerateData (const OutputImageRegionType&, int);
    void PrintSelf (std::ostream& os, Indent indent) const
    {
      Superclass::PrintSelf (os, indent);      
    }
    
    

  private:

    RemoveNonPositiveTensorsTensorImageFilter (const Self&);
    void operator=(const Self&);

    bool          m_UseImageSpacing;
    RadiusType    m_NeighborhoodRadius;
    int           m_RemovingType;
    
    
  };
  
  
      

} // end of namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkRemoveNonPositiveTensorsTensorImageFilter.txx"
#endif

#endif
