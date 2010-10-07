// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//      Interfaces and factories for the GSM 06.10 encoder and decoder.
//

#ifndef GSM610COMMON_H
#define GSM610COMMON_H

#include <e32std.h>


/**
 * Provides an interface to the GSM 6.10 full rate (FR) speech encoder.
 * 
 * Class is intantiated via GSM610FR_EncoderFactory::CreateEncoderL().
 * 
 * @see GSM610FR_EncoderFactory
 * */
class MGSM610FR_Encoder
    {
public:
    virtual void StartL() = 0;
    virtual void ExecuteL(TUint8* aInBuf, TUint8* OutBuf) = 0;
    virtual void StopL() = 0;
    virtual void Release() = 0;
    };

/**
 * Provides an interface to the GSM 6.10 full rate (FR) speech decoder.
 * 
 * Class is intantiated via GSM610FR_DecoderFactory::CreateDecoderL().
 * 
 * @see GSM610FR_DecoderFactory
 * */
class MGSM610FR_Decoder
    {
public:
    virtual void StartL() = 0;
    virtual void ExecuteL(TUint8* aSrc, TUint8* aDst) = 0;
    virtual void StopL() = 0;
    virtual void Release() = 0;
    };

/**
 * Factory class for GSM 6.10 full rate (FR) speech encoder.
 * 
 * Client code can use the factory method to create an encoder object and obtain a handle to it.
 * All operations on the encoder are done through the MGSM610FR_Encoder interface. The client code
 * is responsible for destroying the encoder by calling MGSM610FR_Encoder::Release().
 * 
 * @see MGSM610FR_Encoder
 * */
class GSM610FR_EncoderFactory
    {
public:    
    IMPORT_C static MGSM610FR_Encoder* CreateEncoderL();
    };

/**
 * Factory class for GSM 6.10 full rate (FR) speech decoder.
 * 
 * Client code can use the factory method to create an decoder object and obtain a handle to it.
 * All operations on the decoder are done through the MGSM610FR_Decoder interface. The client code
 * is responsible for destroying the decoder by calling MGSM610FR_Decoder::Release().
 * 
 * @see MGSM610FR_Decoder
 * */
class GSM610FR_DecoderFactory
    {
public:    
    IMPORT_C static MGSM610FR_Decoder* CreateDecoderL();
    };

#endif
