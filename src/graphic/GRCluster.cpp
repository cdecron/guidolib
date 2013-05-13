/*
GUIDO Library
Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include "GRCluster.h"
#include "GRStaff.h"

#include "ARCluster.h"

#include "VGDevice.h"
#include "GRTagARNotationElement.h"
#include "GRSingleNote.h"
#include "ARNoteFormat.h"
#include "TagParameterString.h"

GRCluster::GRCluster(GRStaff * stf, ARCluster * arcls, TYPE_DURATION inDuration, ARNoteFormat * curnoteformat) :
						GRARCompositeNotationElement(arcls),
						GRPositionTag(arcls->getEndPosition(), arcls), mHaveBeenDrawn(false), mStaff(stf), mARCluster(arcls), mDuration(inDuration)
{
	assert(stf);
	GRSystemStartEndStruct * sse = new GRSystemStartEndStruct;
	sse->grsystem = stf->getGRSystem();
	sse->startflag = GRSystemStartEndStruct::LEFTMOST;

	sse->p = (void *) getNewGRSaveStruct();

	mStartEndList.AddTail(sse);

    if (curnoteformat)
    {
        const TagParameterString * tmps = curnoteformat->getColor();
        if (tmps)
        {
            if (!mColRef)
                mColRef = new unsigned char[4];
            tmps->getRGB(mColRef);
        }
    }

    gdx = arcls->getadx();
    gdy = arcls->getady();
    
    int *firstNoteParameters = mARCluster->getFirstNoteParameters();

    mFirstNoteYPosition = stf->getNotePosition(firstNoteParameters[0], firstNoteParameters[1]);
    mSecondNoteYPosition = mFirstNoteYPosition;
}

GRCluster::~GRCluster() {}

void GRCluster::OnDraw(VGDevice &hdc)
{
    if (mHaveBeenDrawn == false)
    {
        const VGColor prevTextColor = hdc.GetFontColor();
        if (mColRef)
            hdc.SelectFillColor(VGColor(mColRef));

        if (mFirstNoteYPosition != mSecondNoteYPosition)
            mHaveBeenDrawn = true;

        NVRect r = getBoundingBox();
        r += getPosition();

        float x = r.left + gdx;

        float curLSpace = mStaff->getStaffLSPACE();

        // - Quarter notes and less
        if (mDuration < DURATION_2 )
        {
            const float xCoords [] = {x - 31, x + 29, x + 29, x - 31};
            const float yCoords [] = {mFirstNoteYPosition + gdy - curLSpace / 2, mFirstNoteYPosition + gdy - curLSpace / 2,
                mSecondNoteYPosition + gdy + curLSpace / 2, mSecondNoteYPosition + gdy + curLSpace / 2};

            hdc.Polygon(xCoords, yCoords, 4);
        }
        else
        {
            const float xCoords1 [] = {x - 31, x + 29, x + 29, x - 31};
            const float yCoords1 [] = {mFirstNoteYPosition + gdy - curLSpace / 2, mFirstNoteYPosition + gdy - curLSpace / 2,
                mFirstNoteYPosition + gdy - curLSpace / 2 + 6, mFirstNoteYPosition + gdy - curLSpace / 2 + 6};
            const float xCoords2 [] = {x + 23, x + 29, x + 29, x + 23};
            const float yCoords2 [] = {mFirstNoteYPosition + gdy - curLSpace / 2, mFirstNoteYPosition + gdy - curLSpace / 2,
                mSecondNoteYPosition + gdy + curLSpace / 2, mSecondNoteYPosition + gdy + curLSpace / 2};
            const float xCoords3 [] = {x - 31, x + 29, x + 29, x - 31};
            const float yCoords3 [] = {mSecondNoteYPosition + gdy + curLSpace / 2 - 6, mSecondNoteYPosition + gdy + curLSpace / 2 - 6,
                mSecondNoteYPosition + gdy + curLSpace / 2, mSecondNoteYPosition + gdy + curLSpace / 2};
            const float xCoords4 [] = {x - 31, x -25, x - 25, x - 31};
            const float yCoords4 [] = {mFirstNoteYPosition + gdy - curLSpace / 2, mFirstNoteYPosition + gdy - curLSpace / 2,
                mSecondNoteYPosition + gdy + curLSpace / 2, mSecondNoteYPosition + gdy + curLSpace / 2};

            hdc.Polygon(xCoords1, yCoords1, 4);
            hdc.Polygon(xCoords2, yCoords2, 4);
            hdc.Polygon(xCoords3, yCoords3, 4);
            hdc.Polygon(xCoords4, yCoords4, 4);
        }

        // - Restore context
        if (mColRef)
            hdc.SelectFillColor(prevTextColor);  //(TODO: in a parent method)
    }
    else
        mHaveBeenDrawn = false;
}

void GRCluster::addAssociation(GRNotationElement *p)
{
	GRARCompositeNotationElement::addAssociation(p);
}

GuidoPos GRCluster::AddTail(GRNotationElement * el)
{
	GuidoPos mypos = GRARCompositeNotationElement::AddTail(el);

	// now, we remove the associatons ...
	// of those elements, that are members of 
	// the composite-sructure ...

	GuidoPos elpos = NULL;
	if (mAssociated && (elpos = mAssociated->GetElementPos(el)) != NULL)
	{
		mAssociated->RemoveElementAt(elpos);
	}

	return mypos;
}

//-------------------------------------------------------------------
void GRCluster::tellPosition(GObject * caller, const NVPoint & np)
{
	GREvent *ev = dynamic_cast<GREvent *>(caller);
	
    if (ev)
	{
        NVPoint newPoint (np);
        newPoint.y = -LSPACE;

        setPosition(newPoint);
	}
}

void GRCluster::setSecondNoteYPosition()
{
    int *secondNoteParameters = mARCluster->getSecondNoteParameters();

    mSecondNoteYPosition = mStaff->getNotePosition(secondNoteParameters[0], secondNoteParameters[1]);

    if (mFirstNoteYPosition > mSecondNoteYPosition)
    {
        float tmpSwitch = mSecondNoteYPosition;
        mSecondNoteYPosition = mFirstNoteYPosition;
        mFirstNoteYPosition = tmpSwitch;
    }
}