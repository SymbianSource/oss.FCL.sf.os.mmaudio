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
//      Factories for the GSM 06.10 encoder and decoder.
//

#include "gsm610common.h"
#include "gsm610fr.h"

EXPORT_C MGSM610FR_Encoder* GSM610FR_EncoderFactory::CreateEncoderL()
    {
    CGSM610FR_Encoder* encoder = new (ELeave) CGSM610FR_Encoder;
	CleanupStack::PushL(encoder);
    encoder->ConstructL();
    CleanupStack::Pop(encoder);
    return encoder;
    }

EXPORT_C MGSM610FR_Decoder* GSM610FR_DecoderFactory::CreateDecoderL()
    {
    CGSM610FR_Decoder* decoder = new (ELeave) CGSM610FR_Decoder;
    CleanupStack::PushL(decoder);
    decoder->ConstructL();
    CleanupStack::Pop(decoder);
    return decoder;
    }
