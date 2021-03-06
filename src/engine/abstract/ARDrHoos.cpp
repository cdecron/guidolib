/*
  GUIDO Library
  Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
  Copyright (C) 2002-2013 Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#include <iostream>
#include "ARDrHoos.h"
// #include "ARFactory.h"
#include "TagParameterInt.h"
#include "ListOfStrings.h"
#include "TagParameterList.h"

ListOfTPLs ARDrHoos::ltpls(1);

ARDrHoos::ARDrHoos(int p_inv)
{
	inverse = p_inv;
}

ARDrHoos::~ARDrHoos()
{
}

void ARDrHoos::setTagParameterList(TagParameterList & tpl)
{
	if (ltpls.GetCount() == 0)
	{
		// create a list of string ...

		ListOfStrings lstrs; // (1); std::vector test impl
		lstrs.AddTail(
			(
			"I,inverse,0,o"));
		CreateListOfTPLs(ltpls,lstrs);

	}

	TagParameterList *rtpl = NULL;
	int ret = MatchListOfTPLsWithTPL(ltpls,tpl,&rtpl);

	if (ret>=0 && rtpl)
	{
		// we found a match!
		if (ret == 0)
		{
			// then, we now the match for
			// the first ParameterList
			// w, h, ml, mt, mr, mb
			GuidoPos pos = rtpl->GetHeadPosition();

			TagParameterInt * tpi =TagParameterInt::cast(rtpl->GetNext(pos));
			assert(tpi);

			if (tpi->pflag != TagParameter::NOTSET)
				inverse = tpi->getValue();
		}

		delete rtpl;
	}
	else
	{
		// failure
	}

	tpl.RemoveAll();

}

void ARDrHoos::printName(std::ostream& os) const
{
    os << "ARDrHoos";
}

void ARDrHoos::printGMNName(std::ostream& os) const
{
    os << "\\drHoos";
}

void ARDrHoos::printParameters(std::ostream& os) const
{
    ARMusicalTag::printParameters(os);
}
