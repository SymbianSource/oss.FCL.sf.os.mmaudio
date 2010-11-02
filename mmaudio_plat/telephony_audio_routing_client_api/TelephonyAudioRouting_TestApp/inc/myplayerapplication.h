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

#ifndef __MYPLAYERAPPLICATION_H__
#define __MYPLAYERAPPLICATION_H__

// INCLUDES
#include <aknapp.h>
#include "myplayer.hrh"

// UID for the application;
// this should correspond to the uid defined in the mmp file
const TUid KUidMyPlayerApp =
    {
    _UID3
    };

// CLASS DECLARATION

/**
 * CMyPlayerApplication application class.
 * Provides factory to create concrete document object.
 * An instance of CMyPlayerApplication is the application part of the
 * AVKON application framework for the MyPlayer example application.
 */
class CMyPlayerApplication : public CAknApplication
    {
public:
    // Functions from base classes

    /**
     * From CApaApplication, AppDllUid.
     * @return Application's UID (KUidMyPlayerApp).
     */
    TUid AppDllUid() const;

protected:
    // Functions from base classes

    /**
     * From CApaApplication, CreateDocumentL.
     * Creates CMyPlayerDocument document object. The returned
     * pointer in not owned by the CMyPlayerApplication object.
     * @return A pointer to the created document object.
     */
    CApaDocument* CreateDocumentL();
    };

#endif // __MYPLAYERAPPLICATION_H__
// End of File
