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
 *	Side Effects Software Inc.
 *	123 Front Street West, Suite 1401
 *	Toronto, Ontario
 *      Canada   M5J 2M2
 *	416-504-9876
 *
 */

#ifndef __HUSD_EditVariants_h__
#define __HUSD_EditVariants_h__

#include "HUSD_API.h"
#include "HUSD_DataHandle.h"
#include <UT/UT_StringHolder.h>

class HUSD_FindPrims;

class HUSD_API HUSD_EditVariants
{
public:
			 HUSD_EditVariants(HUSD_AutoWriteLock &lock);
			~HUSD_EditVariants();

    bool		 setVariant(const HUSD_FindPrims &findprims,
				const UT_StringRef &variantset,
				const UT_StringRef &variantname,
                                int variantsetindex = -1,
                                int variantnameindex = -1);

private:
    HUSD_AutoWriteLock	&myWriteLock;
};

#endif

