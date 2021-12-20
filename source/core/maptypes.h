//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2020, 2021 - Christoph Oelckers

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------
#pragma once

#include <stdint.h>
#include "ns.h"
#include "tarray.h"
#include "tflags.h"

//=============================================================================
//
// Constants
//
//=============================================================================

// the various portal types
enum EPortalBits
{
	PORTAL_SECTOR_FLOOR				= 1,
	PORTAL_SECTOR_CEILING			= 2,
	PORTAL_SECTOR_FLOOR_REFLECT		= 3,
	PORTAL_SECTOR_CEILING_REFLECT	= 4,
	PORTAL_WALL_VIEW				= 5,
	PORTAL_WALL_MIRROR				= 6,
	PORTAL_WALL_TO_SPRITE			= 7,
	PORTAL_SECTOR_GEOMETRY			= 8,
};

// Original Build sector bit flags.
enum ESectorBits
{
	CSTAT_SECTOR_SKY				= 1,
	CSTAT_SECTOR_SLOPE				= 2,
	CSTAT_SECTOR_SWAPXY				= 4,
	CSTAT_SECTOR_TEXHALF			= 8,
	CSTAT_SECTOR_XFLIP				= 16,
	CSTAT_SECTOR_YFLIP				= 32,
	CSTAT_SECTOR_ALIGN				= 64,
	CSTAT_SECTOR_TRANS				= 128,
	CSTAT_SECTOR_TRANS_INVERT		= 256,
	CSTAT_SECTOR_METHOD				= 384,
	CSTAT_SECTOR_FAF_BLOCK_HITSCAN	= 32768,	// SW only

	CSTAT_SECTOR_EXHUMED_BIT1			= 1 << 14,
	CSTAT_SECTOR_EXHUMED_BIT2			= 1 << 15,

	CSTAT_SECTOR_NO_CEILINGSHADE	= 32768,	// Blood: Force use of floorshade for sprites, even in sky sectors.

};

typedef TFlags<ESectorBits, uint16_t> ESectorFlags;
DEFINE_TFLAGS_OPERATORS(ESectorFlags)


// Extended sector bit flags.
enum ESectorExBits
{
	SECTOREX_CLOUDSCROLL			= 1,
};

// Flags for retriangulation
enum EDirty
{
	FloorDirty		= 1,
	CeilingDirty	= 2,
	GeometryDirty	= 4,
	AllDirty		= 7
};

enum EWallBits // names are from Shadow Warrior
{
	CSTAT_WALL_BLOCK				= 1,			//   bit 0: 1 = Blocking wall (use with clipmove, getzrange)         "B"
	CSTAT_WALL_BOTTOM_SWAP			= 2,			//   bit 1: 1 = bottoms of invisible walls swapped, 0 = not          "2"
	CSTAT_WALL_ALIGN_BOTTOM			= 4,			//   bit 2: 1 = align picture on bottom (for doors), 0 = top         "O"
	CSTAT_WALL_XFLIP				= 8,			//   bit 3: 1 = x-flipped, 0 = normal                                "F"
	CSTAT_WALL_MASKED				= 16,			//   bit 4: 1 = masking wall, 0 = not                                "M"
	CSTAT_WALL_1WAY					= 32,			//   bit 5: 1 = 1-way wall, 0 = not                                  "1"
	CSTAT_WALL_BLOCK_HITSCAN		= 64,			//   bit 6: 1 = Blocking wall (use with hitscan / cliptype 1)        "H"
	CSTAT_WALL_TRANSLUCENT			= 128,			//   bit 7: 1 = Transluscence, 0 = not                               "T"
	CSTAT_WALL_YFLIP				= 256,			//   bit 8: 1 = y-flipped, 0 = normal                                "F"
	CSTAT_WALL_TRANS_FLIP			= 512,			//   bit 9: 1 = Transluscence reversing, 0 = normal                  "T"
	CSTAT_WALL_ANY_EXCEPT_BLOCK		= 254,			// Duke stupidity

	CSTAT_WALL_ROTATE_90			= 1<<12,		// EDuke32 extension supported by Raze

	CSTAT_WALL_BLOCK_ACTOR			= 1<<14,		// SW specific.
	CSTAT_WALL_WARP_HITSCAN			= 1<<15,		// SW specific.

	CSTAT_WALL_MOVE_FORWARD			= 1 << 14,		// Blood specific
	CSTAT_WALL_MOVE_BACKWARD		= 1 << 15,		// Blood specific
	CSTAT_WALL_MOVE_MASK			= CSTAT_WALL_MOVE_FORWARD | CSTAT_WALL_MOVE_BACKWARD

};

typedef TFlags<EWallBits, uint16_t> EWallFlags;
DEFINE_TFLAGS_OPERATORS(EWallFlags)

enum ESpriteBits // names mostly from SW.
{
	CSTAT_SPRITE_BLOCK				= 1,			//   bit 0: 1 = Blocking sprite (use with clipmove, getzrange)       "B"
	CSTAT_SPRITE_TRANSLUCENT		= 2,			//   bit 1: 1 = transluscence, 0 = normal                            "T"
	CSTAT_SPRITE_XFLIP				= 4,			//   bit 2: 1 = x-flipped, 0 = normal                                "F"
	CSTAT_SPRITE_YFLIP				= 8,			//   bit 3: 1 = y-flipped, 0 = normal                                "F"

	CSTAT_SPRITE_ALIGNMENT_FACING	= 0,			//   bits 5-4: 00 = FACE sprite (default)                            "R"
	CSTAT_SPRITE_ALIGNMENT_WALL		= 16,			//             01 = WALL sprite (like masked walls)
	CSTAT_SPRITE_ALIGNMENT_FLOOR	= 32,			//             10 = FLOOR sprite (parallel to ceilings&floors)
	CSTAT_SPRITE_ALIGNMENT_SLAB		= 48,			//             11 = either voxel or slope sprite, depending on the situation
	CSTAT_SPRITE_ALIGNMENT_SLOPE	= 48,
	CSTAT_SPRITE_ALIGNMENT_MASK		= 48,
	
	CSTAT_SPRITE_ONE_SIDE			= 64,			//   bit 6: 1 = 1-sided sprite, 0 = normal                           "1"
	CSTAT_SPRITE_YCENTER			= 128,			//   bit 7: 1 = Real centered centering, 0 = foot center             "C"
	CSTAT_SPRITE_BLOCK_HITSCAN		= 256,			//   bit 8: 1 = Blocking sprite (use with hitscan / cliptype 1)      "H"
	CSTAT_SPRITE_TRANS_FLIP			= 512,			//   bit 9: 1 = Transluscence reversing, 0 = normal                  "T"

	CSTAT_SPRITE_BLOCK_ALL			= CSTAT_SPRITE_BLOCK_HITSCAN | CSTAT_SPRITE_BLOCK, // 257
	CSTAT_SPRITE_INVISIBLE = 32768,		//   bit 15: 1 = Invisible sprite, 0 = not invisible

	// SW flags
	CSTAT_SPRITE_RESTORE			= 1<<12, 
	CSTAT_SPRITE_CLOSE_FLOOR		= 1<<13, //tells whether a sprite started out close to a ceiling or floor
	CSTAT_SPRITE_BLOCK_MISSILE		= 1<<14, 
	CSTAT_SPRITE_BREAKABLE			= CSTAT_SPRITE_BLOCK_HITSCAN|CSTAT_SPRITE_BLOCK_MISSILE,

	// Blood flags
	CSTAT_SPRITE_BLOOD_BIT2			= 1024, // Both of these get set but not checked directly, so no idea what they mean...
	CSTAT_SPRITE_BLOOD_BIT1			= 4096,
	CSTAT_SPRITE_MOVE_FORWARD		= 8192,
	CSTAT_SPRITE_MOVE_REVERSE		= 16384,
	CSTAT_SPRITE_MOVE_MASK			= CSTAT_SPRITE_MOVE_FORWARD | CSTAT_SPRITE_MOVE_REVERSE,
};

typedef TFlags<ESpriteBits, uint16_t> ESpriteFlags;
DEFINE_TFLAGS_OPERATORS(ESpriteFlags)

enum ESpriteBits2
{
	CSTAT2_SPRITE_MDLROTATE = 1,   // Only for tsprites: rotate if this is a model or voxel.
	CSTAT2_SPRITE_NOFIND = 2,      // Invisible to neartag and hitscan
	CSTAT2_SPRITE_MAPPED = 4,      // sprite was mapped for automap
	CSTAT2_SPRITE_SLOPE = 8,       // Only for tsprites: render as sloped sprite

};

//=============================================================================
//
// external references
//
//=============================================================================


// For Blood we need to pull in some game specific references.
BEGIN_BLD_NS
	struct XWALL;
	struct XSECTOR;
END_BLD_NS

class DCoreActor;
struct walltype;

//=============================================================================
//
// internal sector struct - no longer identical with on-disk format
//
//=============================================================================

struct sectortype
{
	// Fields were reordered by size, some also enlarged.
	DCoreActor* firstEntry, * lastEntry;
	
	int32_t wallptr;
	int32_t ceilingz;
	int32_t floorz;
	
	// panning byte fields were promoted to full floats to enable panning interpolation.
	float ceilingxpan_;
	float ceilingypan_;
	float floorxpan_;
	float floorypan_;

	int16_t wallnum;
	ESectorFlags ceilingstat;
	ESectorFlags floorstat;
	int16_t ceilingpicnum;
	int16_t ceilingheinum;
	int16_t floorpicnum;
	int16_t floorheinum;
	union { int16_t lotag, type; }; // type is for Blood.
	int16_t hitag;
	int16_t extra;
	
	int8_t ceilingshade;
	uint8_t ceilingpal;
	int8_t floorshade;
	uint8_t floorpal;;
	uint8_t visibility;
	uint8_t fogpal; // EDuke32 extension - was originally a filler byte

	// new additions not from the binary map format.
	uint8_t dirty;
	uint8_t exflags;
	uint8_t portalflags;
	int8_t portalnum;

	// Game specific extensions. Due to how sectors are used they need to be defined in the global class. :(
	union
	{
		struct // DukeRR
		{
			uint8_t keyinfo; // This was originally the repurposed filler byte.
			uint8_t shadedsector;
			TObjPtr<DCoreActor*> hitagactor;    // we need this because Duke stores an actor in the hitag field. Is really a DDukeActor, but cannot be declared here safely.
		};
		struct // Blood
		{
			BLD_NS::XSECTOR* _xs;
			TObjPtr<DCoreActor*> upperLink;
			TObjPtr<DCoreActor*> lowerLink;
			int baseFloor;
			int baseCeil;
			int velFloor;
			int velCeil;
			uint8_t slopewallofs; // This was originally the repurposed filler byte.
		};
		struct // Exhumed
		{
			sectortype* pSoundSect;
			sectortype* pAbove;
			sectortype* pBelow;
			int   Depth;
			short Sound;
			short Flag;
			short Damage;
			short Speed;
		};
		struct // SW
		{
			// No need to allocate this on demand as it is smaller than what Blood needs.
			int flags;
			int depth_fixed;
			short stag;    // ST? tag number - for certain things it helps to know it
			short ang;
			short height;
			short speed;
			short damage;
			short number;  // usually used for matching number
			bool u_defined;
			uint8_t flags2;
		};

	};

	int ceilingxpan() const { return int(ceilingxpan_); }
	int ceilingypan() const { return int(ceilingypan_); }
	int floorxpan() const { return int(floorxpan_); }
	int floorypan() const { return int(floorypan_); }
	void setfloorxpan(float val) { floorxpan_ = fmodf(val + 512, 256); } // +512 is for handling negative offsets
	void setfloorypan(float val) { floorypan_ = fmodf(val + 512, 256); } // +512 is for handling negative offsets
	void setceilingxpan(float val) { ceilingxpan_ = fmodf(val + 512, 256); } // +512 is for handling negative offsets
	void setceilingypan(float val) { ceilingypan_ = fmodf(val + 512, 256); } // +512 is for handling negative offsets
	void addfloorxpan(float add) { floorxpan_ = fmodf(floorxpan_ + add + 512, 256); } // +512 is for handling negative offsets
	void addfloorypan(float add) { floorypan_ = fmodf(floorypan_ + add + 512, 256); } // +512 is for handling negative offsets
	void addceilingxpan(float add) { ceilingxpan_ = fmodf(ceilingxpan_ + add + 512, 256); } // +512 is for handling negative offsets
	void addceilingypan(float add) { ceilingypan_ = fmodf(ceilingypan_ + add + 512, 256); } // +512 is for handling negative offsets
	void setceilingslope(int heinum) { ceilingheinum = heinum; if (heinum) ceilingstat |= CSTAT_SECTOR_SLOPE; else ceilingstat &= ~CSTAT_SECTOR_SLOPE; }
	void setfloorslope(int heinum) { floorheinum = heinum; if (heinum) floorstat |= CSTAT_SECTOR_SLOPE; else floorstat &= ~CSTAT_SECTOR_SLOPE; }
	walltype* firstWall() const;
	walltype* lastWall() const;


	// These will unfortunately have to be within the base struct to refactor Blood properly. They can later be removed again, once everything is done.
	Blood::XSECTOR& xs() const { return *_xs;  }
	bool hasX() const { return _xs != nullptr; } // 0 is invalid!
	void allocX();

	// same for SW
	bool hasU() const { return u_defined; }
};

//=============================================================================
//
// internal wall struct - no longer identical with on-disk format
//
//=============================================================================

struct walltype
{
	// todo: get rid of the single variables!
	union {
		struct { int32_t x, y; };
		vec2_t pos;
	};
	
	int32_t point2;
	int32_t nextwall;
	int32_t sector;	// Build never had this...
	int32_t nextsector;
	
	// Again, panning fields extended for interpolation.
	float xpan_;
	float ypan_;
	
	EWallFlags cstat;
	int16_t picnum;
	int16_t overpicnum;
	union { int16_t lotag, type; }; // type is for Blood
	int16_t hitag;
	int16_t extra;
	
	int8_t shade;
	uint8_t pal;
	uint8_t xrepeat;
	uint8_t yrepeat;
	
	// extensions not from the binary map format.
	binangle clipangle;
	int length; // cached value to avoid calling sqrt repeatedly.
	
	uint16_t portalnum;
	uint8_t portalflags;
	uint8_t lengthflags;

	// Blood is the only game which extends the wall struct.
	Blood::XWALL* _xw;
	vec2_t baseWall;

	int xpan() const { return int(xpan_); }
	int ypan() const { return int(ypan_); }
	void setxpan(float add) { xpan_ = fmodf(add + 512, 256); } // +512 is for handling negative offsets
	void setypan(float add) { ypan_ = fmodf(add + 512, 256); } // +512 is for handling negative offsets
	void addxpan(float add) { xpan_ = fmodf(xpan_ + add + 512, 256); } // +512 is for handling negative offsets
	void addypan(float add) { ypan_ = fmodf(ypan_ + add + 512, 256); } // +512 is for handling negative offsets
	sectortype* nextSector() const;
	sectortype* sectorp() const;
	walltype* nextWall() const;
	walltype* lastWall() const;
	walltype* point2Wall() const;
	vec2_t delta() const { return point2Wall()->pos - pos; }
	vec2_t center() const { return(point2Wall()->pos + pos) / 2; }
	int deltax() const { return point2Wall()->x - x; }
	int deltay() const { return point2Wall()->y - y; }
	bool twoSided() const { return nextsector >= 0; }
	int Length();
	void calcLength();	// this is deliberately not inlined and stored in a file where it can't be found at compile time.
	void move(int newx, int newy);
	void moved();

	Blood::XWALL& xw() const { return *_xw; }
	bool hasX() const { return _xw != nullptr; }
	void allocX();
};

//=============================================================================
//
// internal sprite struct - no longer identical with on-disk format
//
//=============================================================================

struct spritetypebase
{
	// todo: get rid of the single variables!
	union {
		struct { int32_t x, y, z; };
		vec3_t pos;
	};
	union {
		struct { int32_t ox, oy, oz; };
		vec3_t opos;
	};
	
	sectortype* sectp;
	
	ESpriteFlags cstat;
	int16_t picnum;
	int16_t statnum;
	int16_t ang;
	int16_t oang;
	int16_t xvel;
	int16_t yvel;
	union { int16_t zvel, inittype; }; // inittype, type and flags are for Blood.
	union { int16_t lotag, type; };
	union { int16_t hitag, flags; };
	int16_t extra;
	int16_t detail;
	
	int8_t shade;
	uint8_t pal;
	uint8_t clipdist;
	uint8_t blend;
	uint8_t xrepeat;
	uint8_t yrepeat;
	int8_t xoffset;
	int8_t yoffset;

	// extensions not from the binary map format.
	int time;
	uint16_t cstat2;


	void setpos(const vec3_t& newpos)
	{
		pos = newpos;
	}

	int32_t interpolatedx(double const smoothratio, int const scale = 16)
	{
		return interpolatedvalue(ox, x, smoothratio, scale);
	}

	int32_t interpolatedy(double const smoothratio, int const scale = 16)
	{
		return interpolatedvalue(oy, y, smoothratio, scale);
	}

	int32_t interpolatedz(double const smoothratio, int const scale = 16)
	{
		return interpolatedvalue(oz, z, smoothratio, scale);
	}

	vec2_t interpolatedvec2(double const smoothratio, int const scale = 16)
	{
		return
		{
			interpolatedx(smoothratio, scale),
			interpolatedy(smoothratio, scale)
		};
	}

	vec3_t interpolatedvec3(double const smoothratio, int const scale = 16)
	{
		return
		{
			interpolatedx(smoothratio, scale),
			interpolatedy(smoothratio, scale),
			interpolatedz(smoothratio, scale)
		};
	}

	int16_t interpolatedang(double const smoothratio)
	{
		return interpolatedangle(oang, ang, smoothratio, 16);
	}

	void backupx()
	{
		opos.x = pos.x;
	}

	void backupy()
	{
		opos.y = pos.y;
	}

	void backupz()
	{
		opos.z = pos.z;
	}

	void backupvec2()
	{
		opos.vec2 = pos.vec2;
	}

	void backuppos()
	{
		opos = pos;
	}

	void backupang()
	{
		oang = ang;
	}

	void backuploc()
	{
		backuppos();
		backupang();
	}

	sectortype* sector() const;
	int sectno() const;
	bool insector() const;
	void setsector(sectortype*);
	void setsector(int);
};


struct spritetype : public spritetypebase
{
	int16_t owner;
	int16_t detail;
	int16_t wall;	// wall and wdist are for Polymost only.
	int8_t wdist;

	void clear()
	{
		auto sect = sectp;
		int stat = statnum;
		int save = time;    // this may not be cleared ever!!!
		memset(this, 0, sizeof(*this));
		time = save;
		sectp = sect;
		statnum = stat;
	}

};

//=============================================================================
//
// This is mostly the same, but it omits the 'owner' field in favor of a full actor pointer. 
// Incompatibility with spritetype regarding assignments is deliberate as these serve a fundamentally different purpose!
//
//=============================================================================

struct tspritetype : public spritetypebase
{
	DCoreActor* ownerActor;

	void copyfrom(spritetype* spr)
	{
		pos = spr->pos;
		opos = spr->opos;
		cstat = spr->cstat;
		picnum = spr->picnum;
		shade = spr->shade;
		pal = spr->pal;
		clipdist = spr->clipdist;
		blend = spr->blend;
		xrepeat = spr->xrepeat;
		yrepeat = spr->yrepeat;
		xoffset = spr->xoffset;
		yoffset = spr->yoffset;
		sectp = spr->sectp;
		statnum = spr->statnum;
		ang = spr->ang;
		oang = spr->oang;
		xvel = spr->xvel;
		yvel = spr->yvel;
		zvel = spr->zvel;
		lotag = spr->lotag;
		hitag = spr->hitag;
		extra = spr->extra;
		time = spr->time;
		cstat2 = spr->cstat2;
		ownerActor = nullptr;

		// need to copy the slope sprite flag around because for tsprites the bit combination means 'voxel'.
		if ((cstat & CSTAT_SPRITE_ALIGNMENT_MASK) == CSTAT_SPRITE_ALIGNMENT_SLOPE)
		{
			cstat &= ~CSTAT_SPRITE_ALIGNMENT_WALL;
			cstat2 |= CSTAT2_SPRITE_SLOPE;
		}

	}

};

extern TArray<sectortype> sector;
extern TArray<walltype> wall;
extern TArray<sectortype> sectorbackup;
extern TArray<walltype> wallbackup;
extern BitArray gotsector;

//=============================================================================
//
// inlines
//
//=============================================================================

inline bool validSectorIndex(int sectnum)
{
	return (unsigned)sectnum < sector.Size();
}

inline bool validWallIndex(int wallnum)
{
	return (unsigned)wallnum < wall.Size();
}

inline sectortype* spritetypebase::sector() const
{
	return sectp;
}

inline int spritetypebase::sectno() const
{
	return sectp? ::sector.IndexOf(sectp) : -1;
}

inline void spritetypebase::setsector(sectortype* sect)
{
	// place for asserts.
	sectp = sect;
}

inline void spritetypebase::setsector(int sec)
{
	// place for asserts.
	sectp = validSectorIndex(sec)? &::sector[sec] : nullptr;
}

inline bool spritetypebase::insector() const
{
	return sectp != nullptr;
}



inline sectortype* walltype::nextSector() const
{
	return !validSectorIndex(nextsector)? nullptr :  &::sector[nextsector];
}

inline walltype* walltype::nextWall() const
{
	return !validWallIndex(nextwall)? nullptr : &::wall[nextwall];
}

inline sectortype* walltype::sectorp() const
{
	return &::sector[sector]; // cannot be -1 in a proper map.
}

inline walltype* walltype::lastWall() const
{
	int index = wall.IndexOf(this);
	if (index > 0 && wall[index - 1].point2 == index) return &wall[index - 1];

	int check = index;
	for (int i = 0; i < 16384; i++)	// don't run endlessly in case of malformed sectors.
	{
		int next = wall[check].point2;
		if (next == index) return &wall[check];
		check = next;
	}
	return nullptr;
}

inline walltype* walltype::point2Wall() const
{
	return &::wall[point2]; // cannot be -1 in a proper map.
}

inline walltype* sectortype::firstWall() const
{
	return &wall[wallptr]; // cannot be -1 in a proper map
}

inline walltype* sectortype::lastWall() const
{
	return &wall[wallptr + wallnum - 1]; // cannot be -1 in a proper map
}

inline void walltype::moved() 
{
	lengthflags = 3;
	sectorp()->dirty = EDirty::AllDirty;
}

inline void walltype::move(int newx, int newy)
{
	pos.x = newx;
	pos.y = newy;
	lengthflags = 3;
	sectorp()->dirty = EDirty::AllDirty;
}

inline int walltype::Length()
{
	if ((lengthflags & 1) || (point2Wall()->lengthflags & 2))
	{
		// value is stale, recreate
		calcLength();
	}
	return length;
}

//=============================================================================
//
// Map loader stuff
//
//=============================================================================
struct SpawnSpriteDef;

void allocateMapArrays(int numwall, int numsector, int numsprites);
void validateSprite(spritetype& spr, int secno, int index);
void fixSectors();
void loadMap(const char *filename, int flags, vec3_t *pos, int16_t *ang, int *cursectnum, SpawnSpriteDef& sprites);
void loadMapBackup(const char* filename);
void loadMapHack(const char* filename, const unsigned char*, SpawnSpriteDef& sprites);
