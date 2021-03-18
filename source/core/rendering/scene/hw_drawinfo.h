#pragma once

#include <atomic>
#include <functional>
#include "vectors.h"
#include "hw_viewpointuniforms.h"
#include "v_video.h"
#include "hw_drawlist.h"

enum EDrawMode
{
	DM_MAINVIEW,
	DM_OFFSCREEN,
	DM_PORTAL,
	DM_SKYPORTAL
};

struct FSectorPortalGroup;
struct FLinePortalSpan;
struct FFlatVertex;
class HWWall;
class HWFlat;
class HWSprite;
struct HWDecal;
class IShadowMap;
struct FDynLightData;
struct HUDSprite;
class Clipper;
class HWPortal;
class FFlatVertexBuffer;
class IRenderQueue;
class HWScenePortalBase;
class FRenderState;

//==========================================================================
//
// these are used to link faked planes due to missing textures to a sector
//
//==========================================================================

enum SectorRenderFlags
{
    // This is used to merge several subsectors into a single draw item
    SSRF_RENDERFLOOR = 1,
    SSRF_RENDERCEILING = 2,
    SSRF_RENDERALL = 7,
    SSRF_PROCESSED = 8,
    SSRF_SEEN = 16,
};

enum EPortalClip
{
	PClip_InFront,
	PClip_Inside,
	PClip_Behind,
};

enum DrawListType
{
	GLDL_PLAINWALLS,
	GLDL_PLAINFLATS,
	GLDL_MASKEDWALLS,
	GLDL_MASKEDFLATS,
	GLDL_MASKEDWALLSOFS,
	GLDL_MODELS,

	GLDL_TRANSLUCENT,
	GLDL_TRANSLUCENTBORDER,

	GLDL_TYPES,
};


struct HWDrawInfo
{
	struct wallseg
	{
		float x1, y1, z1, x2, y2, z2;
	};

	HWDrawList drawlists[GLDL_TYPES];
	int vpIndex;
	//ELightMode lightmode;

	FLevelLocals *Level;
	HWDrawInfo * outer = nullptr;
	int FullbrightFlags;
	std::atomic<int> spriteindex;
	HWPortal *mClipPortal;
	HWPortal *mCurrentPortal;
	//FRotator mAngles;
	Clipper *mClipper;
	//FRenderViewpoint Viewpoint;
	HWViewpointUniforms VPUniforms;	// per-viewpoint uniform state
	TArray<HWPortal *> Portals;
	TArray<HWDecal *> Decals[2];	// the second slot is for mirrors which get rendered in a separate pass.
	TArray<HUDSprite> hudsprites;	// These may just be stored by value.

	TArray<sectortype *> HandledSubsectors;

	TArray<uint8_t> sector_renderflags;

	// This is needed by the BSP traverser.
	BitArray CurrentMapSections;	// this cannot be a single number, because a group of portals with the same displacement may link different sections.
	fixed_t viewx, viewy;	// since the nodes are still fixed point, keeping the view position  also fixed point for node traversal is faster.
	bool multithread;

private:
    // For ProcessLowerMiniseg
    bool inview;
//    sectortype * viewsubsector;
//	sectortype *currentsubsector;	// used by the line processing code.
	sectortype *currentsector;

	void WorkerThread();

	void UnclipSubsector(sectortype *sub);
	
	void AddLine(walltype *seg, bool portalclip);
	void AddLines(sectortype* sector);
	void AddSpecialPortalLines(sectortype * sector, walltype* line);
	public:
	//void RenderThings(sectortype * sub, sectortype * sector);
	//void RenderParticles(sectortype *sub, sectortype *front);
	void SetColor(FRenderState &state, int sectorlightlevel, int rellight, bool fullbright, const FColormap &cm, float alpha, bool weapon = false);
	void SetFog(FRenderState &state, int lightlevel, int rellight, bool fullbright, const FColormap *cmap, bool isadditive);
	void SetShaderLight(FRenderState &state, float level, float olight);
	int CalcLightLevel(int lightlevel, int rellight, bool weapon, int blendfactor);
	PalEntry CalcLightColor(int light, PalEntry pe, int blendfactor);
	float GetFogDensity(int lightlevel, PalEntry fogcolor, int sectorfogdensity, int blendfactor);
	bool CheckFog(sectortype *frontsector, sectortype *backsector);
public:

	void SetCameraPos(const DVector3 &pos)
	{
		VPUniforms.mCameraPos = { (float)pos.X, (float)pos.Z, (float)pos.Y, 0.f };
	}

	void SetClipHeight(float h, float d)
	{
		VPUniforms.mClipHeight = h;
		VPUniforms.mClipHeightDirection = d;
		VPUniforms.mClipLine.X = -1000001.f;
	}

	void SetClipLine(walltype *line)
	{
		//VPUniforms.mClipLine = { (float)line->v1->fX(), (float)line->v1->fY(), (float)line->Delta().X, (float)line->Delta().Y };
		VPUniforms.mClipHeight = 0;
	}

	HWPortal * FindPortal(const void * src);

	//static HWDrawInfo *StartDrawInfo(FLevelLocals *lev, HWDrawInfo *parent, FRenderViewpoint &parentvp, HWViewpointUniforms *uniforms);
	//void StartScene(FRenderViewpoint &parentvp, HWViewpointUniforms *uniforms);
	void ClearBuffers();
	HWDrawInfo *EndDrawInfo();

	void DrawScene(int drawmode);
	void CreateScene(bool drawpsprites);
	void RenderScene(FRenderState &state);
	void RenderTranslucent(FRenderState &state);
	void RenderPortal(HWPortal *p, FRenderState &state, bool usestencil);
	void EndDrawScene(sectortype * viewsector, FRenderState &state);
	void DrawEndScene2D(sectortype * viewsector, FRenderState &state);
	void Set3DViewport(FRenderState &state);
	void ProcessScene(bool toscreen);

	//void GetDynSpriteLight(AActor *self, float x, float y, float z, FLightNode *node, int portalgroup, float *out);
	//void GetDynSpriteLight(AActor *thing, particle_t *particle, float *out);

	void UpdateCurrentMapSection();
	void SetViewMatrix(const FRotator &angles, float vx, float vy, float vz, bool mirror, bool planemirror);
	void SetupView(FRenderState &state, float vx, float vy, float vz, bool mirror, bool planemirror);
	angle_t FrustumAngle();

	void DrawDecals(FRenderState &state, TArray<HWDecal *> &decals);
	void DrawPlayerSprites(bool hudModelStep, FRenderState &state);

    //void AddSubsectorToPortal(FSectorPortalGroup *portal, sectortype *sub);
    
    void AddWall(HWWall *w);
    void AddMirrorSurface(HWWall *w);
	void AddFlat(HWFlat *flat);
	void AddSprite(HWSprite *sprite, bool translucent);


    HWDecal *AddDecal(bool onmirror);

	bool isSoftwareLighting() const
	{
		return true;// lightmode == ELightMode::ZDoomSoftware || lightmode == ELightMode::DoomSoftware || lightmode == ELightMode::Build;
	}

	bool isBuildSoftwareLighting() const
	{
		return true;// lightmode == ELightMode::Build;
	}

	bool isDoomSoftwareLighting() const
	{
		return false;// lightmode == ELightMode::ZDoomSoftware || lightmode == ELightMode::DoomSoftware;
	}

	bool isDarkLightMode() const
	{
		return false;// lightmode == ELightMode::Doom || lightmode == ELightMode::DoomDark;
	}

	void SetFallbackLightMode()
	{
		//lightmode = ELightMode::Doom;
	}

};

void CleanSWDrawer();
//sectortype* RenderViewpoint(FRenderViewpoint& mainvp, AActor* camera, IntRect* bounds, float fov, float ratio, float fovratio, bool mainview, bool toscreen);
//void WriteSavePic(player_t* player, FileWriter* file, int width, int height);
//sectortype* RenderView(player_t* player);


