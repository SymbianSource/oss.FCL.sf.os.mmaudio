// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/sfl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

/**
 @file
 @internalComponent
*/

#include "mmfmediaclientextdisplaytestprovider.h"
#include "mmfmediaclientextdisplaytesttrace.h"

#include <f32file.h>
#include <bautils.h>

static const TInt KExternalDisplayTestNumber = 0;

_LIT(KInitExtDisplayHDMI, "C:\\vclntavi\\InitExtDisplayHDMI.txt");
_LIT(KInitExtDisplayAnalog, "C:\\vclntavi\\InitExtDisplayAnalog.txt");
_LIT(KConnectExtDisplayOverHDMI, "C:\\vclntavi\\ConnectExtDisplayOverHDMI.txt");
_LIT(KConnectExtDisplayOverAnalog, "C:\\vclntavi\\ConnectExtDisplayOverAnalog.txt");
_LIT(KDisconnectExtDisplay, "C:\\vclntavi\\DisconnectExtDisplay.txt");

CExtDisplayTestConnectionProvider* CExtDisplayTestConnectionProvider::NewL()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::NewL +++");
    CExtDisplayTestConnectionProvider* self = new(ELeave) CExtDisplayTestConnectionProvider();
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::NewL ---");
    return self;
    }

CExtDisplayTestConnectionProvider::CExtDisplayTestConnectionProvider()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::CExtDisplayTestConnectionProvider +++");
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::CExtDisplayTestConnectionProvider ---");
    }

void CExtDisplayTestConnectionProvider::ConstructL()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ConstructL +++");
    
    ReadConnectionInfoL();
    InitialiseConnectionChangeTimerL();
   
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ConstructL ---");
    }

CExtDisplayTestConnectionProvider::~CExtDisplayTestConnectionProvider()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::~CExtDisplayTestConnectionProvider +++");
    
    if(iExtDisplayConnectionTimer != NULL)
        {
        iExtDisplayConnectionTimer->Cancel();
        delete iExtDisplayConnectionTimer;
        }
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::~CExtDisplayTestConnectionProvider ---");
    }

TExtDisplayConnectionProviderConnType CExtDisplayTestConnectionProvider::ExtDisplayConnType()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ExtDisplayConnType +++");
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ExtDisplayConnType ---");
    return iInitialConnectionType;
    }

TInt CExtDisplayTestConnectionProvider::ExtDisplayId()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ExtDisplayId +++");
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ExtDisplayId ---");
    return KExternalDisplayTestNumber;
    }

void CExtDisplayTestConnectionProvider::SetExtDisplayConnectionProviderCallback(MExtDisplayConnectionProviderCallback& aCallback)
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::SetExtDisplayConnectionProviderCallback +++");
    
    iCallback = &aCallback;
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::SetExtDisplayConnectionProviderCallback ---");
    }

void CExtDisplayTestConnectionProvider::ReadConnectionInfoL()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ReadConnectionInfoL +++");

    RFs fs;
    User::LeaveIfError(fs.Connect());
    CleanupClosePushL(fs);

    // determine initial connection type
    if(BaflUtils::FileExists(fs, KInitExtDisplayHDMI))
        {
        iInitialConnectionType = EExtDisplayConnectionProviderConnTypeHdmi;
        }
    else if(BaflUtils::FileExists(fs, KInitExtDisplayAnalog))
        {
        iInitialConnectionType = EExtDisplayConnectionProviderConnTypeAnalog;
        }
    else
        {
        iInitialConnectionType = EExtDisplayConnectionProviderConnTypeDisconnected;
        }

    // determine change connection type
    if(BaflUtils::FileExists(fs, KConnectExtDisplayOverHDMI))
        {
        iConnectionTypeToBeNotified = EExtDisplayConnectionProviderConnTypeHdmi;
        }
    else if(BaflUtils::FileExists(fs, KConnectExtDisplayOverAnalog))
        {
        iConnectionTypeToBeNotified = EExtDisplayConnectionProviderConnTypeAnalog;
        }
    else if(BaflUtils::FileExists(fs, KDisconnectExtDisplay))
        {
        iConnectionTypeToBeNotified = EExtDisplayConnectionProviderConnTypeDisconnected;
        }
    else
        {
        iConnectionTypeToBeNotified = iInitialConnectionType;
        }

    CleanupStack::PopAndDestroy(1, &fs);
    
    DEBUG_PRINTF3("CExtDisplayTestConnectionProvider::ReadConnectionInfoL Initial = %d, Next = %d",
            iInitialConnectionType, iConnectionTypeToBeNotified);    
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::ReadConnectionInfoL ---");
    }

void CExtDisplayTestConnectionProvider::InitialiseConnectionChangeTimerL()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::InitialiseConnectionChangeTimerL +++");

    if(iInitialConnectionType != iConnectionTypeToBeNotified)
        {
        iExtDisplayConnectionTimer = CExtDisplayConnectionTimer::NewL(this, 2000000);
        iExtDisplayConnectionTimer->Start();
        }
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::InitialiseConnectionChangeTimerL ---");
    }

void CExtDisplayTestConnectionProvider::TimerExpired()
    {
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::TimerExpired +++");

    iCallback->MedcpcExtDisplayNotifyConnected(iConnectionTypeToBeNotified);
    
    DEBUG_PRINTF("CExtDisplayTestConnectionProvider::TimerExpired ---");
    }


CExtDisplayConnectionTimer* CExtDisplayConnectionTimer::NewL(CExtDisplayTestConnectionProvider* aParent, TTimeIntervalMicroSeconds32 aInterval)
    {
    DEBUG_PRINTF("CExtDisplayConnectionTimer::NewL +++");

    CExtDisplayConnectionTimer* self = new (ELeave) CExtDisplayConnectionTimer(aParent, aInterval);
    CleanupStack::PushL(self);
    self->ConstructL(); // inherited
    CleanupStack::Pop(self);

    DEBUG_PRINTF("CExtDisplayConnectionTimer::NewL ---");
    return self;    
    }
    
CExtDisplayConnectionTimer::CExtDisplayConnectionTimer(CExtDisplayTestConnectionProvider* aParent, TTimeIntervalMicroSeconds32 aInterval)
    : CTimer(EPriorityNormal), iParent(aParent), iInterval(aInterval)
    {
    DEBUG_PRINTF("CExtDisplayConnectionTimer::CExtDisplayConnectionTimer +++");

    CActiveScheduler::Add(this);
    
    DEBUG_PRINTF("CExtDisplayConnectionTimer::CExtDisplayConnectionTimer ---");
    }
    
void CExtDisplayConnectionTimer::Start()
    {
    DEBUG_PRINTF("CExtDisplayConnectionTimer::Start +++");
    
    After(iInterval);
    
    DEBUG_PRINTF("CExtDisplayConnectionTimer::Start ---");
    }

void CExtDisplayConnectionTimer::RunL()
    {        
    DEBUG_PRINTF("CExtDisplayConnectionTimer::RunL +++");

    iParent->TimerExpired();

    DEBUG_PRINTF("CExtDisplayConnectionTimer::RunL ---");

    }
