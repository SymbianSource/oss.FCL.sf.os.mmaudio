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
#include <coemain.h>
#include "myplayerappview.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CMyPlayerAppView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CMyPlayerAppView* CMyPlayerAppView::NewL(const TRect& aRect)
    {
    CMyPlayerAppView* self = CMyPlayerAppView::NewLC(aRect);
    CleanupStack::Pop(self);
    return self;
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CMyPlayerAppView* CMyPlayerAppView::NewLC(const TRect& aRect)
    {
    CMyPlayerAppView* self = new (ELeave) CMyPlayerAppView;
    CleanupStack::PushL(self);
    self->ConstructL(aRect);
    return self;
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppView::ConstructL(const TRect& aRect)
    {
    // Create a window for this application view
    CreateWindowL();

    // Set the windows size
    SetRect(aRect);

    // Activate the window, which makes it ready to be drawn
    ActivateL();
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::CMyPlayerAppView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CMyPlayerAppView::CMyPlayerAppView()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::~CMyPlayerAppView()
// Destructor.
// -----------------------------------------------------------------------------
//
CMyPlayerAppView::~CMyPlayerAppView()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::Draw()
// Draws the display.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppView::Draw(const TRect& /*aRect*/) const
    {
    // Get the standard graphics context
    CWindowGc& gc = SystemGc();

    // Gets the control's extent
    TRect drawRect(Rect());

    // Clears the screen
    gc.Clear(drawRect);

    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::SizeChanged()
// Called by framework when the view size is changed.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppView::SizeChanged()
    {
    DrawNow();
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppView::HandlePointerEventL()
// Called by framework to handle pointer touch events.
// Note: although this method is compatible with earlier SDKs, 
// it will not be called in SDKs without Touch support.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppView::HandlePointerEventL(const TPointerEvent& aPointerEvent)
    {

    // Call base class HandlePointerEventL()
    CCoeControl::HandlePointerEventL(aPointerEvent);
    }

// End of File
