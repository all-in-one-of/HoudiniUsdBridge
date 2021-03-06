/*
 * Copyright 2019 Side Effects Software Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Produced by:
 *	Side Effects Software Inc
 *	123 Front Street West, Suite 1401
 *	Toronto, Ontario
 *	Canada   M5J 2M2
 *	416-504-9876
 *
 * NAME:	HUSD_HydraCamera.h (HUSD Library, C++)
 *
 * COMMENTS:	Container for GT prim repr of a hydro geometry  prim (HdRprim)
 */
#ifndef HUSD_HydraCamera_h
#define HUSD_HydraCamera_h

#include <pxr/pxr.h>

#include "HUSD_API.h"
#include "HUSD_HydraPrim.h"

#include <SYS/SYS_Types.h>
#include <UT/UT_StringHolder.h>

class HUSD_Scene;

PXR_NAMESPACE_OPEN_SCOPE
class XUSD_HydraCamera;
class TfToken;
class SdfPath;
PXR_NAMESPACE_CLOSE_SCOPE

/// Container for hydra camera (hdSprim)
class HUSD_API HUSD_HydraCamera : public HUSD_HydraPrim
{
public:
	     HUSD_HydraCamera(PXR_NS::TfToken const& typeId,
			      PXR_NS::SdfPath const& primId,
			      HUSD_Scene &scene);
    virtual ~HUSD_HydraCamera();

    PXR_NS::XUSD_HydraCamera	*hydraCamera() const { return myHydraCamera; }

    HUSD_PARM(Aperture, fpreal);
    HUSD_PARM(ApertureOffsets, UT_Vector2D);
    HUSD_PARM(AspectRatio, fpreal);
    HUSD_PARM(FocusDistance, fpreal);
    HUSD_PARM(FocalLength, fpreal);
    HUSD_PARM(FStop, fpreal);
    HUSD_PARM(NearClip, fpreal);
    HUSD_PARM(FarClip, fpreal);
    HUSD_PARM(Projection, UT_StringHolder);
    
private:
    fpreal	myAperture;
    UT_Vector2D myApertureOffsets;
    fpreal	myAspectRatio;
    fpreal	myFocusDistance;
    fpreal	myFocalLength;
    fpreal	myFStop;
    fpreal	myNearClip;
    fpreal	myFarClip;
    UT_StringHolder myProjection;
    
    PXR_NS::XUSD_HydraCamera	*myHydraCamera;
};

#endif
