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
* Description:  build_help.mk
* This make file will build the application help file (.hlp)
*/


do_nothing :
	@rem do_nothing

# build the help from the MAKMAKE step so the header file generated
# will be found by cpp.exe when calculating the dependency information
# in the mmp makefiles.

MAKMAKE : MyPlayer_0xE0EDBE14.hlp
MyPlayer_0xE0EDBE14.hlp : MyPlayer.xml MyPlayer.cshlp Custom.xml
	cshlpcmp MyPlayer.cshlp
ifeq (WINS,$(findstring WINS, $(PLATFORM)))
	copy MyPlayer_0xE0EDBE14.hlp $(EPOCROOT)epoc32\$(PLATFORM)\c\resource\help
endif

BLD : do_nothing

CLEAN :
	del MyPlayer_0xE0EDBE14.hlp
	del MyPlayer_0xE0EDBE14.hlp.hrh

LIB : do_nothing

CLEANLIB : do_nothing

RESOURCE : do_nothing
		
FREEZE : do_nothing

SAVESPACE : do_nothing

RELEASABLES :
	@echo MyPlayer_0xE0EDBE14.hlp

FINAL : do_nothing
