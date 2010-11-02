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


#include "myplayer.h"
#include "StreamControlCustomCommandsParser.h"

CMyPlayer* CMyPlayer::NewL()
    {
    CMyPlayer* self = new(ELeave) CMyPlayer;
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    return self;
    }
void CMyPlayer::ConstructL()
    {
    iTelephonyAudioRouting = CTelephonyAudioRouting::NewL(*this);
    
    RArray<CTelephonyAudioRouting::TAudioOutput> availableoutputs;
    availableoutputs.Append(CTelephonyAudioRouting::ENone);
    availableoutputs.Append(CTelephonyAudioRouting::ELoudspeaker);
    iTelephonyAudioRoutingManager = CTelephonyAudioRoutingManager::NewL(*this,availableoutputs.Array());
        
    }

CMyPlayer::~CMyPlayer()
    {
    RDebug::Printf("CMdaAudioPlayerUtility:CMyPlayer::~CMyPlayer");
    if (iTelephonyAudioRoutingManager)
      {
      delete iTelephonyAudioRoutingManager;
      iTelephonyAudioRoutingManager = NULL;
      }
    
    if (iTelephonyAudioRouting)
        {
        delete iTelephonyAudioRouting;
        iTelephonyAudioRouting = NULL;
        }
    }

void CMyPlayer::SetOutputL()
    {
    TInt error = KErrNone;
    CTelephonyAudioRouting::TAudioOutput output(CTelephonyAudioRouting::ENotActive);
          
    TRAP(error,iTelephonyAudioRouting->SetOutputL(output)); 
    if (error == KErrNone)
        {
        RDebug::Printf("iTelephonyAudioRoutingProxy/SetOutputL - err=%d",error);
        }
    else
        {
        RDebug::Printf("iTelephonyAudioRoutingProxy/SetOutputL - err-else=%d",error);
        }
         
    }

void CMyPlayer::AvailableOutputsChanged( CTelephonyAudioRouting& aTelephonyAudioRouting)
{
    RDebug::Printf("AvailableOutputsChanged");
}
void CMyPlayer::OutputChanged( CTelephonyAudioRouting& aTelephonyAudioRouting)
{
    RDebug::Printf("OutputChanged");
}
void CMyPlayer::SetOutputComplete( CTelephonyAudioRouting& aTelephonyAudioRouting, TInt aError)
{
    RDebug::Printf("SetOutputComplete");
}

TInt CMyPlayer::SetShowNote()
{
    TBool aMode= ETrue;
    TRAPD(error,iTelephonyAudioRouting->SetShowNote(aMode));
    if (error == KErrNone)
            {
            RDebug::Printf("SetShowNote - err=%d",error);
            }
        else
            {
            RDebug::Printf("SetShowNote - err-else=%d",error);
            }
    
}
TInt CMyPlayer::GetShowNote()
    {
       TBool aMode= ETrue;
       TRAPD(error,iTelephonyAudioRouting->GetShowNote(aMode));
       if (error == KErrNone)
               {
               RDebug::Printf("GetShowNote - err=%d",error);
               }
           else
               {
               RDebug::Printf("GetShowNote - err-else=%d",error);
               }
    }


void CMyPlayer::OutputChangedTARManager()
    {
    RDebug::Printf("Enter OutputChangedTARManager");
    CTelephonyAudioRouting::TAudioOutput output(CTelephonyAudioRouting::EHandset);
    iTelephonyAudioRoutingManager->OutputChanged(output);
    RDebug::Printf("Exit OutputChangedTARManager");
    }
void CMyPlayer::OutputChangeRequestCompleted()
    {
    RDebug::Printf("Enter OutputChangeRequestCompleted");
    TInt error=KErrNone;
    CTelephonyAudioRouting::TAudioOutput output(CTelephonyAudioRouting::ELoudspeaker);
    iTelephonyAudioRoutingManager->OutputChangeRequestCompleted(output,error);
    RDebug::Printf("Exit OutputChangeRequestCompleted");
    }
void CMyPlayer::OutputChangeRequested( CTelephonyAudioRoutingManager& aTelephonyAudioRoutingManager, CTelephonyAudioRouting::TAudioOutput aOutput) 
    {
    RDebug::Printf("OutputChangeRequested");
    }
