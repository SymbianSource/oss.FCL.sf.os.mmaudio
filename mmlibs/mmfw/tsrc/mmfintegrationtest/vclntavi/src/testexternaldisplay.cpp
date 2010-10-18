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
//
 
#include "testvideoplayer2.h"
#include <bautils.h>

// file names used to control plugin through their existence. If any are new files are added make sure
// they are also added to TidyFiles().
_LIT(KInitExtDisplayHDMI, "c:\\vclntavi\\InitExtDisplayHDMI.txt");
_LIT(KInitExtDisplayAnalog, "c:\\vclntavi\\InitExtDisplayAnalog.txt");
_LIT(KConnectExtDisplayOverHDMI, "c:\\vclntavi\\ConnectExtDisplayOverHDMI.txt");
_LIT(KConnectExtDisplayOverAnalog, "c:\\vclntavi\\ConnectExtDisplayOverAnalog.txt");
_LIT(KDisconnectExtDisplay, "c:\\vclntavi\\DisconnectExtDisplay.txt");
void TidyFiles()
    {
    RFs fs;
    TInt error= fs.Connect();
    if(error == KErrNone)
        {
        if(BaflUtils::FileExists(fs, KInitExtDisplayHDMI))
            {
            fs.Delete(KInitExtDisplayHDMI);
            }
        if(BaflUtils::FileExists(fs, KInitExtDisplayAnalog))
            {
            fs.Delete(KInitExtDisplayAnalog);
            }
        if(BaflUtils::FileExists(fs, KConnectExtDisplayOverHDMI))
            {
            fs.Delete(KConnectExtDisplayOverHDMI);
            }
        if(BaflUtils::FileExists(fs, KConnectExtDisplayOverAnalog))
            {
            fs.Delete(KConnectExtDisplayOverAnalog);
            }
        if(BaflUtils::FileExists(fs, KDisconnectExtDisplay))
            {
            fs.Delete(KDisconnectExtDisplay);
            }
        }
}

_LIT(KFilename, "filename");

//
// RTestMediaClientExternalDisplay
//

/**
 * RTestMediaClientExternalDisplay::Constructor
 */
RTestMediaClientExternalDisplay::RTestMediaClientExternalDisplay(const TDesC& aTestName)
    : RTestVclnt2AviPlayerStep(aTestName, aTestName, KFilename, KErrNone)
    {
    }

/**
 * RTestMediaClientExternalDisplay::NewL
 */
RTestMediaClientExternalDisplay* RTestMediaClientExternalDisplay::NewL(const TDesC& aTestName)
    {
    RTestMediaClientExternalDisplay* self = new (ELeave) RTestMediaClientExternalDisplay(aTestName);
    return self;
    }

/**
 * RTestMediaClientExternalDisplay::DoTestStepPreambleL
 */
TVerdict RTestMediaClientExternalDisplay::DoTestStepPreambleL()
    {
    TidyFiles();

    TVerdict verdict = SetInitialConnectionType();
    if(verdict != EPass)
        {
        return verdict;
        }

    verdict = SetConnectionTypeNotification();
    if(verdict != EPass)
        {
        return verdict;
        }

    verdict = SetExternalDisplayControl();
    if(verdict != EPass)
        {
        return verdict;
        }
    
    return RTestVclnt2AviPlayerStep::DoTestStepPreambleL();
    }

TVerdict RTestMediaClientExternalDisplay::SetInitialConnectionType()
    {
    // Create a file as named in ini file. When external display test plugin is constructed it
    // checks to see what filenames exist and sets inital connection type as appropriate.
    // If string does not exist in ini file then plugin initialises with exetrnal display disconnected.
    if(GetStringFromConfig(iSectName, _L("initialExternalDisplayType"), iInitialExternalDisplayTypeFilename))
        {
        if(iInitialExternalDisplayTypeFilename.Compare(KInitExtDisplayHDMI) == 0)
            {
            INFO_PRINTF2(_L("Creating %S"), &iInitialExternalDisplayTypeFilename);
            INFO_PRINTF1(_L("External HDMI Display initially connected"));
            }
        else if(iInitialExternalDisplayTypeFilename.Compare(KInitExtDisplayAnalog) == 0)
            {
            INFO_PRINTF2(_L("Creating %S"), &iInitialExternalDisplayTypeFilename);
            INFO_PRINTF1(_L("External Analog Display initially connected"));
            }
        else
            {
            INFO_PRINTF2(_L("External display setting unkown, %S"), &iInitialExternalDisplayTypeFilename);
            return EInconclusive;
            }

        // connect to file system and open file
        RFs fs;
        if(fs.Connect() != KErrNone)
            {
            return EInconclusive;
            }
        RFile file;
        if(file.Replace(fs, iInitialExternalDisplayTypeFilename, EFileWrite) != KErrNone)
            {
            fs.Close();
            return EInconclusive;
            }
        
        file.Close();
        fs.Close();
        }
    else
        {
        INFO_PRINTF1(_L("External Display initially disconnected!"));
        }
    
    return EPass;
    }

TVerdict RTestMediaClientExternalDisplay::SetConnectionTypeNotification()
    {
    // Now create file for the next connection type. This is used to emit a connect or disocnnect notification
    // after a few seconds. Note that if the initial and next connection types are the same the external
    // display test plugin will not emit a notification.    
    if(GetStringFromConfig(iSectName, _L("nextExternalDisplayType"), iNextExternalDisplayTypeFilename))
        {
        if(iNextExternalDisplayTypeFilename.Compare(KConnectExtDisplayOverHDMI) == 0)
            {
            INFO_PRINTF2(_L("Creating %S"), &iNextExternalDisplayTypeFilename);
            INFO_PRINTF1(_L("External HDMI Display to be connected and notification emitted"));
            }
        else if(iNextExternalDisplayTypeFilename.Compare(KConnectExtDisplayOverAnalog) == 0)
            {
            INFO_PRINTF2(_L("Creating %S"), &iNextExternalDisplayTypeFilename);
            INFO_PRINTF1(_L("External Analog Display to be connected and notification emitted"));
            }
        else if(iNextExternalDisplayTypeFilename.Compare(KDisconnectExtDisplay) == 0)
            {
            INFO_PRINTF2(_L("Creating %S"), &iNextExternalDisplayTypeFilename);
            INFO_PRINTF1(_L("External Display to be disconnected and notification emitted"));
            }
        else
            {
            INFO_PRINTF2(_L("External display switch setting unkown, %S"), &iNextExternalDisplayTypeFilename);
            return EInconclusive;
            }

        // connect to file system and open file
        RFs fs;
        if(fs.Connect() != KErrNone)
            {
            return EInconclusive;
            }
        RFile file;
        if(file.Replace(fs, iNextExternalDisplayTypeFilename, EFileWrite) != KErrNone)
            {
            fs.Close();
            return EInconclusive;
            }
        
        file.Close();
        fs.Close();
        }
    else
        {
        INFO_PRINTF1(_L("No External Display switching requested!"));
        }
    
    return EPass;
    }

TVerdict RTestMediaClientExternalDisplay::SetExternalDisplayControl()
    {
    if(GetBoolFromConfig(iSectName, _L("externalDisplayControl"), iExternalDisplayControl))
        {
        INFO_PRINTF2(_L("External display switch control set to %d"), iExternalDisplayControl);
        }
    else
        {
        return EInconclusive;
        }
    return EPass;
    }
    
/**
 * RTestMediaClientExternalDisplay::DoTestStepPostambleL
 */
TVerdict RTestMediaClientExternalDisplay::DoTestStepPostambleL()
    {
    RFs fs;
    // connect to file system and open file
    User::LeaveIfError(fs.Connect());
    CleanupClosePushL(fs);
    
    if((iInitialExternalDisplayTypeFilename.Length()!= 0) && BaflUtils::FileExists(fs, iInitialExternalDisplayTypeFilename))
        {
        User::LeaveIfError(fs.Delete(iInitialExternalDisplayTypeFilename));
        }

    if((iNextExternalDisplayTypeFilename.Length()!= 0) && BaflUtils::FileExists(fs, iNextExternalDisplayTypeFilename))
        {
        User::LeaveIfError(fs.Delete(iNextExternalDisplayTypeFilename));
        }
    
    CleanupStack::PopAndDestroy(1); //fs
    
    return RTestVclnt2AviPlayerStep::DoTestStepPostambleL();        
    }

/**
 * RTestMediaClientExternalDisplay::FsmL
 */
void RTestMediaClientExternalDisplay::FsmL(TVclntTestPlayEvents aEventCode)
    {
    if (FsmCheck(aEventCode))
        {
        switch (aEventCode)
            {
            case EVPIdle:
                HandleIdleL();
                break;
                
            case EVPOpenComplete:
                HandleOpenCompleteL();
                break;
                
            case EVPPrepareComplete:                    
                HandlePrepareCompleteL();
                break;
                
            case EVPPlayComplete:
                HandlePlayCompleteL();
                break;
            }
        }
    }
    
void RTestMediaClientExternalDisplay::HandleIdleL()
    {
    // Open iVideoPlayer
    INFO_PRINTF2(_L("iVideoPlayer2->OpenFileL() %S"), &iFilename);
    iVideoPlayer2->OpenFileL(iFilename, KMmfTestAviPlayControllerUid);
    PrepareState(EVPOpenComplete, KErrNone);
    }

void RTestMediaClientExternalDisplay::HandleOpenCompleteL()
    {
    // Prepare iVideoPlayer2
    INFO_PRINTF1(_L("iVideoPlayer2->Prepare()"));
    iVideoPlayer2->Prepare();
    PrepareState(EVPPrepareComplete, KErrNone);
    }
    
void RTestMediaClientExternalDisplay::HandlePrepareCompleteL()
    {
    // Add display window using default values - ie. video extent & window clipping 
    // defaulted to whole window
    INFO_PRINTF1(_L("iVideoPlayer2->AddDisplayWindowL()"));
    iVideoPlayer2->AddDisplayWindowL(iWs, *iScreen, *iWindow);

    // set external display control
    iVideoPlayer2->SetExternalDisplaySwitchingL((*iScreen).GetScreenNumber(), iExternalDisplayControl);
    
    // trigger the video to start playing                
    StartPlayback();
    }

void RTestMediaClientExternalDisplay::HandlePlayCompleteL()
    {
    iTestStepResult = EPass;
    CActiveScheduler::Stop();
    }

void RTestMediaClientExternalDisplay::StartPlayback()
    {
    iError = KErrTimedOut;
    INFO_PRINTF1(_L("iVideoPlayer2->Play()"));
    PrepareState(EVPPlayComplete, KErrNone);
    iVideoPlayer2->Play();
    }

