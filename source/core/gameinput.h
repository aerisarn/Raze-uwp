#pragma once

#include "m_fixed.h"
#include "binaryangle.h"
#include "gamecvars.h"
#include "gamestruct.h"
#include "packet.h"

inline constexpr binangle getincanglebam(binangle a, binangle na)
{
	return na-a;
}

inline constexpr int getincangle(int a, int na)
{
	return getincanglebam(buildang(a), buildang(na)).signedbuild();
}

struct PlayerHorizon
{
	fixedhoriz horiz, ohoriz, horizoff, ohorizoff;

	friend FSerializer& Serialize(FSerializer& arc, const char* keyname, PlayerHorizon& w, PlayerHorizon* def);

	// Prototypes for functions in gameinput.cpp.
	void applyinput(float const horz, ESyncBits* actions, double const scaleAdjust = 1);
	void calcviewpitch(vec2_t const pos, binangle const ang, bool const aimmode, bool const canslopetilt, sectortype* const cursectnum, double const scaleAdjust = 1, bool const climbing = false);
	void calcviewpitch(const DVector2& pos, binangle const ang, bool const aimmode, bool const canslopetilt, sectortype* const cursectnum, double const scaleAdjust = 1, bool const climbing = false)
	{
		vec2_t ps = { int(pos.X * worldtoint), int(pos.Y * worldtoint) };
		calcviewpitch(ps, ang, aimmode, canslopetilt, cursectnum, scaleAdjust, climbing);
	}
	void calcviewpitch(const DVector3& pos, binangle const ang, bool const aimmode, bool const canslopetilt, sectortype* const cursectnum, double const scaleAdjust = 1, bool const climbing = false)
	{
		vec2_t ps = { int(pos.X * worldtoint), int(pos.Y * worldtoint) };
		calcviewpitch(ps, ang, aimmode, canslopetilt, cursectnum, scaleAdjust, climbing);
	}

	// Interpolation helpers.
	void backup()
	{
		ohoriz = horiz;
		ohorizoff = horizoff;
	}
	void restore()
	{
		horiz = ohoriz;
		horizoff = ohorizoff;
	}

	// Commonly used getters.
	fixedhoriz osum() { return ohoriz + ohorizoff; }
	fixedhoriz sum() { return horiz + horizoff; }
	fixedhoriz interpolatedsum(double const smoothratio) { return interpolatedhorizon(osum(), sum(), smoothratio); }

	// Ticrate playsim adjustment helpers.
	void resetadjustment() { adjustment = 0; }
	bool targetset() { return target.asq16(); }

	// Input locking helpers.
	void lockinput() { inputdisabled = true; }
	void unlockinput() { inputdisabled = false; }
	bool movementlocked() {	return targetset() || inputdisabled; }

	// Draw code helpers.
	double horizsumfrac(double const smoothratio) { return (!SyncInput() ? sum() : interpolatedsum(smoothratio)).asbuildf() * (1. / 16.); }

	// Ticrate playsim adjustment setters and processor.
	void addadjustment(fixedhoriz const value)
	{
		if (!SyncInput())
		{
			adjustment += value.asbuildf();
		}
		else
		{
			horiz += value;
		}
	}

	void settarget(fixedhoriz value, bool const backup = false)
	{
		// Clamp incoming variable because sometimes the caller can exceed bounds.
		value = q16horiz(clamp(value.asq16(), gi->playerHorizMin(), gi->playerHorizMax()));

		if (!SyncInput() && !backup)
		{
			target = value.asq16() ? value : q16horiz(1);
		}
		else
		{
			horiz = value;
			if (backup) ohoriz = horiz;
		}
	}

	void processhelpers(double const scaleAdjust)
	{
		if (targetset())
		{
			auto delta = (target - horiz).asbuildf();

			if (abs(delta) > 1)
			{
				horiz += buildfhoriz(scaleAdjust * delta);
			}
			else
			{
				horiz = target;
				target = q16horiz(0);
			}
		}
		else if (adjustment)
		{
			horiz += buildfhoriz(scaleAdjust * adjustment);
		}
	}

private:
	fixedhoriz target;
	double adjustment;
	bool inputdisabled;
};

struct PlayerAngle
{
	binangle ang, oang;
	DAngle look_ang, olook_ang, rotscrnang, orotscrnang;
	double spin;

	friend FSerializer& Serialize(FSerializer& arc, const char* keyname, PlayerAngle& w, PlayerAngle* def);

	// Prototypes for functions in gameinput.cpp.
	void applyinput(float const avel, ESyncBits* actions, double const scaleAdjust = 1);

	// Interpolation helpers.
	void backup()
	{
		oang = ang;
		olook_ang = look_ang;
		orotscrnang = rotscrnang;
	}
	void restore()
	{
		ang = oang;
		look_ang = olook_ang;
		rotscrnang = orotscrnang;
	}

	// Commonly used getters.
	binangle osum() { return oang + bamang(olook_ang.BAMs()); }
	binangle sum() { return ang + bamang(look_ang.BAMs()); }
	binangle interpolatedsum(double const smoothratio) { return interpolatedangle(osum(), sum(), smoothratio); }
	DAngle interpolatedlookang(double const smoothratio) { return interpolatedangle(olook_ang, look_ang, smoothratio); }
	DAngle interpolatedrotscrn(double const smoothratio) { return interpolatedangle(orotscrnang, rotscrnang, smoothratio); }

	// Ticrate playsim adjustment helpers.
	void resetadjustment() { adjustment = 0; }
	bool targetset() { return target.BAMs(); }

	// Input locking helpers.
	void lockinput() { inputdisabled = true; }
	void unlockinput() { inputdisabled = false; }
	bool movementlocked() { return targetset() || inputdisabled; }

	// Draw code helpers. The logic where these are used rely heavily on Build's angle period.
	double look_anghalf(double const smoothratio) { return (!SyncInput() ? look_ang : interpolatedlookang(smoothratio)).Normalized180().Buildfang() * 0.5; }
	double looking_arc(double const smoothratio) { return fabs((!SyncInput() ? look_ang : interpolatedlookang(smoothratio)).Normalized180().Buildfang()) * (1. / 9.); }

	// Ticrate playsim adjustment setters and processor.
	void addadjustment(const DAngle value)
	{
		if (!SyncInput())
		{
			adjustment += value.Normalized180().Degrees();
		}
		else
		{
			ang += bamang(value.BAMs());
		}
	}

	void settarget(const DAngle value, bool const backup = false)
	{
		if (!SyncInput() && !backup)
		{
			target = value.BAMs() ? value : DAngle::fromBam(1);
		}
		else
		{
			ang = bamang(value.BAMs());
			if (backup) oang = ang;
		}
	}

	void processhelpers(double const scaleAdjust)
	{
		if (targetset())
		{
			auto delta = deltaangle(DAngle::fromBam(ang.asbam()), target).Degrees();

			if (abs(delta) > 1)
			{
				ang += degang(scaleAdjust * delta);
			}
			else
			{
				ang = bamang(target.BAMs());
				target = DAngle::fromBam(0);
			}
		}
		else if (adjustment)
		{
			ang += degang(scaleAdjust * adjustment);
		}
	}

private:
	DAngle target;
	double adjustment;
	bool inputdisabled;
};

class FSerializer;
FSerializer& Serialize(FSerializer& arc, const char* keyname, PlayerAngle& w, PlayerAngle* def);
FSerializer& Serialize(FSerializer& arc, const char* keyname, PlayerHorizon& w, PlayerHorizon* def);


void updateTurnHeldAmt(double const scaleAdjust);
bool isTurboTurnTime();
void resetTurnHeldAmt();
void processMovement(InputPacket* const currInput, InputPacket* const inputBuffer, ControlInfo* const hidInput, double const scaleAdjust, int const drink_amt = 0, bool const allowstrafe = true, double const turnscale = 1);
