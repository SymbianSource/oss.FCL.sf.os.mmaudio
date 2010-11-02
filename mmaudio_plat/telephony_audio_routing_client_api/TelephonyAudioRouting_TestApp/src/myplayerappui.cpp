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
#include <avkon.hrh>
#include <aknmessagequerydialog.h>
#include <CAknMemorySelectionDialog.h>
#include <CAknFileSelectionDialog.h>
#include <AknCommonDialogs.h>
#include <aknnotewrappers.h>
#include <StringLoader.h>
#include <f32file.h>
#include <s32file.h>
#include <hlplch.h>

#include <myplayer_0xe0edbe14.rsg>

#include "myplayer.hrh"
#include "myplayer.pan"
#include "myplayerapplication.h"
#include "myplayerappui.h"
#include "myplayerappview.h"

_LIT( KFileName, "C:\\private\\E0EDBE14\\MyPlayer.txt" );
_LIT( KText, "My Player");

// ============================ MEMBER FUNCTIONS ===============================


// -----------------------------------------------------------------------------
// CMyPlayerAppUi::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppUi::ConstructL()
    {
    // Initialise app UI with standard value.
    BaseConstructL(CAknAppUi::EAknEnableSkin);

    // Create view object
    iAppView = CMyPlayerAppView::NewL(ClientRect());

    // Create a file to write the text to
    TInt err = CCoeEnv::Static()->FsSession().MkDirAll(KFileName);
    if ((KErrNone != err) && (KErrAlreadyExists != err))
        {
        return;
        }

    RFile file;
    err = file.Replace(CCoeEnv::Static()->FsSession(), KFileName, EFileWrite);
    CleanupClosePushL(file);
    if (KErrNone != err)
        {
        CleanupStack::PopAndDestroy(1); // file
        return;
        }

    RFileWriteStream outputFileStream(file);
    CleanupClosePushL(outputFileStream);
    outputFileStream << KText;

    CleanupStack::PopAndDestroy(2); // outputFileStream, file
    

    }
// -----------------------------------------------------------------------------
// CMyPlayerAppUi::CMyPlayerAppUi()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CMyPlayerAppUi::CMyPlayerAppUi()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CMyPlayerAppUi::~CMyPlayerAppUi()
// Destructor.
// -----------------------------------------------------------------------------
//
CMyPlayerAppUi::~CMyPlayerAppUi()
    {
    if (iAppView)
        {
        delete iAppView;
        iAppView = NULL;
        }
    if(iPlayer)
        delete iPlayer;

    }

// -----------------------------------------------------------------------------
// CMyPlayerAppUi::HandleCommandL()
// Takes care of command handling.
// -----------------------------------------------------------------------------
//
void CMyPlayerAppUi::HandleCommandL(TInt aCommand)
    {
    switch (aCommand)
        {
        case EEikCmdExit:
        case EAknSoftkeyExit:
            Exit();
            break;
        
        case ECmdCreatePlayer:
            {

            // Load a string from the resource file and display it
            
            iPlayer = CMyPlayer::NewL();
            
            HBufC* textResource = StringLoader::LoadLC(R_AUDIO_PLAYER_TEXT);
            CAknInformationNote* informationNote;

            informationNote = new (ELeave) CAknInformationNote;

            // Show the information Note with
            // textResource loaded with StringLoader.
            informationNote->ExecuteLD(*textResource);

            // Pop HBuf from CleanUpStack and Destroy it.
            CleanupStack::PopAndDestroy(textResource);
            }
            break;
        case ECmdSetOutputL:
            {
            iPlayer->SetOutputL();
            RFile rFile;

            //Open file where the stream text is
            User::LeaveIfError(rFile.Open(CCoeEnv::Static()->FsSession(),
                    KFileName, EFileStreamText));//EFileShareReadersOnly));// EFileStreamText));
            CleanupClosePushL(rFile);

            // copy stream from file to RFileStream object
            RFileReadStream inputFileStream(rFile);
            CleanupClosePushL(inputFileStream);

            // HBufC descriptor is created from the RFileStream object.
            HBufC* fileData = HBufC::NewLC(inputFileStream, 32);

            CAknInformationNote* informationNote;

            informationNote = new (ELeave) CAknInformationNote;
            // Show the information Note
            informationNote->ExecuteLD(*fileData);

            // Pop loaded resources from the cleanup stack
            CleanupStack::PopAndDestroy(3); // filedata, inputFileStream, rFile
            }
            break;
        case ECmdSetShowNote:
            {
            iPlayer->SetShowNote();
            }
            break;
        case ECmdGetShowNote:
            {
            iPlayer->GetShowNote();
            }
            break;
        case ECmdOutputChanged:
            {
            iPlayer->OutputChangedTARManager();
            }
            break;
        case ECmdOutputChangeReq:
           {
           iPlayer->OutputChangeRequestCompleted();
           }
           break;
        default:
            Panic(EMyPlayerUi);
            break;
        }
    }
// -----------------------------------------------------------------------------
//  Called by the framework when the application status pane
//  size is changed.  Passes the new client rectangle to the
//  AppView
// -----------------------------------------------------------------------------
//
void CMyPlayerAppUi::HandleStatusPaneSizeChange()
    {
    iAppView->SetRect(ClientRect());
    }

CArrayFix<TCoeHelpContext>* CMyPlayerAppUi::HelpContextL() const
    {
#warning "Please see comment about help and UID3..."
    // Note: Help will not work if the application uid3 is not in the
    // protected range.  The default uid3 range for projects created
    // from this template (0xE0000000 - 0xEFFFFFFF) are not in the protected range so that they
    // can be self signed and installed on the device during testing.
    // Once you get your official uid3 from Symbian Ltd. and find/replace
    // all occurrences of uid3 in your project, the context help will
    // work. Alternatively, a patch now exists for the versions of 
    // HTML help compiler in SDKs and can be found here along with an FAQ:
    // http://www3.symbian.com/faq.nsf/AllByDate/E9DF3257FD565A658025733900805EA2?OpenDocument
    CArrayFixFlat<TCoeHelpContext>* array = new (ELeave) CArrayFixFlat<
            TCoeHelpContext> (1);
    CleanupStack::PushL(array);
    //array->AppendL(TCoeHelpContext(KUidMyPlayerApp, KGeneral_Information));
    CleanupStack::Pop(array);
    return array;
    }

// End of File
