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
#include "myplayerappui.h"
#include "myplayerdocument.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CMyPlayerDocument::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CMyPlayerDocument* CMyPlayerDocument::NewL(CEikApplication& aApp)
    {
    CMyPlayerDocument* self = NewLC(aApp);
    CleanupStack::Pop(self);
    return self;
    }

// -----------------------------------------------------------------------------
// CMyPlayerDocument::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CMyPlayerDocument* CMyPlayerDocument::NewLC(CEikApplication& aApp)
    {
    CMyPlayerDocument* self = new (ELeave) CMyPlayerDocument(aApp);

    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CMyPlayerDocument::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CMyPlayerDocument::ConstructL()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CMyPlayerDocument::CMyPlayerDocument()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CMyPlayerDocument::CMyPlayerDocument(CEikApplication& aApp) :
    CAknDocument(aApp)
    {
    // No implementation required
    }

// ---------------------------------------------------------------------------
// CMyPlayerDocument::~CMyPlayerDocument()
// Destructor.
// ---------------------------------------------------------------------------
//
CMyPlayerDocument::~CMyPlayerDocument()
    {
    // No implementation required
    }

// ---------------------------------------------------------------------------
// CMyPlayerDocument::CreateAppUiL()
// Constructs CreateAppUi.
// ---------------------------------------------------------------------------
//
CEikAppUi* CMyPlayerDocument::CreateAppUiL()
    {
    // Create the application user interface, and return a pointer to it;
    // the framework takes ownership of this object
    return new (ELeave) CMyPlayerAppUi;
    }

// End of File
