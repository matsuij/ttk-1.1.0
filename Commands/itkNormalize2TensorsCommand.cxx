/*=========================================================================

  Program:   Tensor ToolKit - TTK
  Module:    $URL: https://scm.gforge.inria.fr/svn/ttk/trunk/Commands/itkNormalize2TensorsCommand.cxx $
  Language:  C++
  Date:      $Date: 2010-06-07 13:39:13 +0200 (Mon, 07 Jun 2010) $
  Version:   $Revision: 68 $

  Copyright (c) INRIA 2010. All rights reserved.
  See LICENSE.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkNormalize2TensorsCommand.h"

#include "itkNormalizeTensorImageFilter.h"
#include "itkTensorImageIO.h"
#include <itkImageFileReader.h>
#include <itkImage.h>

#include "GetPot.h"

namespace itk
{

  Normalize2TensorsCommand::Normalize2TensorsCommand()
  {
    m_ShortDescription = "Divide each tensor by its largest eigenvalue";
    m_LongDescription = "Usage:\n";
    m_LongDescription += "-i <input>\n";
    m_LongDescription += "-o <output>\n\n";
    m_LongDescription += m_ShortDescription;
  }

  Normalize2TensorsCommand::~Normalize2TensorsCommand()
  {}

  int Normalize2TensorsCommand::Execute(int narg, const char* arg[])
  {
    
    GetPot   cl(narg, const_cast<char**>(arg)); // argument parser
    if( cl.size() == 1 || cl.search(2, "--help", "-h") )
    {
      std::cout << this->GetLongDescription() << std::endl;
      return -1;
    }
    
    const char* fileIn   = cl.follow("",2,"-i","-I");
    const char* fileOut  = cl.follow("",2,"-o","-O");


    typedef double ScalarType;  
    typedef itk::Image<ScalarType, 3>                      ImageType;
    typedef itk::TensorImageIO<ScalarType, 3, 3>           IOType;
    typedef IOType::TensorImageType                        TensorImageType;    
    typedef itk::NormalizeTensorImageFilter<TensorImageType,TensorImageType>
      FilterType;
    
    IOType::Pointer myIO = IOType::New();
    myIO->SetFileName (fileIn);
    try
    {
      myIO->Read();
    }
    catch (itk::ExceptionObject &e)
    {
      std::cerr << e;
      return -1;
    }
    
    
    FilterType::Pointer myFilter = FilterType::New();
    myFilter->SetInput ( myIO->GetOutput() );
    
    // now: filter
    try
    {
      myFilter->Update();
    }
    catch(itk::ExceptionObject &e)
    {
      std::cerr << e;
      return -1;
    }
    
    
    
    // write the output
    myIO->SetFileName(fileOut);
    myIO->SetInput ( myFilter->GetOutput() );
    
    std::cout << "Writing..." << std::flush;
    try
    {
      myIO->Write();
    }
    catch(itk::ExceptionObject &e)
    {
      std::cerr << e;
      return -1;
    }
    std::cout << "Done." << std::endl;
    
      
    return 0;
  }
  
}
