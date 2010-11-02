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


#ifndef __MY_PLAYER__
#define __MY_PLAYER__

#include <AudioOutput.h>
#include "TelephonyAudioRouting.h"
#include <MTelephonyAudioRoutingObserver.h>
#include <MTelephonyAudioRoutingPolicyObserver.h>

#include "TelephonyAudioRoutingManager.h"



class CMyPlayer : public CBase,
                  public MTelephonyAudioRoutingPolicyObserver ,
                  public MTelephonyAudioRoutingObserver
    {
public:
    static CMyPlayer* NewL();
    void ConstructL();
    ~CMyPlayer();
    
    
public: 
    //For CTelephonyAudioRouting
    void SetOutputL();
    TInt SetShowNote();
    TInt GetShowNote();  
    
       
    
    //From MTelephonyAudioRoutingObserver
    virtual void AvailableOutputsChanged( CTelephonyAudioRouting& aTelephonyAudioRouting);
    virtual void OutputChanged( CTelephonyAudioRouting& aTelephonyAudioRouting);
    virtual void SetOutputComplete( CTelephonyAudioRouting& aTelephonyAudioRouting, TInt aError);
    
    // For CTelephonyAudioRoutingManager 
    void OutputChangedTARManager();
    void OutputChangeRequestCompleted();
    
    //From MTelephonyAudioRoutingPolicyObserver
    void OutputChangeRequested( CTelephonyAudioRoutingManager& aTelephonyAudioRoutingManager, CTelephonyAudioRouting::TAudioOutput aOutput) ;

    
private:
    CTelephonyAudioRouting* iTelephonyAudioRouting;
    CTelephonyAudioRoutingManager* iTelephonyAudioRoutingManager;
    
    };

#endif
