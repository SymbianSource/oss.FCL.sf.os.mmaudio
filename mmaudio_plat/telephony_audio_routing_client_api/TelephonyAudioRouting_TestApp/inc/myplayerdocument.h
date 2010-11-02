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

#ifndef __MYPLAYERDOCUMENT_h__
#define __MYPLAYERDOCUMENT_h__

// INCLUDES
#include <AknDoc.h>

// FORWARD DECLARATIONS
class CMyPlayerAppUi;
class CEikApplication;

// CLASS DECLARATION

/**
 * CMyPlayerDocument application class.
 * An instance of class CMyPlayerDocument is the Document part of the
 * AVKON application framework for the MyPlayer example application.
 */
class CMyPlayerDocument : public CAknDocument
    {
public:
    // Constructors and destructor

    /**
     * NewL.
     * Two-phased constructor.
     * Construct a CMyPlayerDocument for the AVKON application aApp
     * using two phase construction, and return a pointer
     * to the created object.
     * @param aApp Application creating this document.
     * @return A pointer to the created instance of CMyPlayerDocument.
     */
    static CMyPlayerDocument* NewL(CEikApplication& aApp);

    /**
     * NewLC.
     * Two-phased constructor.
     * Construct a CMyPlayerDocument for the AVKON application aApp
     * using two phase construction, and return a pointer
     * to the created object.
     * @param aApp Application creating this document.
     * @return A pointer to the created instance of CMyPlayerDocument.
     */
    static CMyPlayerDocument* NewLC(CEikApplication& aApp);

    /**
     * ~CMyPlayerDocument
     * Virtual Destructor.
     */
    virtual ~CMyPlayerDocument();

public:
    // Functions from base classes

    /**
     * CreateAppUiL
     * From CEikDocument, CreateAppUiL.
     * Create a CMyPlayerAppUi object and return a pointer to it.
     * The object returned is owned by the Uikon framework.
     * @return Pointer to created instance of AppUi.
     */
    CEikAppUi* CreateAppUiL();

private:
    // Constructors

    /**
     * ConstructL
     * 2nd phase constructor.
     */
    void ConstructL();

    /**
     * CMyPlayerDocument.
     * C++ default constructor.
     * @param aApp Application creating this document.
     */
    CMyPlayerDocument(CEikApplication& aApp);

    };

#endif // __MYPLAYERDOCUMENT_h__
// End of File
