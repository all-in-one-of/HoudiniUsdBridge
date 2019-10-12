/*
 * PROPRIETARY INFORMATION.  This software is proprietary to
 * Side Effects Software Inc., and is not to be reproduced,
 * transmitted, or disclosed in any way without written permission.
 *
 * Produced by:
 *	Side Effects Software Inc.
 *	123 Front Street West, Suite 1401
 *	Toronto, Ontario
 *      Canada   M5J 2M2
 *	416-504-9876
 *
 */

#ifndef __HUSD_CvexDataInputs__
#define __HUSD_CvexDataInputs__

#include "HUSD_API.h"
#include <VEX/VEX_GeoInputs.h>
#include <UT/UT_Array.h>
class HUSD_AutoAnyLock;
class HUSD_DataHandle;

/// Class to query an input on a VEX usd geometry (stage).
class HUSD_API HUSD_CvexDataInputs : public VEX_GeoInputs
{
public:
             HUSD_CvexDataInputs();
    virtual ~HUSD_CvexDataInputs();

    /// Adds the input data lock to the inputs array.
    void     setInputData(int idx, HUSD_AutoAnyLock *data);

    /// Creates a read lock for the given data, and adds it to the input array.
    void     setInputData(int idx, const HUSD_DataHandle &data);

    /// Removes a specific data lock from the inputs array
    void     removeInputData(int idx);

    /// Removes all the data locks from the inputs array
    void     removeAllInputData();

    /// Returns a data lock (may be null) for a given input index. 
    HUSD_AutoAnyLock *getInputData(int idx) const;

private:
    UT_Array<HUSD_AutoAnyLock *>    myDataLockArray;
    UT_Array<HUSD_DataHandle *>     myDataHandleArray;
    UT_Array<bool>                  myIsOwned;
};

#endif
