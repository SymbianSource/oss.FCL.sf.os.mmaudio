/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  TelephonyAudioRouting Test Application
*
*/

// INCLUDE FILES
#include "myplayer.hrh"
#include "myplayerdocument.h"
#include "myplayerapplication.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CMyPlayerApplication::CreateDocumentL()
// Creates CApaDocument object
// -----------------------------------------------------------------------------
//
CApaDocument* CMyPlayerApplication::CreateDocumentL()
    {
    // Create an MyPlayer document, and return a pointer to it
    return CMyPlayerDocument::NewL(*this);
    }

// -----------------------------------------------------------------------------
// CMyPlayerApplication::AppDllUid()
// Returns application UID
// -----------------------------------------------------------------------------
//
TUid CMyPlayerApplication::AppDllUid() const
    {
    // Return the UID for the MyPlayer application
    return KUidMyPlayerApp;
    }

// End of File
