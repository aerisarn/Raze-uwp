#pragma once

// included by game.h

BEGIN_SW_NS


class DSWActor : public DCoreActor
{
	DECLARE_CLASS(DSWActor, DCoreActor)
	HAS_OBJECT_POINTERS

public:

	bool hasUser;
	USER user;
	walltype* tempwall;	// transient, to replace a hack using a 16 bit sprite field.
	TObjPtr<DSWActor*> ownerActor;

	DSWActor() = default;

	bool hasU() { return hasUser; }


	void allocUser() 
	{ 
		hasUser = true;
	}

	void clearUser()
	{
		hasUser = false;
		user.Clear();
	}

	void Serialize(FSerializer& arc) override;
};

inline void UpdateChangeXY(DSWActor* actor)
{
	actor->user.change.X = MOVEx(actor->spr.xvel, actor->int_ang());
	actor->user.change.Y = MOVEy(actor->spr.xvel, actor->int_ang());
}

inline void UpdateChange(DSWActor* actor, double zfactor = 1.0)
{
	UpdateChangeXY(actor);
	actor->user.change.Z = int(actor->spr.zvel * zfactor);
}


// subclassed to add a game specific actor() method

// Iterator wrappers that return an actor pointer, not an index.
using SWStatIterator = TStatIterator<DSWActor>;
using SWSectIterator = TSectIterator<DSWActor>;
using SWSpriteIterator = TSpriteIterator<DSWActor>;


END_SW_NS
